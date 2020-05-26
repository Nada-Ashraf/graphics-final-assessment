SRCS := $(shell find *.cpp)
TARGET_EXEC ?= project
FLAGS ?= -g -lGL -lglut -lGLU -lm
CC = g++

compile:
	$(CC) $(SRCS) -o $(TARGET_EXEC) $(FLAGS)
clean:
	$(RM) -rf $(TARGET_EXEC)