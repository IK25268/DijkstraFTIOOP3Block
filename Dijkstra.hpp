#pragma once
#ifndef __Dijkstra_hpp
#define __Dijkstra_hpp
#include <fstream>
#include <iostream>
#include "Graph.hpp"

class Dijkstra final {
private:
	static const int INF = 1e9;
public:
	static void CalcAllRoutes(Graph& graph);
};

#endif
