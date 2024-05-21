#include <cmath>
#include <iostream>
#include <fstream>
#include "Graph.hpp"

std::map<std::string, std::map<std::string, unsigned int>>& Graph::ReturnWeighOrientGraph()
{
	return WeighOrientGraph;
}