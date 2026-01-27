# Arduino ESP32 开发板软件说明

## 配置环境
使用Arduio IDE进行ESP32开发，需安装ESP32开发板支持包。
- 在开发板管理器中安装ESP32
- 在开发板和端口中选择ESP32S3 Dev Module和对应的COM端口
- 点击 ***验证*** 进行编译，确保环境配置正确

## 原始上游项目说明

- **原版**
```txt
Author: Haoran Guo(haoran.guo@okstate.edu), Oklahoma State University, MIR Lab

Hi, welcome to use Bio-Skin v1.0. 

Bio-Skin is aim to achieve a multi-modal cost effective tactile sensor, which can sense normal, shear force, 
temperature and achieve self temperature regulation.

*Sensor Setup
1. Connect wire between esp32 and MUX board. Pin definition of esp32: 
1 - S0
2 - S1
3 - S2
4 - S3
5 - Out
6 - (Default to plug off) Heat
GND - GND
3.3V - Vcc
3.3V - Vcc2 (For heating function)

2. Connect the Bio-Skin and Mux board by FPC ribbon.

3. Use the <COM> port on esp32 to connect the USB cable.

4. Open the arduino IDE and its serial monitor (or other serial monitor).

5. Connect the USB cable to the PC, and check the new COM port number for Bio-skin and the output of the serial port. 
(Baud rate: 250000)
The correct output include 11 sets of raw ADC data and seperate by comma.
Example: [Normal Force(NF)1, NF2, NF3, NF4, NF5, Shear Force(SF)1, SF2, SF3, SF4, Temperature, Data for calibration]
Then close the serial monitor to release the port.
```

- **中文版**
```txt
Haoran Guo(haoran.guo@okstate.edu), Oklahoma State University, MIR Lab

您好，欢迎使用Bio-Skin v1.0。

Bio-Skin旨在实现一种多模态、高性价比的触觉传感器，能够感知法向力、剪切力、温度，并具备自主温度调节功能。

传感器设置
1. 连接esp32与MUX板之间的导线。esp32引脚定义如下：
1 - S0
2 - S1
3 - S2
4 - S3
5 - Out
6 - （默认断开）加热端
GND - GND
3.3V - Vcc
3.3V - Vcc2（用于加热功能）

2. 通过FPC排线连接Bio-Skin与Mux板。

3. 使用esp32上的<COM>端口连接USB数据线。

4. 打开Arduino IDE及其串口监视器（或其他串口监视工具）。

5. 将USB数据线连接至电脑，确认Bio-skin对应的新COM端口号，并查看串口输出。
（波特率：250000）
正确的输出应包含11组以逗号分隔的原始ADC数据。
示例：[法向力(NF)1, NF2, NF3, NF4, NF5, 剪切力(SF)1, SF2, SF3, SF4, 温度, 校准数据]
随后关闭串口监视器以释放端口。
```




