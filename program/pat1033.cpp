#include<cstdio>
#include<algorithm>
using namespace std;

struct info
{
	float price;
	float distance;
}stand[505];

bool cmp(info a, info b) {
	return a.distance < b.distance;
}

int main() {
	float d, cmax, davg;
	int n;
	scanf("%f%f%f%d", &cmax, &d, &davg, &n);
	for (int i = 0; i < n; i++) {
		scanf("%f%f", &stand[i].price, &stand[i].distance);
	}
	stand[n].distance = d;
	stand[n].price = 0.0;
	sort(stand, stand + n + 1, cmp);
	if (stand[0].distance != 0.0) {
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	float cost = 0.0;//花费
	int now = 0;//当前加油站的下标
	int max_dis = cmax * davg;//能够到达的最大距离
	int min_price = 1;
	float left = 0;
	for (int i = 1; i < n + 1; i++) {
		if (stand[i].distance - stand[now].distance <= max_dis) {
			if (stand[i].price < stand[now].price && (stand[i].distance - stand[now].distance) / davg>left) {
				cost += ((stand[i].distance - stand[now].distance) / davg - left) * stand[now].price;
				now = i;
				left = 0;
				min_price = now + 1;
				continue;
			}
			if (i > min_price && stand[i].price < stand[min_price].price) {
				min_price = i;
			}
		}
		else {
			if (stand[min_price].distance - stand[now].distance <= max_dis) {//能找到油价尽可能低的加油站
				cost += (cmax - left) * stand[now].price;//将油加满
				left = cmax - (stand[min_price].distance - stand[now].distance) / davg;//剩余油量
				now = min_price;
				min_price = now + 1;
				i--;
			}
			else {//加满油仍无法找到加油站
				float x = stand[now].distance + max_dis;
				printf("The maximum travel distance = %.2f", x);
				return 0;
			}
		}
	}
	if (now == n) {
		printf("%.2f\n", cost);
	}
	else {
		printf("The maximum travel distance = %.2f\n", stand[now].distance + max_dis);
	}

	return 0;
}