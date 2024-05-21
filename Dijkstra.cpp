#include <cmath>
#include <iostream>
#include <fstream>
#include "Dijkstra.hpp"

 std::string Dijkstra::CalcAllRoutes(Graph& graph, std::string from, std::string to)
{
	std::map<std::string, DataDistTo> shortDistVector = {};
	for (auto& iterTo : graph.ReturnWeighOrientGraph())
	{
		shortDistVector[iterTo.first] = { {}, INF, "-1", 0 };
	}
	shortDistVector[from].distance = 0;
	for (auto& i : graph.ReturnWeighOrientGraph())
	{
		std::string nearest = "-1";
		for (auto& v : graph.ReturnWeighOrientGraph())
		{
			std::string next = v.first;
			if ((shortDistVector[next].visited == 0) && ((nearest == "-1") || (shortDistVector[nearest].distance > shortDistVector[next].distance))) nearest = next;
		}
		if (shortDistVector[nearest].distance == 1e9) break;
		shortDistVector[nearest].visited = '1';
		for (auto & iter : graph.ReturnWeighOrientGraph()[nearest])
		{
			if (shortDistVector[iter.first].distance > shortDistVector[nearest].distance + iter.second)
			{
				shortDistVector[iter.first].distance = shortDistVector[nearest].distance + iter.second;
				shortDistVector[iter.first].from = nearest;
			}
		}
	}
	for (auto& iter : graph.ReturnWeighOrientGraph())
	{
		if (iter.first != from)
		{
			for (auto end = shortDistVector[iter.first].from; (end != from) && (end != "-1"); end = shortDistVector[end].from)
			{
				shortDistVector[iter.first].stopovers.push_front(end);
			}
		}
	}
	std::string output = "{";
	output += from;
	output += ", ";
	for (auto & iterStopover: shortDistVector[to].stopovers)
    {
		output += iterStopover;
		output += ", ";
    }
	output += to;
	output += "} - ";
	output += std::to_string(shortDistVector[to].distance);
	return output;
}
