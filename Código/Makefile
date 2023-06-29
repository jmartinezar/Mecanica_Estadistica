grapha.png: graph-a.gp datos.txt
	gnuplot graph-a.gp
datos.txt: datos.o
	./datos.o>datos.txt
datos.o: OU-fluctuation-theorem-1a.cpp constantesSMProyecto.h CuerpoGrano.h FuncionesSMProyecto.h
	g++ -O3 -g -fsanitize=address -fsanitize=undefined -fsanitize=leak OU-fluctuation-theorem-1a.cpp constantesSMProyecto.h CuerpoGrano.h FuncionesSMProyecto.h -o datos.o
datos-prueba.txt: datos-prueba.o
	./datos-prueba.o > datos-prueba.txt
datos-prueba.o: prueba.cpp constantesSMProyecto.h CuerpoGrano.h FuncionesSMProyecto.h
	g++ -O3 -g -fsanitize=address -fsanitize=undefined -fsanitize=leak prueba.cpp constantesSMProyecto.h CuerpoGrano.h FuncionesSMProyecto.h -o datos-prueba.o
clean:
	rm *.o *.txt *~ *.out
