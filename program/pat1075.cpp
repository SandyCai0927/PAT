#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct info
{
	int id, rank;
	int score[6];
	int AC;
	bool hand;
}stud[10005];

bool cmp(info a, info b) {
	if (a.score[5] != b.score[5])
		return a.score[5] > b.score[5];
	else if (a.AC != b.AC)
		return a.AC > b.AC;
	else
		return a.id < b.id;
}

int main() {
	int n, k, t;
	scanf("%d%d%d", &n, &k, &t);
	int grade[5] = { 0 };
	for (int i = 0; i < k; i++) {
		scanf("%d", &grade[i]);
	}
	for (int i = 0; i < n; i++) {
		stud[i].id = i + 1;
		stud[i].AC = 0;
		for (int j = 0; j < k; j++)
		{
			stud[i].score[j] = -1;
		}
		//¼ÇÂ¼×Ü·Ö
		stud[i].score[5] = 0;
		stud[i].hand = 0;
	}
	for (int i = 0; i < t; i++) {
		int id, problem, score;
		scanf("%d%d%d", &id, &problem, &score);
		if (score != -1)
			stud[id - 1].hand = 1;
		if (score > stud[id - 1].score[problem - 1]) {
			stud[id - 1].score[problem - 1] = score;
			if (score == grade[problem - 1])
				stud[id - 1].AC++;
		}
		else if (score == -1 && stud[id - 1].score[problem - 1] == -1) {
			stud[id - 1].score[problem - 1] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (stud[i].score[j] == -1)
				continue;
			stud[i].score[5] += stud[i].score[j];
		}
			
	}
	sort(stud, stud + n, cmp);
	for (int i = 0; i < n; i++) {
		if (i != 0 && stud[i].score[5] == stud[i - 1].score[5])
			stud[i].rank = stud[i - 1].rank;
		else
			stud[i].rank = i + 1;
		if (stud[i].hand == 0)
			continue;
		printf("%d %05d %d ", stud[i].rank, stud[i].id,stud[i].score[5]);
		for (int j = 0; j < k; j++) {
			if (stud[i].score[j] != -1)
				printf("%d", stud[i].score[j]);
			else 
				printf("-");
			if (j != k - 1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}