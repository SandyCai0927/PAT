#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

struct info
{
	string id;
	int in_h, in_m, in_s, out_h, out_m, out_s;
}temp,first,last;

int main() {
	int m;
	cin >> m;
	first.in_h = 24;
	first.in_m = 0;
	first.in_m = 0;
	last.out_h = 0;
	last.out_m = 0;
	last.out_s = 0;
	string id, in_time, out_time;
	for (int i = 0; i < m; i++) {
		cin >> id;
		temp.id = id;
		scanf_s("%d:%d:%d", &temp.in_h, &temp.in_m, &temp.in_s);
		scanf_s("%d:%d:%d", &temp.out_h, &temp.out_m, &temp.out_s);
		if (temp.in_h < first.in_h) {
			first.in_h = temp.in_h;
			first.in_m = temp.in_m;
			first.in_s = temp.in_s;
			first.id = temp.id;
		}
		else if (temp.in_h == first.in_h) {
			if (temp.in_m < first.in_m) {
				first.in_h = temp.in_h;
				first.in_m = temp.in_m;
				first.in_s = temp.in_s;
				first.id = temp.id;
			}
			else if (temp.in_m == first.in_m) {
				if (temp.in_s < first.in_s) {
					first.in_h = temp.in_h;
					first.in_m = temp.in_m;
					first.in_s = temp.in_s;
					first.id = temp.id;
				}
			}
		}
		if (temp.out_h > last.out_h) {
			last.out_h = temp.out_h;
			last.out_m = temp.out_m;
			last.out_s = temp.out_s;
			last.id = temp.id;
		}
		else if (temp.out_h == last.out_h) {
			if (temp.out_m > last.out_m) {
				last.out_h = temp.out_h;
				last.out_m = temp.out_m;
				last.out_s = temp.out_s;
				last.id = temp.id;
			}
			else if (temp.out_m == last.out_m) {
				if (temp.out_s > last.out_s) {
					last.out_h = temp.out_h;
					last.out_m = temp.out_m;
					last.out_s = temp.out_s;
					last.id = temp.id;
				}
			}
		}
	}
	printf("%s %s\n", first.id.c_str(), last.id.c_str());
}