#include "notebook.h"

void printMenu(char** array, int N) {
    for (int i = 0; i < N; i++) {
        cout << i + 1 << " - " << array[i] << endl;
    }
    cout << "Выберите вариант действия:" << endl;
}

void deleteMenu(char** array, int N) {
    for (int i = 0; i < N; i++) {
        delete[] array[i];
    }
    delete[] array;
}

char** getMenu(FILE* fptr, int N) {
    rewind(fptr);

    int aIdx = 0;
    char** array = new char *[N];

    if (!array) {
        cerr << "Menu failed to allocate" << endl;
        exit(EXIT_FAILURE);
    }

    char buffer[MAXBUFFER];
    while (fgets(buffer, MAXBUFFER, fptr) != NULL) {
        int buffLen = strlen(buffer);
        array[aIdx] = new char[buffLen];

        if (!array[aIdx]) {
            cerr << "Menu item failed to allocate" << endl;
            deleteMenu(array, aIdx);
            exit(EXIT_FAILURE);
        }

        strncpy(array[aIdx], buffer, buffLen);

        if (aIdx != N - 1) {
            array[aIdx][buffLen - 1] = '\0';
        }

        aIdx++;
    }

    return array;
}

int getMenuSize(FILE* fptr) {
    int ch, lCh, res = 0;
    
    while((ch = getc(fptr)) != EOF) {
        if (ch == '\n') {
            res++;
        }
        lCh = ch;
    }

    if (feof(fptr) && lCh != '\n') {
        res++;
    }

    return res;
}
