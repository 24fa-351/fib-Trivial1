#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursive Fibonacci function
int fib_recursive(int n) {
    if (n == 1) return 0; // Fibonacci #1 is 0
    if (n == 2) return 1; // Fibonacci #2 is 1
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// Iterative Fibonacci function
int fib_iterative(int n) {
    if (n == 1) return 0; // Fibonacci #1 is 0
    if (n == 2) return 1; // Fibonacci #2 is 1
    int prev1 = 0, prev2 = 1, current;
    for (int i = 3; i <= n; i++) { // Start from 3rd Fibonacci
        current = prev1 + prev2;
        prev1 = prev2;
        prev2 = current;
    }
    return prev2;
}


int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: ./fib <integer> <method (r/i)> <filename>\n");
        return 1;
    }

    // Parse the first argument
    int input_num = atoi(argv[1]);

    // Parse the method argument
    char method = argv[2][0];
    if (method != 'r' && method != 'i') {
        printf("Invalid method. Use 'r' for recursive or 'i' for iterative.\n");
        return 1;
    }

    // Open the file and read the integer
    FILE *file = fopen(argv[3], "r");
    if (!file) {
        printf("Error: Could not open file %s\n", argv[3]);
        return 1;
    }
    int file_num;
    fscanf(file, "%d", &file_num);
    fclose(file);

    // Compute N
    int n = input_num + file_num;

    // Compute Fibonacci number
    int result;
    if (method == 'r') {
        result = fib_recursive(n);
    } else {
        result = fib_iterative(n);
    }

    // Output the result
    printf("%d\n", result);

    return 0;
}
