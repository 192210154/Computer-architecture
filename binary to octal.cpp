#include <stdio.h>

int main() {
    long long binary, octal = 0;
    int octalDigit = 0, placeValue = 1;

    printf("Enter a binary number: ");
    scanf("%lld", &binary);

    while (binary != 0) {
        int bit = binary % 1000; // Extract 3 binary digits at a time.
        while (bit != 0) {
            int digit = bit % 10;
            octalDigit += digit * placeValue;
            placeValue *= 2;
            bit /= 10;
        }
        octal = octalDigit + octal * 10;
        placeValue = 1;
        binary /= 1000;
        octalDigit = 0;
    }

    printf("The octal equivalent is: %lld\n", octal);

    return 0;
}
