#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char first[61], second[62], third[63], forth[62];

int main() {
	int x = 0, y = 0, z = 0;
	cin >> first >> second;
	int i = 0, time = 0;
	while (time != 2) {
		if (first[i] == second[i]) {
			if (time == 0 && first[i] < 'A' && first[i] > 'G')
			{
				i++;
				continue;
			}
			else if (time == 1 && (first[i] < '0' || (first[i] > '9' && first[i] < 'A') || first[i]>'N')) {
				i++;
				continue;
			}
			time++;
			if (time == 1) {
				x = first[i] - 'A' + 1;
			}
			else {
				if (first[i] <= '9') {
					y = first[i] - '0';
				}
				else {
					y = first[i] - 'A' + 10;
				}
			}
		}
		i++;
	}
	cin >> third >> forth;
	i = 0;
	while (true)
	{
		if (third[i] == forth[i] && ((third[i] >= 'a' && third[i] <= 'z') || (third[i] >= 'A' && third[i] <= 'Z'))) {
			z = i;
			break;
		}
		i++;
	}
	switch (x)
	{
	case 1:
		printf("MON ");
		break;
	case 2:
		printf("TUE ");
		break;
	case 3:
		printf("WED ");
		break;
	case 4:
		printf("THU ");
		break;
	case 5:
		printf("FRI ");
		break;
	case 6:
		printf("SAT ");
		break;
	case 7:
		printf("SUN ");
		break;
	default:
		break;
	}

	printf("%02d:%02d\n", y, z);
	return 0;
}