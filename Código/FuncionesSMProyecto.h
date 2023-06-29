#ifndef _FUNCIONESSMPROYECTO_H_
#define _FUNCIONESSMPROYECTO_H_

#include <iostream>
#include <cmath>
#include "constantesSMProyecto.h"

// Función que determina la constante del resorte en cualquier instante de tiempo

double k_fun(double t)
{
  if(t < 4) 
    { 
      return std::pow(std::sin(M_PI*t), 2)+1; 
    } 
  else 
    { 
      return 1.0; 
      } 
  //return k0 + ((kf - k0)/(tf - t0))*(t - t0);
}

double DeltaS(double t, double k_monho)
{
  return (kB/(masa*gamma_v))*std::pow(k_fun(t)-k_monho, 2)/k_monho;
}

//Derivada de k(t) en cualquier t

double k_punto(double t)
{
  return (k_fun(t+dt) - k_fun(t))/(2*dt);
}

double DeltaWd(double t, double k_monho)
{
  return (kB*T/2)*k_punto(t)*(std::pow(k_monho, -1) - std::pow(k_fun(t), -1));
}

//Función de laecuación diferencial

double fun(double t, double k_monho)
{
  return -2*k_monho*(k_monho - k_fun(t));
}

double RK4_paso(double t0, double & k_monho0, double h, double (*f)(double, double))
{
  double k1, k2, k3, k4, k;
  k1 = h * (f(t0, k_monho0));
  k2 = h * (f((t0+h/2), (k_monho0+k1/2)));
  k3 = h * (f((t0+h/2), (k_monho0+k2/2)));
  k4 = h * (f((t0+h), (k_monho0+k3)));
  k = (k1+2*k2+2*k3+k4)/6;
  //std::cout << t0 << "\t" << k_fun(t0) << "\t" << k_monho0 << "\n";
  return k;
}
/*
//Método Runge-Kutta 4 para resolver EDO

double RK4(double (*f)(double, double))
{
  double t0, k_monho0, tn, h, k_monhon, k1, k2, k3, k4, k;
  int i, n;
  
  t0 = t0;
  k_monho0 = k0;
  tn = tf;
  n = 1000.0;

  h = (tn-t0)/n;
;
  for(i=0; i < n; i++)
    {
      RK4_paso(t0, k_monho0, h, fun);
    }
  return k_monho0;
}
*/


#endif
