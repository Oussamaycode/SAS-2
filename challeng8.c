#include<stdio.h>
#include<string.h>
int main() {
    float a,b,c,m;
    printf("entrez la valeur de nombre 1:");
    scanf("%f",&a);
	printf("entrez la valeur de nombre 2:");
    scanf("%f",&b);
    printf("entrez la valeur de nombre 3:");
    scanf("%f",&c);
    m=pow((a*b*c),1/3);
    printf("la moynne geometrique: %f",m);
	return 0;
    
}
