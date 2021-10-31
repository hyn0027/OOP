include control.mak

ifeq (TRUE, $(F1))
	C_FLAGS += -D__F1__
endif

ifeq (TRUE, $(F2))
	C_FLAGS += -D__F2__
endif

ifeq (TRUE, $(F3))
	C_FLAGS += -D__F3__
endif

ifeq (TRUE, $(F4))
	C_FLAGS += -D__F4__
endif

all: main

main: main.o f1.o f2.o f3.o f4.o
	g++ $^ -o $@

%.o: %.cpp control.mak
	g++ $(C_FLAGS) -c $< -o $@

clean:
	rm main.o f1.o f2.o f3.o f4.o main
