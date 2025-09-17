#include "ex_params.h"
#include <stdlib.h>

ex_parameters* construct_params(long int nusp)
{
        ex_parameters* nusp_params = malloc(sizeof(ex_parameters));
        double last_3 = nusp % 1000;

        nusp_params->capacitance = (1 + last_3 * 0.001) * 1e-9;
        nusp_params->prop_velocity = (2 + last_3 * 0.001) * 1e8;
        nusp_params->line_length = 20 + last_3 * 0.01;
        nusp_params->resistance = 400 + last_3 * 0.1;
	nusp_params->attenuation = (7 + last_3 * 0.001)* 1e-3;

        return nusp_params;
}
