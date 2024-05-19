#pragma once
#ifndef __Graph_hpp
#define __Graph_hpp
#include <string>
#include <map>
#include <queue>
#include <list>

typedef struct DataDistTo
{
	std::list<std::string> stopovers;
	long int distance;
	std::string from;
	bool visited;
}DataDistTo;

class Graph final {
private:
	std::map<std::string, std::map<std::string, unsigned int>> WeighOrientGraph;
	std::map<std::string, std::map<std::string, DataDistTo>> ShortDistMatrix;
public:
	std::map<std::string, std::map<std::string, unsigned int>>& ReturnWeighOrientGraph();
	std::map<std::string, std::map<std::string, DataDistTo>>& ReturnShortDistMatrix();
};

#endif