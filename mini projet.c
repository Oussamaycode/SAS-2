#include <stdio.h>
#include <math.h>

int main() {
    char titre[100][50]={};
    char auteur[100][50]={};
    char search[50]={};
    float prix[100][50]={};
    int quantite[100][50]={};
    int choix,count=0,i,var=0;
	printf("Bonjour,Merci d'utiliser notre librairie.\nVoulez-vous:\n1:Ajouter un livre au stock.\n2:Afficher tous les livres disponibles\n3:Mettre à jour la quantité d'un livre\n4:Supprimer un livre du stock\n5:Afficher le nombre total de livres en stock.\n6:Quitter le menu.");   
	scanf("%d",&choix);
	switch(choix){
		case 1:
		printf("------AJOUT D'UN LIVRE------")
		printf("Titre du livre:");
		fgets(titre[count],sizeof(titre[count]),stdin);
		printf("Auteur du livre:");
		fgets(auteur[count],sizeof(auteur[count]),stdin);
		printf("Prix du livre:");
		fgets(prix[count],sizeof(prix[count]),stdin);
		printf("Quantité du livre:");
		fgets(Quantité[count],sizeof(Quantité[count]),stdin);
		count++;
		break;
		case 2:
		printf("------LES LIVRES DISPONIBLES------")
		for(i=0;i<count;i++){
			printf("%s",titre[i]);
		break;	
		}
		case 3:
		printf("------METTRE A JOUR LA QUANTITE D'UN LIVRE------");
		printf("entrez le titre du livre:");
		fgets(search,sizeof(search),stdin);	
		for(i=0;i<count;i++){
			for(j=0;j<50;j++){
				i
			}
		}
	return 0;
}
