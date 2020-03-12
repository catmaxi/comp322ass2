BJ.exe: main.cpp blackjack.o
	clang++ -o BJ.exe main.cpp blackjack.o
blackjack.o: blackjack.cpp
	clang++ -c blackjack.cpp