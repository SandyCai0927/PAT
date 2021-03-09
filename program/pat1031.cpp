#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int main() {
	string s;
	cin >> s;
	int len = s.length();
	char* str = (char*)malloc(sizeof(char) * (len + 1));
	strcpy(str, s.c_str());
	int t = (len + 2) % 3;
	int n1, n2;
	n1 = (len + 2) / 3;
	n2 = (len + 2) / 3 + t;
	int m = 0, n = len - 1;
	for (int i = 0; i < n1 - 1; i++) {
		printf("%c", str[m++]);
		for (int j = 0; j < n2 - 2; j++) {
			printf(" ");
		}
		printf("%c\n", str[n--]);
	}
	for (int i = m; i <= n; i++) {
		printf("%c", str[i]);
	}
	printf("\n");
}