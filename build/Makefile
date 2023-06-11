OBJS = ../src/main.o \
	   ../src/app/app.o \
	   ../src/factory/app/app.o \
	   ../src/scenes/orchestrator.o \
	   ../src/scenes/beginGame/beginGame.o \
	   ../src/event/events.o  \
	   ../src/utils/classes/camera/camera.o  \
	   ../src/utils/classes/collision.o  \
	   ../src/utils/classes/floor/floor.o \
	   ../src/utils/classes/textures/textures.o \
	   ../src/utils/classes/turtle/turtle.o \
	   ../src/utils/classes/Draw/turtle/turtle.o  \
	   ../src/utils/classes/Draw/turtle/body/body.o \
	   ../src/utils/classes/Draw/turtle/limb/limb.o \
	   ../src/utils/classes/Draw/turtle/head/head.o


FILE_BIN = Asteroid.bin
LIBS = -lGL -lglfw -lGLEW 
CFLAGS = -Wall
bin: $(OBJS)
	g++ -o $(FILE_BIN) $(OBJS) $(LIBS) $(CFLAGS)
%.o:%.cpp
	g++ -c $< -o $@
clean:
	rm $(FILE_BIN) ../src/*.o ../src/*/*.o ../src/*/*/*.o ../src/*/*/*/*.o ../src/*/*/*/*/*.o
th: 
	@ ./mk $(OBJS) $(LIBS) 
	g++ -o $(FILE_BIN) $(OBJS) $(LIBS) $(CFLAGS)
