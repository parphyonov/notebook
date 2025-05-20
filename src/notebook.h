#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

const int MAXBUFFER = 256;

// Menu stuff
void deleteMenu(char** array, int N);
char** getMenu(FILE* fptr, int N);
int getMenuSize(FILE* fptr);
void printMenu(char** array, int N);