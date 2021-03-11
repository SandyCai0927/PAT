#include<string>
#include<iostream>
using namespace std;

int main() {
	string str1, str2;
	cin >> str1;
	cin >> str2;
	int len1, len2;
	bool Hash[128] = { false };
	len1 = str1.length();
	len2 = str2.length();
	for (int i = 0; i < len1; i++) {
		int j;
		char c1, c2;
		for (j = 0; j < len2; j++) {
			c1 = str1[i];
			c2 = str2[j];
			if (c1 >= 'a' && c1 <= 'z')
				c1 -= 32;
			if (c2 >= 'a' && c2 <= 'z')
				c2 -= 32;
			if (c1 == c2)
				break;
		}
		if (j == len2 && Hash[c1] == false) {
			printf("%c", c1);
		}
		else {
			Hash[c1] = true;
		}
	}
	
}