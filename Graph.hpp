#pragma once
#ifndef __Graph_hpp
#define __Graph_hpp
#include <string>
#include <map>
#include <queue>
#include <list>

typedef struct DataDistTo
{
	std::list<int> stopovers;
	int distance;
	int from;
	bool visited;
}DataDistTo;

class Graph final {
private:
	std::vector<std::string> key;
	std::vector<std::map<int, unsigned int>> WeighOrientGraph;
	std::vector<std::vector<DataDistTo>> ShortDistMatrix;
public:
	std::vector<std::string>& ReturnKey();
	std::vector<std::map<int, unsigned int>>& ReturnWeighOrientGraph();
	std::vector<std::vector<DataDistTo>>& ReturnShortDistMatrix();
};

#endif