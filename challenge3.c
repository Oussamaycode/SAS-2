#include <stdio.h>
#include<string.h>
int main() {
    float d;
    printf("entrez la distance en KM:");
    scanf("%f",&d);
    d*=1093.61;
	printf("la distance en Yards est:%.2f",d);
    return 0;
}

