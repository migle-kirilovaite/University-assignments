/* 
   LSP: 2213745 
   Email: migle.kirilovaite@mif.stud.vu.lt
   Uzd. Nr.: 4
   Variantas: 1 (Sudaryti vienpusį sąrašą. Parašyti procedūrą, 
                kuri įterpia prieš reikšme nurodytą elementą naują elementą. 
                Jeigu tokio elemento nėra, turi būti išvestas atitinkamas pranešimas.)
*/ 

#include <stdio.h>
#include <conio.h>
#include "functions.h"

void menu(struct Node* head)
{
    int choice;
    
    printf("\n-Menu-\n\n");
    printf("Iveskite norimo veiksmo skaiciu.\n\n");
    printf("0 sukuria sarasa (is duoto duomenu failo)\n");
    printf("1 isspausdina sarasa \n");
    printf("2 iterpia pries reiksme nurodyta elementa nauja elementa.\n");
    printf("3 iseina is programos\n");
    printf("Pasirinkimas: ");
    scanf("%d", &choice);
    
    validateChoice(&choice);
    actions(choice, &head);

    printf("\nPaspauskite betkoki mygtuka, kad grizti i meniu.\n");
    getch();

    menu(head);
}

int main()
{
    struct Node* head = NULL;
    menu(head);
    return 0;
}