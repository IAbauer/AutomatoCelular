all:
CPP = g++
OPTS = -lGL -lGLU -lglut 
GAMB = && ./final
all:
	$(CPP) exec.cpp -o final $(OPTS) $(GAMB)
clean:
	rm final