#include"history.h"
#include"ui.h"
History::History()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open())
    {   
        cout<<"文件不存在,请创建文件 !"<<endl;
        cout<<"*************************"<<std::endl;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout<<"无历史记录"<<endl;
        cout<<"*************************"<<std::endl;
        ifs.close();
        m_ifnull=1;
        return;
    }
    m_ifnull=1;
    while(!ifs.eof())
        {    //判断文件是否读取到末尾
            char buffer[100]={0};
            ifs.getline(buffer, 100);
            if (buffer[0]=='-'&&buffer[1]=='-')
                {
                    m_Numhistory++;
                }

        }
    m_Numhistory--;
    cout<<"现共有"<<m_Numhistory<<"条历史记录"<<endl;
    cout<<"*************************"<<std::endl;
    ifs.close();

}
void History::read_file()
{   
    int his_num = 0;
    if(m_ifnull==1)
    {
        ifstream in_file(FILENAME);
        char buffer[100]={0};
        if(!in_file.is_open()){    //判断文件是否打开成功
            cout << "Failed to open file, pls check if file is exist or not.\n";
        }
        while(!in_file.eof()){    //判断文件是否读取到末尾
            in_file.getline(buffer, 100);
            cout << buffer << endl;
        }
        in_file.close();
    }
}
void History::write_file()
{
    ofstream ofs;
    ofs.open(FILENAME,ios::out|ios_base::app);
    m_ifnull=1;
    while(true)
    {   
        char *p=new char [32];
        char wf_choice[5];
        ofs << get_time(p)<<"\t"<<"history" << std::endl;
        delete [] p;
        char h_equation[120] = {0};
        cout << "请输入需要添加的记录: " <<endl;
        cin.get();
        cin.getline(h_equation,120);
        ofs << h_equation<< std::endl<<"---"<<std::endl;
        m_Numhistory++;
        cout << "保存成功!\n" << "输入\"q\"退出写入历史记录功能\n"
             <<"其它键继续记录\n";
        cin >> wf_choice;
        if (wf_choice[0]=='q')
            break;
    }
    
    ofs.close();
}
void History::new_file()
{
    ofstream ofs;
    ofs.open(FILENAME,ios::out|ios_base::app);
    m_ifnull=1;    
    ofs << "---\n";
    ofs.close();
    std::cout<<"新建文件成功!"<<std::endl;
    std::cout<<"*************************"<<std::endl;
}
void History::delete_file()
{
    // ifstream ifs;
    // ifs.open(FILENAME,ios::out|ios::binary);
    // ifs.close();
    remove(FILENAME);
    std::cout<<"文件删除成功!"<<std::endl;
    std::cout<<"*************************"<<std::endl;
}

History::~History()
{
}

void history_choice()
{   
    History hi;
    bool t=0;
    char his;
    while(std::cin>>his)
    {
        switch (his)
        {
            case '0':
                // 读取历史记录
                hi.read_file();
                break;
            case '1':
                hi.write_file();
                // 写入历史记录
                break;
            case '2':
                // 删除历史记录
                hi.delete_file();
                break;
            case '3':
                // 新建历史记录
                hi.new_file();
                break;
            case 'c':
                system(CLEAR_SCREEN); //Ubuntu
                //system(CLEAR_SCREEN); //Windows
                out_history();
                break;
            case 'q':
                t = 1;
                break;
            default:
                std::cout<<"请重新输入正确的序号"<<std::endl;
                break;
        }
        if (t==1)
            break;
    }
    system(CLEAR_SCREEN);
    out0();

}