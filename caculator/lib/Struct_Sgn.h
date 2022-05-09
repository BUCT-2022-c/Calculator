#pragma once
#include <iostream>
#include <string>
using namespace std;
struct Sgn
{
public:

	char type = ' ';
	int position = 0;
	int quo_priority = 0;
	int origin_priority()
	{
		if (type == '+')
		{
			return 1;
		}
		if (type == '-')
		{
			return 1;
		}
		if (type == '*')
		{
			return 2;
		}
		if (type == '/')
		{
			return 2;
		}
		return 0;
	}
	int general_priority()
	{
		return origin_priority() + quo_priority;
	}

};