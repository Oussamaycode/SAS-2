#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int choix;
int count = 0;
int taille = 260;
char Titre[260][50] = {};
char Auteur[260][50] = {};
char search1[50] = {};
float prix[260] = {};
int quantite[260] = {};

int search(char T[][50], char T1[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(T[i], T1) == 0)
            return i;
    }
    return -1;
}

void Menu() {
    printf("Bonjour, Merci d'utiliser notre librairie.\nVoulez-vous:\n1:Ajouter un livre au stock.\n2:Afficher tous les livres disponibles\n3:Mettre a jour la quantite d'un livre\n4:Supprimer un livre du stock\n5:Afficher le nombre total de livres en stock.\n6:Quitter le menu.\n");
    scanf("%d", &choix);
    getchar();
}

void Donne1(char T[][50], char libelle[]) {
    printf("\n%s du livre: ", libelle);
    fgets(T[count], sizeof(T[count]), stdin);
}

void Prix() {
    printf("\nPrix du livre: ");
    scanf("%f", &prix[count]);
}

void Quantite() {
    printf("\nQuantite du livre: ");
    scanf("%d", &quantite[count]);
}

void supprimer(char T1[]) {
    int m = search(Titre, T1);
    if (m != -1) {
        for (int i = m; i < count - 1; i++) {
            for (int j = 0; j < 50; j++) {
                Titre[i][j] = Titre[i + 1][j];
                Auteur[i][j] = Auteur[i + 1][j];
            }
            prix[i] = prix[i + 1];
            quantite[i] = quantite[i + 1];
        }
        count--;
    } else {
        printf("Le livre entre n'est pas disponible");
    }
}

int main() {
    int i;
    while (choix != 0) {
        Menu();
        switch (choix) {
            case 1:
                Donne1(Titre, "Titre");
                Donne1(Auteur, "Auteur");
                Prix();
                Quantite();
                count++;
                break;
            case 2:
                printf("------LES LIVRES DISPONIBLES------\n");
                for (i = 0; i < count; i++) {
                    printf("%s\n", Titre[i]);
                }
                break;
            case 3: {
                printf("------METTRE A JOUR LA QUANTITE D'UN LIVRE------\n");
                printf("\nEntrez le titre du livre: ");
                fgets(search1, sizeof(search1), stdin);
                int m = search(Titre, search1);
                if (m != -1) {
                    printf("Entrez la nouvelle quantite de %s:\n", Titre[m]);
                    scanf("%d", &quantite[m]);
                } else {
                    printf("Le livre entre n'est pas disponible");
                }
                break;
            }
            case 4:
                printf("------SUPPRIMER UN LIVRE DU STOCK------\n");
                printf("\nEntrez le titre du livre: ");
                fgets(search1, sizeof(search1), stdin);
                supprimer(search1);
                break;
            case 5:
                printf("-------LE NOMBRE TOTAL DE LIVRES EN STOCK-------\n");
                printf("Le nombre total de livres en stock: %d", count);
                break;
            case 6:
                exit(0);
        }
    }
    return 0;
}

