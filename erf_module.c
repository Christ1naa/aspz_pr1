#include <math.h>
#include <stdio.h>
#include "erf_module.h"

// Обчислення ймовірності для стандартного нормального розподілу
double normal_probability(double z) {
    return erf(z / sqrt(2.0));
}

// Спрощена симуляція t-розподілу (наближення для великих df)
double student_probability(double t, int df) {
    // Для df > 30 наближається до нормального
    if (df > 30)
        return erf(t / sqrt(2.0));
    else {
        fprintf(stderr, "Student's t-distribution not implemented for df <= 30\n");
        return -1;
    }
}
