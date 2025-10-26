#include <stdio.h>


int main() {
    int x, y, choice;
    int sum_val, sub_val, mul_val, div_val;

    printf("This is a basic calculator.\n\n");

    printf("Enter number 1: ");
    scanf("%d", &x);

    printf("Enter number 2: ");
    scanf("%d", &y);

    printf("\nSelect operation:\n");
    printf("1. Sum\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Calculate results
    sum_val = x + y;
    sub_val = x - y;
    mul_val = x * y;
    div_val= x / y;

    switch (choice) {
        case 1:
            printf("Sum is: %d\n", sum_val);
            break;
        case 2:
            printf("Subtraction is: %d\n", sub_val);
            break;
        case 3:
            printf("Multiplication is: %d\n", mul_val);
            break;
        case 4:
            if (y == 0) {
                printf("Invalid input: division by zero is not allowed.\n");
            } else {
                printf("Division is: %d\n", div_val);
            }
            break;
        default:
            printf("Invalid choice! Please select 1-4.\n");
    }

    return 0;
}
