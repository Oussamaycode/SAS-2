#include<stdio.h>
#include<string.h>
int main() {
    float a,b,c,s1,s2;
    printf("entrez la valeur de nombre 1:");
    scanf("%f",&a);
	printf("entrez la valeur de nombre 2:");
    scanf("%f",&b);
    printf("entrez la valeur de nombre 3:");
    scanf("%f",&c);
    s1=2*a+3*b+5*c;
    s2=2+3+5;
    printf("la moynne pondérée est: %f",s1/s2);
	return 0;
    
}
