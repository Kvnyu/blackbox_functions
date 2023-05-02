#include <stdio.h>
#include <stdlib.h>

// Define a function to compute the Gini coefficient
// scale factor should be in the input
void computeGiniCoefficient(int values[], int length, int* out) {
    // First value of the array is scaleFactor
    int scaleFactor = values[0];
    double sum = 0.0;
    double numerator = 0.0;
    int i, j;
    // We iterate from 1 since values[0] is the scaleFactor
    // Calculate the sum of all values
    for (i = 1; i < length; i++) {
        sum += values[i];
    }
    
    // Calculate the numerator of the Gini coefficient
    for (i = 1; i < length; i++) {
        for (j = 1; j < length; j++) {
            numerator += abs(values[i] - values[j]);
        }
    }
    
    // Place the Gini coefficient
    // Implicit type conversion to int
    out[0] = (numerator / (2 * (length - 1) * sum)) * scaleFactor;
}

void run_function(int* in, int in_length, int* out, int out_length) {
    computeGiniCoefficient(in, in_length, out);
}

// Define a main function to test the computeGiniCoefficient function
int main() {
    int values[] = {10000, 1, 2, 3, 4, 5};
    int length = 6;
    int out[2];
    computeGiniCoefficient(values, length, out);
    printf("Gini coefficient: %d\n", out[0]);
    return 0;
}