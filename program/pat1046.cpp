#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100005;
long mindistance;
int dis[maxn] = { 0 };
int d[maxn] = { 0 };

int main() {
	int N, M;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &dis[i]);
		d[i] = dis[i] + d[i - 1];
	}
	int sum = d[N];
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int left, right;
		scanf("%d%d", &left, &right);
		if (left > right)
			swap(left, right);
		mindistance = d[right - 1] - d[left - 1];
		if (mindistance > sum - mindistance)
			mindistance = sum - mindistance;
		printf("%ld\n", mindistance);
	}
}