#include <stdio.h>
#include <math.h>

double ArrAverage(
	double* Array,
	long NumArray
)
{
	long i;
	double Result;
	Result = 0.0;
	for (i = 0; i < NumArray; i++)
	{
		Result += Array[i];
	}
	Result /= NumArray;
	return Result;
}

long CalcDrift(
	double Rf,
	double Div,
	double* S0,
	double dt,
	long NTrials,
	double* Drift
)
{
	long i;
	for (i = 0; i < NTrials; i++)
	{
		Drift[i] = S0[i] *  (Rf - Div) * dt;
	}

	return 1;
}

long CalcDiversity(
	double* S0,
	double Vol,
	double dt,
	long NTrials,
	double* Rand,
	double* Diversity
)
{
	long i;
	for (i = 0; i < NTrials; i++)
	{
		Diversity[i] = S0[i] * Vol * Rand[i];
	}
	return 1;
}

double makeRand(long *seed)
{
	long a, P, b, c;
	long Orgseed;
	double Rand;
	a = 16807;
	P = 2147483647;
	b = 127773;
	c = 2836;
	Orgseed = (*seed);
	long k;
	k = (long)(Orgseed / b);
	(*seed) = a * (Orgseed - k * b) - k * c;
	if ((*seed) < 0)
		(*seed) += P;
	Rand = (*seed);
	Rand *= 1.0;
	Rand /= P;
	return Rand;
}

// 간단 근사 함수 (Beasley-Springer 근사)
double RationalApproximation(double t) {
	double c[] = { 2.515517, 0.802853, 0.010328 };
	double d[] = { 1.432788, 0.189269, 0.001308 };
	return t - ((c[2] * t + c[1]) * t + c[0]) / (((d[2] * t + d[1]) * t + d[0]) * t + 1.0);
}
double NormalCDFInverse(double p) {
	if (p < 0.5)
		return -RationalApproximation(sqrt(-2.0 *log(p)));
	else
		return RationalApproximation(sqrt(-2.0 *log(1 - p)));
}