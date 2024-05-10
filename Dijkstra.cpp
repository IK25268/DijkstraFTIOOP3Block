#include <cmath>
#include <iostream>
#include <fstream>
#include "Dijkstra.hpp"

Dijkstra::Dijkstra()
{
}

Dijkstra::~Dijkstra()
{
}

void Dijkstra::CalcAllRoutes(Graph& graph)
{
	for (int numbFrom = 0; numbFrom < graph.GetGraphInput().size(); numbFrom++)
	{
		graph.GetGraphOutput().push_back({});
		for (int numbTo = 0; numbTo < graph.GetGraphInput().size(); numbTo++)
		{
			graph.GetGraphOutput()[numbFrom].push_back({ {}, INF, -1, 0});
		}
		graph.GetGraphOutput()[numbFrom][numbFrom].distance = 0;
		for (int i = 0; i < graph.GetGraphInput().size(); i++)
		{
			int n = -1;
			for (int v = 0; v < graph.GetGraphInput().size(); v++)
			{
				if ((graph.GetGraphOutput()[numbFrom][v].visited == 0)&&((n == -1)||(graph.GetGraphOutput()[numbFrom][n].distance > graph.GetGraphOutput()[numbFrom][v].distance)))
				{
					n = v;
				}
			}
			if (graph.GetGraphOutput()[numbFrom][n].distance == 1e9)
			{
				break;
			}
			graph.GetGraphOutput()[numbFrom][n].visited = '1';
			for (auto & iter : graph.GetGraphInput()[n])
			{
				if (graph.GetGraphOutput()[numbFrom][iter.first].distance > graph.GetGraphOutput()[numbFrom][n].distance + iter.second)
				{
					graph.GetGraphOutput()[numbFrom][iter.first].distance = graph.GetGraphOutput()[numbFrom][n].distance + iter.second;
					graph.GetGraphOutput()[numbFrom][iter.first].from = n;
				}
			}
		}
		for (int j = 0; j < graph.GetGraphInput().size(); j++)
		{
			if (j != numbFrom)
			{
				for (int v = graph.GetGraphOutput()[numbFrom][j].from; (v != numbFrom) && (v != -1); v = graph.GetGraphOutput()[numbFrom][v].from)
				{
					graph.GetGraphOutput()[numbFrom][j].stopovers.push_front(v);
				}
			}
		}
	}
}
