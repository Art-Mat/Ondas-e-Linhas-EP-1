#!/bin/bash


gcc -c ex_params.c -o ex_params.o
gcc -c line_simulation.c -o line_simulation.o
gcc solve.c ex_params.o line_simulation.o -lm -Wall -ansi -pedantic -std=c99 -g -O3 -o solve

printf ' ----------- CALCULANDO PARÂMETROS DE LINHAS DE TRANSMISSÃO PARA EC 1 DE ONDAS E LINHAS -----------\n\n'

./solve 14745525

printf '\n \n ----------- CÁLCULOS FINALIZADOS. RESTA REALIZAR AS SIMULAÇÕES EM SPICE COM OS ARQUIVOS ESPECÍFICOS -----------\n'
