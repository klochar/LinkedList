exec = exec

$(exec):main.o Animal.o
	g++ -std=c++20 -o $(exec) $^

main.o:main.cpp
	g++ -std=c++20 -c $^

Animal.o:Animal.cpp
	g++ -std=c++20 -c $^

clean:
	del -rf *.o *.exe

run:$(exec)
	./exec.exe
