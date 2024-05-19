#include <cmath>
#include <iostream>
#include <fstream>
#include "RWFile.hpp"

void RWFile::WriteFile(Graph& graph, const char* outputName)
{
    std::fstream fsOutput;
    fsOutput.open(outputName, std::fstream::in | std::fstream::out | std::fstream::app);
    if (fsOutput.is_open())
    {
        for (auto &iterFrom: graph.ReturnShortDistMatrix())
        {
            for (auto &iterTo: iterFrom.second)
            {
                if ((iterTo.second.distance != 0) && (iterTo.second.distance != INF))
                {
                    fsOutput << iterFrom.first;
                    fsOutput << ' ';
                    for (auto & iterStopover: iterTo.second.stopovers)
                    {
                        fsOutput << iterStopover;
                        fsOutput << ' ';
                    }
                    fsOutput << iterTo.first;
                    fsOutput << ' ';
                    fsOutput << iterTo.second.distance;
                    fsOutput << std::endl;
                }
            }
        }
    }
}

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
