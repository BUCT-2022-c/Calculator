#include"write_history.h"
using namespace std;
write_history::write_history(string his_name)
{
    name = his_name;
    // char *time =new char[32];
    time=get_time(time);
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open())
    {   
        cout<<"文件不存在,请在历史记录菜单创建文件!"<<endl;
        cout<<"*************************"<<std::endl;
        ifs.close();
        ifopen = 0;
        return;
    }
    else
    {
        ofs.open(FILENAME,ios::out|ios_base::app);
        ofs << time << "\t"<<name<<std::endl;
        ifopen = 1;
    }
}
void write_history::write_his(char arr[], int len) 
// 输入一个字符串数组, len为数组长度, 可以大于实际长度
{  
    
    ofs << arr;    
}
void write_history::write_his(std::string arr) 
{  
    
    ofs << arr;    
}
void write_history::write_his(double arr) 
{  
    
    ofs << arr;    
}
void write_history::write_his(int *p,int m,int n)
{
    for(int l=0;l<m;l++)
    {
        for (int i=0;i<n;i++)
        {
            ofs << *p <<"\t";
            p++;
        }
        ofs << endl;
    }
}
write_history::~write_history()
{
    ofs << "\n---\n"; 
    delete [] time;
    // cout << "保存成功!\n" ;
    ifopen = 0;
    ofs.close();
}