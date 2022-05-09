# 超级多功能Calculator

---
## 介绍
北京化工大学, 2020级机械设计制造及其自动化专业程序设计I大作业.

---
## 程序编译
### g++ 编译命令
***不可使用 1. 函数绘制功能***

```
g++ caculator.cpp get_time.cc history.cc ui.cc calendar.cc write_history.cc matrix.cc truth_table.cc else.cc resource.cc
```
### CMake 编译
***不可使用 1. 函数绘制功能***

```
mkdir ./build
cd ./build
cmake ..
make
./caculator
```
### Visual Studio 中编译
***可使用全部功能,但需要在编译前下载EasyX Graphics Library.***

请前往[EasyX官网](https://easyx.cn/ ) 下载EasyX 2022 版.
即可在Visual Studio之中编译所有功能.
还需注意把caculator.cpp中``#include image.h``(第10行)和功能1之中的代码(第39~62行)去掉注释.
### 跨平台编译
在Ubuntu系统中与Windows系统之中清屏操作略有区别, 在`lib/clear_screen.h`中

```
#define CLEAR_SCREEN "clear"
```
Ubuntu中为`"clear"`, Windows为`"cls"`

---
## 使用说明
1. 程序分为两级菜单, 通过输入选项选择功能, 进入每一级功能后同样选择具体功能. 每一级目录中, 输入`c`进行清屏并继续选择功能, 输入`q`返回上一级(在主目录中输入为退出程序)
2. 绘制函数图像功能之中, 在选择完函数类型后需要按照提示的函数表达式, 依次输入指定的系数.
3. 在使用程序前需检查是否已经创建历史记录文件, 如未创建在历史记录功能之中会有所提示, 并通过其中的新建历史文件功能新建文件.

---

## 学习交流

taonaian@outlook.com 

