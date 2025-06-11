#ifndef ERF_MODULE_H
#define ERF_MODULE_H

double compute_erf(double z);
double compute_confidence_interval(double z);
double compute_student_t_interval(double z, int dof); // dof = degrees of freedom

#endif
