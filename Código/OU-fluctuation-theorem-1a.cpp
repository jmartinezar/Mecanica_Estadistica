//---------------------- LIBRERÍAS --------------------------------------------

#include <algorithm>
#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include "CuerpoGrano.h"
#include "FuncionesSMProyecto.h"
#include "constantesSMProyecto.h"
#include <fstream>
  
//---------------------- Función principal --------------------------------------------

int main(void)
{
  //Se definen la posición inicial de los granos a simular 
  double x = x0;

  //Se inicia la simulación de los granos de polen
  Grano Polen[N];

  //Se inicializa cada grano con los valores correspondiente
  for(int i = 0; i < N; ++i)
    {
      Polen[i].Inicie(x);
    }

//Se inicializan variables correspondientes a el trabajo, la energía interna, la entropía y el calor
  double W_T = 0.0, U_T = 0.0, S_T = 0.0, W_aux = 0.0, U_aux = 0.0, S_aux = 0.0;
  
 // Simulación de los granos siendo llevados por el resorte a su posición de equilibrio
  double k_monho = k0;
  for (int paso = 0; paso < NPasos; ++paso) {
    double t = paso * dt; // Tiempo del paso actual
    for (int i = 0; i < N; ++i) {
      double aux = Polen[i].Getx();
      Polen[i].DarPaso(t); // Obtener nueva posición
      

      //Calcular el trabajo hasta el momento
      W_T += RK4_paso(t, k_monho, dt, DeltaWd)/N;
      //Calcular la energía interna hasta el momento
      U_T = 0.5*(k_fun(t)*Polen[i].Getx()*Polen[i].Getx() - k0*x0*x0)/(double)N;
      //std::cout << t << "\t" << k_fun(t) << "\t" << k_monho << "\n";
      //Calcular la entropía hasta el momento
      S_T += RK4_paso(t, k_monho, dt, DeltaS)/(double)N;

      if(i == N-1)
	{
	  k_monho += RK4_paso(t, k_monho, dt, fun);
	  std::cout << t << "\t" << W_T << "\t" << U_T - W_T << "\t" << S_T << "\t" << std::exp(-S_T/kB) << "\t" << k_monho << "\t" << k_fun(t) << "\n";
	}
    } 
  }

  return 0;
}
