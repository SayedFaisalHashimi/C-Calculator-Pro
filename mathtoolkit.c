#include <stdio.h>
#include<math.h>


int main() {
    int x, y, choice;
    int sum_val, sub_val, mul_val, mod_val;
    double div_val, pow_val, sqrt_x, sqrt_y, avg_val;
    unsigned long long fact_x, fact_y;
    double rad_x, rad_y;

    printf("This is a basic calculator.\n\n");

    while (1) {
    printf("Enter number 1: ");
    if(scanf("%d", &x) != 1 ) break;

    printf("Enter number 2: ");
    if(scanf("%d", &y) != 1 ) break;

    printf("\nSelect operation:\n");
    printf("0. Exit\n");
    printf("1. Sum\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Power\n");
    printf("7. Square root\n");
    printf("8. Average\n");
    printf("9. Factorial\n");
    printf("10. Trigonometry (sin, cos, tan)\n");
    printf("11. Radians ↔ Degrees conversion\n"); 


    printf("Enter your choice: ");
    if(scanf("%d", &choice) != 1 ) break;

    if (choice == 0) {
            printf("Exiting calculator. Goodbye!\n");
            break;
        }

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



    // Factorial of x
        if (x >= 0) {
            fact_x = 1;
            for (int i = 1; i <= x; i++)
                fact_x *= i;
        } else {
            fact_x = 0; // invalid
        }

        // Factorial of y
        if (y >= 0) {
            fact_y = 1;
            for (int i = 1; i <= y; i++)
                fact_y *= i;
        } else {
            fact_y = 0; // invalid
        }

        // Trigonometry (in degrees -> radians)
        rad_x = x * M_PI / 180.0;
        rad_y = y * M_PI / 180.0;



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
                printf("Division is: %f\n", div_val);
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
        case 9:
            if (x >= 0)
                printf("Factorial of %d is: %llu\n", x, fact_x);
            else
                    printf("Factorial of %d is undefined (negative number)\n", x);
            if (y >= 0)
                printf("Factorial of %d is: %llu\n", y, fact_y);
            else
                printf("Factorial of %d is undefined (negative number)\n", y);
            break;
        case 10:
                printf("Trigonometry of %d degrees: sin=%.6g, cos=%.6g, tan=%.6g\n", x, sin(rad_x), cos(rad_x), tan(rad_x));
                printf("Trigonometry of %d degrees: sin=%.6g, cos=%.6g, tan=%.6g\n", y, sin(rad_y), cos(rad_y), tan(rad_y));
            break;
        case 11: // Radian ↔ Degree conversion
                printf("%d degrees = %.6g radians\n", x, rad_x);
                printf("%d degrees = %.6g radians\n", y, rad_y);
                printf("%.6g radians = %.6g degrees\n", rad_x, rad_x * 180.0 / M_PI);
                printf("%.6g radians = %.6g degrees\n", rad_y, rad_y * 180.0 / M_PI);
            break;
        default:
            printf("Invalid choice! Please select 1-8.\n");
    }
 
    printf("\n");  
  }   

  return 0;
}
