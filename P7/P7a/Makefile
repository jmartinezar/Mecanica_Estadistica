all: P7a

P7a: Graph_P7.gp datosp7a1.txt datosp7a2.txt
	gnuplot Graph_P7.gp

p7a.exe: ResorteAgitado.cpp
	g++ ResorteAgitado.cpp -o p7a.exe

Graph_P7.gp: p7a.exe
	./p7a.exe

clean:
	del *.txt *.exe *.png
