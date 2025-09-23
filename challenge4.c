#include <stdio.h>
#include<string.h>
int main() {
    float v;
    printf("entrez vitesse en KM/h:");
    scanf("%f",&v);
    v*= 0.27778;
	printf("la vitesse en m/s est:%.2f",v);
    return 0;
}
