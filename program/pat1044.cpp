#include<iostream>
using namespace std;

const int maxn = 100005;
int num[maxn], sum[maxn];

int upper_bound(int L, int R, int x) {
	int mid;
	while (L < R) {
		mid = (L + R) / 2;
		if (sum[mid] > x)
			R = mid;
		else
			L = mid + 1;
	}
	return L;
}

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		sum[i] = sum[i - 1] + num[i];
	}

	int near = 100000005;
	for (int i = 1; i <= n; i++) {
		int j = upper_bound(i, n + 1, sum[i - 1] + m);
		if (sum[j - 1] - sum[i - 1] == m) {
			near = m;
			break;
		}
		else if (j != n + 1 && sum[j] - sum[i - 1] < near) {
			near = sum[j - 1] - sum[i - 1];
		}
	}

	for (int i = 1; i <= n; i++) {
		int j = upper_bound(i, n + 1, sum[i - 1] + near);
		if (sum[j - 1] - sum[i - 1] == near) {
			cout << i << "-" << j - 1 << "\n";
		}
	}
	return 0;
}