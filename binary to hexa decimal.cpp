#include <stdio.h>
#include <math.h>
int main() {
    long long binary, hex = 0;
    int bit, decimal = 0, i = 0;
    printf("Enter a binary number: ");
    scanf("%lld", &binary);
    while (binary > 0) {
        bit = binary % 10;
        decimal += bit * pow(2, i);
        binary /= 10;
        i++;
    }
    i = 0;
    while (decimal > 0) {
        int remainder = decimal % 16;
        hex += remainder * pow(10, i);
        decimal /= 16;
        i++;
    }
    printf("Hexadecimal: %lld\n", hex);
    return 0;
}