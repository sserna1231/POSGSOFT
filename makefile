programa: main.o evaluacion.o colaborador.o estudiante.o acta.o sistema.o
	g++ -o posg.exe main.o evaluacion.o colaborador.o estudiante.o \
	acta.o sistema.o
	make clean

main.o: source/main.cpp include/sistema.h
	g++ -I./include -c source/main.cpp

evaluacion.o: source/evaluacion.cpp include/evaluacion.h
	g++ -I./include -c source/evaluacion.cpp

colaborador.o: source/colaborador.cpp include/colaborador.h
	g++ -I./include -c source/colaborador.cpp

estudiante.o: source/estudiante.cpp include/estudiante.h
	g++ -I./include -c source/estudiante.cpp

acta.o: source/acta.cpp include/acta.h include/evaluacion.h include/colaborador.h include/estudiante.h
	g++ -I./include -c source/acta.cpp

sistema.o: source/sistema.cpp include/sistema.h include/evaluacion.h include/colaborador.h include/estudiante.h include/acta.h	
	g++ -I./include -c source/sistema.cpp

clean:
	del main.o evaluacion.o colaborador.o estudiante.o acta.o sistema.o