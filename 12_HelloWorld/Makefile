#**********************************************************************
# Copyright (c) 2020 by William MANGOUA SOFACK
#
# Simple makefile
#
# Use: make
#
# Target:
# 	<FILE>.o . Builds <FILE>.o objetc file
# 	build . Builds ans links all sources files
# 	all . Same as build
# 	clean . remove all generated files
#
#**********************************************************************
include sources.mk

BASENAME	= executable
TARGET 		= $(BASENAME).out
OBJS = $(SRCS:.cpp=.o)
SIZE = size - Atd

#Compiler Flags
CC = g++

#C/C++ Preprocessor Flags -MD to generate dependency files
CPPFLAGS = -MD

#C/C++ program flags
CFLAGS		=	-Wall 	\
				 		-Werror
#C/C++ program Linker Flags
LDFLAGS	= -Wl,-Map=$(BASENAME).map

#Generate .i files
%.i : %.c
	$(CC) -E $(INCLUDES) $(CPPFLAGS) $^ -o $@

#Generate .asm files
%.asm : %.c
	$(CC) -S $(INCLUDES) $(CPPFLAGS) $(CFLAGS) $^ -o $@

#Generate .o files 
%.o : %.c
	$(CC) -c $(INCLUDES) $(CPPFLAGS) $< $(CFLAGS) $(LDFLAGS) $^ -o $@

#Generate target
$(TARGET) : $(OBJS)
	$(CC) $(INCLUDES) $(CFLAGS) $(LDFLAGS) $^ -o $@
	$(SIZE) $@

.PHONY : print
print :
	$(info OBJS is $(OBJS))
	$(info SRCS is $(SRCS))
	
.PHONY : build
build : all

.PHONY : all
all : $(TARGET)

.PHONY : clean
clean :
	rm -rf *.i *.asm *.o *.d *.map *.out

