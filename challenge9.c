#include<stdio.h>
#include<math.h>
int main() {
    float x1,x2,y1,y2,z1,z2,d;
    printf("entrez x du point 1:");
    scanf("f",&x1);
    printf("entrez x du point 2:");
    scanf("f",&x2);
    printf("entrez y du point 1:");
    scanf("f",&y1);
    printf("entrez y du point 2 :");
    scanf("f",&y2);
    printf("entrez z du point 1:");
    scanf("f",&z1);
    printf("entrez z du point 2:");
    scanf("f",&z2);
    d=sqrt(pow((x1-x2),2)+pow((y1-y2),2)+pow((z1-z2),2));
    printf("%f",d);
	return 0;
}
