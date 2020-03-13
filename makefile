blackjack.exe: main.cpp blackjack.o
	clang++ -o blackjack.exe main.cpp blackjack.o
blackjack.o: blackjack.cpp
	clang++ -c blackjack.cpp