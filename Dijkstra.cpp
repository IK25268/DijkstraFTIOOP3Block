#include <cmath>
#include <iostream>
#include <fstream>
#include "Dijkstra.hpp"

void Dijkstra::CalcAllRoutes(Graph& graph)
{
	for (auto& iterFrom : graph.ReturnWeighOrientGraph())
	{
		graph.ReturnShortDistMatrix()[iterFrom.first] = {};
		for (auto& iterTo : graph.ReturnWeighOrientGraph())
		{
			graph.ReturnShortDistMatrix()[iterFrom.first][iterTo.first] = { {}, INF, "-1", 0 };
		}
		graph.ReturnShortDistMatrix()[iterFrom.first][iterFrom.first].distance = 0;
		for (auto& i : graph.ReturnWeighOrientGraph())
		{
			std::string n = "-1";
			for (auto& v : graph.ReturnWeighOrientGraph())
			{
				if ((graph.ReturnShortDistMatrix()[iterFrom.first][v.first].visited == 0) && ((n == "-1") || (graph.ReturnShortDistMatrix()[iterFrom.first][n].distance > graph.ReturnShortDistMatrix()[iterFrom.first][v.first].distance)))
				{
					n = v.first;
				}
			}
			if (graph.ReturnShortDistMatrix()[iterFrom.first][n].distance == 1e9)
			{
				break;
			}
			graph.ReturnShortDistMatrix()[iterFrom.first][n].visited = '1';
			for (auto & iter : graph.ReturnWeighOrientGraph()[n])
			{
				if (graph.ReturnShortDistMatrix()[iterFrom.first][iter.first].distance > graph.ReturnShortDistMatrix()[iterFrom.first][n].distance + iter.second)
				{
					graph.ReturnShortDistMatrix()[iterFrom.first][iter.first].distance = graph.ReturnShortDistMatrix()[iterFrom.first][n].distance + iter.second;
					graph.ReturnShortDistMatrix()[iterFrom.first][iter.first].from = n;
				}
			}
		}
		for (auto& j : graph.ReturnWeighOrientGraph())
		{
			if (j.first != iterFrom.first)
			{
				for (auto v = graph.ReturnShortDistMatrix()[iterFrom.first][j.first].from; (v != iterFrom.first) && (v != "-1"); v = graph.ReturnShortDistMatrix()[iterFrom.first][v].from)
				{
					graph.ReturnShortDistMatrix()[iterFrom.first][j.first].stopovers.push_front(v);
				}
			}
		}
	}
}
