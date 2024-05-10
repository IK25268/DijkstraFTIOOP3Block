#include <iostream>
#include "Dijkstra.hpp"
#include "RWFile.hpp"

int main()
{
	Graph graph;
	RWFile rWFile;
	Dijkstra dijkstra;
	rWFile.ReadFile(graph, "input.txt");
	dijkstra.CalcAllRoutes(graph);
	rWFile.WriteFile(graph, "output.txt");
	return 0;
}