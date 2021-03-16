#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 1005;

int hashTable[80] = { 0 };

int to_num(char c) {
	if (c >= '0' && c <= '9')
		return c - '0';
	else if (c >= 'a' && c <= 'z')
		return c - 'a' + 10;
	else
		return c - 'A' + 36;
}

int main() {
	char first[maxn], second[maxn];
	scanf("%s", first);
	scanf("%s", second);
	int len1 = strlen(first);
	int len2 = strlen(second);
	int miss = 0;

	for (int i = 0; i < len1; i++) {
		int num = to_num(first[i]);
		hashTable[num]++;
	}

	for (int i = 0; i < len2; i++) {
		int num = to_num(second[i]);
		hashTable[num]--;
		if (hashTable[num] < 0)
			miss++;
	}

	if (miss > 0) {
		printf("No %d\n", miss);
	}
	else {
		printf("Yes %d\n", len1 - len2);
	}

	return 0;
}