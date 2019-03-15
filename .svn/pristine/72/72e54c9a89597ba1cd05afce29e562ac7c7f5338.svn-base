/**
 * @file NimLearner.cpp
 * CS 225 - Fall 2017
 */

#include "NimLearner.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

/**
 * Constructor to create a game of Nim with `startingTokens` starting tokens.
 *
 * This function creates a graph, `g_` representing all of the states of a
 * game of Nim with vertex labels "p#-X", where:
 * - # is the current player's turn; p1 for Player 1, p2 for Player2
 * - X is the tokens remaining at the start of a player's turn
 *
 * For example:
 *   "p1-4" is Player 1's turn with four (4) tokens remaining
 *   "p2-8" is Player 2's turn with eight (8) tokens remaining
 *
 * All legal moves between states are created as edges with initial weights
 * of 0.
 *
 * @param startingTokens The number of starting tokens in the game of Nim.
 */
NimLearner::NimLearner(unsigned startingTokens) : g_(true) {
	tokennumber = int(startingTokens);
	string s1;
	string s2;
	string s3;
	string s4;
	string total;
	Vertex v1;
	Vertex v2;
	bool check;
	for (int i = 1; i < 3; i++)
	{
		for (int j = 0; j <= int(startingTokens); j++)
		{
			s1 = "p";
			s2 = to_string(i);
			s3 = "-";
			s4 = to_string(j);
			total = s1 + s2 + s3 + s4;
			v1 = g_.insertVertex(total);
		}
	}
	s1 = "p";
	s2 = "1";
	s3 = "-";
	s4 = to_string(int(startingTokens));
	total = s1 + s2 + s3 + s4;
	startingVertex_ = g_.getVertexByLabel(total);
	for (int j = int(startingTokens); j >= 1; j--)
	{
		for (int i = 1; i <= 2; i++)
		{
			total = s1 + to_string(i) + s3 + to_string(j);
			v1 = g_.getVertexByLabel(total);
			total = s1 + to_string(3 - i) + s3 + to_string(j - 1);
			v2 = g_.getVertexByLabel(total);
			check = g_.insertEdge(v1, v2);
			g_.setEdgeWeight(v1, v2, 0);
		}
	}
	for (int j = int(startingTokens); j >= 2; j--)
	{
		for (int i = 1; i <= 2; i++)
		{
			total = s1 + to_string(i) + s3 + to_string(j);
			v1 = g_.getVertexByLabel(total);
			total = s1 + to_string(3 - i) + s3 + to_string(j - 2);
			v2 = g_.getVertexByLabel(total);
			check = g_.insertEdge(v1, v2);
			g_.setEdgeWeight(v1, v2, 0);
		}
	}
}

/**
 * Plays a random game of Nim, returning the path through the state graph
 * as a vector of `Edge` classes.  The `origin` of the first `Edge` must be
 * the vertex with the label "p1-#", where # is the number of starting
 * tokens.  (For example, in a 10 token game, result[0].origin must be the
 * vertex "p1-10".)
 *
 * @returns A random path through the state space graph.
 */
std::vector<Edge> NimLearner::playRandomGame() const {
  vector<Edge> path;
	//cout << g_.getVertices().size() << "\n" << endl;
	string s1;
	string s2;
	string s3;
	string s4;
	string total;
	Vertex v1;
	Vertex v2;
	s1 = "p";
	s3 = "-";
	int step = 0;
	int player = 1;
	int temp = tokennumber;
	step = rand() % 2 + 1;
	Edge store;
	while (temp > 0)
	{
		total = s1 + to_string(player) + s3 + to_string(temp);
		v1 = g_.getVertexByLabel(total);
		if (temp == 1)
		{
			total = s1 + to_string(3 - player) + s3 + to_string(0);
			v2 = g_.getVertexByLabel(total);
			temp = 0;
		}
		else
		{
			total = s1 + to_string(3 - player) + s3 + to_string(temp - step);
			v2 = g_.getVertexByLabel(total);
			temp = temp - step;
		}
		player = 3 - player;
		store = g_.getEdge(v1, v2);
		path.push_back(store);
		step = rand() % 2 + 1;
	}
  return path;
}


/*
 * Updates the edge weights on the graph based on a path through the state
 * tree.
 *
 * If the `path` has Player 1 winning (eg: the last vertex in the path goes
 * to Player 2 with no tokens remaining, or "p2-0", meaning that Player 1
 * took the last token), then all choices made by Player 1 (edges where
 * Player 1 is the source vertex) are rewarded by increasing the edge weight
 * by 1 and all choices made by Player 2 are punished by changing the edge
 * weight by -1.
 *
 * Likewise, if the `path` has Player 2 winning, Player 2 choices are
 * rewarded and Player 1 choices are punished.
 *
 * @param path A path through the a game of Nim to learn.
 */
void NimLearner::updateEdgeWeights(const std::vector<Edge> & path) {
	int pathsize = 0;
	pathsize = path.size();
	int temp = pathsize - 1;
	int counter = 0;
	Edge lastE = path[pathsize - 1];
	Edge curr;
	Vertex start;
	Vertex end;
	int currweight;
	Vertex lastV = lastE.dest;
	string labelV = g_.getVertexLabel(lastV);
	if (labelV == "p1-0" || labelV == "p2-0")
	{
		counter = 1;
		while (temp >= 0)
		{
			curr = path[temp];
			start = curr.source;
			end = curr.dest;
			currweight = g_.getEdgeWeight(start, end);
			currweight = currweight + counter;
			counter = -counter;
			g_.setEdgeWeight(start, end, currweight);
			temp--;
		}
	}
	return;
}


/**
 * Returns a constant reference to the state space graph.
 *
 * @returns A constant reference to the state space graph.
 */
const Graph & NimLearner::getGraph() const {
  return g_;
}
