#pragma once
#include <stdio.h>
double ArrAverage(
	double* Array,
	long NumArray
);

long CalcDrift(
	double Rf,
	double Div,
	double* S0,
	double dt,
	long NTrials,
	double* Drift
);

long CalcDiversity(
	double* S0,
	double Vol,
	double dt,
	long NTrials,
	double* Rand,
	double* Diversity
);
double makeRand(long* seed);
double NormalCDFInverse(double p);