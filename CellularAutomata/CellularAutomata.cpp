#include <iostream>
#include "GraphAutomata.h"

int main()
{
	GraphAutomata* A = new GraphAutomata(100, 60);
	A->createCircularGraph(A->graph);
	A->applySeed();
	for (int i = 0; i < 50; i++) {
		A->printGeneration();
	}
}