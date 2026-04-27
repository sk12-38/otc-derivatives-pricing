// MCS.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cmath>
#include "Utility.h"

int main()
{
    double S0 = 100;
    double K = 100;
    long NTrials = 50000;
    double T = 1.0;
    long Days = 250;
    double dt = 1 / 250.0;
    double r = 0.02;
    double Vol = 0.3;
    double** S;
    double* Drift;
    double* Diversity;
    double* Rand;
    double OptionPrice;
    OptionPrice = 0.0;
    long seed = 1000;
    double rand = 0.0;
    long i,j;
    S = (double**)malloc((Days+1) * sizeof(double*));
    Drift = (double*)malloc(NTrials * sizeof(double));
    Diversity = (double*)malloc(NTrials * sizeof(double));
    Rand = (double*)malloc(NTrials * sizeof(double));
    for (i = 0; i < Days+1; i++)
    {
        S[i] = (double*)malloc(NTrials * sizeof(double));
    }
    for (i = 0; i < NTrials; i++)
        S[0][i] = S0;
    for (i = 0; i < Days; i++)
    {
        for (j = 0; j < NTrials; j++)
            Rand[j] = NormalCDFInverse(makeRand(&seed));
        CalcDrift(r, 0.0, S[i], dt, NTrials, Drift);
        CalcDiversity(S[i], Vol*sqrt(dt), dt, NTrials, Rand, Diversity);
        for (j = 0; j < NTrials; j++)
        {
            S[i + 1][j] = S[i][j] + Drift[j] + Diversity[j];
        }
    }
    for (j = 0; j < NTrials; j++)
        if(S[Days][j] > K)
            OptionPrice += (S[Days][j] - K);
    OptionPrice *= exp(-r * T);
    OptionPrice /= NTrials;
    printf("Option 가격: %f\n", OptionPrice);
    if (Rand) free(Rand);
    if (Drift) free(Drift);
    if (Diversity) free(Diversity);
    for (i = 0; i < Days + 1; i++)
    {
        if (S[i]) free(S[i]);
    }
    if (S) free(S);



}