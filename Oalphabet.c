// afficher les noms par ordre alphabetiques
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char alphab[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int alphb(char T[]) {
    int n = strlen(T);
    for (int j = 0; j < 26; j++) { 
        if (T[0] == alphab[j])
            return j;
    }
    return -1; 
}

typedef struct {
    char name[50];
    char lastName[50];
    int age;
} Person;

int main() {
    Person people[11] = {
        {"Alice", "Smith", 25},
        {"Bob", "Johnson", 30},
        {"Charlie", "Williams", 22},
        {"David", "Brown", 28},
        {"Eve", "Jones", 24},
        {"Frank", "Garcia", 27},
        {"Grace", "Martinez", 45},
        {"Alice", "Martinez", 18},    
        {"Bob", "Smith", 67},         
        {"Hannah", "Smith", 23},
        {"Julia", "Martinez", 21} 
    };

    Person temp;
    int n=11;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (alphb(people[j].name) > alphb(people[j + 1].name)) {
                temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("nom: %s\nprenom: %s\nage: %d\n\n",
               people[i].name, people[i].lastName, people[i].age);

    return 0;
}

