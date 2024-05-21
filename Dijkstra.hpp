#pragma once
#ifndef __Dijkstra_hpp
#define __Dijkstra_hpp
#include <fstream>
#include <iostream>
#include "Graph.hpp"

class Dijkstra final {
private:
	typedef struct DataDistTo
	{
		std::list<std::string> stopovers;
		long int distance;
		std::string from;
		bool visited;
	}DataDistTo;
	static const int INF = 1e9;
public:
	static std::string CalcAllRoutes(Graph& graph, std::string from, std::string to);
};

#endif
