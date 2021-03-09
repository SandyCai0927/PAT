#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

string to_thirteen(int x) {
	string s = "";
	int y;
	if (x == 0)
		s += '0';
	while (x != 0) {
		y = x % 13;
		x = x / 13;
		if (y < 10) {
			s += y + '0';
		}
		else {
			s += y - 10 + 'A';
		}
	}
	if (s.length() == 1)
		s += '0';
	reverse(s.begin(), s.end());
	return s;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	string s = "#";
	s += to_thirteen(a);
	s += to_thirteen(b);
	s += to_thirteen(c);
	cout << s << endl;
	return 0;
}