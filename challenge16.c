#include<stdio.h>
#include<math.h>
int main(){
int a,b,s;
printf("entrez la valeur de a:");
scanf("%d",&a);
printf("entrez la valeur de b:");
scanf("%d",&b);
s=a+b;
if(a==b){
    printf("%d",3*s);
}else{
    printf("%d",s);
}
return 0;
}