PROJECT := $(notdir $(CURDIR))
EXCECUTABLE = $(BUILDDIR)/$(PROJECT)

# Directories specification
SRCDIRS := src
INCDIRS := .
BUILDDIR := build
DOCDIR := doc

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
override CFLAGS += -gdwarf -fprofile-args -ftest-coverage -Wall -Wmaybe-uninitialized -Wfloat-equal -Wcast-qual -Wshadow -Wundef -Wunused-variable -Werror -O0 -std=c++11 --short-enums
override CXXFLAGS += -gdwarf -Wall -Wmaybe-uninitialized -Wfloat-equal -Wcast-qual -Wshadow -Wundef -Wunused-variable -Werror -O0 -std=c++11 --short-enums
override LDFLAGS += -Wl,-Map=$(EXCECUTABLE).map
INCFLAGS := $(INCDIRS:%=-I%)
DEPFLAGS := -MMD -MP

# Tools and flags
CPPLINT := cpplint
override CPPLINTFLAGS += --linelength=100 --filter=-build/header_guard,-runtime/references,-runtime/indentation_namespace,-build/namespaces --extensions=$(subst $( ),$(,),$(SRCEXTS)) --headers=$(subst $( ),$(,),$(HDREXTS))
CPPCHECK := cppcheck
override CPPCHECKFLAGS += --enable=style,warning,missingInclude --check-config --template=gcc -I $(INCDIRS)\/include
SIZE = size
SIZEFLAGS := -Adt
NM = nm
NMFLAGS := -S --defined --size-sort -S
DOC = doxygen
DOCFLAGS := -g
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


.PHONY: all help run clean force cpplint cppcheck size info doc list-headers list-sources list-objects debug

# Main target for building
all: $(EXCECUTABLE)
	@echo Done.

# Print commands
help:
	@echo "Some useful make targets:"
	@echo " make all          - Build entire project (modified sources only or dependents)"
	@echo " make run          - Build and launch excecutable immediately"
	@echo " make force        - Force rebuild of entire project (clean first)"
	@echo " make clean        - Remove all build output"
	@echo " make info         - Print out project configurations"	
	@echo " make cpplint      - C++ style checker tool following Google's C++ style guide"
	@echo " make cppcheck     - Static code analysis tool for the C and C++"
	@echo " make size		      - Print size info"
	@echo " make doc		      - Generate documentation"
	@echo " make list-headers - Print out all recognized headers files"
	@echo " make list-sources - Print out all recognized sources files"
	@echo " make list-objects - Print out final objects"
	@echo ""

# make sure Make do not delete included dependencies files
.PRECIOUS: $(BUILDDIR)/%.d
# include the dependency files here (should not be before first target)
include $(wildcard $(foreach ext, $(SRCEXTS), $(patsubst %.$(ext), $(BUILDDIR)/%.d, $(filter %.$(ext), $(SOURCES)))))


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
	@rm -rf $(DOCDIR)
	@echo Cleaned.

# Force build of all files
force: clean all

# C++ style checker tool (following Google's C++ style guide)
cpplint:
	@$(CPPLINT) $(CPPLINTFLAGS) $(SOURCES) $(INCLUDES)

# Static code analysis tool for the C and C++
cppcheck:
	@$(CPPCHECK) $(CPPCHECKFLAGS) $(SOURCES) $(INCLUDES) $(INCFLAGS)

# Print size informations
size: $(EXCECUTABLE)
	@$(NM) $(NMFLAGS) $(EXCECUTABLE)
	@$(SIZE) $(SIZEFLAGS) $(EXCECUTABLE)
	@$(SIZE) $(EXCECUTABLE)

# Generate documentation
doc:
	@$(DOC) $(DOCFLAGS)
	@sed -i -r 's/^INPUT                  =/INPUT                     = $(INCDIRS)\/include $(SRCDIRS)/g' Doxyfile
	@sed -i -r 's/^RECURSIVE              = NO/RECURSIVE                  = YES/g' Doxyfile
	@sed -i -r 's/^FILTER_SOURCE_FILES    = NO/FILTER_SOURCE_FILES    = YES/g' Doxyfile
	@sed -i -r 's/^SOURCE_BROWSER         = NO/SOURCE_BROWSER         = YES/g' Doxyfile
	@sed -i -r 's/^INLINE_SOURCES         = NO/INLINE_SOURCES         = YES/ ' Doxyfile
	@sed -i -r 's/^FILTER_SOURCE_FILES    = NO/FILTER_SOURCE_FILES    = YES/g' Doxyfile
	@sed -i -r 's/^SOURCE_BROWSER         = NO/SOURCE_BROWSER         = YES/g' Doxyfile
	@sed -i -r 's/^PROJECT_NAME           = "My Project"/PROJECT_NAME           = "Test Doxygen"/g' Doxyfile
	@sed -i -r 's/^OUTPUT_DIRECTORY       =/OUTPUT_DIRECTORY       = .\/$(DOCDIR) /g' Doxyfile
	@sed -i -r 's/^PROJECT_NUMBER         =/PROJECT_NUMBER         = 1.0/g' Doxyfile
	@$(DOC) Doxyfile
	@make -C $(DOCDIR)/latex pdf
	@mv Doxyfile $(DOCDIR)/
#	@mkdir -p $(DOCDIR)
#	@mv html $(DOCDIR)/
#	@mv latex $(DOCDIR)/	

# Prints out project configurations
info:
	@echo Project: $(PROJECT)
	@echo Excecutable: $(EXCECUTABLE)
	@echo SourceDirs: $(SRCDIRS)
	@echo IncludeDirs: $(INCDIRS)
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

list-objects:
	$(foreach obj, $(OBJECTS), $(call print,$(obj)))


# Debugging of this makefile, for development
debug:
	@echo SourceExts: $(SRCEXTS)
	@echo HeaderExts: $(HDREXTS)


# 
# ### Utils ###
#
define print
	@echo $1

endef

# comma -> $(,)
, = ,
# blank -> $(blank)
blank =
# space -> $( )
space = $(blank) $(blank)
$(space) = $(space)
