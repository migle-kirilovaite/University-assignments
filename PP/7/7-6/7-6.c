#include <stdio.h>

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg)
{
    menuTitle = "Meniu";
    inputMsg = "Iveskite savo pasirinkimo skaiciu: ";
    printf("%s \n", menuTitle);
    for(int i = 0; i < menuSize; ++i)
    {
        printf("%s \n", menuOptions[i]);
    }
    printf("%s \n", inputMsg);

    int choice;
    scanf("%d", &choice);

    if (choice > 0 && choice <= menuSize)
    {
        return choice;
    }
    else 
        choice = showMenu(menuTitle, menuOptions, menuSize, inputMsg);
}

int main()
{
    char menuTitle, inputMsg;
    char *menuOptions[] = {"1. Pasirinkimas",
                            "2. Pasirinkimas,",
                            "3. Pasirinkimas,",
                            "4. Pasirinkimas"};
    int menuSize = 3, choice;
    choice = showMenu(&menuTitle, menuOptions, menuSize, &inputMsg);
    return 0;
}