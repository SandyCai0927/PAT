#include<string>
#include<iostream>
using namespace std;

string number[] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
string unit[] = { "Shi","Bai","Qian","Wan","Yi" };

int main() {
	string n;
	cin >> n;
	if (n.length() == 1) {
		cout << number[n[0] - '0'];
		return 0;
	}
	int i = 0;
	if (n[0] == '-') {
		cout << "Fu ";
		i++;
	}
	int len = n.length() - i;
	bool other = false;
	if (len == 9) {
		//处理“亿”
		cout << number[n[i] - '0'] << " " << unit[4];
		i++;
		//处理“万”
		int k = 4;
		for (int j = i; j < i + 4; j++, k--) {
			if (n[j] == '0') {
				if (n[j + 1] == '0')
					continue;
				else if (k - 1 != 0 && n[j + 1] != '0') {
					cout << " " << number[0];
				}
			}
			else {
				other = true;
				cout << " " << number[n[j] - '0'];
				if (k != 1)
					cout << " " << unit[k - 2];
			}
		}
		if (other)
			cout << " " << unit[3];
		i = i + 4;
		//处理“千”
		k = 4;
		for (int j = i; j < i + 4; j++, k--) {
			if (n[j] == '0') {
				if (n[j + 1] == '0')
					continue;
				else if (k - 1 != 0 && n[j + 1] != '0') {
					cout << " " << number[0];
				}
			}
			else {
				cout << " " << number[n[j] - '0'];
				if (k != 1)
					cout << " " << unit[k - 2];
			}
		}
	}
	else if (len > 4 && len < 9) {
		//处理“万”
		int k = len - 4;
		for (int j = i; j < i + k; j++, k--) {
			if (n[j] == '0') {
				if (n[j + 1] == '0')
					continue;
				else if (k - 1 != 0 && n[j + 1] != '0') {
					cout << " " << number[0];
				}
			}
			else {
				if (k != len - 4) {
					cout << " ";
				}
				cout << number[n[j] - '0'];
				if (k != 1)
					cout << " " << unit[k - 2];
			}
		}
		cout << " " << unit[3];
		i = i + len - 4;
		//处理“千”
		k = 4;
		for (int j = i; j < i + 4; j++, k--) {
			if (n[j] == '0') {
				if (n[j + 1] == '0')
					continue;
				else if (k - 1 != 0 && n[j + 1] != '0') {
					cout << " " << number[0];
				}
			}
			else {
				cout << " " << number[n[j] - '0'];
				if (k != 1)
					cout << " " << unit[k - 2];
			}
		}
	}
	else if (len > 0 && len < 5) {
		int k = len;
		for (int j = i; j < i + 4; j++, k--) {
			if (n[j] == '0') {
				if (n[j + 1] == '0')
					continue;
				else if (k - 1 != 0 && n[j + 1] != '0') {
					cout << " " << number[0];
				}
			}
			else {
				if (k != len)
					cout << " ";
				cout << number[n[j] - '0'];
				if (k != 1)
					cout << " " << unit[k - 2];
			}
		}
	}
	
}