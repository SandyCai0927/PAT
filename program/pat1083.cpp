#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct info
{
	char name[11];
	char ID[11];
	int grade;
}stud[50];

bool cmp(info a, info b) {
	return a.grade > b.grade;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %s %d", stud[i].name, stud[i].ID, &stud[i].grade);
	}
	sort(stud, stud + n, cmp);
	int grade1, grade2;
	scanf("%d %d", &grade1, &grade2);
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (stud[i].grade > grade2)
			continue;
		else if (stud[i].grade < grade1)
			break;
		else {
			flag = true;
			printf("%s %s\n", stud[i].name, stud[i].ID);
		}
	}
	if (flag == false)
		printf("NONE");
	return 0;
}