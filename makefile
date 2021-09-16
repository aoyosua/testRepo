# project name (generate executable with this name). This is windows specific.
TARGET   = app.exe

CC       = gcc
# compiling flags here.
# std=c99: Use the C99 standard (Changed this to gnu99 to fix some bug).
# Wall: Turn on all warnings
# o0: Optimization level 0 (best for debugging)
# ggdb3: Generate debugging information specifically for gdb with extra information
# -I.: ???
CFLAGS   = -std=gnu99 -O0 -Wall -ggdb3 -I.

# Linker command
LINKER   = gcc -o
# linking flags here
LFLAGS   = -Wall -I. -lm

# change these to proper directories where each file should be
SRCDIR    = src/app/src
INCDIR    = src/app/include
OBJDIR    = obj
BINDIR    = bin
SCRIPTDIR = scripts

APPMAIN := src/app/main.c
APPMAINOBJ := obj/main.o

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(INCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
OBJECTSNOMAIN := $(filter-out $(APPMAINOBJ), $(OBJECTS))

rm       = rm -f
$(info $$OBJECTSNOMAIN is [${OBJECTSNOMAIN}])
all: app

app: $(BINDIR)/$(TARGET)


# This line will print the value of a makefile variable if it is uncommented out.
#all: $(BINDIR)/$(TARGET)

# Builds the application target and takes the compiled source as the prereq.
$(BINDIR)/$(TARGET): $(OBJECTS)
	$(LINKER) $@ $(LFLAGS) $(OBJECTS)
	@echo "Linking complete!"

# Compiles all the application source code.
$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -I$(INCDIR) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"
	@echo ""

# A phony clean command to remove everything except the executables.
.PHONY: clean
clean:
	$(rm) $(OBJECTS)
	$(rm) output.txt
	@echo "Cleanup complete!"

# A phony clean command to remove everything including the executables.
.PHONY: remove
remove: clean
	$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"
