#include"ui.h"
#include"get_time.h"
void out0()
{
    std::cout<<"***超级多功能Calculator***"<<std::endl;
    std::cout<<"请输入序号以选择计算器模式:"<<std::endl;
    std::cout<<"0.四则运算\n"<<"1.函数图像\n"<<"2.矩阵运算\n"
             <<"3.布尔代数\n"<<"4.日历节日\n"
             <<"5.其他功能\n"<<"6.历史记录\n"<<"输入\"c\"清理屏幕\t输入\"q\"退出\n";
    get_time();
    // std::cout<<get_time(1)<<std::endl;
    std::cout<<"*************************"<<std::endl;
}

void out_history()
{
    std::cout<<"********历史记录*********"<<std::endl;
    std::cout<<"请选择历史记录管理模式:"<<std::endl;
    std::cout<<"0.读取历史记录\n"<<"1.写入历史记录\n"<<"2.删除历史记录\n"
             <<"3.新建历史文件\n"<<"输入\"c\"清理屏幕\t输入\"q\"返回上一级\n";
    get_time();
    std::cout<<"*************************"<<std::endl;

}