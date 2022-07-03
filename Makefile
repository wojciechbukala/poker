APP= Poker_Texas_Holdem

FLAGS= -c -g -Iinc -Wall -pedantic -iquote headers


__start__: ./Poker_Texas_Holdem
	./Poker_Texas_Holdem 

./Poker_Texas_Holdem: obj obj/main.o 

# Tworzy katalog "obj" gdy go nie ma
# 
obj:
	mkdir obj

./${APP}: obj obj/main.o obj/deck.o obj/hand.o
	g++ -o ./${APP} obj/main.o obj/deck.o obj/hand.o


obj/main.o: program/main.cpp headers/deck.hh headers/hand.hh
	g++  ${FLAGS} -o obj/main.o program/main.cpp

obj/deck.o: program/deck.cpp headers/deck.hh
	g++ -c ${FLAGS} -o obj/deck.o program/deck.cpp

obj/hand.o: program/hand.cpp headers/hand.hh
	g++ -c ${FLAGS} -o obj/hand.o program/hand.cpp

clean:
	rm -f obj/* ./${APP}



help:
	@echo
	@echo " make        - tworzenie i uruchomienie aplikacji"
	@echo " make clean  - usuniecie produktow kompilacji i konsolidacji"
	@echo " make help   - wyswietla niniejsza informacje"
	@echo