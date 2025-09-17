#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ex_params.h"
#include "line_simulation.h"

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("Forneça um NUSP\n");
		exit(1);
	}

	// Saves student NUSP to calculate circuit parameters
	long int nusp = strtol(argv[1], NULL, 10);

	ex_parameters* nusp_params = construct_params(nusp);
	
	//double ref_time = reflection_time(nusp_params->line_length, nusp_params->prop_velocity);

	printf("LINHA SEM PERDAS\n\n");
	printf("----------- TENSÃO NA ENTRADA DA LINHA PARA A PRIMEIRA REFLEXÃO -----------\n");
	printf("Antes da reflexão no gerador: %f [V]\n", gen_voltage_bef_first_reflection(LOSSLESS));
	printf("Depois da reflexão no gerador: %f [V]\n", gen_voltage_right_after_first_reflection(LOSSLESS));
	printf("\n");
	printf("----------- TENSÕES DA LINHA PARA REGIME PERMANENTE -----------\n");
	printf("Como a carga da linha é um capacitor, em regime permanente teremos um aberto\n");
	printf("V_1(t->inf): %f [V]\n", GENERATOR_VOLTAGE);
	printf("V_2(t->inf): %f [V]\n", GENERATOR_VOLTAGE);
	printf("\n");
	double time_constant = LINE_RESISTANCE * nusp_params->capacitance;
	printf("Constante de tempo: %f ns\n", time_constant * 1e9);
	printf("V_1(0.39999us): %f [V]\n", voltage_divisor(LOSSLESS) * (2 - 2 * exp(-0.19999 * 1e-6 / time_constant) + gen_reflection_coefficient(LOSSLESS) * (1 - 2 * exp(-0.19999 * 1e-6 / time_constant))));

	printf("\n\n");
	printf("LINHA COM PERDAS E SEM DISTORÇÃO (CONDIÇÃO DE HEAVISIDE)\n");
	printf("----------- PARÂMETROS -----------\n");
	double inductance = (LINE_RESISTANCE / nusp_params->prop_velocity);
	printf("Indutância: %f nH/m \n", inductance * 1e9);
	double capacitance = 1 / (LINE_RESISTANCE * nusp_params->prop_velocity);
	printf("Capacitância: %f pF/m \n", capacitance * 1e12);
	printf("Resistência: %f Ohm/m \n", inductance * nusp_params->attenuation * nusp_params->prop_velocity);
	printf("Condutância: %f mS/m \n", capacitance * nusp_params->attenuation * nusp_params->prop_velocity * 1e3);

	printf("\n");
	printf("QUESTÃO 2\n");
	// Como os parâmetros Z_0 e v da linha se mantêm os mesmos da anterior, podemos reutilizar C e L
	printf("C_10: %f pF\n", capacitance * (nusp_params->line_length / 10) * 1e12);
	printf("C_20: %f pF\n", capacitance * (nusp_params->line_length / 20) * 1e12);
	printf("L_10: %f nH\n", inductance * (nusp_params->line_length / 10) * 1e9);
	printf("L_20: %f nH\n", inductance * (nusp_params->line_length / 20) * 1e9);
	

	free(nusp_params);

	return 0;
}
