# art_pi2_exp

这是一个基于**ART-Pi II**开发板的示例工程，用于评估一些性能和第三方的算法。

已使用**STM32CubeMX**重新生成工程，不依赖**RT-Thread**

> 使用STM32CubeMX生成后 art_pi2_exp_Boot 部分的 `xspi.c`有一些更改，主要目的是调整外置的flash的时钟速度，在初始化和地址映射模式下的最大时钟速度不同。



## 1. 评估内容

### 1.1 perfc_counter

[perfc_counter](https://github.com/GorgonMeducer/perf_counter)

具体性能请参考说明，本示例评估了 （v2.5.4）的一些裸机相关的功能。