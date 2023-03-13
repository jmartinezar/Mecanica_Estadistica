#include <iostream>
#include <cmath>
#include "Random64.h"

void GeneraCondicionInicial(double Masa, double Kresorte, double & x0,
			    double & Px0, double XmaxResorte, double PmaxResorte, 
			    double Enmin, double deltaE, Crandom & ran64){
  bool FueraDelAnillo=true; double E; 
  do{
    x0=(2*ran64.r()-1)*XmaxResorte;
    Px0=(2*ran64.r()-1)*PmaxResorte;
    E=(Px0*Px0/Masa+Kresorte*x0*x0)/2;
    if (E>Enmin && E<(Enmin+deltaE)) FueraDelAnillo=false;
  }while(FueraDelAnillo);
}

int main(){

  Crandom ran64(0);

  //Inicializa el sistema -------------------------------------------------

  //Constantes del sistema
  
  double MResorte=1.0, KResorte=1.0;

  int N = 400;

  //Rangos de energía
  
  double Emin=10, DeltaE=4.0;

  //Rangos de posición
  
  double Xmax=sqrt(2*(Emin+DeltaE)/KResorte), Pmax=sqrt(2*MResorte*(Emin+DeltaE));

  
  double X, P;

  //Generar estados
  for(int i = 0; i < N; ++i)
    {
      GeneraCondicionInicial(MResorte, KResorte, X, P, Xmax, Pmax, Emin, DeltaE, ran64);
      std::cout << X << "\t" << P << "\n";
    }
  
  return 0;
}
