// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
int choix;
int count=0;
struct menu{
    char text[100];
    int num;
};
struct menu Menus;
Menus[]={{"Ajouter un animal",1},{"Afficher les animaux",2},{"Modifier un animal",3},{"Supprimer un animal",4},{"Rechercher un animal",5},{"Statistiques",6},{"Afficher la liste complète",7},{"Afficher uniquement les animaux d’un habitat spécifique",8},{"Modifier l’habitat",9},{"Modifier l’âge",10},{"Rechercher par id",11},{"Rechercher par nom",12},{"Rechercher par espece",13},{"Nombre total d’animaux dans le zoo",14},{"Âge moyen des animaux",15},{"Plus vieux et plus jeune animal",16},{"Afficher les espèces les plus représentées",17}};
struct zoo{
    int id;
    int age;
    float poids;
    char nom[50];
    char espece[50];
    char habitat[50];
}
stuct zoo animal[200];
void menu1(int a,int b,char T[]){
    printf("-----%s----",T)
    for(int i=a-1;a<b;i++){
        printf("%d. %s",Menus[i].num,Menus[i].text);
    }
    scanf("%d",&choix);
}
void lookforid(int a){
    while(a>count+1){
      printf("Id invalide,Veuillez ressayer:");
      scanf("%d",a);}
      printf("nom:%d\nage:%d\npoids:%d\nespece:%s\nhabitat:%s\n",animal[a-1].nom,animal[a-1].poids,animal[a-1].espece,animal[a-1].habitat);
}
int lookfor(char T){
    for(int i=0;i<200;i++){
        if (stricmp(T,animal[i].espece)==0)
            return i;
        if (stricmp(T,animal[i].name)==0)
            return i;
    }
    return -1
}
int main() {
    while(1){
    menu1(1,6,MENU);
    switch(choix){
        case 1:
        printf("Nom:");
        fgets(animal[count].nom,sizeof(animal[count].nom),stdin);
        printf("Age:");
        printf("Poids:");
        printf("espece:");
        fgets(animal[count].espece,sizeof(animal[count].espece),stdin);
        printf("habitat:");
        fgets(animal[count].nom,sizeof(animal[count].habitat),stdin);
    }
    }
    return 0;
}
