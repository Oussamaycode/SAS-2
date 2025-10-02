#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>
int choix;
int count=20;
int howmany;
int indice;
char in[50]={};//buffer

// menu structure
struct menu{
    char text[100];
    int num;
};

// menu items
struct menu Menus[] = {
    {"Ajouter un animal",1},
    {"Afficher les animaux",2},
    {"Modifier un animal",3},
    {"Supprimer un animal",4},
    {"Rechercher un animal",5},
    {"Statistiques",6},
    {"Ajout simple",7},
    {"Ajout multiple",8},
    {"Afficher la liste complète",9},
    {"Trier par nom",10},
    {"Trier par age",11},
    {"Afficher uniquement les animaux un habitat spécifique",12},
    {"Modifier lhabitat",13},
    {"Modifier lâge",14},
    {"Rechercher par id",15},
    {"Rechercher par nom",16},
    {"Rechercher par espece",17},
    {"Nombre total danimaux dans le zoo",18},
    {"Âge moyen des animaux",19},
    {"Plus vieux et plus jeune animal",20},
    {"Afficher les espèces les plus représentées",21}
};

// zoo structure
struct zoo{
    int id;
    int age;
    float poids;
    char nom[50];
    char espece[50];
    char habitat[50];
};

// initial animals
struct zoo animal[200]={
    {1,5,190.5,"Simba","Lion","Savane"},
    {2,4,175.0,"Nala","Lion","Savane"},
    {3,8,220.3,"ShereKhan","Tigre","Jungle"},
    {4,12,310.0,"Baloo","Ours","Foret"},
    {5,15,540.7,"Raja","Elephant","Savane"},
    {6,6,300.2,"Marty","Zebre","Savane"},
    {7,10,450.0,"Gloria","Hippopotame","Riviere"},
    {8,7,200.0,"Alex","Lion","Savane"},
    {9,3,12.5,"Julien","Lemurien","Jungle"},
    {10,9,390.8,"Melman","Girafe","Savane"},
    {11,2,1.2,"Timon","Suricate","Desert"},
    {12,5,120.0,"Pumbaa","Phacochere","Savane"},
    {13,11,210.4,"Scar","Lion","Savane"},
    {14,6,45.0,"Kaa","Serpent","Jungle"},
    {15,4,2.1,"Iko","Perroquet","Jungle"},
    {16,3,320.0,"Dumbo","Elephant","Savane"},
    {17,7,25.0,"Kiki","Chien sauvage","Savane"},
    {18,40,90.5,"Donatello","Tortue","Riviere"},
    {19,5,1.5,"Polly","Oiseau","Jungle"},
    {20,13,180.0,"Kong","Gorille","Jungle"}
};

struct zoo temp;
float getInt(char T[]) {
    float x;
    printf("Enter %s:",T);
    while (scanf("%f", &x) != 1) {           
        printf("%s invalide! Veuillez ressayer: ",T);
        while (getchar() != '\n');    
    }
    return x;
}
// affiche un menu entre a et b
void menu1(int a,int b,char T[]){
    printf("-----%s-----\n",T);
    for(int i=a-1;i<b;i++){
        printf("%d. %s\n",Menus[i].num,Menus[i].text);
    }
    choix=getInt("choix");
    getchar();
}
// afficher ou ajouter un animal
void print(int a){
    for (int i=0;i<a;i++){
        printf("--------------\n");
        printf("Nom:");
        fgets(animal[count].nom,sizeof(animal[count].nom),stdin);
        animal[count].nom[strcspn(animal[count].nom,"\n")]=0;
        animal[count].age=getInt("age");
        animal[count].poids=getInt("poids");
        getchar();
        printf("espece:");
        fgets(animal[count].espece,sizeof(animal[count].espece),stdin);
        animal[count].espece[strcspn(animal[count].espece,"\n")]=0;
        printf("habitat:");
        fgets(animal[count].habitat,sizeof(animal[count].habitat),stdin);
        animal[count].habitat[strcspn(animal[count].habitat,"\n")]=0;
        animal[count].id=count+1;
        count++;
    }
}

// afficher les details d'un animal
void details(int i){
    printf("ID:%d\nnom:%s\nage:%d\npoids:%.2f\nespece:%s\nhabitat:%s\n",
           animal[i].id,animal[i].nom,animal[i].age,animal[i].poids,animal[i].espece,animal[i].habitat);
}

//Dans le cas ideal;indice=id-1.Mais pas toujours vrai, par exple dans le cas de supression;alors recherche lineaire.
int lookforid(){
    int id=getInt("ID");
    for (int j=0;j<count;j++){
        if (animal[j].id==id)
            return j;
    }
}
void lookfor(char T[]){
    int a=0;
    for(int i=0;i<count;i++){
        if (strcasecmp(T,animal[i].nom)==0){
            details(i);
            a=1;
            break;// le nom est unique.
        }
        else if (strcasecmp(T,animal[i].espece)==0)
            details(i);
            a=1;
            //l'espece n' est pas unique.
    }if(a==0)
        printf("Desole,le donne entree est invalide");
}

void echanger(int a,int b){
    temp = animal[a];
    animal[a] = animal[b];
    animal[b] = temp;
}

