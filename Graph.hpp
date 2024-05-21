#pragma once
#ifndef __Graph_hpp
#define __Graph_hpp
#include <string>
#include <map>
#include <queue>
#include <list>

class Graph final {
private:
	std::map<std::string, std::map<std::string, unsigned int>> WeighOrientGraph;
public:
	std::map<std::string, std::map<std::string, unsigned int>>& ReturnWeighOrientGraph();
};

#endif