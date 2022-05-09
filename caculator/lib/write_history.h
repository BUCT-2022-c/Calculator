#pragma once
#define FILENAME "hisfile.txt"
#include <fstream> 
#include <string.h>
#include "get_time.h"

class write_history
{
    private:
        std::string name;
        char* time = new char[32];
        std::ofstream ofs;
        bool ifopen = 0;
    public:
        write_history(std::string);
        void write_his(char [],int);
        void write_his(std::string);
        void write_his(double);
        void write_his(int *,int,int);
        ~write_history();
};
