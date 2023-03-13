set size ratio -1
set samples 1000
set term png
set output "P7a.png"

plot 'datosp7a1.txt' t 'Simulación', 'datosp7a2.txt' t 'Curva paramétrica'