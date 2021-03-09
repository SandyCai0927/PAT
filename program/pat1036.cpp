#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

struct info
{
	string name;
	string id;
	int grade;
	char gender;
}temp, lowest, highest;

int main() {
	int n;
	highest.grade = -1;
	lowest.grade = 101;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp.name >> temp.gender >> temp.id >> temp.grade;
		if (temp.gender == 'F') {
			if (temp.grade > highest.grade) {
				highest.name = temp.name;
				highest.gender = temp.gender;
				highest.id = temp.id;
				highest.grade = temp.grade;
			}
		}
		else if (temp.gender == 'M')
		{
			if (temp.grade < lowest.grade) {
				lowest.name = temp.name;
				lowest.gender = temp.gender;
				lowest.id = temp.id;
				lowest.grade = temp.grade;
			}
		}
	}
	bool flag = true;
	if (highest.grade == -1) {
		printf("Absent\n");
		flag = false;
	}
	else {
		printf("%s %s\n", highest.name.c_str(), highest.id.c_str());
	}
	if (lowest.grade == 101) {
		printf("Absent\n");
		flag = false;
	}
	else {
		printf("%s %s\n", lowest.name.c_str(), lowest.id.c_str());
	}
	if (flag)
		printf("%d\n", highest.grade - lowest.grade);
	else
		printf("NA\n");
}