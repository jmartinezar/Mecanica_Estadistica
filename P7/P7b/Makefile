Graph: datosp7b.txt
	gnuplot GraphP7b.gp

P7b.exe: P7b.cpp
	g++ P7b.cpp -o P7b.exe

datosp7b.txt: P7b.exe
	P7b.exe > datosp7b.txt

clean:
	del *.png
