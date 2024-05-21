#include "Dijkstra.hpp"
#include "RWFile.hpp"

int main()
{
	Graph graph;
	RWFile::ReadFile(graph, "input.txt");
	std::string path = Dijkstra::CalcAllRoutes(graph, "Krasnoyarsk", "Toronto");
	return 0;
}