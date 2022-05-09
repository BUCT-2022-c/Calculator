#pragma once
#define FILENAME "hisfile.txt"
#include "clear_screen.h"
#include <fstream> 
#include <string.h>
#include"get_time.h"

using namespace std;

class History
{
private:
    bool m_ifnull=0; // 0为空
    int m_Numhistory=0;
public:
    History();
    void read_file();
    void write_file();
    void delete_file();
    void new_file();
    ~History();
};

void history_choice();



