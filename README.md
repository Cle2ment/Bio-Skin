# Bio-Skin 多模态触觉传感器

## 环境配置
1. 安装使用Arduino IDE
2. 在Arduino IDE中安装ESP32开发板支持（esp32）
3. 选择ESP32S3 Dev Module或者实际的ESP32S3开发板
4. 验证项目代码

## 上游项目原始说明
- **原版**
```markdown
# Bio-Skin multi-modal tactile sensor

Nice to see you here!

This document will help you to know how to make your own Bio-Skin tactile sensor. If you still don't know what is Bio-Skin, please check our project homepage for more detail: https://williamalexanda.github.io/Bio-Skin/




## About the open source

Hardware of Bio-Skin will be open sourced under the Creative Commons Attribution-NonCommercial 4.0 International License, which means it's open for personal NonCommercial usage only.

Hardware parts include all molds, materials list and code for Esp32. Without software in PC, you can still get the sensor raw data by following this tutorial: https://youtu.be/GShOp8S6hr8

If you want the software which includes super-resolution or GUI or have any other questions, please send a email(haoran.guo@okstate.edu) to get more information.

中文制作教程：https://www.bilibili.com/video/BV1KD8Tz4ERr/
## Open Source List
Hardware folder: including all molds, Sensor PCB and single MUX PCB. All electronic components are directly marked in the figure.

Software folder: The code for ESP32-S3, which includes control, sample and data transmission function.

Material list: All the material you need to make the Bio-Skin.


## License

This project is released under a split licensing model to ensure both the hardware designs and the software code remain open and reciprocal.

| Component | License | Copyleft Strength | Full Text |
| :--- | :--- | :--- | :--- |
| **Hardware Designs** (Schematics, PCB, CAD files) | **CERN Open Hardware Licence v2.0 - Strongly Reciprocal (CERN-OHL-S 2.0)** | Strong | [LICENSE-HARDWARE](./LICENSE-HARDWARE) |
| **Software** (Firmware, Control Code) | **GNU Affero General Public License v3.0 (AGPLv3)** | Strong (Network Usage) | [LICENSE-SOFTWARE](./LICENSE-SOFTWARE) |

**CERN-OHL-S 2.0:** Requires that any modifications to the hardware design files must also be shared under the same license.

**AGPLv3:** Requires that any changes to the software, even if used only as a network service, must have their source code made available to users.
```

- **中文版**
```markdown
# Bio-Skin 多模态触觉传感器

很高兴在这里见到你！

本文档将帮助你了解如何制作你自己的 Bio-Skin 触觉传感器。如果你还不了解 Bio-Skin 是什么，请查看我们的项目主页以获取更多详情：https://williamalexanda.github.io/Bio-Skin/




## 关于开源

Bio-Skin 的硬件将在知识共享署名-非商业性使用 4.0 国际许可协议下开源，这意味着它仅开放用于个人非商业用途。

硬件部分包括所有模具、材料清单和 Esp32 的代码。即使没有 PC 端软件，你仍然可以通过遵循本教程获取传感器原始数据：https://youtu.be/GShOp8S6hr8

如果你需要包含超分辨率或图形用户界面的软件，或有任何其他问题，请发送邮件至 haoran.guo@okstate.edu 以获取更多信息。

中文制作教程：https://www.bilibili.com/video/BV1KD8Tz4ERr/
## 开源清单
硬件文件夹：包含所有模具、传感器 PCB 和单个多路复用器 PCB。所有电子元件均在图中直接标注。

软件文件夹：ESP32-S3 的代码，包含控制、采样和数据传输功能。

材料清单：制作 Bio-Skin 所需的所有材料。


## 许可证

本项目采用分拆许可模式发布，以确保硬件设计和软件代码保持开放和互惠。

| 组件 | 许可证 | Copyleft 强度 | 完整文本 |
| :--- | :--- | :--- | :--- |
| **硬件设计**（原理图、PCB、CAD 文件） | **CERN 开放硬件许可证 v2.0 - 强互惠 (CERN-OHL-S 2.0)** | 强 | [LICENSE-HARDWARE](./LICENSE-HARDWARE) |
| **软件**（固件、控制代码） | **GNU Affero 通用公共许可证 v3.0 (AGPLv3)** | 强（网络使用） | [LICENSE-SOFTWARE](./LICENSE-SOFTWARE) |

**CERN-OHL-S 2.0：** 要求对硬件设计文件的任何修改也必须以相同许可证共享。

**AGPLv3：** 要求对软件的任何更改，即使仅作为网络服务使用，也必须向用户提供其源代码。
```

## 作者
© Clément, Sphinx, 2025.