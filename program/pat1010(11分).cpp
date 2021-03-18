#include<iostream>
#include<cstring>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;

long long to_decimal(string n, int radix) {
	if (radix == 10)
		return atoll(n.c_str());
	else {
		int len = n.length();
		int N = 0;
		for (int i = 0; i < len; i++) {
			//change to number
			if (n[i] >= '0' && n[i] <= '9') {
				N += (n[i] - '0') * pow(radix, len - i - 1);
			}
			else {
				N += (n[i] - 'a' + 10) * pow(radix, len - i - 1);
			}
			
		}
		return N;
	}
}

int find_max_num(string n) {
	int len = n.length();
	char maxn = n[0];
	for (int i = 0; i < len; i++) {
		if (n[i] > maxn) {
			maxn = n[i];
		}
	}
	if (maxn >= '0' && maxn >= '9') {
		return maxn - '0';
	}
	else {
		return maxn - 'a' + 10;
	}
}

int main() {
	ios::sync_with_stdio(false);
	string n1, n2;
	int tag, radix;
	cin >> n1 >> n2 >> tag >> radix;
	long long N1 = 0, N2 = 0;
	if (tag == 1) {
		N1 = to_decimal(n1, radix);
	}
	else {
		N1 = to_decimal(n2, radix);
		n1.swap(n2);//交换两个字符串，后面只需处理字符串n2
	}
	long long low, high, mid;
	low = find_max_num(n2) + 1;
	high = max(low, N1) + 1;
	bool flag = false;
	while (low < high && flag == false) {
		mid = (low + high) / 2;
		N2 = to_decimal(n2, mid);
		//可能存在溢出情况
		if (N1 > N2 && N2 > 0)
			low = mid + 1;
		else if (N1 < N2 || N2 < 0)
			high = mid - 1;
		else
			flag = true;
	}
	if (flag)
		cout << mid << "\n";
	else
		cout << "Impossible\n";
	return 0;
}