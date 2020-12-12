###################################
# CS421 Computational Theory
# Program: A Japanese to English translator
#Features: Includes skip, and replace word, and records all errors and tranlations.
# Made by: Rodolfo Rodriguez, Julian Jaramillo, and Andrew Malmstead	
###################################
CC = g++			# use g++ for compiling c++ code or gcc for c code
CFLAGS = -O -std=c++11		# compilation flags: -Change to -O or -O2 for optimized code. -std
LIB = -lm			# linked libraries
LDFLAGS = -L.			# link flags
PROG = group25project			# target executable (output)
SRCS = translator.cpp      # .c or .cpp source files.
OBJ = $(SRCS:.cpp=.o) 	# object files for the target.

all : $(PROG)

$(PROG): $(OBJ)
	$(CC) -o $(PROG) $(OBJ) $(LDFLAGS) $(LIB)

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^ > ./.depend;

include .depend

# cleanup
clean:
	/bin/rm -f *.o $(PROG)

# DO NOT DELETE
