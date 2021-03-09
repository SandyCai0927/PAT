#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int n;
	int minlen = 260;
	char s[100][260];
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++) {
		fgets(s[i], sizeof(s[i]), stdin);
		reverse(s[i], s[i] + strlen(s[i]));
		if (strlen(s[i]) < minlen)
			minlen = strlen(s[i]);
	}
	bool flag = true;
	int len = 0;
	for (int i = 0; i < minlen; i++) {
		char c = s[0][i];
		for (int j = 1; j < n; j++) {
			if (s[j][i] != c) {
				flag = false;
				break;
			}
		}
		if (flag) {
			len++;
		}
		else
			break;
	}
	if (len == 0) {
		cout << "nai";
	}
	else {
		for (int i = len - 1; i >= 0; i--) {
			cout << s[0][i];
		}
	}
}