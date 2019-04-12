PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
CC=gcc
CXX=g++
CFLAGS=-g
LFLAGS=-pthread -lm
OBJS=$(patsubst %.c,%.o,$(wildcard *.c))

SUPPORT_PATH=testcasesupport/
INCLUDES=$(SUPPORT_PATH)
SUPPORT_FILES=$(SUPPORT_PATH)io.c $(SUPPORT_PATH)std_thread.c
SUPPORT_OBJECTS=io.o std_thread.o

all:	main

main:	$(OBJS) $(SUPPORT_OBJECTS)
	$(CXX) $(LFLAGS) $(OBJS) $(SUPPORT_OBJECTS) -o main

%.o:	$(PROJECT_ROOT)%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

%.o:	$(PROJECT_ROOT)%.c
	$(CC) -c $(CFLAGS) -I $(INCLUDES) -o $@ $<
	
$(SUPPORT_OBJECTS): $(SUPPORT_FILES)
	$(CC) -c $(CFLAGS) -I $(INCLUDES) $(SUPPORT_PATH)$(@:.o=.c) -o $@
	
clean:
	rm -fr main *.o *.bc
