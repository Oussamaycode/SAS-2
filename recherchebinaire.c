#include <stdio.h>

int main() {
    int T[] = {1, 2, 3, 4, 5};
    int taille = 5, k;
    int sline = 0, fline= taille - 1, mid;
    int found = 0;

    printf("K = ");
    scanf("%d", &k);

    while (sline<= fline) {
        mid = (sline+ fline) / 2;  
        if (k < T[mid]) {
            fline = mid - 1; 
        } else if (k > T[mid]) {
            sline = mid + 1; 
        } else {
            printf("T[%d] = %d\n", mid, k);
            found = 1;
            break;
        }
    }

    if (found==0) {
        printf("L'élément entré n'existe pas dans la liste\n");
    }

    return 0;
}
