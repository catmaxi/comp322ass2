blackjack.exe: main.cpp blackjack.o
	g++ -o blackjack.exe main.cpp blackjack.o
blackjack.o: blackjack.cpp
	g++ -c blackjack.cpp