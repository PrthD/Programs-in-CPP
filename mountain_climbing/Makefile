# --------------------------------------------------
# Name: Parth Dadhania
# SID: 1722612
# CCID: pdadhani
# AnonID: 1000330704
# CMPUT 275, Winter 2023
# Assessment: Weekly Exercise #7: Divide and Conquer
# --------------------------------------------------

all: we7_solution

we7_solution: climbing.o
	g++ -o we7_solution climbing.o

climbing.o: climbing.cpp
	g++ -Wall -O2 -g -c climbing.cpp

clean:
	rm -f *.o we7_solution