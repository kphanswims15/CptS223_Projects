#ifndef GRAPH_H
#define GRAPH_H
#include <unordered_map>
#include <queue>
#include <functional>
#include <iostream>

#include "Vertex.h"
using namespace std;
class Graph
{
	unordered_map<int, Vertex> _vertices;

public:

	void addVertex(Vertex vertex)
	{
		_vertices[vertex.getId()] = vertex;
	}

	//MA #12 TODO: IMPLEMENT!
	unordered_map<Vertex, int> computeShortestPath(Vertex *start)
	{
		//holds known distances
		unordered_map<Vertex, int> distances;

		//underlying heap
		priority_queue<Vertex, vector<Vertex>, PathWeightComparer> dijkstra_queue{};

		//reset start's path weight
		start->setPathWeight(0);

		auto it = _vertices.find((start)->getId());

		//make sure that the starting vertex is in the graph
		if (it != _vertices.end())
		{
			//push on starting vertex
      		dijkstra_queue.push(*start);

			//while queue not empty
			while(!dijkstra_queue.empty())
			{
				Vertex vertex = dijkstra_queue.top();
				dijkstra_queue.pop();
				int value = vertex.getPathWeight();

				//Top of heap not known (in distances)?
				auto i = distances.find(vertex);
				if (i == distances.end())
				{
					//make known
					distances.insert(make_pair(vertex, value));
				}

				//push on outgoing edges
				unordered_map<Vertex *, int> edges = vertex.getEdges();
				for(auto edge_it = edges.begin(); edge_it != edges.end(); edge_it++)
				{
					// look to see if vertex is in distances
					auto edge_i = distances.find(*(edge_it->first));
					if(edge_i != distances.end())
					{
						int newPathWeight = vertex.getPathWeight() + edge_it->second;
						if ((*(edge_it->first)).getPathWeight() > newPathWeight)
						{
							// update the vertex if the newPathWeight is better
						 	(*(edge_it->first)).setPathWeight(newPathWeight);
							distances.erase((*(edge_it->first)));
							distances.insert(make_pair((*(edge_it->first)), newPathWeight));
							// push the new vertex on the priority_queue
							dijkstra_queue.push((*(edge_it->first)));
						}
					}
					else
					{
						// push the new vertex on the priority_queue
						int newPathWeight = vertex.getPathWeight() + edge_it->second;
						(*(edge_it->first)).setPathWeight(newPathWeight);
						dijkstra_queue.push((*(edge_it->first)));
					}
				}
			}
		}
		else
		{
			cout << "The start vertice is not in the list." << endl;
		}

		return distances;
	}
};

#endif
