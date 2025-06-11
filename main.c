#include <stdio.h>
#include <stdlib.h>
#include "erf_module.h"

int main() {
    double z;
    int confidence;

    printf("Enter Z-score: ");
    if (scanf("%lf", &z) != 1) {
        fprintf(stderr, "Invalid input for Z-score!\n");
        return 1;
    }

    printf("Enter confidence level (90, 95, 99): ");
    if (scanf("%d", &confidence) != 1 || (confidence != 90 && confidence != 95 && confidence != 99)) {
        fprintf(stderr, "Invalid confidence level! Choose 90, 95, or 99.\n");
        return 1;
    }

    double prob = normal_probability(z);
    if (prob < 0.0) {
        fprintf(stderr, "Error computing probability.\n");
        return 1;
    }

    printf("Probability between -Z and Z for N(0,1): %.6f\n", prob);
    printf("Confidence interval for %d%%: %.2f%%\n", confidence, prob * 100);

    // Для демонстрації: студентський розподіл (df=40)
    double t = z; // для простої симуляції
    double p_student = student_probability(t, 40);
    if (p_student > 0)
        printf("Approximate probability for Student's t (df=40): %.6f\n", p_student);

    return 0;
}
