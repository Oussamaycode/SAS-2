#include<stdio.h>
#include<math.h>
int main(){
int a;
printf("entrez un nombre entier:");
scanf("%d",&a);
int b=a;
printf("Binaire:\n");
while(a > 0) {
    printf("%d", a%2);
    a /= 2;
}
printf("\nhexadecimal:");
char hed[] = "0123456789ABCDEF";
while (b>0){
printf("%c",hed[b % 16]);
b/=16;
}
return 0;
}