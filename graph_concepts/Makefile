# ----------------------------------------------
# Name: Parth Dadhania
# SID: 1722612
# CCID: pdadhani
# AnonID: 1000330704
# CMPUT 275, Winter 2023
# Assessment: Weekly Exercise #6: Graph Concepts
# ----------------------------------------------

we6_solution: graph_concepts.o digraph.o
	g++ graph_concepts.o digraph.o -o we6_solution

graph_concepts.o: graph_concepts.cpp
	g++ -c graph_concepts.cpp

digraph.o: digraph.cpp digraph.h
	g++ -c digraph.cpp

clean:
	rm *.o we6_solution