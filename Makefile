FLAGS = -pedantic-errors -std=c++11 gcd.o: gcd.cpp gcd.h

main-2.o: main-2.cpp SnakeGame.h InputOutput.h
	g++ $(FLAGS) -c $<

SnakeGame.o: SnakeGame.cpp Snakegame.h
	g++ $(FLAGS) -c $<

InputOutput.o: InputOutput.cpp InputOutput.h SnakeGame.h
	g++ $(FLAGS) -c $<

Snake: main-2.o SnakeGame.o InputOutput.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f Snake SnakeGame.o InputOutput.o main-2.o

clean:
  rm -f main
	
.PHONY: clean


FLAGS = -pedantic-errors -std=c++11 gcd.o: gcd.cpp gcd.h
g++ $(FLAGS) -c $< gcd_main.o: gcd_main.cpp gcd.h
      g++ $(FLAGS) -c $<
gcd: gcd.o gcd_main.o
      g++ $(FLAGS) $^ -o $@
clean:
rm -f gcd gcd.o gcd_main.o gcd.tgz
tar:
      tar -czvf gcd.tgz *.cpp *.h
.PHONY: clean tar
