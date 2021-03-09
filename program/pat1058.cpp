#include<cstdio>
using namespace std;

int main() {
	int galleon_a, galleon_b;
	int sickle_a, sickle_b, knut_a, knut_b;
	scanf("%d.%d.%d", &galleon_a, &sickle_a, &knut_a);
	scanf("%d.%d.%d", &galleon_b, &sickle_b, &knut_b);
	int x;
	knut_a += knut_b;
	x = knut_a / 29;
	knut_a -= x * 29;
	sickle_a += sickle_b + x;
	x = sickle_a / 17;
	sickle_a -= x * 17;
	galleon_a += galleon_b + x;
	printf("%d.%d.%d\n", galleon_a, sickle_a, knut_a);
	return 0;
}