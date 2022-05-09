#pragma once
#include <iostream>
#include <string>
#include "F_Trans_Format.h"
#include "F_Type_Judge.h"
#include "Struct_Num.h"
#include "Struct_Sgn.h"
using namespace std;

string prepare(string sx);
void sort(string sx,Num *pnum,Sgn *psgn,int *pnum_max,int *psgn_max);



string prepare(string sx)
{
	string s = sx;
	int len = str_len(s);
	
	s = s + " ";
	//cout << "=" << s << endl;
	return s;
}





void sort(string sx, Num *pnum, Sgn *psgn, int *pnum_max, int *psgn_max)
{
	string s = sx;
	int len = str_len(s);
	int ready_num = 1;
	int ready_sgn = 1;

	
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(')
		{
			s.erase(s.begin() + i);
			len = len - 1;
			i = 0;
		}
		if (s[i] == ')')
		{
			s.erase(s.begin() + i);
			len = len - 1;
			i = 0;
		}
	}
	//cout << endl << "sorting:" << s << endl << endl;
	
	for (int i = 0; i < len; i++)
	{
		
			if (i > 0)
			{
				if (ch_type(s[i - 1]) > ch_type(s[i]))
				{
					//cout << "num[" << ready_num << "].app=" << (pnum + ready_num)->app << endl;
					ready_num = ready_num + 1;
					*pnum_max = *pnum_max + 1;
				}

				if (ch_type(s[i - 1]) < ch_type(s[i]))
				{
					//cout << "sgn[" << ready_sgn << "].type=" << (psgn + ready_sgn)->type << endl;
					ready_sgn = ready_sgn + 1;
					*psgn_max = *psgn_max + 1;
				}


			}

			if (ch_type(s[i]) == 2)
			{
				(pnum + ready_sgn)->app = (pnum + ready_sgn)->app + s[i];
			}


			if (ch_type(s[i]) == 1)
			{
				(psgn + ready_sgn)->type = s[i];
			}		
	}
}