#include "notebook.h"

int main() {
    FILE* menuFile = fopen("../data/menuItems.txt", "r");

    if (!menuFile) {
        cerr << "Menu file not loaded" << endl;
        exit(EXIT_FAILURE);
    }

    int menuSize = getMenuSize(menuFile);

    char** Menu = getMenu(menuFile, menuSize);

    printMenu(Menu, menuSize);

    delete[] Menu;

    fclose(menuFile);

    return 0;
}