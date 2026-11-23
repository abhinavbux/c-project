#include "../input.h"

int main(void)
{
    char text[256];
    if (!read_line("Enter text (up to 255 characters): ", text, sizeof text)) {
        return 1;
    }
    int length = 0, vowels = 0, consonants = 0, digits = 0, spaces = 0;
    while (text[length] != '\0') {
        unsigned char c = (unsigned char)text[length];
        if (c >= 'A' && c <= 'Z') {
            c = (unsigned char)(c - 'A' + 'a');
        }
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            ++vowels;
        } else if (c >= 'a' && c <= 'z') {
            ++consonants;
        } else if (c >= '0' && c <= '9') {
            ++digits;
        } else if (c == ' ') {
            ++spaces;
        }
        ++length;
    }
    printf("Length = %d\nVowels = %d\nConsonants = %d\nDigits = %d\nSpaces = %d\n",
           length, vowels, consonants, digits, spaces);

    int palindrome = 1;
    for (int i = 0; i < length / 2; ++i) {
        if (text[i] != text[length - 1 - i]) {
            palindrome = 0;
            break;
        }
    }

    printf("Reverse: ");
    for (int i = length; i > 0; --i) {
        putchar((unsigned char)text[i - 1]);
    }
    printf("\nPalindrome: %s\n", palindrome ? "yes" : "no");
    return 0;
}
