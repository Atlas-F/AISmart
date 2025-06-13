# AISmart
AI 小智 圆形界面，使用文件模拟数据参数等

***

**环境**
    ubuntuSDL和GEC6818

**开发工具**
    Square Line 
    Vscode
    ubuntu20

**编译**
    arm-linux-gcc

**项目管理**
    CMake

**版本管理**
    git@github.com:Atlas-F/AISmart.git

**界面**

    数量：4
        常态界面：
            表情图：10个，间隔随机3秒内切换，循环
            切换方式：新旧交替浮现，调整不透明度
            实现：
                
        切换方式：点击
        1.主界面：
            内容：
                电池logo
                WIFIlogo
                日历
                时钟：时分秒
        2.
        3.


**技术栈**
    - LVGL
    - C语言

**数据**
    从文件导入，不能写死





### 项目日志

####  2025.6.13  V1.0

**问题**

- 从Square Line 中下载的项目源码可能会在编译时出现提示#include <in18> 这个报错，则只需将ui.h中该行预处理代码注释即可，

**注意**

- 屏幕加载初始化的函数与trigger要放置在screen对象下，放置在子控件下不起作用。相应的trigger要放置在相应的控件对象下是。



