#include <stdio.h>
#include<string.h>
int main() {
	float a,b,s,p,d;
	printf("entrez la valeur de a:");
	scanf("%f",&a);
	printf("entrez la valeur de b:");
	scanf("%f",&b);
	s=a+b;
	p=a*b;
	d=a/b;
	printf("a + b =%f\na x b =%f\na / b =%f",s,p,d);
	return 0;
    
}
