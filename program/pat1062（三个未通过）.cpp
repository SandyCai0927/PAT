#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct grade
{
	string id;
	int virtue;
	int talent;
}temp, sage[100002], nobel[100002], fool[100002], other[100002];

bool cmp(grade a, grade b) {
	if (a.virtue + a.talent != b.virtue + b.talent) {
		return (a.virtue + a.talent > b.virtue + b.talent);
	}
	else {
		if (a.virtue != b.virtue)
			return (a.virtue > b.virtue);
		else
			return (a.id < b.id);
	}
}

int main() {
	int n, l, h;
	cin >> n >> l >> h;
	int sages = 0, nobels = 0, fools = 0, others = 0, ranked = n;
	for (int i = 0; i < n; i++) {
		cin >> temp.id >> temp.virtue >> temp.talent;
		//圣人
		if (temp.talent >= h && temp.virtue >= h) {
			sage[sages++] = temp;
		}
		//君子
		else if (temp.talent < h && temp.virtue >= h && temp.talent >= l) {
			nobel[nobels++] = temp;
		}
		//愚人
		else if (temp.talent <= temp.virtue && temp.virtue < h && temp.virtue >= l) {
			fool[fools++] = temp;
		}
		//其他
		else if (temp.talent >= l && temp.virtue >= l) {
			other[others++] = temp;
		}
		//不符合要求
		else {
			ranked--;
		}
	}
	cout << ranked << endl;
	if (sages > 0) {
		sort(sage, sage + sages, cmp);
		for (int i = 0; i < sages; i++)
			cout << sage[i].id << " " << sage[i].virtue << " " << sage[i].talent << endl;
	}
	if (nobels > 0) {
		sort(nobel, nobel + nobels, cmp);
		for (int i = 0; i < nobels; i++)
			cout << nobel[i].id << " " << nobel[i].virtue << " " << nobel[i].talent << endl;
	}
	if (fools > 0) {
		sort(fool, fool + fools, cmp);
		for (int i = 0; i < fools; i++)
			cout << fool[i].id << " " << fool[i].virtue << " " << fool[i].talent << endl;
	}
	if (others > 0) {
		sort(other, other + others, cmp);
		for (int i = 0; i < others; i++) {
			cout << other[i].id << " " << other[i].virtue << " " << other[i].talent << endl;
		}
	}
}