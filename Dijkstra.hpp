#pragma once
#ifndef __Dijkstra_hpp
#define __Dijkstra_hpp
#include <fstream>
#include <iostream>
#include "Graph.hpp"

class Dijkstra final {
private:
	static std::unordered_map<std::string, std::pair<std::pair<std::list<std::string>, unsigned int>, std::pair<std::string, bool>>> InitShortDistVector(const Graph& graph, const std::string& from);
	static std::string MakeStr(const std::unordered_map<std::string, std::pair<std::pair<std::list<std::string>, unsigned int>, std::pair<std::string, bool>>>& shortDistVector, const std::string& from, const std::string& to);
	static void CalcStopovers(const Graph& graph, std::unordered_map<std::string, std::pair<std::pair<std::list<std::string>, unsigned int>, std::pair<std::string, bool>>>& shortDistVector, const std::string& from);
	static const unsigned int INF = 1e9;
public:
	static std::string CalcRoute(const Graph& graph, const std::string& from, const std::string& to);
};

#endif
