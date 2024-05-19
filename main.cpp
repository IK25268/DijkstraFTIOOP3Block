#include "Dijkstra.hpp"
#include "RWFile.hpp"

int main()
{
	Graph graph;
	RWFile::ReadFile(graph, "input.txt");
	Dijkstra::CalcAllRoutes(graph);
	RWFile::WriteFile(graph, "output.txt");
	return 0;
}