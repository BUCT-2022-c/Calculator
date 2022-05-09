#pragma once
#include<iostream>
#include<cmath>
#include<graphics.h>
#include <conio.h>
#include"get_time.h"
class graph {
private:
	double a, b, c, d;
	int parameter;
public:
	
	bool check_input();
	void welcome();
	int get_parameter();
	double get_a();
	double get_b();
	double get_c();
	double get_d();
	
};
void abstract_graph(int, int);
void print_graph(double, double, double, double, int);