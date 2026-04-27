// Utility.cpp
#include "Utility.h"
#include <math.h>
#include <time.h>
#include <fstream>
#include <iostream>
using namespace std;
void tridiagonal_elimination(double** Smat, double* known, double* unknown, int n_eqns) {
	double ratio, sum;
	int i, j, k;
	for (k = 0; k < n_eqns - 1; k++) {
		if (Smat[k][k] == 0) {
			cout << "matrix is singular" << endl;
			exit(0);
		}
		ratio = -Smat[k + 1][k] / Smat[k][k];
		if(k == n_eqns - 2){
			for (j = k; j <= k + 1; j++) {
				if (Smat[k][j] == 0.) continue;
				Smat[k + 1][j] += ratio * Smat[k][j];
			}

		}
		else {
			for (j = k; j <= k + 2; j++) {
				if (Smat[k][j] == 0.) continue;
				Smat[k + 1][j] += ratio * Smat[k][j];
			}
		}
		known[k + 1] += ratio * known[k];
	}
	unknown[n_eqns - 1] = known[n_eqns - 1] / Smat[n_eqns - 1][n_eqns - 1];
	for (i = n_eqns - 2; i >= 0; i--) {
		sum = Smat[i][i + 1] * unknown[i + 1];
		unknown[i] = (known[i] - sum) / Smat[i][i];
	}
}
double a(double S, double t, double dS, double dt, double r, double sigma) {
	double a1,a2;
	a1 = 0.5 * pow(((sigma * S) / dS),2);
	a2 = 0.5 * r * S / dS;
	return -a1 - a2;

}
double b(double S, double t, double dS, double dt, double r, double sigma) {
	return r + pow((sigma * S) / dS, 2);

}
double c(double S, double t, double dS, double dt, double r, double sigma) {
	double c1, c2;
	c1 = 0.5 * pow(((sigma * S) / dS), 2);
	c2 = 0.5 * r * S / dS;
	return -c1 + c2;

}

double ai(double S, double t, double dS, double dt, double r, double sigma) {
	return a(S, t, dS, dt, r, sigma) * dt;
}

double bi(double S, double t, double dS, double dt, double r, double sigma) {
	return b(S, t, dS, dt, r, sigma) * dt + 1;

}

double ci(double S, double t, double dS, double dt, double r, double sigma) {
	return c(S, t, dS, dt, r, sigma) * dt;
}

void trimat(double** temp,double Smax, double t, double dS, double dt, double r, double sigma, int N) {
	int i=0,j=0;
	temp[0][0] = 2 * ci(dS, t, dS, dt, r, sigma) + bi(dS, t, dS, dt, r, sigma);
	temp[0][1] = -ci(dS, t, dS, dt, r, sigma) + ai(dS, t, dS, dt, r, sigma);
	for (j = 1; j < N - 1; j++) {
		temp[j][j - 1] = ci((j + 1) * dS, t, dS, dt, r, sigma);
		temp[j][j] = bi((j + 1) * dS, t, dS, dt, r, sigma);
		temp[j][j + 1] = ai((j + 1) * dS, t, dS, dt, r, sigma);
	}
	temp[N - 1][N - 2] = ci(Smax, t, dS, dt, r, sigma) - ai(Smax, t, dS, dt, r, sigma);
	temp[N - 1][N - 1] = bi(Smax, t, dS, dt, r, sigma) + 2 * ai(Smax, t, dS, dt, r, sigma);

}
void thomas(double** Smat, double* known, double* unknown, int N) {
	double *v1, *v2;
	int i = 0;
	v1 = new double[N - 1];
	v2 = new double[N];
	v1[0] = Smat[0][1] / Smat[0][0];
	v2[0] = known[0] / Smat[0][0];
	for (i = 1; i < N - 1;i++) {
		v1[i] = Smat[i][i + 1] / (Smat[i][i] - Smat[i][i - 1] * v1[i - 1]);
	}
	for (i = 1; i < N; i++) {
		v2[i] = (known[i] - Smat[i][i - 1] * v2[i - 1]) / (Smat[i][i] - Smat[i][i - 1] * v1[i - 1]);
	}
	unknown[N - 1] = v2[N - 1];
	for (i = 1; i < N; i++) {
		unknown[N - i - 1] = v2[N - i - 1] - v1[N - i - 1] * unknown[N - i];
	}
}