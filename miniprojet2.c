#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct contact{
	char nom[30];
	char num[50];
	char mail[100];
};

struct contact contacts[100];
int count=0;
char in[100]={};

int lookfor(char T[]){
	for(int i=0;i<count;i++){
		if (strcmp(contacts[i].nom,T)==0)
			return i;
	}
	return -1;
}

int delete(char T[]){
	int m=lookfor(T);
	if (m!=-1){
	struct contact temp;
	for(int i=m;i<count-1;i++){
		temp=contacts[m];
		contacts[i]=contacts[i+1];
		contacts[i+1]=temp;
	}
	count--;
	printf("le contact est supprime avec succes");
	}
	else
		printf("le contact n'existe pas");
}
int checknum(char T[]){
	int n=strlen(T);
	if (n == 0) 
	return -1;
	if (T[0]=='+'||T[0]=='0' ){
		for(int i=1;i<n;i++){
			if (isdigit(T[i])==0){
				return -1;				
			}	
		}return 1;
	}else 
	return -1;
}
int checkmail(char T[]){
	int n=strlen(T);
	if (n == 0) 
	return -1;
	int count=0;
	for(int i=0;i<n;i++){
		if(T[i]=='@')
		count++;
	}	
	if (count>2 )
	{
        return -1;
	}					
	return 1;	}

int main(){
	int choix;
    while(1){
	printf("------CONTACTS------\n1:Ajouter un Contact\n2:Modifier un Contact\n3:Supprimer un Contact\n4:Afficher Tous les Contacts\n5:Rechercher un Contact\n6:Quitter le menu\n");
    scanf("%d",&choix);
    getchar();
    switch(choix){
    	case 1:
		printf("------AJOUTER UN CONTACT------\n");
		printf("Entrez le nom:\n");
		fgets(in,sizeof(in),stdin);
		strcpy(contacts[count].nom,in);
		printf("Entrez le numéro de téléphone:\n");
		fgets(in,sizeof(in),stdin);
		if(checknum(in)==-1)
			strcpy(contacts[count].num,in);
		else{
			printf("Le numero entre n'est pas valide");
			break;
		}	
		printf("Entrez Adresse e-mail:\n");
		fgets(in,sizeof(in),stdin);
		if(checkmail(in)==-1)
			strcpy(contacts[count].mail,in);
		else{
			printf("L' adresse email entrée n'est pas valide");
			break;
		}
		count++;
		break;
		case 2:
		printf("------MODIFIER UN CONTACT------\n");
		printf("Entrez le nom du contact:\n");
		fgets(in,sizeof(in),stdin);
		if(lookfor(in)!=-1){
			int id=lookfor(in);
			printf("Nom:");
			fgets(in,sizeof(in),stdin);
			strcpy(contacts[id].nom,in);
			printf("E-mail:");
			fgets(in,sizeof(in),stdin);
			strcpy(contacts[id].mail,in);}
		else{
			printf("Le contact n'existe pas dans le carnet de contact");
		}
		break;
		case 3:
		printf("Entrez le nom du contact:");
		fgets(in,sizeof(in),stdin);
		delete(in);
		break;
		case 4:
		for(int i=0;i<count;i++){
			printf("CONTACT%d:\nNom:%s\nNum:%s\nE-mail:%s",i+1,contacts[i].nom,contacts[i].num,contacts[i].mail);
		}
		break;
		case 5:
		printf("Entrez le nom du contact:");
		fgets(in,sizeof(in),stdin);
		if (lookfor(in)!=-1){
			printf("CONTACT %d:\nNom:%s\nNum:%s\nE-mail:%s",lookfor(in)+1,contacts[lookfor(in)].nom,contacts[lookfor(in)].num,contacts[lookfor(in)].mail);
		}
		else{
		printf("Le contact n'existe pas dans le carnet de contact");	
		}
		break;
		case 6:
		exit(0);
	}}}
