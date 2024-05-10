#pragma once
#ifndef __RWFile_hpp
#define __RWFile_hpp
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <fstream>
#include <iostream>
#include "Graph.hpp"

class RWFile final {
private:
	const int INF = 1e9;
public:
	RWFile();
	~RWFile();
	void WriteFile(Graph& graph, const char* outputName);
	void ReadFile(Graph& graph, const char* inputName);
};

#endif