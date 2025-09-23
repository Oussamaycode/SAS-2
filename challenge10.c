#include <stdio.h>
#include<math.h>
int main(){
    float volume;
    float rayon;
    printf("entrez la valeur du rayon:");
    scanf("%f",&rayon);
    volume = (4/3)*3.14*pow(rayon,2);
    return 0;
}
