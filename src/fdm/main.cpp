#define _CRT_SECURE_NO_DEPRECATE
#include "Utility.h"
#include <time.h>
using namespace std;
void trimat(double** temp, double Smax, double t, double dS, double dt, double r, double sigma, int N);
void tridiagonal_elimination(double** Smat, double* known, double* unknown, int n_eqns);
void  thomas(double** Smat, double* known, double* unknown, int N);
void main(void) {
	clock_t start, finish;
	double duration;
	start = clock();
	double s0, k, r, q, sigma, dS, dt, year, T, maxS, time;
	int N=0, i=0, j=0 ,days = 0;
	double *known, *unknown;
	double **grid, **matrix;
	s0 = 100;
	k = 100;
	r = 0.03;
	q = 0;
	sigma = 0.2;
	dS = 1;
	year = 250;
	dt = 1 / year;
	T = 1;
	days = int(T * year);
	maxS = s0 * (1 + T*3 * sigma);
	N = int(maxS / dS);
	grid = new double* [N];
	matrix = new double* [N];
	known = new double[N];
	unknown = new double[N];
	for (i = 0; i < N; i++) grid[i] = new double[days+1];
	for (i = 0; i < N; i++) {
		grid[i][days] = max(i + 1 - k, 0);
	}
	for (i = 0; i < N; i++) matrix[i] = new double[N];
	for (j = 0; j < days; j++) {
		time = T - j / year;
		trimat(matrix, maxS, time, dS, dt, r, sigma, N);
		for (i = 0; i < N; i++) {
			known[i] = grid[i][days - j];
		}
		thomas(matrix, known, unknown, N);

		for (i = 0; i < N; i++) {
			grid[i][days-j-1] = unknown[i];
		}
		
	}
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	
	cout << "가격:" << grid[99][0] << endl;
	cout << "델타:" << 0.5 * (grid[101][0] - grid[99][0]) << endl;
	cout << duration << "초 소요" << endl;

}