all: prog

prog: src/loopConUsuario.cpp src/main.cpp src/operarArchivo.cpp \
	src/operarVector.cpp src/procEntrada.cpp \
    src/vectorPermisos.cpp src/procesarCuento.cpp
	g++ -fopenmp src/loopConUsuario.cpp src/main.cpp \
    src/operarArchivo.cpp src/operarVector.cpp \
    src/procEntrada.cpp src/vectorPermisos.cpp \
    src/procesarCuento.cpp -o prog

clean:
	rm -f prog

