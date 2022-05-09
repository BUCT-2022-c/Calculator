#include<iostream>
#include"ui.h"
#include"history.h"
#include"calendar.h"
#include"write_history.h"
#include"matrix.h"
#include"truth_table.h"
#include"resource.h"
#include"else.h"
// #include"image.h"
int main()
{
    system(CLEAR_SCREEN);
    out0();
    char choice;
    while(std::cin>>choice)
    {
        switch (choice)
        {
        case '0':
            {
                // write_history test 加入历史记录可参考如下
                // 需包含"history.h"
                // string arr_test0="Hello World!";
                // char arr_test[500];
                // strcpy(arr_test,arr_test0.c_str());
                // write_history wh("ta");
                //wh.write_his(arr_test,500);
                // 普通计算器
                system(CLEAR_SCREEN);
                caculator0();
                system(CLEAR_SCREEN);
                out0();
            break;
            }
        case '1':
        {   // 函数图像
            
            // system(CLEAR_SCREEN);
            // char image_choice = 0;
            // while (image_choice != 'q')
            // {
            //     if (image_choice == 'c')
            //     {
            //         system(CLEAR_SCREEN);
            //         image_choice = 0;
            //         continue;
            //     }
            //     graph s1;
            //     s1.welcome();
            //     if (s1.check_input()) {
            //         abstract_graph(700, 700);
            //         print_graph(s1.get_a(), s1.get_b(), s1.get_c(), s1.get_d(), s1.get_parameter());
            //     }
            //     _getch();
            //     closegraph();
            //     cin.get();
            //     cout<< "输入\"c\"清理屏幕\t输入\"q\"退出"<<endl;
            //     cin >> image_choice;
            // }
            // system(CLEAR_SCREEN);
            // out0();
            break;

        }
        case '2':
            system(CLEAR_SCREEN);
            express();
            system(CLEAR_SCREEN);
            out0();
            // 矩阵运算
            break;
        case '3': 
            // 布尔代数
            {
                system(CLEAR_SCREEN);
                truth_table();
                system(CLEAR_SCREEN);
                out0();
                break;
            }
        case '4':
            // 日历和星座
            {
                system(CLEAR_SCREEN);
                calendar();
                system(CLEAR_SCREEN);
                out0();
                break;
            }
        case '5':
            {
                system(CLEAR_SCREEN);
                
                buct else_fun;
                else_fun.welcome();
                
                break;
            }
        case '6':
        {    // 历史记录
       
            system(CLEAR_SCREEN);
            out_history();
            history_choice();
            break;
        }
        case 'c':
            system(CLEAR_SCREEN); //Ubuntu
            //system(CLEAR_SCREEN); //Windows
            out0();
            break;
        case 'q':
            return 0;
            break;
        default:
            std::cout<<"请重新输入正确的序号"<<std::endl;
            break;
        
        }
    }


}
