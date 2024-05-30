#pragma once
#ifndef __Dijkstra_hpp
#define __Dijkstra_hpp
#include <fstream>
#include <iostream>
#include "Graph.hpp"

struct DataDistTo
{
	std::list<std::string> stopovers;
	unsigned int distance;
	std::string from;
	bool visited;
};

class Dijkstra final {
private:
	Dijkstra();
	static std::unordered_map<std::string, DataDistTo> InitShortDistVector(const Graph& graph, const std::string& from);
	static std::string MakeStr(const std::unordered_map<std::string, DataDistTo>& shortDistVector, const std::string& from, const std::string& to);
	static void CalcStopovers(const Graph& graph, std::unordered_map<std::string, DataDistTo>& shortDistVector, const std::string& from);
	static const unsigned int INF = 1e9;
public:
	static std::string CalcRoute(const Graph& graph, const std::string& from, const std::string& to);
};

#endif
