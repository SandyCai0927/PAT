#include<cstdio>
#include<algorithm>
using namespace std;

struct info
{
	char name[10];
	int age;
	int worth;
}people[100005], cases[100005];

bool cmp(info a, info b) {
	if (a.worth != b.worth)
		return a.worth > b.worth;
	else if (a.age != b.age)
		return a.age < b.age;
	else {
		int s = strcmp(a.name, b.name);
		return s < 0;
	}
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s %d %d", people[i].name, &people[i].age, &people[i].worth);
	}
	sort(people, people + n, cmp);
	int age[100005] = { 0 };
	int num = 0;
	//筛选出每个年龄段财富值前100的人
	for (int i = 0; i < n; i++) {
		if (age[people[i].age] < 100)
		{
			age[people[i].age]++;
			cases[num++] = people[i];
		}
	}
	for (int i = 0; i < k; i++) {
		int m, l, r;
		scanf("%d%d%d", &m, &l, &r);
		int pnum = 0;
		printf("Case #%d:\n", i + 1);
		for (int j = 0; j < num && j < pnum; j++) {
			if (cases[j].age >= l && cases[j].age <= r) {
				printf("%s %d %d\n", cases[j].name, cases[j].age, cases[j].worth);
				pnum++;
			}
		}
		if (pnum == 0)
			printf("None\n");
	}
	return 0;
}