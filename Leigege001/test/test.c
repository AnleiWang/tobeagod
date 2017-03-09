#include <stdio.h>
int main() {
    int a[3][2] = {{2, 5}, {4, 3}, {6, 1}};
    int *p = &a[0][1];
	    printf("%d\n", *(p + 3));
		    return 0;
}
