#include<stdio.h>
#include<string.h>
int main(){
    char nom[50];
    char prenom[50];
    char email[50];
    int age;
    char sex;
    printf("veuillez entrez vos donnes:\n");
	printf("entrez votre nom:");
    scanf("%s",nom);
    printf("entrez votre prenom:");
    scanf("%s",prenom);
    printf("entrez votre adresse email:");
    scanf("%s",email);
    printf("entrez votre age:");
    scanf("%d", &age);
    printf("entrez votre sexe:");
    scanf(" %c", &sex);
    printf("Nom: %s \n",nom);
    printf("Prénom: %s \n",prenom);
    printf("Age: %d \n",age);
    printf("sex: %c \n",sex);
    printf("email: %s \n",email);
    return 0;
}


