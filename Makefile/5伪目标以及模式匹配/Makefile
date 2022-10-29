.PHONY: clean

OBJ    = Add.o Sub.o main.o
TARGET = main

$(TARGET):$(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o:%.c
	$(CXX) -c $^ -o $@

clean:
	$(RM) $(TARGET) *.o
