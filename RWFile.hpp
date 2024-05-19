#pragma once
#ifndef __RWFile_hpp
#define __RWFile_hpp
#include <fstream>
#include <iostream>
#include "Graph.hpp"

class RWFile final {
private:
	static const int INF = 1e9;
public:
	static void WriteFile(Graph& graph, const char* outputName);
	static void ReadFile(Graph& graph, const char* inputName);
};

#endif