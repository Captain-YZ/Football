#include <stdio.h>
#include <math.h>

int fact(int n) {
	if (n == 0)
		return 1;
	else
		return n * fact(n - 1);
}

double Poisson(double lamda, int x) {
	return pow(lamda, x) * exp(-lamda) / fact(x);
}

int main() {
	double p0[128] = {0}, p1[128] = {0}, p3[128] = {0}; //0=fu，1=平，3=胜，均是对a队的描述
	double lamda_1, lamda_2;
	for (int i = 0; i < 128; i++) {
		scanf("%lf%lf", &lamda_1, &lamda_2);
		for (int x_1 = 0; x_1 <= 5; x_1++)
			for (int x_2 = 0; x_2 <= 5; x_2++) {
				if (x_1 > x_2)
					p3[i] += Poisson(lamda_1, x_1) * Poisson(lamda_2, x_2);
				else if (x_1 == x_2)
					p1[i] += Poisson(lamda_1, x_1) * Poisson(lamda_2, x_2);
				else if (x_1 < x_2)
					p0[i] += Poisson(lamda_1, x_1) * Poisson(lamda_2, x_2);
			}
	}

	for (int i = 0; i < 128; i++)
		printf("胜：%lf  平：%lf  负：%lf  sum=%lf\n", p3[i], p1[i], p0[i], p3[i] + p1[i] + p0[i]);
	return 0;
}