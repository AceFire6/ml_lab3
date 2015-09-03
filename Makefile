.SUFFIXES:
.SUFFIXES: .cpp .o

CC=g++
FLAGS=-std=c++11
SOURCES=src/main.cpp src/Perceptron.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXE_NAME=ml_lab3

default: $(OBJECTS)
		$(CC) $(SOURCES) -o build/$(EXE_NAME) $(FLAGS)

.cpp.o:
		$(CC) -c $< -o $@ $(FLAGS)

clean:
		rm -f $(OBJECTS) build/$(EXE_NAME)

run: default
		cd ./build && ./$(EXE_NAME) $(ARGS)
