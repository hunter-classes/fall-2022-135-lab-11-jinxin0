OBJS = profile.o

main: main.o ${OBJS}
	g++ -o main main.o ${OBJS}

tests: tests.o ${OBJS}
	g++ -o tests tests.o ${OBJS}

profile.o: profile.cpp profile.h

main.o: main.cpp

tests.o: tests.cpp

clean:
	rm -f *.o
