#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

struct account
{
	string name, pwd;
}temp, modi[1001];

int main() {
	int n, m = 0;
	cin >> n;
	bool flag1 = true, flag2 = true;
	for (int i = 0; i < n; i++) {
		flag2 = true;
		cin >> temp.name >> temp.pwd;
		for (int j = 0; j < temp.pwd.length(); j++) {
			switch (temp.pwd[j])
			{
			case '1':
				temp.pwd[j] = '@';
				flag1 = false;
				flag2 = false;
				break;
			case '0':
				temp.pwd[j] = '%';
				flag1 = false;
				flag2 = false;
				break;
			case 'l':
				temp.pwd[j] = 'L';
				flag1 = false;
				flag2 = false;
				break;
			case 'O':
				temp.pwd[j] = 'o';
				flag1 = false;
				flag2 = false;
				break;
			default:
				break;
			}
		}
		if (flag2 == false) {
			modi[m].name = temp.name;
			modi[m++].pwd = temp.pwd;
		}
	}
	if (flag1 == true) {
		if (n > 1) {
			cout << "There are " << n << " accounts and no account is modified";
		}
		else if (n == 1) {
			cout << "There is 1 account and no account is modified";
		}
		else {
			cout << "There is 0 account and no account is modified";
		}
	}
	else {
		cout << m << endl;
		for (int i = 0; i < m; i++) {
			cout << modi[i].name << " " << modi[i].pwd << endl;
		}
	}
}