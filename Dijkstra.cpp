#include <cmath>
#include <iostream>
#include <fstream>
#include "Dijkstra.hpp"

void Dijkstra::CalcAllRoutes(Graph& graph)
{
	for (int numbFrom = 0; numbFrom < graph.ReturnWeighOrientGraph().size(); numbFrom++)
	{
		graph.ReturnShortDistMatrix().push_back({});
		for (int numbTo = 0; numbTo < graph.ReturnWeighOrientGraph().size(); numbTo++)
		{
			graph.ReturnShortDistMatrix()[numbFrom].push_back({ {}, INF, -1, 0});
		}
		graph.ReturnShortDistMatrix()[numbFrom][numbFrom].distance = 0;
		for (int i = 0; i < graph.ReturnWeighOrientGraph().size(); i++)
		{
			int n = -1;
			for (int v = 0; v < graph.ReturnWeighOrientGraph().size(); v++)
			{
				if ((graph.ReturnShortDistMatrix()[numbFrom][v].visited == 0)&&((n == -1)||(graph.ReturnShortDistMatrix()[numbFrom][n].distance > graph.ReturnShortDistMatrix()[numbFrom][v].distance)))
				{
					n = v;
				}
			}
			if (graph.ReturnShortDistMatrix()[numbFrom][n].distance == 1e9)
			{
				break;
			}
			graph.ReturnShortDistMatrix()[numbFrom][n].visited = '1';
			for (auto & iter : graph.ReturnWeighOrientGraph()[n])
			{
				if (graph.ReturnShortDistMatrix()[numbFrom][iter.first].distance > graph.ReturnShortDistMatrix()[numbFrom][n].distance + iter.second)
				{
					graph.ReturnShortDistMatrix()[numbFrom][iter.first].distance = graph.ReturnShortDistMatrix()[numbFrom][n].distance + iter.second;
					graph.ReturnShortDistMatrix()[numbFrom][iter.first].from = n;
				}
			}
		}
		for (int j = 0; j < graph.ReturnWeighOrientGraph().size(); j++)
		{
			if (j != numbFrom)
			{
				for (int v = graph.ReturnShortDistMatrix()[numbFrom][j].from; (v != numbFrom) && (v != -1); v = graph.ReturnShortDistMatrix()[numbFrom][v].from)
				{
					graph.ReturnShortDistMatrix()[numbFrom][j].stopovers.push_front(v);
				}
			}
		}
	}
}
