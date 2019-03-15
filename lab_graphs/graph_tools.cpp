/**
 * @file graph_tools.cpp
 * This is where you will implement several functions that operate on graphs.
 * Be sure to thoroughly read the comments above each function, as they give
 *  hints and instructions on how to solve the problems.
 */

#include "graph_tools.h"
#include "edge.h"
#include <vector>
#include <map>

/**
 * Finds the minimum edge weight in the Graph graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @return the minimum weighted edge
 *
 * @todo Label the minimum edge as "MIN". It will appear blue when
 *  graph.savePNG() is called in minweight_test.
 *
 * @note You must do a traversal.
 * @note You may use the STL stack and queue.
 * @note You may assume the graph is connected.
 *
 * @hint Initially label vertices and edges as unvisited.
 */
int GraphTools::findMinWeight(Graph& graph)
{
    /* Your code here! */
    /*vector<Edge> edges = graph.getEdges();
    Edge minWeight = edges[0];
    for (int i=0; i<int(edges.size()); i++) {
      if (edges[i]<minWeight){
        minWeight = edges[i];
    	}
    }
    graph.setEdgeLabel(minWeight.source, minWeight.dest, "MIN");
    return minWeight.weight;*/
    //return -1;
    vector <Vertex> vertices = graph.getVertices();
    for(size_t i = 0; i < vertices.size(); i++){
      graph.setVertexLabel(vertices[i], "UNEXPLORED");
    }
    vector <Edge> edges = graph.getEdges();
    for(size_t i = 0; i < edges.size(); i++){
      	Vertex s = edges[i].source;
    		Vertex d = edges[i].dest;
    		graph.setEdgeLabel(s, d, "UNEXPLORED");
      }
      queue <Vertex> q;
    	q.push(vertices[0]);
    	graph.setVertexLabel(vertices[0], "VISITED");
    	Vertex startDest = (graph.getAdjacent(vertices[0]))[0];
    	int minWeight = graph.getEdgeWeight(vertices[0], startDest);
    	Vertex min1 = vertices[0];
    	Vertex min2 = startDest;
    	while(!q.empty())
    	{
    		Vertex d = q.front();
    		q.pop();
    		vector <Vertex> adjacent = graph.getAdjacent(d);
    		for(size_t i = 0; i < adjacent.size(); i++)
    		{
    			if(graph.getVertexLabel(adjacent[i]) == "UNEXPLORED")
    			{
    				graph.setEdgeLabel(d, adjacent[i], "DISCOVERY");
    				graph.setVertexLabel(adjacent[i], "VISITED");
    				int currWeight = graph.getEdgeWeight(adjacent[i], d);
    				if(currWeight < minWeight)
    				{
    					minWeight = currWeight;
    					min1 = d;
    					min2 = adjacent[i];
    				}
    				q.push(adjacent[i]);
    			}
    			else if(graph.getEdgeLabel(d, adjacent[i]) == "UNEXPLORED")
    			{
    				graph.setEdgeLabel(d, adjacent[i], "CORSS");
    				int currWeight = graph.getEdgeWeight(adjacent[i], d);
    				if(currWeight < minWeight)
    				{
    					minWeight = currWeight;
    					min1 = d;
    					min2 = adjacent[i];
    				}
    			}
    		}
    	}
    	graph.setEdgeLabel(min1, min2, "MIN");
    	return minWeight;

}

/**
 * Returns the shortest distance (in edges) between the Vertices
 *  start and end.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @param start - the vertex to start the search from
 * @param end - the vertex to find a path to
 * @return the minimum number of edges between start and end
 *
 * @todo Label each edge "MINPATH" if it is part of the minimum path
 *
 * @note Remember this is the shortest path in terms of edges,
 *  not edge weights.
 * @note Again, you may use the STL stack and queue.
 * @note You may also use the STL's unordered_map, but it is possible
 *  to solve this problem without it.
 *
 * @hint In order to draw (and correctly count) the edges between two
 *  vertices, you'll have to remember each vertex's parent somehow.
 */
int GraphTools::findShortestPath(Graph& graph, Vertex start, Vertex end)
{
    /* Your code here! */
    queue < Vertex > path;
	  path.push(start);
	  unordered_map< Vertex, Vertex> prev;
	  prev.insert(make_pair(start, start));
	  Vertex vert, vet1;
	  while(!path.empty()){
      vet1 = path.front();
		  path.pop();
		  if(vet1 == end){
        vert = vet1;
      }
		  vector< Vertex > next = graph.getAdjacent(vet1);
		  for(int i =0 ; i< int(next.size()); i++)
		  {
			  if(graph.getVertexLabel(next[i]) != "visited")
        {
          path.push(next[i]);
				  graph.setVertexLabel(next[i], "visited");
				  prev.insert(make_pair(next[i], vet1));
        }
		  }
	   }
	  int counter = 0;
	  while( vert != prev[vert])
    {
      vet1 = prev[vert];
		  graph.setEdgeLabel(vet1, vert, "MINPATH");
		  vert = vet1;
		  counter++;
    }
	  return counter;
    //return -1;
}

/**
 * Finds a minimal spanning tree on a graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to find the MST of
 *
 * @todo Label the edges of a minimal spanning tree as "MST"
 *  in the graph. They will appear blue when graph.savePNG() is called.
 *
 * @note Use your disjoint sets class from MP 7.1 to help you with
 *  Kruskal's algorithm. Copy the files into the libdsets folder.
 * @note You may call std::sort instead of creating a priority queue.
 */
void GraphTools::findMST(Graph& graph)
{
    /* Your code here! */
    vector< Edge > edges = graph.getEdges();
	  vector< Vertex > vertexes = graph.getVertices();
    DisjointSets ds;
	  std::sort(edges.begin(), edges.end());
	  ds.addelements(vertexes.size());
	  for(int i=0; i < int(edges.size()); i++){
		  Vertex vet1 = edges[i].source;
		  Vertex vet2 = edges[i].dest;
		  if(ds.find(vet1) != ds.find(vet2)){
        ds.setunion(vet1, vet2);
			  graph.setEdgeLabel(vet1, vet2, "MST");
      }
    }
}
