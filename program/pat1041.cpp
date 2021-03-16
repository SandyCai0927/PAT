#include<cstdio>
using namespace std;

const int maxn = 100005;
int num[maxn], hashTable[maxn] = { 0 };

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		hashTable[num[i]]++;
	}
	int m = 0;
	for (int i = 0; i < n; i++) {
		if (hashTable[num[i]] == 1) {
			m = num[i];
			break;
		}
	}

	if (m == 0) {
		printf("None\n");
	}
	else {
		printf("%d\n", m);
	}

	return 0;
}