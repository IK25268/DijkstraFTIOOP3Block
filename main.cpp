#include "Dijkstra.hpp"
#include "RWFile.hpp"

int main()
{
	Graph graph(RWFile::ReadFile("input.txt"));
	std::string path = Dijkstra::CalcRoute(graph, "Krasnoyarsk", "Toronto");
	return 0;
}