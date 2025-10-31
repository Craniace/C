#include <stdio.h>
#include <math.h>

// Function to convert binary to decimal
int binaryToDecimal(long long binary) {
    int decimal = 0, i = 0, remainder;
    while (binary != 0) {
        remainder = binary % 10;
        binary /= 10;
        decimal += remainder * pow(2, i);
        ++i;
    }
    return decimal;
}

// Function to convert decimal to binary
long long decimalToBinary(int decimal) {
    long long binary = 0;
    int remainder, i = 1;

    while (decimal != 0) {
        remainder = decimal % 2;
        decimal /= 2;
        binary += remainder * i;
        i *= 10;
    }
    return binary;
}

// Function to convert binary to Gray code
long long binaryToGray(long long binary) {
    // Convert binary to decimal first
    int decimal = binaryToDecimal(binary);

    // Perform XOR between decimal and decimal right-shifted by 1
    int grayDecimal = decimal ^ (decimal >> 1);

    // Convert Gray code back to binary representation for display
    return decimalToBinary(grayDecimal);
}

int main() {
    long long binary;

    printf("Enter a binary number: ");
    scanf("%lld", &binary);

    // Validate input
    long long temp = binary;
    while (temp > 0) {
        if (temp % 10 > 1) {
            printf("❌ Invalid input! Please enter only 0s and 1s.\n");
            return 0;
        }
        temp /= 10;
