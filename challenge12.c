#include<stdio.h>
#include<math.h>
int main(){
int a;
printf("entrez un nombre a quatre chiffres:");
scanf("%d",&a);
printf("%d%d%d%d",a%10,((a%100)-a%10)/10,((a%1000)-a%100)/100,((a%10000)-a%1000)/1000);
return 0;
}