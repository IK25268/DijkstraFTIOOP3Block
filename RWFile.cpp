#include <cmath>
#include <iostream>
#include <fstream>
#include "RWFile.hpp"

Graph RWFile::ReadFile(const std::string& inputName)
{
    Graph graph;
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
            graph.AddEdge(from, to, weight);
        }
    }
    fsInput.close();
    return graph;
}
