/* Experiment 1: Variables, data types, arithmetic operators and formatted I/O.
 * Applications: rectangle area/perimeter and temperature conversion.
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
    const int experiment_number = 1; /* int stores a whole number. */
    double length, width, area, perimeter; /* double supports decimals. */
    double temperature, converted_temperature;
    char scale; /* char stores one character, such as C or F. */

    printf("Experiment %d: Measurements and temperature\n", experiment_number);
    printf("\nRECTANGLE\n");
    printf("Enter length and width in the same unit (example: 5 3): ");
    fflush(stdout);

    /* scanf returns the number of values it successfully reads.
     * %lf reads a double; & tells scanf where to store that value.
     */
    if (scanf("%lf %lf", &length, &width) != 2) {
        printf("Invalid input: enter two numbers.\n");
        return 1;
    }

    /* A generous upper limit keeps subsequent arithmetic in range. */
    if (!isfinite(length) || !isfinite(width) ||
        length <= 0.0 || width <= 0.0 || length > 1e100 || width > 1e100) {
        printf("Invalid dimensions: each must be greater than 0 and at most 1e100.\n");
        return 1;
    }

    area = length * width;
    perimeter = 2.0 * (length + width);
    printf("Area = %.2f square units\n", area);
    printf("Perimeter = %.2f units\n", perimeter);

    printf("\nTEMPERATURE\n");
    printf("Enter a temperature followed by its scale (example: 25 C or 77 F): ");
    fflush(stdout);

    /* The space before %c skips whitespace, including a leftover newline. */
    if (scanf("%lf %c", &temperature, &scale) != 2) {
        printf("Invalid input: enter a number followed by C or F.\n");
        return 1;
    }

    if (!isfinite(temperature) || temperature < -1e100 || temperature > 1e100) {
        printf("Invalid temperature: enter a finite number from -1e100 to 1e100.\n");
        return 1;
    }

    if (scale == 'C' || scale == 'c') {
        converted_temperature = temperature * (9.0 / 5.0) + 32.0;
        printf("%.2f C = %.2f F\n", temperature, converted_temperature);
    } else if (scale == 'F' || scale == 'f') {
        converted_temperature = (temperature - 32.0) * (5.0 / 9.0);
        printf("%.2f F = %.2f C\n", temperature, converted_temperature);
    } else {
        printf("Invalid scale: use C for Celsius or F for Fahrenheit.\n");
        return 1;
    }

    return 0; /* Zero reports successful completion to the operating system. */
}
