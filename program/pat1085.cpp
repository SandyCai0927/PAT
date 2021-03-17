#include<algorithm>
#include<cstdio>
using namespace std;

const int maxn = 100005;
int num[maxn];

int main() {
	int n, p;
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	sort(num, num + n);
	int len = 1;
	for (int i = 0; i < n; i++) {
		int j = upper_bound(num + i + 1, num + n, (long long)num[i] * p) - num;
		len = max(len, j - i);
	}

	printf("%d\n", len);
	return 0;
}