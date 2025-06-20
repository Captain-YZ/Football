#include <stdio.h>
#include <math.h>

double SD(double a, double b, double c) {
	double bar = (a + b + c) / 3;
	double sum = (a - bar) * (a - bar) + (b - bar) * (b - bar) + (c - bar) * (c - bar);
	return pow(sum / 3, 0.5);
}

void sort_f(double a[4], int b[3]) {
	a[2] = 999;
	b[0] = 0, b[1] = 1, b[2] = 2;
	for (int i = 0; i < 4; i++)
		if (a[i] <= a[b[0]])
			b[0] = i;
	for (int i = 0; i < 4; i++)
		if (i == b[0])
			continue;
		else if (a[i] < a[b[1]])
			b[1] = i;
	for (int i = 0; i < 4; i++)
		if (i != b[0] && i != b[1] && i != 2) {
			b[2] = i;
			break;
		}
}

int main() {
	double odds[64][4], sd[64]; // [3]记录胜，[1]记录平，[0]记录负
	int sort[64][3];//将赔率从小到大排序，记录对应的情况
	int num[64];
	for (int i = 0; i < 64; i++) {
		scanf("%lf%lf%lf", &odds[i][3], &odds[i][1], &odds[i][0]);
		sort_f(odds[i], sort[i]);
		sd[i] = SD(odds[i][3], odds[i][1], odds[i][0]);
		if (sd[i] > 1.5)
			num[i] = 1;
		else if (sd[i] < 0.8)
			num[i] = 3;
		else
			num[i] = 2;
	}
	//输出赔率方差，购买注数，下注情况
	for (int i = 0; i < 64; i++) {
		printf("第%2d场比赛：赔率方差：%9lf  购买注数：%d  下注情况", i + 1, sd[i], num[i]);
		if (num[i] == 1)
			printf("%d\n", sort[i][0]);
		else if (num[i] == 2)
			printf("%d %d\n", sort[i][0], sort[i][1]);
		else
			printf("%d %d %d\n", sort[i][0], sort[i][1], sort[i][2]);
	}
}