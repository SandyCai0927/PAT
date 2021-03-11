#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<map>
using namespace std;

struct info
{
	char plate[8];
	int hour, minute, second;
	int time;
	bool status;
}car[10005], valid[10005];

bool cmp(info a, info b) {
	int s = strcmp(a.plate, b.plate);
	if (s != 0)
		return s < 0;
	else
		return a.time < b.time;
}

bool cmpTime(info a, info b) {
	return a.time < b.time;
}

int getTime(info a) {
	int time = a.hour * 3600 + a.minute * 60 + a.second;
	return time;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	string status;
	map<string, int> park;
	for (int i = 0; i < n; i++) {
		cin >> car[i].plate;
		scanf("%d:%d:%d", &car[i].hour, &car[i].minute, &car[i].second);
		cin >> status;
		if (status == "in") {
			car[i].status = 1;
		}
		else
			car[i].status = 0;
		car[i].time = getTime(car[i]);
	}
	sort(car, car + n, cmp);
	int num = 0;
	int maxTime = -1;
	for (int i = 0; i < n - 1; i++) {
		if (strcmp(car[i].plate, car[i + 1].plate) == 0 && car[i].status == 1 && car[i + 1].status == 0) {
			valid[num++] = car[i];
			valid[num++] = car[i + 1];
			int parkTime = car[i + 1].time - car[i].time;
			if (park.count(car[i].plate) == 0)
				park[car[i].plate] = 0;
			park[car[i].plate] += parkTime;
			maxTime = max(maxTime, park[car[i].plate]);
		}
	}
	sort(valid, valid + num, cmpTime);
	int carNum = 0;
	int now = 0;
	for (int i = 0; i < k; i++) {
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		int time = h * 3600 + m * 60 + s;
		while (now < num && valid[now].time <= time) {
			if (valid[now].time <= time) {
				if (valid[now].status == 1)
					carNum++;
				else
					carNum--;
			}
			now++;
		}
		printf("%d\n", carNum);
	}
	map<string, int>::iterator p;
	for (p = park.begin(); p != park.end(); p++) {
		if (p->second == maxTime) {
			printf("%s ", p->first.c_str());
		}
	}
	printf("%02d:%02d:%02d", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);
}