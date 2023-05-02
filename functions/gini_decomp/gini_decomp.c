#include <stdio.h>
#include <stdlib.h>

// Define a function to compute the Gini coefficient
// scale factor should be in the input
void computeGiniCoefficient(int values[], int length, int* out) {
    // First value of the array is scaleFactor
    int M = values[0];
    int v = values[1];
    int s = values[2];
    double numerator = 0.0;
    int i, j;
    
    // Calculate the numerator of the Gini coefficient
    for (i = 3; i < length; i++) {
        for (j = 4; j < length; j++) {
            numerator += abs(values[i] - values[j]);
        }
    }
    
    // Place the Gini coefficient
    // Implicit type conversion to int
    
    out[0] = ((numerator * s) / ((length - 3) * abs(M)));
}

void run_function(int* in, int in_length, int* out, int out_length) {
    computeGiniCoefficient(in, in_length, out);
}