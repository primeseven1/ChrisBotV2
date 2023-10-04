CXX = g++ -c
CC = gcc -c
LD = gcc

C_FLAGS = -g -I ./include -MMD -MP
CXX_FLAGS = -g -I ./include -std=c++17 -MMD -MP
LD_FLAGS = -L ./lib -lstdc++ -Wl,-rpath=../lib -ldpp

CXX_SRC := $(shell find ./src/ -type f -name *.cpp)
CXX_OBJ := $(patsubst %.cpp, %.o, $(CXX_SRC))
CXX_DEPENDENCIES := $(patsubst %.o, %.d, $(CXX_OBJ))
C_SRC := $(shell find ./src/ -type f -name *.c)
C_OBJ := $(patsubst %.c, %.o, $(C_SRC))
C_DEPENDENCIES := $(patsubst %.o, %.d, $(C_OBJ))

OUTPUT = ./chris_bot

ifeq ($(TARGET), release)
	C_FLAGS = -O2 -I ./include -MMD -MP
	CXX_FLAGS = -O2 -I ./include -std=c++17 -MMD -MP
endif

all: $(OUTPUT)

$(OUTPUT): ./include/bot/pch.h.gch $(CXX_OBJ) $(C_OBJ)
	$(LD) $(LD_FLAGS) $(CXX_OBJ) $(C_OBJ) -o $(OUTPUT) -O2

-include $(CXX_DEPENDENCIES) $(C_DEPENDENCIES)

./include/bot/pch.h.gch: ./include/bot/pch.h
	g++ -x c++-header -std=c++17 $< -o $@ -I ./include

%.o: %.cpp
	$(CXX) $(CXX_FLAGS) $< -o $@ -Wall

%.o: %.c
	$(CC) $(C_FLAGS) $< -o $@ -Wall

clean:
	rm -f $(CXX_OBJ) $(C_OBJ) $(C_DEPENDENCIES) $(CXX_DEPENDENCIES) $(OUTPUT)