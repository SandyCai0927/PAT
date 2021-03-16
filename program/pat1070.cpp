#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 1005;

struct info
{
	float amount;
	float total_sale;
	float price;
}mooncake[N];

bool cmp(info a, info b) {
	return a.price > b.price;
}


int main() {
	int n, d;
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; i++) {
		scanf("%f", &mooncake[i].amount);
	}
	for (int i = 0; i < n; i++) {
		scanf("%f", &mooncake[i].total_sale);
		mooncake[i].price = mooncake[i].total_sale / mooncake[i].amount;
	}
	sort(mooncake, mooncake + n, cmp);
	float left = d;
	float profit = 0.0;
	for (int i = 0; i < n; i++) {
		if (mooncake[i].amount >= left) {
			profit += (left / mooncake[i].amount) * mooncake[i].total_sale;
			break;
		}
		else {
			left -= mooncake[i].amount;
			profit += mooncake[i].total_sale;
		}
	}
	printf("%.2f\n", profit);
	return 0;
}