#include<cstdio>
#include<algorithm>
using namespace std;

struct info
{
	int id;
	int GE;
	int GI;
	int school[5];
	int grade;
	int rank;
}stud[40005];

struct sch
{
	int num;//��¼ÿ��ѧУ��¼ȡ����
	int admit[40005];//��¼ÿ��ѧУ��¼ȡѧ��Id
	int stu;//��¼ÿ��ѧУ¼ȡ����
}school[100];

bool cmp(info a, info b) {
	if (a.grade != b.grade)
		return a.grade > b.grade;
	else if (a.GE != b.GE)
		return a.GE > b.GE;
	else
		return a.id < b.id;
}

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i <m; i++) {
		scanf("%d", &school[i].num);
	}
	for (int i = 0; i < n; i++) {
		stud[i].id = i;
		scanf("%d %d", &stud[i].GE, &stud[i].GI);
		stud[i].grade = (stud[i].GE + stud[i].GI) / 2;
		for (int j = 0; j < k; j++)
			scanf("%d", &stud[i].school[j]);
	}
	sort(stud, stud + n, cmp);
	for (int i = 0; i < n; i++) {
		if (i > 0 && (stud[i].grade == stud[i - 1].grade)) {
			if (stud[i].GE == stud[i - 1].GE)
				stud[i].rank = stud[i - 1].rank;
			else
				stud[i].rank = i + 1;
		}
		else
			stud[i].rank = i + 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			int p = stud[i].school[j];
			//��У��������
			if (school[p].num != 0) {
				school[p].num--;
				school[p].admit[school[p].stu++] = stud[i].id;
				break;
			}
			//��У���������꣬���������
			else {
				//��ǰһλ¼ȡ��ͬѧ������ͬ
				if (school[p].stu > 0 && stud[i].rank == stud[school[p].admit[school[p].stu - 1]].rank) {
					school[p].admit[school[p].stu++] = stud[i].id;
					break;
				}
				else {
					continue;
				}
			}
		}
	}
	for (int i = 0; i < m; i++) {
		sort(school[i].admit, school[i].admit+school[i].stu);
		for (int j = 0; j < school[i].stu; j++) {
			printf("%d", school[i].admit[j]);
			if (j != school[i].stu - 1)
				printf(" ");
		}
		printf("\n");
	}
}