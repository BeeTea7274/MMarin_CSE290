#include <iostream>
#include "Cube.h"
#include "Cube.cpp"

using namespace std;

void PrintCubeStats(Cube);

int main() {
	Cube Miguel1(17.38, 6.7, 6.9);
	Cube Miguel2;

	PrintCubeStats(Miguel1);
	PrintCubeStats(Miguel2);
}

void PrintCubeStats(Cube cube) {
	cout << "==========================\n";
	cout << "Cube stats: \n";
	cout << "Length = " << cube.GetLength() << endl;
	cout << "Width = " << cube.GetWidth() << endl;
	cout << "Height = " << cube.GetHeight() << endl;
	cout << "Volume = " << cube.CalculateVolume() << endl;
	cout << "==========================\n\n";
}