#pragma once
#include "clear_screen.h"
#include<iostream>
#include<string.h>
#include<iomanip>
#include<cmath>
#include<cstring>
#include"ui.h"
#include"get_time.h"
#include"write_history.h"
void calendar();
int CaculateWeekDay(int, int, int);
int yearcal(int);
void screenhead(int, int);
int number(int, int);
void holiday(int);
void arrange(int, int, int);
void repeat(char, int*);