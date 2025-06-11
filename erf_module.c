#include "erf_module.h"
#include <math.h>
#include <stdio.h>
#include <errno.h>

double compute_erf(double z) {
    errno = 0;
    double result = erf(z * sqrt(0.5));
    if (errno != 0) {
        perror("Error computing erf");
        return -1;
    }
    return result;
}

// Normal distribution confidence interval: area between -z and z
double compute_confidence_interval(double z) {
    return compute_erf(z);
}

// Simplified Student's t-distribution approximation
double compute_student_t_interval(double z, int dof) {
    // For simplicity, assume same as normal when dof > 30
    // A full implementation would use `tgamma` and more logic
    if (dof > 30) return compute_erf(z);
    // Fake approximation for demo
    return compute_erf(z * (1 - 1.0 / (4 * dof)));
}
