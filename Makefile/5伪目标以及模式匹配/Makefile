.PHONY: clean

ALLFILE= $(wildcard *.c)
OBJ    = $(patsubst %.c,%.o, $(ALLFILE))
TARGET = main

$(TARGET):$(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o:%.c
	$(CXX) -c $^ -o $@

clean:
	$(RM) $(TARGET) *.o

print: 
	echo $(patsubst %.c,%.o, $(ALLFILE))