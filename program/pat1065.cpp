#include<cstdio>
#include<string>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		long long a, b, c;
			scanf("%lld%lld%lld", &a, &b, &c);
			long long r = a + b;
			string res;
			if (a > 0 && b > 0 && r < 0)
				res = "true";
			else if (a < 0 && b < 0 && r >= 0)
				res = "false";
			else if (r > c)
				res = "true";
			else
				res = "false";
			printf("Case #%d: %s\n", i + 1,res.c_str());
	}
	
}