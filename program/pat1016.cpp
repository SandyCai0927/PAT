#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int fee[24];

struct record
{
	string name;
	int month, day, hour, mintue;
	bool status;//1为接听，0为挂断
}rec[1010], temp;

bool cmp(record a, record b) {
	if (a.name != b.name)
		return a.name < b.name;
	else if (a.month != b.month)
		return a.month < b.month;
	else if (a.day != b.day)
		return a.day < b.day;
	else if (a.hour != b.hour)
		return a.hour < b.hour;
	else
		return a.mintue < b.mintue;
}

void getTime(int on, int off, int& time, int& money) {
	temp = rec[on];
	while (temp.day < rec[off].day || temp.hour < rec[off].hour || temp.mintue < rec[off].mintue) {
		temp.mintue++;
		money += fee[temp.hour];
		time++;
		if (temp.mintue == 60) {
			temp.mintue = 0;
			temp.hour++;
		}
		if (temp.hour == 24) {
			temp.hour = 0;
			temp.day++;
		}

	}
}

int main() {
	for (int i = 0; i < 24; i++) {
		cin >> fee[i];
	}
	int n;
	cin >> n;
	string status;
	for (int i = 0; i < n; i++) {
		cin >> rec[i].name;
		scanf("%d:%d:%d:%d", &rec[i].month, &rec[i].day, &rec[i].hour, &rec[i].mintue);
		cin >> status;
		if (status == "on-line") {
			rec[i].status = 1;
		}
		else
			rec[i].status = 0;
	}
	sort(rec, rec + n, cmp);
	int on = 0, off, next;
	while (on < n) {
		int pair = 0;
		next = on;
		while (next < n && rec[on].name == rec[next].name) {
			if (pair == 0 && rec[next].status == 1)
				pair = 1;
			if (pair == 1 && rec[next].status == 0)
				pair = 2;
			next++;
		}
		//没有找到配对
		if (pair != 2)
		{
			on = next;
			continue;
		}
		int sum = 0;
		printf("%s %02d\n", rec[on].name.c_str(), rec[on].month);
		while (on < next) {
			while (on < next - 1 && !(rec[on].status == 1 && rec[on + 1].status == 0))
				on++;
			if (on + 1 == next) {
				on++;
				break;
			}
			printf("%02d:%02d:%02d %02d:%02d:%02d ", rec[on].day, rec[on].hour, rec[on].mintue, rec[on + 1].day, rec[on + 1].hour, rec[on + 1].mintue);
			int time = 0, money = 0;
			getTime(on, on + 1, time, money);
			printf("%d $%.2f\n", time, money / 100.0);
			sum += money;
			on += 2;
		}
		printf("Total amount: $%.2f\n", sum / 100.0);
	}
}