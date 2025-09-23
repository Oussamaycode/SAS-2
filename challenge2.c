#include <stdio.h>
#include<string.h>
int main() {
    float T;
    printf("entrez la temprature en Celsius:");
    scanf("%f",&T);
    T=T + 273.15;
    printf("la temperature en kevlin est: %.2f",T);
    return 0;
}

