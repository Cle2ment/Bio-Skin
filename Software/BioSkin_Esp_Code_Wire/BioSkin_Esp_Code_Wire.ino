#include <Arduino.h>

// 引脚定义
#define MUX_S0 1
#define MUX_S1 2
#define MUX_S2 3
#define MUX_S3 4
#define MUX_SIG 5           // 从多路复用器到 ESP32-S3 的信号
#define MUX_EN 15           // 多路复用器使能引脚
#define HEATER_CTRL 6       // 加热器控制引脚
#define STANDARD_SENSOR 10  // 新的标准传感器模拟输入

// 多路复用器控制
uint8_t muxChannel[10] = {
  0b0000, 0b0001, 0b0010, 0b0011, 0b0100,
  0b0101, 0b0110, 0b0111, 0b1000, 0b1001
};

// 采样间隔
const unsigned long samplingInterval = 5;  // 100Hz 对应 10ms
const unsigned long heaterPeriod = 500;    // 0.5 秒（毫秒）

unsigned long lastHeaterUpdate = 0;
int heaterDutyCycle = 0;  // 占空比（百分比）

void setup() {
  // 初始化串口监视器
  Serial.begin(250000);

  // 引脚模式
  pinMode(MUX_S0, OUTPUT);
  pinMode(MUX_S1, OUTPUT);
  pinMode(MUX_S2, OUTPUT);
  pinMode(MUX_S3, OUTPUT);
  pinMode(MUX_EN, OUTPUT);
  pinMode(HEATER_CTRL, OUTPUT);
  pinMode(MUX_SIG, INPUT);
  pinMode(STANDARD_SENSOR, INPUT);  // 将标准传感器引脚配置为输入

  // 使能多路复用器
  digitalWrite(MUX_EN, LOW);
  // 初始关闭加热器
  digitalWrite(HEATER_CTRL, LOW);

  // 设置 ADC 参数
  analogReadResolution(12);        // 将 ADC 分辨率设为 12 位
  analogSetAttenuation(ADC_11db);  // 设置衰减以测量全量程（0 - 3.3V）
}

void loop() {
  // 用于存储模拟读数的数组
  int readings[11];  // 调整大小以包含标准传感器数据

  // 遍历多路复用器的每个通道
  for (int i = 0; i < 10; i++) {
    selectMuxChannel(i);
    delayMicroseconds(100);  // 允许稳定时间（0.1ms）
    readings[i] = analogRead(MUX_SIG);
    if (i == 9) {  // 检查温度通道
      adjustHeater(readings[i]);
    }
  }

  // 读取标准传感器数据
  readings[10] = analogRead(STANDARD_SENSOR);

  // 通过串口发送数据
  sendDataSerial(readings);

  // 等待下一次采样
  delay(samplingInterval);
}

void selectMuxChannel(int channel) {
  digitalWrite(MUX_S0, bitRead(muxChannel[channel], 0));
  digitalWrite(MUX_S1, bitRead(muxChannel[channel], 1));
  digitalWrite(MUX_S2, bitRead(muxChannel[channel], 2));
  digitalWrite(MUX_S3, bitRead(muxChannel[channel], 3));
}

void sendDataSerial(int *readings) {
  char data[64];
  int len = 0;

  // 将数据格式化为紧凑的逗号分隔字符串
  for (int i = 0; i < 11; i++) {
    len += snprintf(data + len, sizeof(data) - len, "%d", readings[i]);
    if (i < 10) {
      len += snprintf(data + len, sizeof(data) - len, ",");
    }
  }

  // 通过串口发送数据
  Serial.println(data);
}

void adjustHeater(int temperatureAdcValue) {
  if (temperatureAdcValue < 1100) {
    heaterDutyCycle = 100;  // 最大占空比
  } else if (temperatureAdcValue >= 1100 && temperatureAdcValue < 2050) {
    heaterDutyCycle = map(temperatureAdcValue, 1100, 2100, 100, 0);  // 线性降低占空比
  } else {
    heaterDutyCycle = 0;  // 关闭加热器
  }

  unsigned long currentTime = millis();
  unsigned long onTime = heaterPeriod * heaterDutyCycle / 100;
  unsigned long offTime = heaterPeriod - onTime;

  if (heaterDutyCycle > 0 && currentTime - lastHeaterUpdate < onTime) {
    digitalWrite(HEATER_CTRL, HIGH);  // 加热器开
  } else if (heaterDutyCycle > 0 && currentTime - lastHeaterUpdate >= onTime && currentTime - lastHeaterUpdate < heaterPeriod) {
    digitalWrite(HEATER_CTRL, LOW);  // 加热器关
  } else if (currentTime - lastHeaterUpdate >= heaterPeriod) {
    lastHeaterUpdate = currentTime;  // 重置周期
  }
}
