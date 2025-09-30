#include <stdio.h>
int main() {
    int T[]={4,2,-1,100,-54};
    int taille=5;
    int k;
    printf("K=");
    scanf("%d",&k);
    for(int i=0;i<taille;i++){
        if(T[i]==k){
            printf("T[%d]=%d",i,k);
            break;
        }if (i==4)
            printf("l'element entree n' existe pas dans le tableau");
    }
    
    return 0;
}
