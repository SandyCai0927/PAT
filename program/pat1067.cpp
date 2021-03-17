#include<cstdio>
using namespace std;

const int maxn = 100005;
int num[maxn], index[maxn];
int wrong = 0;

bool check(int n) {
	for (int i = wrong; i < n; i++) {
		if (num[i] != i) {
			wrong = i;
			return false;
		}
			
	}
	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	int i = 0, left = n - 1;
	for (int j = 0; j < n; j++) {
		scanf("%d", &num[j]);
		index[num[j]] = j;//记录当前数字所在的下标
		if (num[j] == 0)
			i = j;
		if (num[j] == j)
			left--;
	}

	int time = 0;
	while (left > 0) {
		if (num[0] == 0) {
			check(n);
			num[0] = num[wrong];
			num[wrong] = 0;
			index[num[0]] = 0;
			index[0] = wrong;
			time++;
			i = wrong;
		}
		while (num[0] != 0) {
			int j;
			j = index[i];
			num[i] = i;
			num[j] = 0;
			index[i] = i;
			index[0] = j;
			time++;
			i = j;
			left--;
		}
	}
	printf("%d\n", time);
	return 0;
}