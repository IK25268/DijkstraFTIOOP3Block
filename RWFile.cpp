#include <cmath>
#include <iostream>
#include <fstream>
#include "RWFile.hpp"

RWFile::RWFile()
{
}

RWFile::~RWFile()
{
}

void RWFile::WriteFile(Graph& graph, const char* outputName)
{
    std::fstream fsOutput;
    fsOutput.open(outputName, std::fstream::in | std::fstream::out | std::fstream::app);
    if (fsOutput.is_open())
    {
        for (int i = 0; i < graph.GetGraphOutput().size(); i++)
        {
            for (int j = 0; j < graph.GetGraphOutput().size(); j++)
            {
                if ((graph.GetGraphOutput()[i][j].distance != 0) && (graph.GetGraphOutput()[i][j].distance != INF))
                {
                    fsOutput << graph.GetKey()[i];
                    fsOutput << ' ';
                    for (auto & iterStopover:graph.GetGraphOutput()[i][j].stopovers)
                    {
                        fsOutput << graph.GetKey()[iterStopover];
                        fsOutput << ' ';
                    }
                    fsOutput << graph.GetKey()[j];
                    fsOutput << ' ';
                    fsOutput << graph.GetGraphOutput()[i][j].distance;
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
            auto iterFrom = std::find(begin(graph.GetKey()), end(graph.GetKey()), from);
            auto iterTo = std::find(begin(graph.GetKey()), end(graph.GetKey()), to);
            int numbFrom = iterFrom == graph.GetKey().end() ? -1 : iterFrom - graph.GetKey().begin();
            int numbTo = iterTo == graph.GetKey().end() ? -1 : iterTo - graph.GetKey().begin();
            if (numbFrom == -1)
            {
                graph.GetKey().push_back(from);
                graph.GetGraphInput().push_back({});
                numbFrom = graph.GetKey().size() - 1;
            }
            if (numbTo == -1)
            {
                graph.GetKey().push_back(to);
                graph.GetGraphInput().push_back({});
                numbTo = graph.GetKey().size() - 1;
            }
            graph.GetGraphInput()[numbFrom].insert({numbTo, weight});
        }
    }
    fsInput.close();
}
