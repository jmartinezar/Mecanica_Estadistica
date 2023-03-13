Gif: P7c.gp
	gnuplot P7c.gp

P7c.exe: trabajo_V2.cpp
	g++ trabajo_V2.cpp -o P7c.exe

P7c.gp: P7c.exe
	P7c.exe > P7c.gp

clean:
	del *.gif *.exe *.gp
