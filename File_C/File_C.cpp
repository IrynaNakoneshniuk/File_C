#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
void Task1() {
    FILE* file, * file2;
    const char* path = "test.txt";
    const char* path2 = "test2.txt";
    char buf[500];
    char* p = NULL;
    if ((file = fopen(path, "w")) == NULL) {
        perror("File 1 not open");
    }
    else {
        cout << "->";
        gets_s(buf);
        fputs(buf, file);
        cout << "Done!" << endl;
        fclose(file);
    }
    if ((file2 = fopen(path2, "w")) == NULL||ferror(file2)) {
        perror("File 2 not open");
    }
    if ((file = fopen(path, "r")) == NULL) {
        perror("File 1 not open");
    }
    else {
        while (fgets(buf, 1000, file)) {
            p = strtok(buf, " ,.-");
            while (p != NULL) {
                if (strlen(p) >= 7) {
                    fputs(p, file2);
                    fputs(" ", file2);
                }
                p = strtok(NULL, " ,.-");
            }
        };
        fclose(file);
        fclose(file2);
    }
}
void Task2() {
    FILE* out; 
    FILE* in;
    const char* path1= "test.txt";
    const char* path2 = "test2.txt";
    char buf[256];
    if ((out=fopen(path1, "r") )== NULL) {
        perror("File 1 not open");
    }
    if ((in=fopen(path2, "w")) == NULL) {
        perror("File 2 not open");
    }
    while ((fgets(buf, 256, out))!=NULL) {
       fputs(buf,in);
       printf(buf, "%s");
    }
    fclose(in);
    fclose(out);
}

void Task3() {
    FILE* out;
    FILE* in;
    string str1;
    string str2;
    const char* path1 = "test.txt";
    const char* path2 = "test2.txt";
    char buf[256];
    char buf2[256];
    if ((out = fopen(path1, "r")) == NULL) {
        perror("File 1 not open");
    }
    if ((in = fopen(path2, "w")) == NULL) {
        perror("File 2 not open");
    }
    while ((fgets(buf, 256, out)) != NULL) {
        int i = strlen(buf);
        int k = 0;
        do {
            buf2[k] = buf[i - 1];
            i--;
            k++;
        } while (i != 0);
        buf2[k++] = '\0';
        fputs(buf2, in);
        printf(buf2, "%s");
    }
    fclose(in);
    fclose(out);
}
int main()
{
    /*Task1();
    Task2();*/
    Task3();
    return 0;
}

