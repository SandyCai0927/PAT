#include<cstdio>
using namespace std;

const int maxn = 100005;
int hashTable[maxn] = { 0 };

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		hashTable[a]++;
	}
	for (int i = 1; i < m; i++) {
		if (hashTable[i] && hashTable[m - i]) {
			if (i == m - i && hashTable[i] == 1) {
				continue;
			}
			printf("%d %d\n", i, m - i);
			return 0;
		}
	}
	printf("No Solution\n");
	return 0;
}