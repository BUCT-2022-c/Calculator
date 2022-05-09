#include "get_time.h"

void get_time() 
{
    // 直接输出
    time_t t = time(NULL);
    struct tm* stime=localtime(&t);
    char tmp[32]={0};
    snprintf(tmp,sizeof(tmp),"%04d-%02d-%02d %02d:%02d:%02d",1900+stime->tm_year,1+stime->tm_mon,stime->tm_mday, stime->tm_hour,stime->tm_min,stime->tm_sec);
    std::cout<<"   "<<tmp<<std::endl;
}
char* get_time(char *tmp)
{   
    // 返回时间的指针
    time_t t = time(NULL);
    struct tm* stime=localtime(&t);
    snprintf(tmp,32,"%04d-%02d-%02d %02d:%02d:%02d",1900+stime->tm_year,1+stime->tm_mon,stime->tm_mday, stime->tm_hour,stime->tm_min,stime->tm_sec);
    return tmp;
    // **使用完需要使用:**
    // delete [] tmp;
    // 另一种实现
    // time_t t = time(0); 
    // char tmp[32]={NULL};
    // strftime(tmp, 32, "%Y-%m-%d %H:%M:%S",localtime(&t)); 
}

