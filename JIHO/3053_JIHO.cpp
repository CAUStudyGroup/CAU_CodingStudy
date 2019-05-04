#include <stdio.h>

#define PI 3.14159265358979

int main()
{
	int num; 
	scanf("%d",&num);

	printf("%.6f\n%.6f", num*num*PI, num*num*2.0);

	return 0;
}