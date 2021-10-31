all: main

main: main.o Parser.o
	g++ $^ -o $@
	make clean
	
%.o: %.cpp
	g++ -c $< -o $@

clean:
	rm main.o Parser.o