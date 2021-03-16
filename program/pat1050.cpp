#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;

const int maxn = 10005;
bool hashTable[128] = { false };

int main() {
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int len1 = s1.size();
	int len2 = s2.size();

	for (int i = 0; i < len2; i++) {
		hashTable[s2[i]] = true;
	}

	for (int i = 0; i < len1; i++) {
		if (hashTable[s1[i]] == false) {
			printf("%c", s1[i]);
		}
	}
	printf("\n");
	return 0;
}