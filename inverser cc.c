#include <stdio.h>
#include <string.h>

char* inverse(char T[]) {
    int n = strlen(T);
    char m;
    for (int i = 0; i <(n-1)/2; i++) { 
        m=T[i];
        T[i]=T[n-i-1];
        T[n-i-1]=m;
    }
    return (T);
}
int main() {
    char T[] = "oussama";
    printf("%s",inverse(T));
    return 0;
}
