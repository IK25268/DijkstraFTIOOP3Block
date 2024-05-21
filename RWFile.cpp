#include <cmath>
#include <iostream>
#include <fstream>
#include "RWFile.hpp"

void RWFile:: ReadFile(Graph& graph, const char* inputName)
{
    std::fstream fsInput;
    fsInput.open(inputName, std::fstream::in | std::fstream::out | std::fstream::app);
    std::string from = "";
    std::string to = "";
    unsigned int weight = 0;
    if (fsInput.is_open())
    {
        while (!fsInput.eof())
        {
            from = "";
            to = "";
            fsInput >> from;
            fsInput >> to;
            fsInput >> weight;
            graph.ReturnWeighOrientGraph()[from][to] = weight;
        }
    }
    fsInput.close();
}
