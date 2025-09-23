#include<stdio.h>
#include<math.h>
int main(){
float l1;
float l2;
float S;
printf("entrez la longueur du triangle:");
scanf("%f",&l1);
printf("entrez la largeur du triangle:");
scanf("%f",&l2);
S=l1*l2;
printf("la surface du rectangle est S = %.2f",S);
return 0;
}