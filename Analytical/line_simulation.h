#ifndef LINE_SIMULATION_H
#define LINE_SIMULATION_H

#define GENERATOR_VOLTAGE 30.0
#define NO_LOSS_LINE_GENERATOR_RESISTANCE 25.0
#define LOSSY_LINE_GENERATOR_RESISTANCE 5.0
#define LINE_RESISTANCE 50.0

typedef enum line_position
{
	GENERATOR,
	LOAD,
}line_position;

typedef enum line_type
{
	LOSSLESS,
	LOSSY
}line_type;

// Returns the time it takes for the wave to return to the generator and change the output voltage
double voltage_divisor(line_type type);
double gen_reflection_coefficient(line_type type);
double reflection_time(double length, double velocity);
double gen_voltage_bef_first_reflection(line_type type);
double gen_voltage_right_after_first_reflection(line_type type);
double gen_voltage_permanent();
double load_voltage_permanent();

#endif
