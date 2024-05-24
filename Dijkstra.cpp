#include <cmath>
#include <iostream>
#include <fstream>
#include "Dijkstra.hpp"

std::string Dijkstra::CalcRoute(const Graph& graph, const std::string& from, const std::string& to)
{
	std::unordered_map<std::string, std::pair<std::pair<std::list<std::string>, unsigned int>, std::pair<std::string, bool>>> shortDistVector = InitShortDistVector(graph, from);
	for (auto const& i : graph.GetWeighOrientGraph())
	{
		std::string nearest = "-1";
		for (auto const& v : graph.GetWeighOrientGraph())
		{
			std::string next = v.first;
			if ((shortDistVector[next].second.second == 0) && ((nearest == "-1") || (shortDistVector[nearest].first.second > shortDistVector[next].first.second))) nearest = next;
		}
		if (shortDistVector[nearest].first.second == INF) break;
		shortDistVector[nearest].second.second = '1';
		for (auto const& iter : graph.GetWeighOrientGraph().at(nearest))
		{
			if (shortDistVector[iter.first].first.second > shortDistVector[nearest].first.second + iter.second)
			{
				shortDistVector[iter.first].first.second = shortDistVector[nearest].first.second + iter.second;
				shortDistVector[iter.first].second.first = nearest;
			}
		}
	}
	CalcStopovers(graph, shortDistVector, from);
	return MakeStr(shortDistVector, from, to);
}

std::string Dijkstra::MakeStr(const std::unordered_map<std::string, std::pair<std::pair<std::list<std::string>, unsigned int>, std::pair<std::string, bool>>>& shortDistVector, const std::string& from, const std::string& to)
{
	std::string output = "{";
	output += from;
	output += ", ";
	for (auto const& iterStopover : shortDistVector.at(to).first.first)
	{
		output += iterStopover;
		output += ", ";
	}
	output += to;
	output += "} - ";
	output += std::to_string(shortDistVector.at(to).first.second);
	return output;
}

void Dijkstra::CalcStopovers(const Graph& graph, std::unordered_map<std::string, std::pair<std::pair<std::list<std::string>, unsigned int>, std::pair<std::string, bool>>>& shortDistVector, const std::string& from)
{
	for (auto const& iter : graph.GetWeighOrientGraph())
	{
		if (iter.first != from)
		{
			for (auto end = shortDistVector[iter.first].second.first; (end != from) && (end != "-1"); end = shortDistVector[end].second.first)
			{
				shortDistVector[iter.first].first.first.push_front(end);
			}
		}
	}
}

std::unordered_map<std::string, std::pair<std::pair<std::list<std::string>, unsigned int>, std::pair<std::string, bool>>> Dijkstra::InitShortDistVector(const Graph& graph, const std::string& from)
{
	std::unordered_map<std::string, std::pair<std::pair<std::list<std::string>, unsigned int>, std::pair<std::string, bool>>> shortDistVector = {};
	for (auto const& iterTo : graph.GetWeighOrientGraph())
	{
		shortDistVector[iterTo.first] = { {{}, INF}, {"-1", 0} };
	}
	shortDistVector[from].first.second = 0;
	return shortDistVector;
}
