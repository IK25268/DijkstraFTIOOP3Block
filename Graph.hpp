#pragma once
#ifndef __Graph_hpp
#define __Graph_hpp
#include <string>
#include <map>
#include <queue>
#include <list>

typedef struct DataGraphTo
{
	std::list<int> stopovers;
	int distance;
	int from;
	bool visited;
}DataGraphTo;

class Graph final {
private:
	std::vector<std::string> key;
	std::vector<std::map<int, unsigned int>> graphInput;
	std::vector<std::vector<DataGraphTo>> graphOutput;
public:
	std::vector<std::string>& GetKey();
	std::vector<std::map<int, unsigned int>>& GetGraphInput();
	std::vector<std::vector<DataGraphTo>>& GetGraphOutput();
	Graph();
	~Graph();
};

#endif