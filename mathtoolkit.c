#include <stdio.h>
#include<math.h>


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


void sum(int   arr[], int n);
void sub(int   arr[], int n);
void mul(int   arr[], int n);
void divi(int  arr[], int n);
void mod(int   arr[], int n);
void powe(int  arr[], int n);
void sqr_x(int arr[], int n);
void sqr_y(int arr[], int n);
void avg(int   arr[], int n);
void fac_x(int arr[], int n);
void fac_y(int arr[], int n);
void tri(int   arr[], int n);
void rad(int   arr[], int n);
void deg(int   arr[], int n);
void sin_x(int arr[], int n);
void cos_x(int arr[], int n);
void tan_x(int arr[], int n);
void sin_y(int arr[], int n);
void cos_y(int arr[], int n);
void tan_y(int arr[], int n);



int main(void) {
    int choice;
    

    {
    void (*ptr[20])(int [], int) = {
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

        int n;
        printf("How many numbers do you want to enter? ");
        if (scanf("%d", &n) != 1 || n <= 0) break;

        int numbers[n];
        for (int i = 0; i < n; i++) {
            printf("Enter number %d: ", i + 1);
            if (scanf("%d", &numbers[i]) != 1) break;
        }

    

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

    (*ptr[choice])(numbers, n);
        printf("\n");
    }
  }
    return 0;
    
}




void sum(int arr[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++) total += arr[i];
    printf("Sum is: %d\n", total);
}

void sub(int arr[], int n)
{
    if (n == 0) return;
    int total = arr[0];
    for (int i = 1; i < n; i++) total -= arr[i];
    printf("Subtraction is: %d\n", total);
}

void mul(int arr[], int n)
{
    int total = 1;
    for (int i = 0; i < n; i++) total *= arr[i];
    printf("Multiplication is: %d\n", total);
}

void divi(int arr[], int n)
{
    if (n == 0) return;
    double total = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] == 0) { printf("Division by zero!\n"); return; }
        total /= arr[i];
    }
    printf("Division result: %.6g\n", total);
}

void mod(int arr[], int n)
{
    if (n == 0) return;
    int total = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] == 0) { printf("Modulus by zero!\n"); return; }
        total %= arr[i];
    }
    printf("Modulus result: %d\n", total);
}

void powe(int arr[], int n)
{
    if (n == 0) return;
    double total = arr[0];
    for (int i = 1; i < n; i++) total = pow(total, arr[i]);
    printf("Power result: %.6g\n", total);
}

void sqr_x(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) printf("Square root of %d is undefined\n", arr[i]);
        else printf("Square root of %d: %.6g\n", arr[i], sqrt(arr[i]));
    }
}

void sqr_y(int arr[], int n)
{
    { sqr_x(arr, n); }
}

void avg(int arr[], int n)
{
    if (n == 0) return;
    double total = 0;
    for (int i = 0; i < n; i++) total += arr[i];
    printf("Average is: %.6g\n", total / n);
}

void fac_x(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0  || arr[i]>20) { printf("Factorial of %d is undefined\n", arr[i]); continue; }
        unsigned long long f = 1;
        for (int j = 1; j <= arr[i]; j++) f *= j;
        printf("Factorial of %d: %llu\n", arr[i], f);
    }
}

void fac_y(int arr[], int n)
{
     fac_x(arr, n);
}

void tri(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        double rad = arr[i] * M_PI / 180.0;
        printf("Trigonometry of %d degrees: sin=%.6g cos=%.6g tan=%.6g\n", arr[i], sin(rad), cos(rad), tan(rad));
    }
}

void rad(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        double r = arr[i] * M_PI / 180.0;
        printf("%d degrees = %.6g radians, %.6g radians = %.6g degrees\n", arr[i], r, r, r * 180.0 / M_PI);
    }
}

void deg(int arr[], int n)
{
    rad(arr, n);
}

void sin_x(int arr[], int n)
{
    for (int i = 0; i < n; i++) 
    printf("sin(%d degrees) = %.6g\n", arr[i], sin(arr[i]*M_PI/180));
}

void cos_x(int arr[], int n)
{
    for (int i = 0; i < n; i++) 
    printf("cos(%d degrees) = %.6g\n", arr[i], cos(arr[i]*M_PI/180));
}

void tan_x(int arr[], int n)
{
    for (int i = 0; i < n; i++)
     printf("tan(%d degrees) = %.6g\n", arr[i], tan(arr[i]*M_PI/180));
}

void sin_y(int arr[], int n)
{
    sin_x(arr, n);
}

void cos_y(int arr[], int n)
{
    cos_x(arr, n);
}

void tan_y(int arr[], int n)
{
    tan_x(arr, n);
}
