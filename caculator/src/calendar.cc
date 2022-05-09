#include "calendar.h"
using namespace std;
void calendar() 
{
    write_history cal("calender");
    std::cout<<"**********日历***********"<<std::endl;
    int num=0, year=0, month=0;
    char cyear[10], cmonth[10];
    int z = 1;
    int* judge=&z;
    
    while (*judge != 0) 
    {
        char charcter = '0';
        cout << "请输入年份及月份:" << endl;
        if (*judge == 2) 
        {
            cout << "请重新输入年份及月份:" << endl;
        }
        cout << "年份:"; cin >> cyear;
        cout << "月份:"; cin >> cmonth;
        year = atoi(cyear);
        month = atoi(cmonth);
        cal.write_his(cyear,10);
        cal.write_his("年\t");
        cal.write_his(cmonth,10);
        cal.write_his("月\t");
        cout << endl;

        if (month > 0 && month <= 12 && year>0) 
        {
            screenhead(year, month);
            arrange(year, month, num);
            holiday(month);
            get_time();
            std::cout<<"*************************"<<std::endl;
            std::cout<<"输入\"c\"清理屏幕\t输入\"q\"返上一级"<<std::endl;
            std::cout<<"其它键继续"<<std::endl;
            repeat(charcter, judge);
        }   //正确输入
        else 
        {
            std::cout << "输入错误请重新输入"<<std::endl;
            std::cout<<"输入\"c\"清理屏幕\t输入\"q\"返上一级"<<std::endl;
            std::cout<<"其它键继续"<<std::endl;
            repeat(charcter, judge);
        }
        
            // *judge = 2;//如果judge==2就进入循环重新继续输入
        
        cout << endl;
    }
    system(CLEAR_SCREEN);
    out0();

}

int CaculateWeekDay(int y, int m, int d)
{
    int ww = 0;
    if (m == 1 || m == 2) {
        m += 12;
        y--;
    }
    int iWeek = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    switch (iWeek)
    {
    case 0: ww = 1; break;
    case 1: ww = 2; break;
    case 2: ww = 3; break;
    case 3: ww = 4; break;
    case 4: ww = 5; break;
    case 5: ww = 6; break;
    case 6: ww = 7; break;
    }
    return ww;
}

int yearcal(int year) {
    int judge;
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                judge = 1;
            }
            else judge = 0;
        }
        else judge = 1;
    }
    else judge = 0;
    return judge;
}

void screenhead(int year, int month) {
    cout << "                         " << year << "年" << "           " << month << "月" << endl << endl;
    cout << "星期:  日        一        二        三        四        五        六" << endl;
}//显示日历的年月日,星期数情况

int number(int year, int month) {
    int num = 0;
    //这里显示日历的年月日,星期数情况
    switch (month)
    {
    case 1:; case 3:; case 5:; case 7:case 8:
    case 10: num = 31; break;
    default:
        num = 30;
        break;
    }
    if (yearcal(year) == 1) {
        if (month == 2) num = 29;
    }//这是闰年
    else {
        if (month == 2) num = 28;
    }//这是平年
    return num;
}

void holiday(int month) {
    if (month == 1 || month == 2 || month == 4 || month == 5 || month == 10) {
        cout << "本月的节假日有:";
        if (month == 1) {
            cout << "元旦,春节";
            cout << endl;
        }
        if (month == 2) {
            cout << "春节期间";
            cout << endl;
        }
        if (month == 4) {
            cout << "清明节";
            cout << endl;
        }
        if (month == 5) {
            cout << "劳动节,端午节";
            cout << endl;
        }
        if (month == 10) {
            cout << "中秋节,国庆节";
            cout << endl;
        }
    }
    else cout << "本月无节假日" << endl;
    return;
}

void arrange(int year, int month,int num) {
    num = number(yearcal(year), month);
    switch (CaculateWeekDay(year, month, 1))
    {
    case 7:cout << setw(10) << "1"; break;
    case 1:cout << setw(20) << "1"; break;
    case 2:cout << setw(30) << "1"; break;
    case 3:cout << setw(40) << "1"; break;
    case 4:cout << setw(50) << "1"; break;
    case 5:cout << setw(60) << "1"; break;
    case 6:cout << setw(70) << "1" << endl; break;
    }
    for (int i = 2; i <= num; i++) {
        if (CaculateWeekDay(year, month, i) == 6) cout << setw(10) << i << endl;
        else cout << setw(10) << i;
    }
    cout << endl << endl;
    return;
}

void repeat(char charcter,int *judge)
{
    cin >> charcter;
    if (charcter == 'q') 
        *judge = 0;
    else if (charcter == 'c') 
        {
            system(CLEAR_SCREEN);
            std::cout<<"**********日历***********"<<std::endl;
        }
    else *judge = 2;
    return;
}