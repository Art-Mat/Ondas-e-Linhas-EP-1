#include "line_simulation.h"
#include <stdio.h>

double reflection_time(double length, double velocity)
{       
        return 2 * length / velocity;
}

double voltage_divisor(line_type type)
{
	if(type == LOSSLESS)
		return GENERATOR_VOLTAGE * LINE_RESISTANCE / (NO_LOSS_LINE_GENERATOR_RESISTANCE + LINE_RESISTANCE);
	
	return GENERATOR_VOLTAGE * LINE_RESISTANCE / (LOSSY_LINE_GENERATOR_RESISTANCE + LINE_RESISTANCE);
}

double gen_reflection_coefficient(line_type type)
{
	if(type == LOSSLESS)
		return (NO_LOSS_LINE_GENERATOR_RESISTANCE - LINE_RESISTANCE) / (NO_LOSS_LINE_GENERATOR_RESISTANCE + LINE_RESISTANCE);

	return (LOSSY_LINE_GENERATOR_RESISTANCE - LINE_RESISTANCE) / (LOSSY_LINE_GENERATOR_RESISTANCE + LINE_RESISTANCE);
}

double gen_voltage_bef_first_reflection(line_type type)
{
	return voltage_divisor(type);
}

double gen_voltage_right_after_first_reflection(line_type type)
{
	//printf("voltage_divisor = %f\n", voltage_divisor(type));
	printf("reflection_coefficient: %f\n", gen_reflection_coefficient(type));
	return voltage_divisor(type) * (-1) * gen_reflection_coefficient(type);
}

double gen_voltage_permanent()
{
	
}

double load_voltage_permanent()
{

}

