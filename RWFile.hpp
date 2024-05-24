#pragma once
#ifndef __RWFile_hpp
#define __RWFile_hpp
#include <fstream>
#include <iostream>
#include "Graph.hpp"

class RWFile final {
public:
	static Graph ReadFile(const std::string& inputName);
};

#endif