// ------------------------------------------------
// Name: Parth Dadhania
// SID: 1722612
// CCID: pdadhani
// AnonID: 1000330704
// CMPUT 275, Winter 2023
// Assessment: Weekly Exercise #6: Graph Concepts
// ------------------------------------------------

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "digraph.h"

using namespace std;

/*
    Description: Calls the depth-first-search algorithm recursively, exploring the unvisited reachable
                 nodes. If the node is already visited, the fucntion returns without continuing the
                 exploration. This function was taken from Lecture 13 in-class discussion.

    Arguments:
		graph (const Digraph&): the digrapgh instance to perform depth-first-search on
		u (const int): integer (here, vertex/node) currently being checked if already visited or not
		prev (const int): the previous vertex/node to u
		visited (unordered_map<int, int>&): map in which keys are the vertices/nodes just visited and values
                                            are the vertices/nodes visited prior to the one currently visited
	
    Returns: This function does not return anything.
*/
void depth_first_search(const Digraph &graph, const int u, const int prev, unordered_map<int, int> &visited)
{
    if (visited.find(u) != visited.end()) // checking if vertex is visited or not
    {
        return; // returns since it was visited before
    }
    visited[u] = prev;

    // Iterate over all neighbours of u
    for (auto itr = graph.neighbours(u); itr != graph.endIterator(u); ++itr)
    {
        depth_first_search(graph, *itr, u, visited); // recursive call to explore the previous vertex
    }
}

/*
    Description: This function calculates the total number of connected components in an undirected
                 graph of a given digraph instance ("graph") by using the depth-first-search algorithm.

    Arguments:
		graph (const Digraph&): the digrapgh instance with the undirected graph in which the total
                                number of connected components are to be counted
	
    Returns:
        count (int): total number of connected components in the given undirected graph
*/
unsigned int count_components(const Digraph &graph)
{
    int count = 0;
    unordered_map<int, int> visited; // initiating the unordered map containing the visited nodes
    vector<int> vertices = graph.vertices(); // getting the vertices of the undirected graph from the digraph instance
    for (int node : vertices) // iterating over the vertices/nodes of the undirected graph
    {
        if (visited.find(node) == visited.end())
        {
            count++; // if the node is not present in the "visited" map, increasing the number of connected components by 1
            depth_first_search(graph, node, node, visited); // calling the depth-first-search algorithm to explore nodes
        }
    }
    return count; // returning the total number of connected components of the undirected graph
}

/*
    Description: This function reads the graph description from stdin and builds an instance of the Digraph
                 class to represent the undirected graph of Edmonton graph by parsing input lines according
                 to the format.

    Arguments: This function takes no arguments.
	
    Returns:
        graph (Digraph): the digrapgh instance with the undirected graph that reperesents Edmonton graph
*/
Digraph read_city_graph_undirected()
{
    // initializing digraph instance and various variables according to the input format
    Digraph graph;
    string label, name, input, temp_str;
    float Lat, Lon;
    int ID, start, end;
    int comma_1, comma_2, comma_3;

    while (getline(cin, input) && !input.empty()) // getting the input string from stdin and checking whether it is not empty (eof)
    {
        label = input.substr(0, 1); // getting the "V" or "E" identifier from the input line

        comma_1 = input.find(','); // calculating the position of the first comma in the input string line
        comma_2 = input.find(',', comma_1 + 1); // calculating the position of the second comma in the input string line
        comma_3 = input.find(',', comma_2 + 1); // calculating the position of the third comma in the input string line

        if (label == "V")
        {
            temp_str = input.substr(comma_1 + 1, comma_2 - comma_1 - 1); // calculating the "ID" part of input string
            ID = stoi(temp_str); // converting the "ID" from string to integer
            graph.addVertex(ID); // adding the vertex to the digraph instance "graph"

            temp_str = input.substr(comma_2 + 1, comma_3 - comma_2 - 1); // calculating the "Latitude" part of input string
            Lat = stof(temp_str); // converting the "Latitude" from string to float

            temp_str = input.substr(comma_3 + 1); // calculating the "Longitude" part of input string
            Lon = stof(temp_str); // converting the "Longitude" from string to float
        }
        else if (label == "E")
        {
            temp_str = input.substr(comma_1 + 1, comma_2 - comma_1 - 1); // calculating "start" part of input string
            start = stoi(temp_str); // converting the "start" from string to integer

            temp_str = input.substr(comma_2 + 1, comma_3 - comma_2 - 1); // calculating "end" part of input string
            end = stoi(temp_str); // converting the "end" from string to integer

            // modelling the undirected graph using a digraph instance ("graph") by adding both (start, end) and
            // (end, start) directed edges for each undirected edge
            graph.addEdge(start, end);
            graph.addEdge(end, start);

            name = input.substr(comma_3 + 1); // calculating "name" part of input string
        }
    }
    return graph; // returning the digraph instance "graph" with the modelled undirected graph
}

// main function that takes no arguments but calls the above functions to print the total number of connected
// components of an undirected graph through stdput.
int main()
{
    Digraph graph = read_city_graph_undirected();
    cout << count_components(graph) << endl;
}