programa: main.o evaluacion.o colaborador.o estudiante.o acta.o sistema.o
	g++ -o posg.exe main.o evaluacion.o colaborador.o estudiante.o \
	acta.o sistema.o
	make clean

main.o: main.cpp sistema.h
	g++ -I/include -c main.cpp

evaluacion.o: evaluacion.cpp evaluacion.h
	g++ -I/include -c evaluacion.cpp

colaborador.o: colaborador.cpp colaborador.h
	g++ -I/include -c colaborador.cpp

estudiante.o: estudiante.cpp estudiante.h
	g++ -I/include -c estudiante.cpp

acta.o: acta.cpp acta.h evaluacion.h colaborador.h estudiante.h
	g++ -I/include -c acta.cpp

sistema.o: sistema.cpp sistema.h evaluacion.h colaborador.h estudiante.h acta.h	
	g++ -I/include -c sistema.cpp

clean:
	del main.o evaluacion.o colaborador.o estudiante.o acta.o sistema.o