all: prog

prog: loopConUsuario.cpp main.cpp metodos.h operarArchivo.cpp operarVector.cpp procEntrada.cpp 
	g++ -fopenmp loopConUsuario.cpp main.cpp metodos.h operarArchivo.cpp operarVector.cpp procEntrada.cpp -o prog

clean:
	rm -f prog
