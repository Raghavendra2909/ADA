#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int col[20]; // stores column positions of queens (1-based index)
int n;

int promising(int i) {
    for (int k = 1; k < i; k++) {
        if (col[i] == col[k] || abs(col[i] - col[k]) == abs(i - k)) {
            return 0; // Conflict in column or diagonal
        }
    }
    return 1;
}

void printSolution() {
    for (int i = 1; i <= n; i++) {
        printf("%d ", col[i]);
    }
    printf("\n");
}

void queens(int i) {
    if (i == n) {
        printSolution(); // All queens placed successfully
    } else {
        for (int j = 1; j <= n; j++) {
            col[i + 1] = j; // Try placing queen in column j
            if (promising(i + 1)) {
                queens(i + 1); // Recur for next row
            }
        }
    }
}

int main() {
    printf("Enter number of queens (n): ");
    scanf("%d", &n);
    queens(0); // Start with 0th row
    return 0;
}


/*
OUTPUT:
Enter number of queens (n): 4
2 4 1 3 
3 1 4 2
*/
