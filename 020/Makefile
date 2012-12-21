# Target to build
TARGET = 020
EXECS = ./$(TARGET)

# Libraries - LINUX
#LIBS=-lglut -lGLU
# Libraries - OSX
LIBS=-framework OpenGL -framework GLUT

all: $(TARGET)

# Generic compile rules
.c.o: 
	gcc -c -g -O -Wall $<

# Generic compile and link
%: %.c screencasts.a
	gcc -Wall -O3 -o ./$@ $^ $(LIBS)

clean:
	rm -f $(EXECS) *.o *.a

# without .h => globals.o
screencasts.a:globals.o print.o error.o fatal.o display.o 
	ar -rcs screencasts.a $^
