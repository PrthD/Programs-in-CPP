# -------------------------------------------------
# Name: Parth Dadhania
# SID: 1722612
# CCID: pdadhani
# AnonID: 1000330704
# CMPUT 275, Winter 2023
# Assessment: Weekly Exercise #3: Reference Manager
# -------------------------------------------------

we3_solution: ref_manager.o we3_test.o
	g++ ref_manager.o we3_test.o -o we3_solution

ref_manager.o: ref_manager.cpp ref_manager.h
	g++ -c ref_manager.cpp

we3_test.o: we3_test.cpp
	g++ -c we3_test.cpp

clean:
	rm *.o we3_solution