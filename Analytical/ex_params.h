#ifndef EX_PARAMETERS_H
#define EX_PARAMETERS_H

typedef struct
{
	double capacitance;
	double prop_velocity;
	double line_length;
	double resistance;
	double attenuation;
} ex_parameters;

ex_parameters* construct_params(long int nusp);


#endif
