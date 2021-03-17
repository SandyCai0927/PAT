#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int maxn = 1005;
string str[maxn];

bool cmp(string a, string b) {
	return a + b < b + a;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}

	sort(str, str + n, cmp);
	string result = "";
	for (int i = 0; i < n; i++) {
		result += str[i];
	}
	while (result.size() && result[0] == '0')
		result.erase(result.begin());
	if (result.size() == 0)
		cout << 0 << endl;
	else
		cout << result << endl;
	return 0;
}