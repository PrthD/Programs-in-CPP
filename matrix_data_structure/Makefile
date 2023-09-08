# --------------------------------------------------
# Name: Parth Dadhania
# SID: 1722612
# CCID: pdadhani
# AnonID: 1000330704
# CMPUT 275, Winter 2023
# Assessment: Weekly Exercise #5: Matrix Class
# --------------------------------------------------

we5_solution: matrix.o we5_test.o
	g++ matrix.o we5_test.o -o we5_solution

we5_test.o: we5_test.cpp
	g++ -c we5_test.cpp

matrix.o: matrix.cpp matrix.h
	g++ -c matrix.cpp

clean:
	rm *.o we5_solution