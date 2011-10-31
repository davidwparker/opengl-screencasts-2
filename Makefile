# Target to build
#TARGET = 011 012 013 014
TARGET = 014
#EXECS = ./011 ./012 ./013 ./014
EXECS = ./executables/014

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
	gcc -Wall -O3 -o ./executables/$@ $^ $(LIBS)

clean:
	rm -f $(EXECS) *.o *.a

# without .h => globals.o
screencasts.a:globals.o print.o error.o fatal.o textures.o shapes.o models.o interaction.o initialization.o draw.o display.o
	ar -rcs screencasts.a $^