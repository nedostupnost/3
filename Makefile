all: compil

compil: 
	clang++ -o main bubley_tea.cpp tPoint.cpp -lsfml-graphics -lsfml-window -lsfml-system

clear:
	rm main
