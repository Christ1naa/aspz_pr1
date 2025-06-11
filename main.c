#include <stdio.h>
#include <stdlib.h>
#include "erf_module.h"

int main() {
    double z;
    int dof;
    int interval_choice;

    printf("Enter Z-score: ");
    if (scanf("%lf", &z) != 1) {
        fprintf(stderr, "Invalid input for Z-score!\n");
        return 1;
    }

    printf("Enter degrees of freedom (e.g. 30): ");
    if (scanf("%d", &dof) != 1 || dof <= 0) {
        fprintf(stderr, "Invalid input for degrees of freedom!\n");
        return 1;
    }

    printf("Select confidence interval:\n");
    printf("1. 90%%\n2. 95%%\n3. 99%%\n");
    if (scanf("%d", &interval_choice) != 1 || interval_choice < 1 || interval_choice > 3) {
        fprintf(stderr, "Invalid confidence level selection!\n");
        return 1;
    }

    switch (interval_choice) {
        case 1: z = 1.645; break;
        case 2: z = 1.96;  break;
        case 3: z = 2.576; break;
    }

    double normal_interval = compute_confidence_interval(z);
    double t_interval = compute_student_t_interval(z, dof);

    printf("Normal distribution CI area (approx): %.4f\n", normal_interval);
    printf("Student's t-distribution CI area (approx): %.4f\n", t_interval);

    return 0;
}
