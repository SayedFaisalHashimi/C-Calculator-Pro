#include <stdio.h>
#include<math.h>


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


void sum(int x, int y);
void sub(int x, int y);
void mul(int x, int y);
void divi(int x, int y);
void mod(int x, int y);
void powe(int x, int y);
void sqr_x(int x, int y);
void sqr_y(int x, int y);
void avg(int x, int y);
void fac_x(int x, int y);
void fac_y(int x, int y);
void tri(int x, int y);
void rad(int x, int y);
void deg(int x, int y);
void sin_x(int x, int y);
void cos_x(int x, int y);
void tan_x(int x, int y);
void sin_y(int x, int y);
void cos_y(int x, int y);
void tan_y(int x, int y);



int main(void) {
    int x, y, choice;

    void (*ptr[20])(int, int) = {
        NULL,
        sum,
        sub,
        mul,
        divi,
        mod,
        powe,
        sqr_x,
        sqr_y,
        avg,
        fac_x,
        fac_y,
        tri,
        rad,
        sin_x,
        cos_x,
        tan_x,
        sin_y,
        cos_y,
        tan_y
    };

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
    printf("7. Square root (x)\n");
    printf("8. Square root (y)\n");
    printf("9. Average\n");
    printf("10. Factorial of X\n");
    printf("11. Factorial of Y\n");
    printf("12. Trigonometry (sin, cos, tan)\n");
    printf("13. Radians ↔ Degrees conversion\n"); 
    printf("14. sin(x)\n");
    printf("15. cos(x)\n");
    printf("16. tan(x)\n");
    printf("17. sin(y)\n");
    printf("18. cos(y)\n");
    printf("19. tan(y)\n");


    printf("Enter your choice: ");
    if(scanf("%d", &choice) != 1 ) break;

    if (choice == 0) {
            printf("Exiting calculator. Goodbye!\n");
            break;
        }

        if (choice < 0 ||
            choice >= (int)(sizeof(ptr) / sizeof(ptr[0])) ||
            ptr[choice] == NULL)
        {
            printf("Invalid choice! Please select a valid option.\n\n");
            continue;
        }

    (*ptr[choice])(x, y);
        printf("\n");
    }

    return 0;
}




void sum(int x, int y)
{
    printf("Sum is: %d\n", x + y);
}

void sub(int x, int y)
{
    printf("Subtraction is: %d\n", x - y);
}

void mul(int x, int y)
{
    printf("Multiplication is: %d\n", x * y);
}

void divi(int x, int y)
{
    if (y != 0)
        printf("Division is: %f\n", (double)x / y);
    else
        printf("Invalid input: division by zero is not allowed.\n");
}

void mod(int x, int y)
{
    if (y != 0)
        printf("Modulus is: %d\n", x % y);
    else
        printf("Invalid input: modulus by zero is not allowed.\n");
}

void powe(int x, int y)
{
    printf("Power (x^y) is: %.6g\n", pow((double)x, (double)y));
}

void sqr_x(int x, int y)
{
    double s = (x >= 0) ? sqrt((double)x) : NAN;
    if (!isnan(s))
        printf("Square root of %d is: %.6g\n", x, s);
    else
        printf("Square root of %d is undefined (negative)\n", x);
}

void sqr_y(int x, int y)
{
    double s = (y >= 0) ? sqrt((double)y) : NAN;
    if (!isnan(s))
        printf("Square root of %d is: %.6g\n", y, s);
    else
        printf("Square root of %d is undefined (negative)\n", y);
}

void avg(int x, int y)
{
    printf("Average is: %.6g\n", (x + y) / 2.0);
}

void fac_x(int x, int y)
{
    if (x < 0) {
        printf("Factorial of %d is undefined (negative)\n", x);
        return;
    }
    unsigned long long f = 1;
    for (int i = 1; i <= x; i++)
        f *= i;
    printf("Factorial of %d is: %llu\n", x, f);
}

void fac_y(int x, int y)
{
    if (y < 0) {
        printf("Factorial of %d is undefined (negative)\n", y);
        return;
    }
    unsigned long long f = 1;
    for (int i = 1; i <= y; i++)
        f *= i;
    printf("Factorial of %d is: %llu\n", y, f);
}

void tri(int x, int y)
{
    double rx = x * M_PI / 180.0;
    double ry = y * M_PI / 180.0;
    printf("Trigonometry of %d degrees: sin=%.6g, cos=%.6g, tan=%.6g\n", x, sin(rx), cos(rx), tan(rx));
    printf("Trigonometry of %d degrees: sin=%.6g, cos=%.6g, tan=%.6g\n", y, sin(ry), cos(ry), tan(ry));
}

void rad(int x, int y)
{
    double rx = x * M_PI / 180.0;
    double ry = y * M_PI / 180.0;
    printf("%d degrees = %.6g radians\n", x, rx);
    printf("%d degrees = %.6g radians\n", y, ry);
    printf("%.6g radians = %.6g degrees\n", rx, rx * 180.0 / M_PI);
    printf("%.6g radians = %.6g degrees\n", ry, ry * 180.0 / M_PI);
}

void deg(int x, int y)
{
    double dx = (double)x * 180.0 / M_PI;
    double dy = (double)y * 180.0 / M_PI;
    printf("%d (interpreted as radians) = %.6g degrees\n", x, dx);
    printf("%d (interpreted as radians) = %.6g degrees\n", y, dy);
}

void sin_x(int x, int y)
{
    double rad_x = x * M_PI / 180.0;
    printf("sin(%d degrees) = %.6g\n", x, sin(rad_x));
}

void cos_x(int x, int y)
{
    double rad_x = x * M_PI / 180.0;
    printf("cos(%d degrees) = %.6g\n", x, cos(rad_x));
}

void tan_x(int x, int y)
{
    double rad_x = x * M_PI / 180.0;
    printf("tan(%d degrees) = %.6g\n", x, tan(rad_x));
}

void sin_y(int x, int y)
{
    double rad_y = y * M_PI / 180.0;
    printf("sin(%d degrees) = %.6g\n", y, sin(rad_y));
}

void cos_y(int x, int y)
{
    double rad_y = y * M_PI / 180.0;
    printf("cos(%d degrees) = %.6g\n", y, cos(rad_y));
}

void tan_y(int x, int y)
{
    double rad_y = y * M_PI / 180.0;
    printf("tan(%d degrees) = %.6g\n", y, tan(rad_y));
}
