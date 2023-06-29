#include <algorithm>
#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include "CuerpoGrano.h"
#include "FuncionesSMProyecto.h"
#include "constantesSMProyecto.h"
#include <fstream>


int main(void)
{
  double kprueba=1.0, kmprueba=1.0;
  for(int i = 0; i < NPasos; ++i)
    {
      double ti = dt*i;
      std::cout << ti << "\t" << k_fun(ti) << "\t" << kmprueba << "\n";
      kprueba += RK4_paso(ti, kprueba, dt, fun);
      
    }

  return 0;
}
