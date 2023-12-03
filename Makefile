CC ?= gcc
CXX ?= g++
CPP ?= g++

APP_NAME_MQ_SERVER = LEDControl
OBJ_FILES_MQ_SERVER = LEDControl.o

LIBS = .

all: $(APP_NAME_MQ_SERVER) 

$(APP_NAME_MQ_SERVER) : $(OBJ_FILES_MQ_SERVER)
	$(CC) $^ -o $@ -L$(LIBS) 

%.o: %.c
	$(CC) -o $@ -c $^

clean:
	rm *.o $(APP_NAME_MQ_SERVER)

fresh:
	make clean
	make all
