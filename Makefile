TARGET=./main
CC=g++
SRCS=\
	./main.cpp \
	./test/CPUTime.cpp

STD=-std=c++17
WER=-Wall -Wextra -Werror -ansi

all: clean $(TARGET)

$(TARGET): 
	$(CC) $(WER) -O3 $(STD) -lm -o $(TARGET) $(SRCS)

build: $(TARGET)

clean:
	rm -rf $(TARGET)
