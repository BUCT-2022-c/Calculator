#pragma once
#include <iostream>
#include <string>
using namespace std;

int ascii(char c);
int ch_type(char c);
int str_type(string s);

int ascii(char c)
{
	int asc = c;
	return asc;
}

int ch_type(char c)
{
	int asc = c;

	//if (   (  (asc >= 48) && (asc <= 57)  )|| (c = '.')   );
	if (asc == 40)return 0;                 //符号'('
	if (asc == 41)return 0;                 //符号')'
	if (asc == 42)return 1;                 //符号'*'
	if (asc == 43)return 1;                 //符号'+'
	if (asc == 45)return 1;                 //符号'-'
	if (asc == 47)return 1;                 //符号'/'	
	if (c==' ')return 0;                 //符号' '
	return 2;     //数字0~9,小数点
}

int str_type(string s)
{
	int asc = s[0];

	if ((asc >= 48) && (asc <= 57))return 2;//数字0~9
	if (s[0] = '.')return 2;                //点号
	if (asc == 40)return 0;                 //符号'('
	if (asc == 41)return 0;                 //符号')'
	if (asc == 42)return 1;                 //符号'*'
	if (asc == 43)return 1;                 //符号'+'
	if (asc == 45)return 1;                 //符号'-'
	if (asc == 47)return 1;                 //符号'/'
	return 666;
}