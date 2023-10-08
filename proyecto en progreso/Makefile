all: prog

prog: archivosCPP/loopConUsuario.cpp main.cpp archivosCPP/operarArchivo.cpp archivosCPP/operarVector.cpp archivosCPP/procEntrada.cpp archivosCPP/vectorPermisos.cpp archivosCPP/procesarCuento.cpp
	g++ -fopenmp archivosCPP/loopConUsuario.cpp main.cpp archivosCPP/operarArchivo.cpp archivosCPP/operarVector.cpp archivosCPP/procEntrada.cpp archivosCPP/vectorPermisos.cpp archivosCPP/procesarCuento.cpp -o prog

clean:
	rm -f prog
