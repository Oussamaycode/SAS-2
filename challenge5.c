#include <stdio.h>
#include<string.h>
int main() {
    float T;
    printf("entrez la temperature en Celsius:");
    scanf("%f",&T);
    if(T<0){
    	printf("Solide");
	}else if(T>=0 && T<100){
		printf("Liquide");
	}else if(T>=100){
		printf("Gaz");
	}
    return 0;
}
