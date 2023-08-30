all: prog

prog: loopConUsuario.cpp main.cpp metodos.h operarArchivo.cpp operarVector.cpp procEntrada.cpp vectorPermisos.cpp procesarCuento.cpp
	g++ -fopenmp loopConUsuario.cpp main.cpp metodos.h operarArchivo.cpp operarVector.cpp procEntrada.cpp vectorPermisos.cpp procesarCuento.cpp -o prog

clean:
	rm -f prog
