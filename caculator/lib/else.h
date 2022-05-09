#pragma once
#include<iostream>
#include<string>
#include<cmath>
#include<stdio.h>
#include<cstring>
#include"clear_screen.h"
#include"get_time.h"
#include"ui.h"
using namespace std;
class buct {
public:
    void welcome(); 
	void Fraction_simplification();
    void Greatest_common_factorand_least_common_multiple();
    int max_common_divisor(int a[], int p);
    int min_common_multiple(int a[], int p);
    int lcm(int m1, int n1);
    int gcd(int m, int n);
    void Prime_factorization();
    void base_conversion();
    int TenNum(char a[], int B);   
    void Numchange(int m, int B);
    void determine_prime();
    void Statistics();
    double max(double a[], int);
    double ave(double a[], int);
    double mid(double a[], int);
    double variance(double a[], int);
};