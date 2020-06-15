# Directories specification
SRCDIRS := .
INCDIRS := .
INCVENDORDIRS += $(CPPUTEST_HOME)/include
BUILDDIR := build

PROJECT := executable #$(notdir $(CURDIR))
EXCECUTABLE = $(BUILDDIR)/$(PROJECT)


# @note: to add another source extension, add to herer AND make sure to
#	write the " $(BUILDDIR)/%.o: %.ext " rule for this extention in order to work
SRCEXTS := cpp cc c cxx c++ C
# @note: to add another header extention, just add here and it should recognize it
HDREXTS := hpp hh h hxx h++ H

# list of all recognized files found in the specified directories
SOURCES := $(foreach dir, $(SRCDIRS), $(foreach ext, $(SRCEXTS), $(wildcard $(dir)/*.$(ext))))
INCLUDES := $(foreach dir, $(INCDIRS), $(foreach ext, $(HDREXTS), $(wildcard $(dir)/*.$(ext))))
OBJECTS := $(foreach ext, $(SRCEXTS), $(patsubst %.$(ext), $(BUILDDIR)/%.o, $(filter %.$(ext), $(SOURCES))))



# Compilers and flags

#C/C++ program flags
#           -gdwarf \ #Produce debugging information in DWARF format
#             DWARF: most expressive & best supported debugging GDB format
#           -fprofile-args -ftest-coverage  \ generate test coverage info
#           -Wmaybe-uninitialized \ #variables declared but not initialised
#           -Wfloat-equal \ #inappropriate floating point comparisons.
#           -Wcast-qual \ #pointer is cast so as to remove a type qualifier
#           -Wshadow \ #variable declaration shadows another variable.
#           -Wbad-function-cast \ #function call cast to non-matching type.
#           -Wundef \ #undefined identifier is evaluated in #if directive
#           -Wunused-variable \ #local or static variable is unused.
#           
CC := gcc
CXX := g++

override CFLAGS += -gdwarf -fprofile-arcs -ftest-coverage -Wall -Wmaybe-uninitialized -Wfloat-equal -Wcast-qual -Wshadow -Wundef -Wunused-variable -Werror -O0 -std=c++11 --short-enums
override CXXFLAGS += -gdwarf -Wall -Wmaybe-uninitialized -Wfloat-equal -Wcast-qual -Wshadow -Wundef -Wunused-variable -Werror -O0 -std=c++11 --short-enums

#  Linker options
#  You need to add CppUTest library to the linker flags, for example, like:
#  (The last flag is only needed when you want to use extensions such as mocking)

override LDFLAGS += -L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt

INCFLAGS := $(INCDIRS:%=-iquote %)
INCVENDORFLAGS := $(INCVENDORDIRS:%=-isystem %)
INCFLAGS += $(INCVENDORFLAGS)
DEPFLAGS := -MMD -MP


# This makefile name
MAKEFILE := $(lastword $(MAKEFILE_LIST))



# Function to compile using $(CC) : (files: .c)
define compilecc
	@mkdir -p $(dir $1)
	@$(CC) -c $2 -o $1 $(CFLAGS) $(INCFLAGS) -MT $1 -MF $(BUILDDIR)/$3.Td $(DEPFLAGS)
	@mv -f $(BUILDDIR)/$3.Td $(BUILDDIR)/$3.d && touch $1
	@echo CC: $1
endef

# Function to compile using $(CXX) : (files: .cpp .cc .cxx .c++ .C)
define compilecxx
	@mkdir -p $(dir $1)
	@$(CXX) -c $2 -o $1 $(CXXFLAGS) $(INCFLAGS) -MT $1 -MF $(BUILDDIR)/$3.Td $(DEPFLAGS)
	@mv -f $(BUILDDIR)/$3.Td $(BUILDDIR)/$3.d && touch $1
	@echo CXX: $1
endef

# Rules to build objects for each source file extension
$(BUILDDIR)/%.o: %.c $(BUILDDIR)/%.d $(MAKEFILE) $@
	$(call compilecc,$@,$<,$*)

$(BUILDDIR)/%.o: %.cc $(BUILDDIR)/%.d $(MAKEFILE) $@
	$(call compilecxx,$@,$<,$*)

$(BUILDDIR)/%.o: %.cpp $(BUILDDIR)/%.d $(MAKEFILE) $@
	$(call compilecxx,$@,$<,$*)

$(BUILDDIR)/%.o: %.cxx $(BUILDDIR)/%.d $(MAKEFILE) $@
	$(call compilecxx,$@,$<,$*)

$(BUILDDIR)/%.o: %.c++ $(BUILDDIR)/%.d $(MAKEFILE) $@
	$(call compilecxx,$@,$<,$*)

$(BUILDDIR)/%.o: %.C $(BUILDDIR)/%.d $(MAKEFILE) $@
	$(call compilecxx,$@,$<,$*)

$(BUILDDIR)/%.d: ;




.PHONY: all help run clean

# Main target for building
all: $(EXCECUTABLE)
	@echo Done.


# Compile binary if necessary, checks for modified files first
# @note: uses CC if all source files are .c , otherwise uses CXX
$(EXCECUTABLE): $(OBJECTS) $(MAKEFILE) $@
ifeq ($(filter-out %.c,$(SOURCES)),$(blank))
	@$(CC) -o $@ $(OBJECTS) $(CFLAGS) $(LDFLAGS)
	@echo CC: $@ (excecutable)
else
	@$(CXX) -o $@ $(OBJECTS) $(CXXFLAGS) $(LDFLAGS)
	@echo CXX: $@
endif

# Launch excecutable, compile if necessary
run: $(EXCECUTABLE)
	@./$(EXCECUTABLE)

# Clean all build files
clean:
	@rm -rf $(EXCECUTABLE)
	@rm -rf $(BUILDDIR)
	@echo Cleaned.



# Prints out project configurations
info:
	@echo Project: $(PROJECT)
	@echo Excecutable: $(EXCECUTABLE)
	@echo SourceDirs: $(SRCDIRS)
	@echo Sources: $(SOURCES)
	@echo IncludeDirs: $(INCDIRS)
	@echo Includes: $(INCLUDES)
	@echo BuildDir: $(BUILDDIR)
	@echo CC: $(CC)
	@echo CXX: $(CXX)
	@echo CCFlags: $(CFLAGS)
	@echo CXXFlags: $(CXXFLAGS)
	@echo LDFlags: $(LDFLAGS)
	@echo IncFlags: $(INCFLAGS)
	@echo DepFlags: $(DEPFLAGS)
	@echo CppLintFlags : $(CPPLINTFLAGS)
	@echo CppCheckFlags: $(CPPCHECKFLAGS)
	@echo SizeFlags : $(SIZEFLAGS)
	@echo NmFlags: $(NMFLAGS)
	@echo DocFlags: $(DOCFLAGS)



list-sources:
	$(foreach src, $(SOURCES), $(call print,$(src)))

list-headers:
	$(foreach hdr, $(INCLUDES), $(call print,$(hdr)))



	# 
# ### Utils ###
#
define print
	@echo $1

endef
