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
        for (int i = 0; i < graph.ReturnShortDistMatrix().size(); i++)
        {
            for (int j = 0; j < graph.ReturnShortDistMatrix().size(); j++)
            {
                if ((graph.ReturnShortDistMatrix()[i][j].distance != 0) && (graph.ReturnShortDistMatrix()[i][j].distance != INF))
                {
                    fsOutput << graph.ReturnKey()[i];
                    fsOutput << ' ';
                    for (auto & iterStopover:graph.ReturnShortDistMatrix()[i][j].stopovers)
                    {
                        fsOutput << graph.ReturnKey()[iterStopover];
                        fsOutput << ' ';
                    }
                    fsOutput << graph.ReturnKey()[j];
                    fsOutput << ' ';
                    fsOutput << graph.ReturnShortDistMatrix()[i][j].distance;
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
            auto iterFrom = std::find(begin(graph.ReturnKey()), end(graph.ReturnKey()), from);
            auto iterTo = std::find(begin(graph.ReturnKey()), end(graph.ReturnKey()), to);
            int numbFrom = iterFrom == graph.ReturnKey().end() ? -1 : iterFrom - graph.ReturnKey().begin();
            int numbTo = iterTo == graph.ReturnKey().end() ? -1 : iterTo - graph.ReturnKey().begin();
            if (numbFrom == -1)
            {
                graph.ReturnKey().push_back(from);
                graph.ReturnWeighOrientGraph().push_back({});
                numbFrom = graph.ReturnKey().size() - 1;
            }
            if (numbTo == -1)
            {
                graph.ReturnKey().push_back(to);
                graph.ReturnWeighOrientGraph().push_back({});
                numbTo = graph.ReturnKey().size() - 1;
            }
            graph.ReturnWeighOrientGraph()[numbFrom].insert({numbTo, weight});
        }
    }
    fsInput.close();
}
