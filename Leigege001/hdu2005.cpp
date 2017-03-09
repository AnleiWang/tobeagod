#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	int y, m, d, count;
	int f1[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int f2[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	while(scanf("%d/%d/%d", &y, &m, &d) != EOF) {
		count = 0;
		if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
			for(int i = 0; i < m - 1; i++ ) {
				count += f1[i];
			}
			printf("%d\n", count + d);
		} else {
			for(int i = 0; i < m - 1; i++) {
				count += f2[i];
			}
			printf("%d\n", count + d);
		}
	}
	return 0;
}
