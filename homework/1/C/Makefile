all: main

main: main.o Farm.o Cow.o
	g++ $^ -o $@
	make clean
	
%.o: %.cpp
	g++ -c $< -o $@

clean:
	rm main.o Farm.o Cow.o