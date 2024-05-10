#pragma once
#ifndef __Dijkstra_hpp
#define __Dijkstra_hpp
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <fstream>
#include <iostream>
#include "Graph.hpp"

class Dijkstra final {
private:
	const int INF = 1e9;
public:
	Dijkstra();
	~Dijkstra();
	void CalcAllRoutes(Graph& graph);
};

#endif
