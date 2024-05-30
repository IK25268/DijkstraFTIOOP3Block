#include <cmath>
#include <iostream>
#include <fstream>
#include "Dijkstra.hpp"

std::string Dijkstra::CalcRoute(const Graph& graph, const std::string& from, const std::string& to)
{
	std::unordered_map<std::string, DataDistTo> shortDistVector = InitShortDistVector(graph, from);
	for (auto const& i : graph.GetWeighOrientGraph())
	{
		std::string nearest = "-1";
		for (auto const& v : graph.GetWeighOrientGraph())
		{
			std::string next = v.first;
			if ((shortDistVector[next].visited == 0) && ((nearest == "-1") || (shortDistVector[nearest].distance > shortDistVector[next].distance))) nearest = next;
		}
		if (shortDistVector[nearest].distance == INF) break;
		shortDistVector[nearest].visited = '1';
		for (auto const& iter : graph.GetWeighOrientGraph().at(nearest))
		{
			if (shortDistVector[iter.first].distance > shortDistVector[nearest].distance + iter.second)
			{
				shortDistVector[iter.first].distance = shortDistVector[nearest].distance + iter.second;
				shortDistVector[iter.first].from = nearest;
			}
		}
	}
	CalcStopovers(graph, shortDistVector, from);
	return MakeStr(shortDistVector, from, to);
}

std::string Dijkstra::MakeStr(const std::unordered_map<std::string, DataDistTo>& shortDistVector, const std::string& from, const std::string& to)
{
	std::string output = "{";
	output += from;
	output += ", ";
	for (auto const& iterStopover : shortDistVector.at(to).stopovers)
	{
		output += iterStopover;
		output += ", ";
	}
	output += to;
	output += "} - ";
	output += std::to_string(shortDistVector.at(to).distance);
	return output;
}

void Dijkstra::CalcStopovers(const Graph& graph, std::unordered_map<std::string, DataDistTo>& shortDistVector, const std::string& from)
{
	for (auto const& iter : graph.GetWeighOrientGraph())
	{
		if (iter.first != from)
		{
			for (auto end = shortDistVector[iter.first].from; (end != from) && (end != "-1"); end = shortDistVector[end].from)
			{
				shortDistVector[iter.first].stopovers.push_front(end);
			}
		}
	}
}

std::unordered_map<std::string, DataDistTo> Dijkstra::InitShortDistVector(const Graph& graph, const std::string& from)
{
	std::unordered_map<std::string, DataDistTo> shortDistVector = {};
	for (auto const& iterTo : graph.GetWeighOrientGraph())
	{
		shortDistVector[iterTo.first] = { {}, INF, "-1", 0 };
	}
	shortDistVector[from].distance = 0;
	return shortDistVector;
}
