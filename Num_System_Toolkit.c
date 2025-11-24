#include <stdio.h>
#include <math.h>

int countDigits(int n) {
    if (n == 0) return 1;
    if (n < 0) n = -n;
    return (int)log10(n) + 1;
}

int reverseNumber(int n) {
    int rev = 0;
    while (n != 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev;
}

int isPalindrome(int n) {
    return n == reverseNumber(n);
}

int isArmstrong(int n) {
    int original = n;
    int digits = countDigits(n);
    int sum = 0;

    while (n != 0) {
        int d = n % 10;
        sum += pow(d, digits);
        n /= 10;
    }
    return sum == original;
}

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

int sumOfDigits(int n) {
    int sum = 0;
    if (n < 0) n = -n;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

long long power(int base, int exp) {
    long long result = 1;
    for (int i = 0; i < exp; i++)
        result *= base;
    return result;
}

int main() {
    int choice, num;

    while (1) {
        printf("\n==============================\n");
        printf("    NUMBER SYSTEM TOOLKIT    \n");
        printf("==============================\n");
        printf("1. Count Digits\n");
        printf("2. Reverse Number\n");
        printf("3. Check Palindrome\n");
        printf("4. Check Armstrong Number\n");
        printf("5. Check Prime Number\n");
        printf("6. Factorial\n");
        printf("7. Sum of Digits\n");
        printf("8. Even or Odd\n");
        printf("9. Power\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 10) {
            printf("Exiting...\n");
            break;
        }

        printf("Enter a number: ");
        scanf("%d", &num);

        switch (choice) {
            case 1:
                printf("Digits = %d\n", countDigits(num));
                break;
            case 2:
                printf("Reverse = %d\n", reverseNumber(num));
                break;
            case 3:
                if (isPalindrome(num))
                    printf("Palindrome!\n");
                else
                    printf("Not Palindrome.\n");
                break;
            case 4:
                if (isArmstrong(num))
                    printf("Armstrong Number!\n");
                else
                    printf("Not Armstrong.\n");
                break;
            case 5:
                if (isPrime(num))
                    printf("Prime Number!\n");
                else
                    printf("Not Prime.\n");
                break;
            case 6:
                printf("Factorial = %lld\n", factorial(num));
                break;
            case 7:
                printf("Sum of digits = %d\n", sumOfDigits(num));
                break;
            case 8:
                if (num % 2 == 0)
                    printf("Even Number!\n");
                else
                    printf("Odd Number!\n");
                break;
            case 9: {
                int exp;
                printf("Enter exponent: ");
                scanf("%d", &exp);
                printf("Result = %lld\n", power(num, exp));
                break;
            }
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

