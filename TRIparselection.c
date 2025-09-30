#include <stdio.h>
void print(int T[],int taille){
    for(int i=0;i<taille;i++){
        printf("%d\n",T[i]);
    }
}
int main() {
    int T[]={4,2,-1,100,-54};
    int taille=5,mintemp,k;
    print(T,5);
    for(int i=0;i<taille;i++){
        mintemp=T[i],k=i;
        for(int j=i;j<taille;j++){
            if (T[j]<mintemp){
                mintemp=T[j];
                k=j;
            }
        }
        T[k]=T[i];
        T[i]=mintemp;
    }
    print(T,5);
    return 0;
}
