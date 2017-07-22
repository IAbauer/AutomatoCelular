all:
CPP = g++
OPTS = -lGL -lGLU -lglut 
GAMB = && ./final
all:
	$(CPP) graphics.cpp -o final $(OPTS) $(GAMB)
clean:
	rm final