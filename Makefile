all:
	mkdir -p obj bin
	g++ -g -std=c++17 -c ./src/*.cpp -I ./inc
	mv *.o obj/
	g++ -g -std=c++17 -o bin/Main obj/*.o
	rm -rf a.out*
obj:
	mkdir -p obj bin
	g++ -g -std=c++17 -c ./src/*.cpp -I ./inc
	mv *.o obj/
clean:
	rm -rf *.o
	rm -rf obj bin
