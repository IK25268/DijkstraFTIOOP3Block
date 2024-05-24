#pragma once
#ifndef __Graph_hpp
#define __Graph_hpp
#include <string>
#include <map>
#include <queue>
#include <list>
#include <unordered_map>

class Graph final {
private:
	std::unordered_map<std::string, std::unordered_map<std::string, unsigned int>> WeighOrientGraph;
public:
	const std::unordered_map<std::string, std::unordered_map<std::string, unsigned int>>& GetWeighOrientGraph() const;
	void AddEdge(const std::string& from, const std::string& to, const unsigned int& weight);
};

#endif