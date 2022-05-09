#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include "F_Trans_Format.h"
#include "F_Type_Judge.h"

using namespace std;

bool pre_work(char *p);
void despace(char *p);
bool rough_check(char *p);
bool rewrite(char *p);
bool double_check(char *p);


bool pre_work(char *p)
{
	bool go_on = 1;
	despace(p);

	if (rough_check(p))
	{
		go_on = 0;
	}
	else
	{
		//cout << "yeah!" << endl;
		rewrite(p);
		//cout << p << endl;
		if (double_check(p))
		{
			go_on = 0;
		}
		
		if (go_on)
		{
			if (rewrite(p))
			{
				cout << "=" << p;
			}
		}
	
	}

	

	
	



	return go_on;
}

void despace(char *p)
{
	int len = strlen(p);
	for (int i = 0; i < len; i++)
	{
		if (*(p + i) == ' ')
		{
			for (int j = i; j < len; j++)
			{
				*(p + j) = *(p + j + 1);
			}
			i = 0;
			len = len - 1;
		}
	}
}

bool rough_check(char *p)
{
	bool Fr = 0, f;
	int len = strlen(p);
	for (int i = 0; i < len + 1; i++)
	{
		f = 1;
		int asc = *(p + i);

		if ((asc >= 48) && (asc <= 57))f = 0;//数字0~9合法
		if (*(p + i) == '.')f = 0;			 //符号'.'合法
		if (asc == 40)f = 0;                 //符号'('合法
		if (asc == 41)f = 0;                 //符号')'合法
		if (asc == 42)f = 0;                 //符号'*'合法
		if (asc == 43)f = 0;                 //符号'+'合法
		if (asc == 45)f = 0;                 //符号'-'合法
		if (asc == 47)f = 0;                 //符号'/'合法
		if (asc == 0) f = 0;                 //符号'\0'合法

		if (f == 1)
		{
			if (Fr == 0)
			{
				cout << "存在非法字符，请重新输入:\n";
				Fr = 1;
			}
		}
	}
	//if (Fr == 0) cout << " 2、不存在非法字符\n";

	return Fr;
}

bool rewrite(char *p)
{
	//string s = p;
	//int len = str_len(s);
	int len = strlen(p);
	//cout << "len="<<len << endl;
	
	bool nece = 0;
	for (int i = 0; i < len - 1; i++)
	{
		if
			/*
			(
			((s[i] == ')') && (s[i+1] == '('))
				|| ((s[i] == ')') && (ch_type(s[i+1]) == 2))
				|| ((ch_type(s[i]) == 2) && (s[i+1] == '('))
				)
			*/
			(
			((*(p + i) == ')') && (*(p + i + 1) == '('))
				|| ((*(p + i) == ')') && (ch_type(*(p + i + 1)) == 2))
				|| ((ch_type(*(p + i)) == 2) && (*(p + i + 1) == '('))
				)

		{
			nece = 1;
			//s.insert(s.begin() + i + 1, '*');
			//cout << s;
			
			for (int j = len; j > i; j--)
			{
				*(p + j + 1) = *(p + j);
			}
			*(p + i + 1) = '*';
			nece = 1;
			len = len + 1;
			
			i = 0;
		}
	}

	if (*p == '-')
	{
		nece = 1;
		for (int i = len - 1; i >= 0; i--)
		{
			*(p + i + 1) = *(p + i);
		}
		*p = '0';
		//*(p + 1) = '0';
		len = len + 1;
		*(p + len) = '\0';


		/*
		bool find_right = 0;
		for (int i = 3; i < len + 1; i++)
		{
			if (ch_type(*(p + i)) > ch_type(*(p + i + 1)))
			{
				for (int j = len; j > i; j--)
				{
					*(p + j + 1) = *(p + j);
				}
				*(p + i + 1) = ')';
				find_right = 1;
				nece = 1;
				len = len + 1;
				break;
			}
		}
		if (find_right == 0)
		{
			string temp = p;
			temp = temp + ")";
			len = len + 1;
			for (int i = 0; i < len; i++)
			{
				*(p + i) = temp[i];
			}
			find_right = 1;
			nece = 1;
		}

		*/
		
	}

	for (int i = 1; i < len + 1; i++)
	{
		if (*(p + i) == '-')
		{
			if (*(p + i - 1) == '(')
			{
				nece = 1;
				for (int j = len; j >= i; j--)
				{
					*(p + j + 2) = *(p + j);
				}
				*(p + i) = '(';
				*(p + i + 1) = '0';
				len = len + 2;

				for (int j = i + 3; j < len + 1; j++)
				{
					if (ch_type(*(p + j)) > ch_type(*(p + j + 1)))
					{
						for (int k = len; k > j; k--)
						{
							*(p + k + 1) = *(p + k);
						}
						*(p + j + 1) = ')';
						len = len + 1;
						break;
					}
				}
			}
		}
	}

	/*
		cout << "   =";
	for (int i = 0; i < len + 1; i++)
	{
		cout << *(p + i);
	}
	cout << endl;
	*/

	/*
	len = str_len(s);
	
	for (int i = 0; i < len; i++)
	{
		*(p + i) = s[i];
	}
	*(p + len) = '\0';
	*/
	
	return nece;
}

bool double_check(char *p)
{
	//cout << " 4、检验符号合法性\n";
	bool F = 0, K = 0;
	int L = 0, R = 0;
	int len = strlen(p);
	for (int i = 0; i < len; i++)
	{
		if ((ch_type(*(p + i)) < 2) && (ch_type(*(p + i + 1)) < 2))
		{
			if (ch_type(*(p + i)) + ch_type(*(p + i + 1)) == 2)
			{
				F = 1;
			}
			if (ch_type(*(p + i)) + ch_type(*(p + i + 1)) == 1)
			{
				if (*(p + i + 1) == ')')
				{
					F = 1;
				}
				if (*(p + i) == '(')
				{
					F = 1;
				}
			}
			if ((*(p + i) == '(') && (*(p + i + 1) == ')'))
			{
				K = 1;
			}
		}
		if (*(p + i) == '(')L = L + 1;
		if (*(p + i) == ')')R = R + 1;
		if (R > L)K = 1;
	}
	if (L != R)K = 1;

	if (F == 1)cout << "运算符号不合法，请重新输入:\n";
	else
	{
		//cout << "    运算符号合法 !\n";
		if (K == 1)
		{
			cout << "括号不合法，请重新输入:\n";
		}
		else
		{
			//cout << "    括号合法 !\n";
		}
	}



	return F + K;
}