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
SIZE = size
NM = nm -S --defined --size-sort -S

#Compiler Flags
CC = g++

#C/C++ Preprocessor Flags -MD to generate dependency files
CPPFLAGS = -MD

#C/C++ program flags
#           -Wmaybe-uninitialized \ #variables declared but not initialised
#           -Wfloat-equal \ #inappropriate floating point comparisons.
#           -Wcast-qual \ #pointer is cast so as to remove a type qualifier
#           -Wshadow \ #variable declaration shadows another variable.
#           -Wbad-function-cast \ #function call cast to non-matching type.
#           -Wundef \ #undefined identifier is evaluated in #if directive
#           -Wunused-variable \ #local or static variable is unused.

CFLAGS		=	-g                      \
            -Wall                   \
            -Wmaybe-uninitialized   \
            -Wfloat-equal           \
            -Wcast-qual             \
            -Wshadow                \
            -Wundef                 \
            -Wunused-variable       \
				 		-Werror                 \
            -O0                     \
            -std=c++11              \
            --short-enums

#C/C++ program Linker Flags
LDFLAGS	= -Wl,-Map=$(BASENAME).map

#Generate .i files
%.i : %.cpp
	$(CC) $(CPPFLAGS) -E $^ -I $(INCLUDES) -o $@

#Generate .asm files
%.asm : %.cpp
	$(CC) $(CPPFLAGS) $(CFLAGS) -S $^ -I $(INCLUDES) -o $@

#Generate .o files 
%.o : %.cpp
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -c $^ -I $(INCLUDES) -o $@

#Generate target
$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -I $(INCLUDES) -o $@
	$(NM) $@
	$(SIZE) -Adt $@
	$(SIZE) $@

.PHONY : print
print :
	$(info OBJS is $(OBJS))
	$(info SRCS is $(SRCS))
	$(info CC is $(CC))
	$(info INCLUDES is $(INCLUDES))
	$(info CFLAGS is $(CFLAGS))
	$(info LDFLAGS is $(LDFLAGS))
	$(info CPPFLAGS is $(CPPFLAGS))

.PHONY : build
build : all

.PHONY : all
all : $(TARGET)

.PHONY : clean
clean :
	rm -rf *.i *.asm *.o *.d *.map *.out

