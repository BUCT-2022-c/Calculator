#pragma once
#include <iostream>
#include <string>
#include "F_Char_Perp.h"
#include "F_String_Prep.h"
#include "clear_screen.h"
#include "write_history.h"
#include "get_time.h"
using namespace std;

void find_position(string sx, Sgn *psgn, int psgn_max);
void deve_pri(string sx,  Sgn *psgn,  int *psgn_max);
Num cal(Num, Sgn, Num);
void result(Num *pnum, Sgn *psgn, int *pnum_max, int *psgn_max,double *answer);
void list_check(Num *pnum, Sgn *psgn, int *pnum_max, int *psgn_max);
void si_ze_yun_suan();


void find_position(string sx, Sgn *psgn, int psgn_max) 
{
	string s = sx;
	int len = str_len(s);
	int found = 1;
	for (int i = 0; i < len; i++)
	{
		if (ch_type(s[i]) == 1)
		{
			(psgn + found)->position = i;
			found = found + 1;
		}
	}
}



void deve_pri(string sx, Sgn *psgn, int *psgn_max)
{
	
	string s = sx;

	find_position(s, psgn, *psgn_max);


	int len = str_len(s);
	for (int deal = 1; deal < *psgn_max + 1; deal++)
	{
		int left_quo = 0;
		int right_quo = 0;
		for (int i = 0; i < ((psgn + deal)->position); i++)
		{
			if (ascii(s[i]) == 40)
			{
				left_quo = left_quo + 1;
			}
			if (ascii(s[i]) == 41)
			{
				right_quo = right_quo + 1;
			}
		}
		(psgn + deal)->quo_priority = (left_quo - right_quo) * 10;
	}
}


Num cal(Num x, Sgn op, Num y)
{
	Num re;
	double val;
	if (op.type == '+')
	{
		val = x.val() + y.val();
	}
	if (op.type == '-')
	{
		val = x.val() - y.val();
	}
	if (op.type == '*')
	{
		val = x.val() * y.val();
	}
	if (op.type == '/')
	{
		val = x.val() / y.val();
	}

	re.cal_val = val;
	re.val_switch = 1;

	return re;
}


void result(Num *pnum, Sgn *psgn, int *pnum_max, int *psgn_max,double *a)
{

	if (*psgn_max > 1)
	{
		
		int psgn_todo = 1;
		for (int i = 1; i < *psgn_max + 1; i++)
		{
			if ((psgn + i)->general_priority() > (psgn + psgn_todo)->general_priority())
			{
				psgn_todo = i;
			}
		}


		//list_check(pnum, psgn, pnum_max, psgn_max);
		//cout << "psgn_todo= " << psgn_todo << endl << endl;


		*(pnum + psgn_todo) = cal(*(pnum + psgn_todo), *(psgn + psgn_todo), *(pnum + psgn_todo + 1));

		for (int i = psgn_todo + 1; i < *pnum_max; i++)
		{
			*(pnum + i) = *(pnum + i + 1);
		}

		for (int i = psgn_todo ; i < *psgn_max; i++)
		{
			*(psgn + i) = *(psgn + i + 1);
		}


		*pnum_max = *pnum_max - 1;
		*psgn_max = *psgn_max - 1;

		result(&(*pnum), &(*psgn), &(*pnum_max), &(*psgn_max),&(*a));
	}
	else
	{
		if (*psgn_max == 0)
		{
			if ((psgn + 1)->type == ' ')
			{
				//cout << "=" << (pnum + 1)->app_val() << endl;
				*a=(pnum + 1)->app_val();
			}
		}
		else
		{
			int psgn_todo = 1;
			//list_check(pnum, psgn, pnum_max, psgn_max);
			//cout << "psgn_todo= " << psgn_todo << endl << endl;
			Num re = cal(*(pnum + 1), *(psgn + 1), *(pnum + 2));
			//cout << "=" << re.cal_val << endl;
			*a=re.cal_val;
		}
		
	}
}




void list_check(Num *pnum, Sgn *psgn, int *pnum_max, int *psgn_max)
{
	for (int i = 1; i < *psgn_max + 1; i++)
	{
		cout << "num[" << i << "].app=" << (pnum+i)->app << "\t\t\t"
			<< "num[" << i << "].val()=" << (pnum + i)->val() << endl;
		cout << "sgn[" << i << "].type=" << (psgn + i)->type << "\t\t\t"
			<< "sgn[" << i << "].priority()=" << (psgn + i)->general_priority() << endl;
	}
	cout << "num[" << *pnum_max << "].app=" << (pnum+*pnum_max)->app << "\t\t\t"
		<< "num[" << *pnum_max << "].val()=" << (pnum + *pnum_max)->val() << endl;
	

}


void si_ze_yun_suan()
{
	char line[2000];
	cin.get();
	std::cout<<"*********四则运算*********"<<std::endl;
	get_time();
	cout<<"输入\"c\"清理屏幕\t输入\"q\"返回上一级\n";
	while (1)
	{	
		cout << "请输入四则运算算式:\n";
		cin.getline(line, 2000);
		if (line[0]=='q') break;
		if (line[0]=='c') system(CLEAR_SCREEN);
		if (pre_work(line))
		{
			write_history ari("arithmetic");
			string sen = line;
			double answer;
			ari.write_his(sen);
			sen = prepare(sen);
			Num num[200];
			Sgn sgn[200];
			int num_max = 0;
			int sgn_max = 0;
			sort(sen, num, sgn, &num_max, &sgn_max);
			deve_pri(sen, sgn, &sgn_max);
			result(num, sgn, &num_max, &sgn_max,&answer);
			cout<<"="<<answer<<endl;
			ari.write_his("=");
			ari.write_his(answer);
			

		}
	}
}