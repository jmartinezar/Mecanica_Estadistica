#ifndef _CONSTANTESSMPROYECTO_H_
#define _CONSTANTESSMPROYECTO_H_

#include <iostream>

//Constante de Boltzmann
double kB = 1.0; 
//Temperatura del baño térmico
double T = 1.0; 
// Número de resortes en el sistema
int N = 50; 
//Número de pasos en los procesos numéricos
int NPasos = 500; 
//Ancho de la partición en los procesos numéricos
double dt = 0.01; 
//constante del resorte en el instante t=0
double k0 = 1.0;
//constante del resorte en el instante final
double kf = 20.0;
//masa del grano de polen (es la misma para todo t)
double masa = 1.0; 
//gamma del sistema (es la misma para todo t)
double gamma_v = 1.0; 
//tiempo característico del sistema (es la misma para todo t)
double tau = masa*gamma_v/k0;
// Tiempo inicial
double t0 = 0.0;
//Tiempo final
double tf = NPasos*dt;
//Posición inicial
double x0 = 1.0;

#endif
