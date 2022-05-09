#pragma once
#include <iostream>
#include <string>
#include <cstring>

using namespace std;



int str_len(string s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return i;
}



double val(string sx)
{
	string s = sx;
	int len = str_len(s);
	int pointp = 0;
	double value = 0;

	bool isInt = 1;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '.')
		{
			if (i == 0)
			{
				s.insert(s.begin(), '0');
				pointp = 1;
				isInt = 0;
			}
			else
			{
				if (i < len - 1)
				{
					pointp = i;
					isInt = 0;
				}
				else
				{
					s[i] = '\0';
					isInt = 1;
				}
			}

		}
	}

	/*
	if (isInt)
	{
		for (int p = num.size - 1; p >= 0; p = p - 1)
		{
			num.val = num.val + num.app[p] * pow(10, num.size - p - 1);
		}
	}
	else
	{
		int pop;
		for (int i = 0; i < num.size; i++)
		{
			if (num.app[i] = '.')
			{
				pop = i;
			}
			for (int p = pop - 1; p >= 0; p--)
			{
				num.val = num.val + num.app[p] * pow(10, pop - p - 1);
			}
			for (int p = pop + 1; p <= num.size; p++)
			{
				num.val = num.val + num.app[p] * pow(10, pop - p);
			}
		}

	}
	*/

	return value;
}



