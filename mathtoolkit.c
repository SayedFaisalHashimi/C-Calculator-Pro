#include <stdio.h>
#include<math.h>


int main() {
    int x, y, choice;
    int sum_val, sub_val, mul_val, mod_val;
    double div_val, pow_val, sqrt_x, sqrt_y, avg_val;

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
    printf("5. Modulus\n");
    printf("6. Power\n");
    printf("7. Square root\n");
    printf("8. Average\n");


    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Calculate results
    sum_val = x + y;
    sub_val = x - y;
    mul_val = x * y;

    
    if (y != 0) {
        div_val = (double)x / (double)y;
        mod_val = x % y;
    } else {
        div_val = NAN;   /* division undefined */
        mod_val = 0;     /* placeholder, will check before printing */
    }

    pow_val  = pow((double)x, (double)y);
    sqrt_x   = (x >= 0) ? sqrt((double)x) : NAN;
    sqrt_y   = (y >= 0) ? sqrt((double)y) : NAN;
    avg_val  = (x + y) / 2.0;


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
        case 5:
            if (y == 0) {
                printf("Invalid input: modulus by zero is not allowed.\n");
            } else {
                printf("Modulus is: %d\n", mod_val);
            }
            break;
        case 6:
            printf("Power (x^y) is: %.6g\n", pow_val);
            break;
        case 7:
            if (!isnan(sqrt_x))
                printf("Square root of %d is: %.6g\n", x, sqrt_x);
            else
                printf("Square root of %d is: undefined (negative input)\n", x);

            if (!isnan(sqrt_y))
                printf("Square root of %d is: %.6g\n", y, sqrt_y);
            else
                printf("Square root of %d is: undefined (negative input)\n", y);
            break;
        case 8:
            printf("Average is: %.6g\n", avg_val);
            break;
        default:
            printf("Invalid choice! Please select 1-8.\n");
    }

    return 0;
}
