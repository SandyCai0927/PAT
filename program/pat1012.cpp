#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct stud
{
	int id;
	int grade[4];
}stu[2001];

int Rank[1000000][4];
char course[4] = { 'A','C','M','E' };
int k;

bool cmp(stud a, stud b) {
	return a.grade[k] > b.grade[k];
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> stu[i].id >> stu[i].grade[1] >> stu[i].grade[2] >> stu[i].grade[3];
		stu[i].grade[0] = (stu[i].grade[3] + stu[i].grade[1] + stu[i].grade[2]) / 3;
	}
	
	for (k = 0; k < 4; k++) {
		sort(stu, stu + n, cmp);
		Rank[stu[0].id][k] = 1;
		for (int i = 1; i < n; i++) {
			if (stu[i].grade[k] == stu[i - 1].grade[k])
				Rank[stu[i].id][k] = Rank[stu[i - 1].id][k];
			else
				Rank[stu[i].id][k] = i + 1;
		}
	}
	int id;
	for (int i = 0; i < m; i++) {
		cin >> id;
		if (Rank[id][0] == 0)
			cout << "N/A" << endl;
		else {
			int p = 0;
			for (int j = 1; j < 4; j++) {
				if (Rank[id][j] < Rank[id][p])
					p = j;
			}
			cout << Rank[id][p] << " " << course[p] << endl;
		}
	}
	return 0;
}