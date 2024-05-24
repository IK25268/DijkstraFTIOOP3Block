#include "pch.h"
#include "../DijkstraFTIOOP3Block/RWFile.hpp"
#include "../DijkstraFTIOOP3Block/Dijkstra.hpp"
#include "../DijkstraFTIOOP3Block/RWFile.cpp"
#include "../DijkstraFTIOOP3Block/Dijkstra.cpp"
#include "../DijkstraFTIOOP3Block/Graph.cpp"
#include "../DijkstraFTIOOP3Block/Graph.hpp"

TEST(TestRoutes, TestName) {
	Graph graph(RWFile::ReadFile("input.txt"));
	std::string routeKT = Dijkstra::CalcRoute(graph, "Krasnoyarsk", "Toronto");
	std::string routeTO = Dijkstra::CalcRoute(graph, "Toronto", "Omsk");
	ASSERT_STREQ(routeKT.data(), "{Krasnoyarsk, Kiev, Omsk, Toronto} - 26");
	ASSERT_STREQ(routeTO.data(), "{Toronto, Krasnoyarsk, Kiev, Omsk} - 17");
}