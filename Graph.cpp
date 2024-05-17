#include <cmath>
#include <iostream>
#include <fstream>
#include "Graph.hpp"

std::vector<std::string>& Graph::GetKey()
{
	return key;
}

std::vector<std::map<int, unsigned int>>& Graph::GetGraphInput()
{
	return graphInput;
}

std::vector<std::vector<DataGraphTo>>& Graph::GetGraphOutput()
{
	return graphOutput;
}

Graph::Graph()
{
}

Graph::~Graph()
{
}
