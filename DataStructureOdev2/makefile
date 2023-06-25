all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/TestProgrami.cpp -o ./lib/TestProgrami.o
	g++ -c -I "./include" ./src/Queue.cpp -o ./lib/Queue.o
	g++ -c -I "./include" ./src/Doku.cpp -o ./lib/Doku.o
	g++ -c -I "./include" ./src/Radix.cpp -o ./lib/Radix.o
	g++ -c -I "./include" ./src/Hucre.cpp -o ./lib/Hucre.o	
	g++ -c -I "./include" ./src/Organ.cpp -o ./lib/Organ.o	
	g++ -c -I "./include" ./src/Sistem.cpp -o ./lib/Sistem.o	
	g++ -c -I "./include" ./src/ikiliAramaAgaci.cpp -o ./lib/ikiliAramaAgaci.o	
	g++ -c -I "./include" ./src/Organizma.cpp -o ./lib/Organizma.o
	g++ -c -I "./include" ./src/Kontrol.cpp -o ./lib/Kontrol.o

bagla:
	g++ ./lib/Kontrol.o ./lib/Organizma.o ./lib/Doku.o ./lib/ikiliAramaAgaci.o ./lib/Radix.o ./lib/Queue.o ./lib/TestProgrami.o ./lib/Hucre.o ./lib/Organ.o ./lib/Sistem.o -o ./bin/program
calistir:
	./bin/program