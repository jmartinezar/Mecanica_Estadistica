#ifndef _CUERPOGRANO_H_
#define _CUERPOGRANO_H_

#include <algorithm>
#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include "constantesSMProyecto.h"
#include "FuncionesSMProyecto.h"

//---------------------- Cuerpo - Grano de polen --------------------------------------------

// Se establecen los granos como cuerpos que se definen a través de los valores de la posición, x, y la constante del resorte, k.

class Grano{
private:
  double x;
public:
  void Inicie(double x0);
  void DarPaso(double t);
  double Getx(void){return x;};//El grano puede mostrar su posición.
};

// El grano puede ser inicializado, asignando un valor numérico a cada una de estas variables que lo definen, esto se hace con la función Inicie

void Grano::Inicie(double x0)
{
  x = x0;
}

// El grano puede moverse a través del tiempo, su posición siguiente está determinada por la solución al problema de Ornstein-Uhlenbeck

void Grano::DarPaso(double t)
{
  double media = x*std::exp(-t/tau);
  double desvest = std::sqrt((kB*T/k_fun(t))*(1-std::exp(-2*t/tau)));
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<double> distribution(media, desvest);
  x = distribution(gen);
}


#endif
