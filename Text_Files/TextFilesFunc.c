#include "TextFiles.h"
#include <stdio.h>
#include <string.h>

/* =========================
   fopen modes
   ========================= */
void Q1_OpenAllModes(void)
{
    FILE* fp;
    const char* filename = "q1_test.txt";

    /* Create file first so "r" won't fail because file doesn't exist */
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("ERROR: cannot create %s\n", filename);
        return;
    }
    fprintf(fp, "hello\n");
    fclose(fp);

    fp = fopen(filename, "r");
    printf("mode r:  %s\n", (fp == NULL) ? "NULL" : "OK");
    if (fp) fclose(fp);

    fp = fopen(filename, "w");
    printf("mode w:  %s\n", (fp == NULL) ? "NULL" : "OK");
    if (fp) fclose(fp);

    fp = fopen(filename, "a");
    printf("mode a:  %s\n", (fp == NULL) ? "NULL" : "OK");
    if (fp) fclose(fp);

    fp = fopen(filename, "r+");
    printf("mode r+: %s\n", (fp == NULL) ? "NULL" : "OK");
    if (fp) fclose(fp);

    fp = fopen(filename, "w+");
    printf("mode w+: %s\n", (fp == NULL) ? "NULL" : "OK");
    if (fp) fclose(fp);

    fp = fopen(filename, "a+");
    printf("mode a+: %s\n", (fp == NULL) ? "NULL" : "OK");
    if (fp) fclose(fp);
}

/* =========================
   5 persons
   ========================= */
typedef struct
{
    char name[20];
    int age;
} Person;

void Q2_PersonsWriteRead(void)
{
    Person p[5] = {
        {"Yosi", 30},
        {"Ilan", 28},
        {"Gilad", 25},
        {"Boaz", 40},
        {"Dana", 35}
    };

    FILE* fp = fopen("persons.txt", "w");
    if (fp == NULL)
    {
        printf("ERROR: cannot open persons.txt for writing\n");
        return;
    }

    /* write persons to file */
    for (int i = 0; i < 5; i++)
        fprintf(fp, "%s %d\n", p[i].name, p[i].age);

    fclose(fp);

    /* check file exists: try to open */
    fp = fopen("persons.txt", "r");
    if (fp == NULL)
    {
        printf("ERROR: file does not exist or cannot open for reading\n");
        return;
    }

    printf("persons from file:\n");

    /* read persons and print */
    Person temp;
    while (fscanf(fp, "%19s %d", temp.name, &temp.age) == 2)
    {
        printf("Name: %s | Age: %d\n", temp.name, temp.age);
    }

    fclose(fp);
}

/* =========================
   last N lines
   ========================= */
void Q4_LastNLines(const char* filename, int n)
{
    if (filename == NULL || n <= 0)
    {
        printf("ERROR: invalid input\n");
        return;
    }

    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("ERROR: cannot open file %s\n", filename);
        return;
    }

    /* up to 200 lines, each up to 200 chars */
    char lines[200][200];
    int count = 0;

    while (count < 200 && fgets(lines[count], 200, fp) != NULL)
        count++;

    fclose(fp);

    int start = 0;
    if (count > n)
        start = count - n;

    printf("last %d lines of %s:\n", n, filename);
    for (int i = start; i < count; i++)
        printf("%s", lines[i]);
}

/* =========================
   count word
   ========================= */
void Q6_CountWordFromControlFile(const char* controlFilename)
{
    if (controlFilename == NULL)
    {
        printf("ERROR: invalid input\n");
        return;
    }

    /* 1) read control file: targetFile + word */
    FILE* ctrl = fopen(controlFilename, "r");
    if (ctrl == NULL)
    {
        printf("ERROR: cannot open control file %s\n", controlFilename);
        return;
    }

    char targetFile[100];
    char word[50];

    if (fscanf(ctrl, "%99s %49s", targetFile, word) != 2)
    {
        printf("ERROR: control file must contain: <targetFile> <word>\n");
        fclose(ctrl);
        return;
    }
    fclose(ctrl);

    /* 2) open target file and count word */
    FILE* fp = fopen(targetFile, "r");
    if (fp == NULL)
    {
        printf("ERROR: cannot open target file %s\n", targetFile);
        return;
    }

    int count = 0;
    char token[200];

    while (fscanf(fp, "%199s", token) == 1)
    {
        /* count exact match (case-sensitive) */
        if (strcmp(token, word) == 0)
            count++;
    }
    fclose(fp);

    /* 3) print result */
    printf("In file %s the word %s appeared %d times\n", targetFile, word, count);
}
