// Welcome to square matrix generator
// this program generates matrix with given values
// You can adjust size, max/min values below in - VARIABLES - section
//
// by Szymon Rozmyslowski 17.04.2022

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>


// --------------- VARIABLES -----------------
int sizeOfMatrix = 10; // Size of square matrix. Amount of all numbers equals A x A
int minValue = 5; // Minimal value of numbers in matrix
int maxValue = 50; // Maximal value of numbers in matrix

bool ifDiagonal = 1; // Makes zeros diagonally in matrix
bool saveAsArray = 1; // Allows to save matrix into file in one line (it makes further inplementation easier but makes it much more illegible to You)

char path[] = ""; // leave empty if you want .txt file to be in the same folder as this program is
// -------------------------------------------


void generateMatrix(int matrix[sizeOfMatrix][sizeOfMatrix], int max, int min, bool diagonal)
{
    srand(time(NULL)); // Initialization of random number generator, should only be called once.

    for (int i = 0; i < sizeOfMatrix; i++)
    {
        for (int j = 0; j < sizeOfMatrix; j++)
        {
            int r = rand() % (max - min) + min; // Returns a pseudo-random integer
            matrix[i][j] = r;
        }
    }

    if (diagonal == true)
    {
        for (int i = 0; i < sizeOfMatrix; i++)
        {
            matrix[i][i] = 0;
        }
    }
}

void showMatrix(int matrix[sizeOfMatrix][sizeOfMatrix], int size)
{
    for (int i = 0; i < sizeOfMatrix; i++)
    {
        for (int j = 0; j < sizeOfMatrix; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void matrixToFile(int matrix[sizeOfMatrix][sizeOfMatrix], bool ifArray, char path[])
{
    char fileName[] = "generated_matrix.txt";
    char *fullPath = (char *)malloc(1 + strlen(path) + strlen(fileName));
    strcpy(fullPath, path);
    strcat(fullPath, fileName);

    FILE *ftw;
    ftw = fopen(fullPath, "w+");
    for (int i = 0; i < sizeOfMatrix; i++)
    {
        for (int j = 0; j < sizeOfMatrix; j++)
        {
            fprintf(ftw, "%d\t", matrix[i][j]);
        }
        if (ifArray != 1)
            fprintf(ftw, "\n");
    }
}

void main()
{
    if (sizeOfMatrix < 1)
    {
        printf("Size cannot be less than 1\n");
        exit(0);
    }

    if (minValue > maxValue)
    {
        printf("Minimal value cannot be higher than maximal one\n");
        exit(0);
    }

    int (*matrix)[sizeOfMatrix];
    matrix = malloc(sizeof(*matrix) * sizeOfMatrix);
    matrix = malloc(sizeof(int[sizeOfMatrix][sizeOfMatrix]));
    generateMatrix(matrix, maxValue, minValue, ifDiagonal);
    //showMatrix(matrix, sizeOfMatrix);
    matrixToFile(matrix, saveAsArray, path);
    free(matrix);
}
