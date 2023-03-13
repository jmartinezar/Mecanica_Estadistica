#include <iostream>
#include <fstream>
#include <cmath>
#include "Vector.h"

using namespace std;

const double CHI   =0.1786178958448091;
const double LAMBDA=-0.2123418310626054;
const double XI    =-0.06626458266981849;
const double uno_m2LAMBDA_S2=(1-2*LAMBDA)/2;
const double uno_m2_XIplusCHI=(1-2*(XI+CHI));

//------------------------- CLASE CUERPO -------------------------------
class Cuerpo{
private:
  double x,Vx,Fx;
  double k,m,R; 
public:
  void Inicie(double x0,double Vx0,double k0,double m0,double R0);
  void CalculeFuerza(double xs);
  void Mueva_r(double dt,double CTE);
  void Mueva_V(double dt,double CTE);
  void Dibujese(void);
  double Getx(void){return x;};
  double GetPx(void){return m*Vx;};
};	
void Cuerpo::Inicie(double x0,double Vx0,double k0,double m0,double R0){
  x=x0; Vx=Vx0; k=k0; m=m0; R=R0;
}
void Cuerpo::CalculeFuerza(double xs){
  Fx=-k*(x-xs);
}
void Cuerpo::Mueva_r(double dt,double CTE){
  x+=Vx*(CTE*dt);
}
void Cuerpo::Mueva_V(double dt,double CTE){
  Vx+=Fx*(CTE*dt/m);
}
void Cuerpo::Dibujese(void){
  cout<<", "<<x<<"+"<<R<<"*cos(t),"<<m*Vx<<"+"<<R<<"*sin(t)";
}

//------------------------- PROGRAMA PRINCIPAL -------------------------

int main(void)
{
  double MResorte=1.0, KResorte=1.0;
  double OmegaResorte=sqrt(MResorte/KResorte);
  double XResorte=1.5,PResorte=0.0,VResorte=PResorte/MResorte,xs=0;
  double A = XResorte, B = PResorte/(OmegaResorte*MResorte);
  Cuerpo Resorte;

  // Fstream

  ofstream myfile("datosp7a1.txt");

  ofstream myfile2("datosp7a2.txt");

  // PARAMETROS DE TIEMPO
  double t,Deltat;
  double T,tmax,tdibujo;
  int ndibujos=10000;
  T=2*M_PI/OmegaResorte;  tmax=10*T; Deltat=T/2000;  tdibujo=tmax/ndibujos;

  Resorte.Inicie(XResorte, VResorte, KResorte, MResorte, 0.05);
  //  InicieAnimacion(XResorte, PResorte);

  for(t=0,tdibujo=0; t<tmax; t+=Deltat,tdibujo+=Deltat){
    myfile<<Resorte.Getx()<<" "<<Resorte.GetPx()<<endl;
    //Mover el resorte por PEFRL
    Resorte.Mueva_r(Deltat,CHI);
    Resorte.CalculeFuerza(xs); Resorte.Mueva_V(Deltat,uno_m2LAMBDA_S2);
    Resorte.Mueva_r(Deltat,XI);
    Resorte.CalculeFuerza(xs); Resorte.Mueva_V(Deltat,LAMBDA); 
    Resorte.Mueva_r(Deltat,uno_m2_XIplusCHI);
    Resorte.CalculeFuerza(xs); Resorte.Mueva_V(Deltat,LAMBDA); 
    Resorte.Mueva_r(Deltat,XI);
    Resorte.CalculeFuerza(xs); Resorte.Mueva_V(Deltat,uno_m2LAMBDA_S2);
    Resorte.Mueva_r(Deltat,CHI);
  }

  double ti = 0;
  double h = M_PI*sqrt(MResorte/KResorte)/1000.0;
  for(int i = 0; i < 2000; ++i)
    {
      ti = i*h;
      myfile2 << A*cos(OmegaResorte*ti)+B*sin(OmegaResorte*ti) << "\t" << -A*OmegaResorte*MResorte*sin(OmegaResorte*ti)+B*OmegaResorte*MResorte*cos(OmegaResorte*ti) << "\n";
    }

  return 0;
}
