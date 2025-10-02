#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>
int choix;
int count=20;
int howmany;
int indice,i,j;
char in[50]={};

// Configuration du menu
struct menu{
    char text[100];
    int num;
};
struct menu Menus[] = {
    {"Ajouter un animal",1},
    {"Afficher les animaux",2},
    {"Modifier un animal",3},
    {"Supprimer un animal",4},
    {"Rechercher un animal",5},
    {"Statistiques",6},
    {"exit",7},
    {"Ajout simple",8},
    {"Ajout multiple",9},
    {"Afficher la liste complète",10},
    {"Trier par nom",11},
    {"Trier par age",12},
    {"Afficher uniquement les animaux un habitat spécifique",13},
    {"Modifier lhabitat",14},
    {"Modifier lâge",15},
    {"Rechercher par id",16},
    {"Rechercher par nom",17},
    {"Rechercher par espece",18},
    {"Nombre total danimaux dans le zoo",19},
    {"Âge moyen des animaux",20},
    {"Plus vieux et plus jeune animal",21},
    {"Afficher les espèces les plus représentées",22}
    
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

// Animaux
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

float getInt(char T[]) { // Verification d'input de type float et ID
    float x;
    printf("Enter %s:",T);
	if (strcmp(T,"ID")==0){
    	while (scanf("%f", &x) !=1 || x>count) {           
        printf("%s invalide!\nVeuillez ressayer:",T);
        while (getchar() != '\n');    
	}
}   else{
    while (scanf("%f", &x) != 1 || x<0) {           
        printf("%s invalide!\nVeuillez ressayer:",T);
        while (getchar() != '\n');    
    }}
    return x;
}
void menu1(int a,int b,char T[]){ // affiche un menu de choix a jusqu'a b
    printf("-----%s-----\n",T);
    for(i=a-1;i<b;i++){
        printf("%d. %s\n",Menus[i].num,Menus[i].text);
    }
    choix=getInt("choix");
    getchar();
}
// afficher ou ajouter un animal
void print(int a){
    for (i=0;i<a;i++){
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
void details(int i){
    printf("ID:%d\nnom:%s\nage:%d\npoids:%.2f\nespece:%s\nhabitat:%s\n",
           animal[i].id,animal[i].nom,animal[i].age,animal[i].poids,animal[i].espece,animal[i].habitat);
}
int lookforid(){ //Dans le cas ideal;indice=id-1.Mais pas toujours vrai, par exple dans le cas de supression;alors recherche lineaire.
    int id=getInt("ID");
    for (j=0;j<count;j++){
        if (animal[j].id==id)
            return j;
    }
}
void lookfor(char T[]){
    int a=0;
    for(i=0;i<count;i++){
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

void echanger(int a,int b){ //operation swap
    temp = animal[a];
    animal[a] = animal[b];
    animal[b] = temp;
}

// restore original order by ID
void original(){
    for( i=0;i<count-1;i++){
        for(j=0;j<count-i-1;j++){
            if (animal[j].id > animal[j+1].id)
                echanger(j,j+1);
        }
    }
}

// trier par nom ou age
void trier(char T[]){
    
    if (strcasecmp(T,"nom")==0){
    char alphab[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int indice2[count];
    for(j = 0; j < count; j++){
        char first = toupper(animal[j].nom[0]);
        for( i = 0; i < 26; i++){
            if (first == alphab[i]) {
                indice2[j] = i;
                break;
            }
        }
    }    
    // bubble sort
    for( i = 0; i < count - 1; i++){
        for( j = 0; j < count - i - 1; j++){
            if(indice2[j] > indice2[j+1]){
                echanger(j, j+1);
                int tmp = indice2[j];
                indice2[j] = indice2[j+1];
                indice2[j+1] = tmp;
            }
        }
    }
    }else if (strcasecmp(T,"age")==0){
        for( i=0;i<count-1;i++){
            for(j=0;j<count-i-1;j++){
                if(animal[j].age>animal[j+1].age)
                    echanger(j,j+1);
            }
        }
    }
}

void afficher(char T[]){
    int count1=0, k=0;
    if (strcasecmp(T,"all")==0)
        original();
    else{
    	if (strcasecmp(T,"habitat")==0){
	       printf("Entrez l'habitat:");
	       fgets(in,sizeof(in),stdin);
	       while(in[k]!='\n')k++;
	       in[k] = '\0';
	       for(i=0;i<count;i++){
	       	printf("%s?\n", animal[i].habitat);
	            if(stricmp(animal[i].habitat, in)==0){
	                details(i);
	                count1++;
	            }
       	   }
	       if(count1==0){
	           printf("l'habitat entree n' est pas disponible\n");}
	    }
	    else{
	    	trier(T);
	    	for(i=0;i<count;i++){
		        printf("---------------\n");
		        details(i);
			}
		}
	        
	}    
}

void delete_animal(){
    indice=lookforid();
    echanger(indice,count-1);
    count--;
    original();
}

void agemoyen(){
    int s=0;
    for(i=0;i<count;i++)
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
    for(i=0;i<count;i++){
        for( j=0;j<16;j++){
            if(strcasecmp(animal[i].espece,especes[j].espece1)==0)
                especes[j].nombre++;
        }
    }
    int max=0,indice=0;
    for(j=0;j<16;j++){
        if(especes[j].nombre>max){
            max=especes[j].nombre;
            indice=j;
        }
    }
    printf("L'espece le plus present est:%s\n",especes[indice].espece1);
}

int main(){
    while(1){
        menu1(1,7,"MENU");
        switch(choix){
            case 1:
                menu1(8,9,"AJOUTER UN ANIMAL");
                switch(choix){
                    case 8: print(1); break;
                    case 9:
                        printf("Combien d'animaux vous voulez ajouter:");
                        scanf("%d",&howmany);
                        getchar();
                        print(howmany);
                        break;
                    default:
                    printf("Choix entree est invalide!\n");
                }
                break;
            case 2:
                menu1(10,13,"AFFICHER LES ANIMAUX");
                switch(choix){
                    case 10: afficher("all"); break;
                    case 11: afficher("nom"); break;
                    case 12: afficher("age"); break;
                    case 13: afficher("habitat"); break;
                    default:
                    printf("Choix entree est invalide!\n");
                }
                break;
            case 3:
                indice=lookforid();
                menu1(14,15,"MODIFIER UN ANIMAL");
                switch(choix){
                    case 14:
                        printf("Habitat:");
                        fgets(animal[indice].habitat,sizeof(animal[indice].habitat),stdin);
                        animal[indice].habitat[strcspn(animal[indice].habitat,"\n")]=0;
                        break;
                    case 15:
                        animal[indice].age=getInt("age");
                        break;
                    default:
                    printf("Choix entree est invalide!\n");
                }
                break;
            case 4:
                delete_animal();
                break;
            case 5:
                menu1(16,18,"RECHERCHER UN ANIMAL");
                switch(choix){
                    case 16:
                        indice=lookforid();
                        details(indice);
                        break;
                    case 17:
                        printf("Entrez le nom:");
                        fgets(in,sizeof(in),stdin);
                        in[strcspn(in,"\n")]=0;
                        lookfor(in);
                        break;
                    case 18:
                        printf("Entrez l'espece:");
                        fgets(in,sizeof(in),stdin);
                        in[strcspn(in,"\n")]=0;
                        lookfor(in);
                        break;
                    default:
                    printf("Choix entree est invalide!\n");
                }
                break;
            case 6:
                menu1(19,22,"STATISTIQUES");
                switch(choix){
                    case 19: printf("Le nombre total des animaux est: %d\n",count); break;
                    case 20: agemoyen(); break;
                    case 21: pvpj(); break;
                    case 22: epr(); break;
                    default:
                    printf("Choix entree est invalide!\n");
                }
                break;
            case 7:
			    exit(0);    
            default:
            printf("choix entree est invalide!\n");   
        }
    }
    return 0;
}
