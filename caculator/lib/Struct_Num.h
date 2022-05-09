#pragma once
#include <iostream>
#include <string>
#include "F_Trans_Format.h"
#include "F_Type_Judge.h"
using namespace std;
struct Num
{
public:

	string app;
	bool val_switch = 0;
	
	double app_val()
	{
		int len = str_len(app);
		int pointp = 0;
		double value = 0;


		bool isInt = 1;
		for (int i = 0; i < len; i++)
		{
			if (app[i] == '.')
			{
				if (i == 0)
				{
					app.insert(app.begin(), '0');
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
						app[i] = '\0';
						isInt = 1;
					}
				}

			}
			len = str_len(app);
		}




		if (isInt)
		{
			for (int i = 0; i < len; i++)
			{
				value = value * 10 + (ascii(app[i])) - 48;
			}
		}


		else
		{
			for (int i = 0; i < pointp; i++)
			{
				value = value * 10 + (ascii(app[i])) - 48;
			}
			for (int i = pointp + 1; i < len; i++)
			{
				value = value * 10 + (ascii(app[i])) - 48;
			}
			for (int i = pointp; i < len - 1; i++)
			{
				value = value / 10;
			}
		}

		return value;
	}
	double cal_val=app_val();
	double val()
	{
		if (val_switch)
		{
			return cal_val;
		}
		else
		{
			return app_val();
		}
		
	}

};


