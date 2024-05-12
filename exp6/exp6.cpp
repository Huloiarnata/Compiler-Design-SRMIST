#include <stdio.h>
#include <string.h>

char prol[7][10] = {"S", "A", "A", "B", "B", "C", "C"};
char pror[7][10] = {"A", "Bb", "Cd", "aB", "@", "Cc", "@"};
char first[7][10] = {"abcd", "ab", "cd", "a@", "@", "c@", "@"};
char follow[7][10] = {"$", "$", "$", "a$", "b$", "c$", "d$"};
char table[5][6][10];

int numr(char c) {
    switch (c) {
        case 'S': return 0;
        case 'A': return 1;
        case 'B': return 2;
        case 'C': return 3;
        case 'a': return 0;
        case 'b': return 1;
        case 'c': return 2;
        case 'd': return 3;
        case '$': return 4;
    }
    return 2;
}

void fill_table(char pro[][10], char f[][10], int size) {
    int i, j, k;
    for (i = 0; i < size; i++) {
        k = strlen(f[i]);
        for (j = 0; j < k; j++) {
            if (f[i][j] != '@') {
                int row = numr(prol[i][0]) + 1;
                int col = numr(f[i][j]) + 1;
                if (strcmp(table[row][col], " ") == 0) {
                    strcpy(table[row][col], pro[i]);
                } else {
                    printf("Conflict at table[%d][%d].\n", row, col);
                }
            }
        }
    }
}

int main() {
    int i, j;
    for (i = 0; i < 5; i++)
        for (j = 0; j < 6; j++)
            strcpy(table[i][j], " ");

    fill_table(prol, first, 7);
    fill_table(pror, follow, 7);

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 6; j++) {
            printf("%-10s", table[i][j]);
            if (j == 5)
                printf("\n--------------------------------------------------------\n");
        }
    }
    return 0;
}
