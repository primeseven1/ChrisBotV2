CXX = g++ -c -I ./include -std=c++17
CC = gcc -c
LD = gcc -L ./lib -lstdc++ -Wl,-rpath=../lib -ldpp

CXX_SRC := $(shell find ./src/ -type f -name *.cpp)
CXX_OBJ := $(patsubst %.cpp, %.o, $(CXX_SRC))
C_SRC := $(shell find ./src/ -type f -name *.c)
C_OBJ := $(patsubst %.c, %.o, $(C_SRC))

OUTPUT = ./bin/chris_bot

all: $(OUTPUT)

$(OUTPUT): ./include/bot/pch.h.gch $(CXX_OBJ) $(C_OBJ)
	$(LD) $(CXX_OBJ) $(C_OBJ) -o $(OUTPUT) -O2

./include/bot/pch.h.gch: ./include/bot/pch.h
	g++ -x c++-header -std=c++17 $< -o $@ -I ./include

%.o: %.cpp
	$(CXX) $< -o $@ -O2 -Wall

%.o: %.c
	$(CC) $< -o $@ -O2 -Wall

clean:
	rm -f $(CXX_OBJ) $(C_OBJ)