**作者**：Haoran Guo（haoran.guo@okstate.edu），Oklahoma State University，MIR Lab

欢迎使用 Bio-Skin v1.0。

Bio-Skin 旨在实现一种**多模态、低成本**的触觉传感器，可感知**法向力**、**切向力（剪切力）**与**温度**，并支持**自温控**（温度调节）。

## 传感器接线与使用步骤（Sensor Setup）

1. 连接 ESP32 与 MUX 板之间的导线。ESP32 引脚定义如下：
	- 1 — S0
	- 2 — S1
	- 3 — S2
	- 4 — S3
	- 5 — Out
	- 6 —（默认不接）Heat
	- GND — GND
	- 3.3V — Vcc
	- 3.3V — Vcc2（用于加热功能）

2. 使用 FPC 排线将 Bio-Skin 与 MUX 板连接。

3. 使用 ESP32 上标注为 `<COM>` 的接口连接 USB 线。

4. 打开 Arduino IDE 以及其串口监视器（或其他串口监视工具）。

5. 将 USB 线连接到电脑，确认 Bio-Skin 新出现的 COM 口编号，并查看串口输出。（波特率：250000）
	- 正确输出应包含 11 组原始 ADC 数据，并使用英文逗号 `,` 分隔。
	- 示例：`[Normal Force(NF)1, NF2, NF3, NF4, NF5, Shear Force(SF)1, SF2, SF3, SF4, Temperature, Data for calibration]`
	- 查看完成后请关闭串口监视器，以释放串口占用。







