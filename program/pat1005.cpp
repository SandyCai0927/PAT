#include<iostream>
#include<string>
using namespace std;

string digit[] = { "zero","one","two","three","four","five","six","seven","eight","nine" };

int main() {
	string s;
	cin >> s;
	long sum = 0;
	for (int i = 0; i < s.length(); i++) {
		sum += s[i] - '0';
	}
	s = to_string(sum);
	for (int i = 0; i < s.length(); i++) {
		cout << digit[s[i] - '0'];
		if (i != s.length() - 1)
			cout << " ";
	}
	return 0;
}