# Target to build
#TARGET = 011
TARGET = 011
#EXECS = ./executables/011
EXECS = ./executables/011

# Libraries - LINUX
#LIBS=-lglut -lGLU
# Libraries - OSX
LIBS=-framework OpenGL -framework GLUT

all: $(TARGET)

# Generic compile rules
.c.o: 
	gcc -c -O -Wall $<

# Generic compile and link
%: %.c screencasts.a
	gcc -Wall -O3 -o ./executables/$@ $^ $(LIBS)

clean:
	rm -f $(EXECS) *.o *.a

# without .h => globals.o
screencasts.a:globals.o print.o error.o shapes.o models.o interaction.o initialization.o draw.o display.o
	ar -rcs screencasts.a $^