// restore original order by ID
void original(){
    for(int i=0;i<count-1;i++){
        for(int j=0;j<count-i-1;j++){
            if (animal[j].id > animal[j+1].id)
                echanger(j,j+1);
        }
    }
}

// trier par nom ou age (alphabet-based for nom)
void trier(char T[]){
    if (strcasecmp(T,"nom")==0){
        char alphab[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int indice2[count];
        for(int j=0;j<count;j++){
            for(int i=0;i<26;i++){
                if (toupper(animal[j].nom[0])==alphab[i])
                    indice2[j]=i;
            }
        }
        for(int i=0;i<count-1;i++){
            for(int j=0;j<count-i-1;j++){
                if(indice2[j]>indice2[j+1])
                    echanger(j,j+1);
            }
        }
    }
    else if (strcasecmp(T,"age")==0){
        for(int i=0;i<count-1;i++){
            for(int j=0;j<count-i-1;j++){
                if(animal[j].age>animal[j+1].age)
                    echanger(j,j+1);
            }
        }
    }
}

void afficher(char T[]){
    int count1=0;
    if (strcasecmp(T,"all")==0)
        original();
    else if (strcasecmp(T,"habitat")==0){
       printf("Entrez l'habitat:");
       fgets(in,sizeof(in),stdin);
       in[strcspn(in,"\n")]=0;
       for(int i=0;i<count;i++){
            if(strcasecmp(animal[i].habitat,in)==0){
                details(i);
                count1++;
            }
       }
       if(count1==0)
           printf("l'habitat entree n' est pas disponible\n");
    }
    else
        trier(T);

    for(int i=0;i<count;i++)
        details(i);
}

void delete_animal(){
    indice=lookforid();
    echanger(indice,count-1);
    count--;
    original();
}

void agemoyen(){
    int s=0;
    for(int i=0;i<count;i++)
        s+=animal[i].age;
    printf("L'age moyen des animaux est : %.2f\n",(float)s/count);    
}

void pvpj(){//plus vieux plus jeune
    trier("age");
    printf("l'animal le plus jeune est: %s\nl'animal le plus vieux est: %s\n",
           animal[0].nom,animal[count-1].nom);
}

void epr(){//especes les plus representes
    struct espece{
        char espece1[50];
        int nombre;
    };
    struct espece especes[16]={
        {"Lion",0},{"Tigre",0},{"Ours",0},{"Elephant",0},
        {"Zebre",0},{"Hippopotame",0},{"Lemurien",0},{"Girafe",0},
        {"Suricate",0},{"Phacochere",0},{"Serpent",0},{"Perroquet",0},
        {"Chien sauvage",0},{"Tortue",0},{"Oiseau",0},{"Gorille",0}
    };
    for(int i=0;i<count;i++){
        for(int j=0;j<16;j++){
            if(strcasecmp(animal[i].espece,especes[j].espece1)==0)
                especes[j].nombre++;
        }
    }
    int max=0,indice=0;
    for(int j=0;j<16;j++){
        if(especes[j].nombre>max){
            max=especes[j].nombre;
            indice=j;
        }
    }
    printf("L'espece le plus present est:%s\n",especes[indice].espece1);
}

int main(){
    while(1){
        menu1(1,6,"MENU");
        switch(choix){
            case 1:
                menu1(7,8,"AJOUTER UN ANIMAL");
                switch(choix){
                    case 7: print(1); break;
                    case 8:
                        printf("Combien d'animaux vous voulez ajouter:");
                        scanf("%d",&howmany);
                        getchar();
                        print(howmany);
                        break;
                }
                break;
            case 2:
                menu1(9,12,"AFFICHER LES ANIMAUX");
                switch(choix){
                    case 9: afficher("all"); break;
                    case 10: afficher("nom"); break;
                    case 11: afficher("age"); break;
                    case 12: afficher("habitat"); break;
                }
                break;
            case 3:
                indice=lookforid();
                menu1(13,14,"MODIFIER UN ANIMAL");
                switch(choix){
                    case 13:
                        printf("Habitat:");
                        fgets(animal[indice].habitat,sizeof(animal[indice].habitat),stdin);
                        animal[indice].habitat[strcspn(animal[indice].habitat,"\n")]=0;
                        break;
                    case 14:
                        animal[indice].age=getInt("age");
                        break;
                }
                break;
            case 4:
                delete_animal();
                break;
            case 5:
                menu1(15,17,"RECHERCHER UN ANIMAL");
                switch(choix){
                    case 15:
                        indice=lookforid();
                        details(indice);
                        break;
                    case 16:
                        printf("Entrez le nom:");
                        fgets(in,sizeof(in),stdin);
                        in[strcspn(in,"\n")]=0;
                        lookfor(in);
                        break;
                    case 17:
                        printf("Entrez l'espece:");
                        fgets(in,sizeof(in),stdin);
                        in[strcspn(in,"\n")]=0;
                        lookfor(in);
                        break;
                }
                break;
            case 6:
                menu1(18,21,"STATISTIQUES");
                switch(choix){
                    case 18: printf("Le nombre total des animaux est: %d\n",count); break;
                    case 19: agemoyen(); break;
                    case 20: pvpj(); break;
                    case 21: epr(); break;
                }
                break;
        }
    }
    return 0;
}