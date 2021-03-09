#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct info
{
	int No;
	char name[9];
	int grade;
}stud[100010];

bool cmp(info a, info b) {
	return a.No < b.No;
}

bool cmp1(info a, info b) {
	int s = strcmp(a.name, b.name);
	if (s != 0)
		return s < 0;
	else
		return a.No < b.No;
}

bool cmp2(info a, info b) {
	if (a.grade != b.grade)
		return a.grade < b.grade;
	else
		return a.No < b.No;
}

int main() {
	int n, p;
	scanf("%d %d", &n, &p);
	for (int i = 0; i < n; i++) {
		scanf("%d", stud[i].No);
		scanf("%s", stud[i].name);
		scanf("%d", stud[i].grade);
	}
	if (p == 1)
		sort(stud, stud + n, cmp);
	else if (p == 2)
		sort(stud, stud + n, cmp1);
	else
		sort(stud, stud + n, cmp2);
	for (int i = 0; i < n; i++) {
		printf("%06d %s %d\n", stud[i].No, stud[i].name, stud[i].grade);
	}
	return 0;
}