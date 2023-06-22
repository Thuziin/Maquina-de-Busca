CC = c++ -I include
CXXFLAGS = -std=c++17

main: obj/main.o obj/document.o obj/index.o
	@ ${CC} ${CFLAGS} $^ -o main

obj/document.o: include/document.h src/document.cpp 
	@ ${CC} ${CFLAGS} -c src/document.cpp -o obj/document.o

obj/index.o: include/index.h src/index.cpp 
	@ ${CC} ${CFLAGS} -c src/index.cpp -o obj/index.o

obj/main.o: src/main.cpp obj/document.o obj/index.o
	@ ${CC} ${CFLAGS} -c src/main.cpp -o obj/main.o

clean:
	@ rm main obj/*.o
