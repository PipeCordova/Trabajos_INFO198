all: prog

prog: $(wildcard src/*.cpp)
	g++ -fopenmp $^ -o $@

clean:
	rm -f prog
