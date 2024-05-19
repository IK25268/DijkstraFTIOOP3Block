#include <cmath>
#include <iostream>
#include <fstream>
#include "Graph.hpp"

std::vector<std::string>& Graph::ReturnKey()
{
	return key;
}

std::vector<std::map<int, unsigned int>>& Graph::ReturnWeighOrientGraph()
{
	return WeighOrientGraph;
}

std::vector<std::vector<DataDistTo>>& Graph::ReturnShortDistMatrix()
{
	return ShortDistMatrix;
}