#include <stdio.h>
void print(int T[],int taille){
    for(int i=0;i<taille;i++){
        printf("%d\n",T[i]);
    }
}
int main() {
    int temp;
    int T[]={6,7,-100,7,5};
    print (T,5);
    int taille=5;
    for(int i=1;i<taille;i++){
        for(int j=i;j>0;j--){
            if (T[j]<T[j-1]){
                temp=T[j];
                T[j]=T[j-1];
                T[j-1]=temp;
                
            }
            
        }
    }
    print (T,5);
    return 0;
}
