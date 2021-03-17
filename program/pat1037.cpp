#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100002;
int coupon[maxn], product[maxn];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", coupon[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &product[i]);
	}
	sort(coupon, coupon + n, cmp);
	sort(product, product + m, cmp);

	int i = 0;
	int sum = 0;
	while (i < n && i < m && coupon[i]>0 && product[i]>0) {
		sum += coupon[i] * product[i];
		i++;
	}
	i = n - 1;
	int j = m - 1;
	while (i >= 0 && j >= 0 && coupon[i] < 0 && product[j] < 0) {
		sum += coupon[i] * product[j];
		i--;
		j--;
	}
	printf("%d\n", sum);
	return 0;
}