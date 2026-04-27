#pragma once
//Utility.h
#include <iostream>
#define _CRT_SECURE_NO_DEPRECATE
#define max(a,b) (((a)>(b))?(a):(b))
#define PI 3.1415926535897932384626433832795028841
void tridiagonal_elimination(double** Smat, double* known, double* unknown, int n_eqns);