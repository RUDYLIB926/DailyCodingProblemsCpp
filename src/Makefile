dailyCodingProblem: program.o problemSelector.o
	g++ -o dailyCodingProblem program.o problemSelector.o -std=c++17 -lstdc++fs

program.o: Program.cpp ProblemSelector.h
	g++ -c Program.cpp -std=c++17 -lstdc++fs
	
problemSelector.o: ProblemSelector.cpp ProblemSelector.h
	g++ -c ProblemSelector.cpp -std=c++17 -lstdc++fs

