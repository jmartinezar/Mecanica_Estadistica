# Establecer el nombre del archivo de salida
set term png
set output 'Pa.png'

# Título del gráfico
set title 'Cambio de k suave'

# Etiquetas de los ejes
set xlabel 'Tiempo'
unset ylabel 

# Rango de los ejes
set xrange [0:5.2]


# Graficar los datos
plot 'datos.txt' u 1:2 w l lw 2 t 'Trabajo', 'datos.txt' u 1:3 w l lw 2 t 'Calor', 'datos.txt' u 1:4 w l lw 2 t 'Entropia', 'datos.txt' u 1:5 w l lw 2 t 'exp(-S/k_{b})'

# Guardar y mostrar el gráfico
set output
