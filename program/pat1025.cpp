#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct info
{
	int location, grade;
	string No;
	int rankAll, rankGroup;
}stud[30005];

bool cmp(info a, info b) {
	if (a.grade != b.grade)
		return a.grade > b.grade;
	else
		return a.No < b.No;
}

int main() {
	int locations;
	cin >> locations;
	int num = 0;
	for (int i = 0; i < locations; i++) {
		int n;
		cin >> n;
		for (int j = num; j < n + num; j++) {
			cin >> stud[j].No >> stud[j].grade;
			stud[j].location = i + 1;
		}
		sort(stud + num, stud + num + n, cmp);
		stud[num].rankGroup = 1;
		for (int j = num + 1; j < n + num; j++) {
			if (stud[j].grade == stud[j - 1].grade)
				stud[j].rankGroup = stud[j - 1].rankGroup;
			else
				stud[j].rankGroup = j - num + 1;
		}
		num += n;
	}
	sort(stud, stud + num, cmp);
	stud[0].rankAll = 1;
	for (int i = 1; i < num; i++) {
		if (stud[i].grade == stud[i - 1].grade)
			stud[i].rankAll = stud[i - 1].rankAll;
		else
			stud[i].rankAll = i + 1;
	}
	cout << num << endl;
	for (int i = 0; i < num; i++) {
		cout << stud[i].No << " " << stud[i].rankAll << " " << stud[i].location << " " << stud[i].rankGroup << endl;
	}
}