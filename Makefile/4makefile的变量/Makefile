OBJ=main.o Add.o
TARGET=main

${TARGET}: ${OBJ}
	CXX ${OBJ} -o ${TARGET}

Add.o: Add.c
	CXX -c $^
main.o: main.c
	CXX -c $^

clean:
	RM *.o $(TARGET)
