# About 
This project deals with the implementation of KDTree class which provides the
user with an easy use and fast query time for D dimentional queries.

# Overview
/bigtests : Test cases which have 100000 Data points and 20000 query
points.

/mediumtests : Test cases which have 10000 Data points and 2000 query
points.

/smalltests : Test cases which have 100 Data points and 200 query points.

/test_gens : Test case generater files.

/executibles : Executibles of KDTree compiled specifically for the demo. The
names given are self explanatory.

bruteforce.cpp : Bruteforce way to do existance check, circle count and report
queries and rectangle count and report queries.

kdtree.cpp : KDTree approach to the above problem.

# How to run code ? 
The location of the test case files and that of the executibles are provided in
the details given above. The main function of KDTree also has few pre-written
and commented sections in the main function which can be uncommented or
commented according to the need to verify specific cases. 

The test cases can also be generated using the test case generaters provided in
the /test_gen folder.

Names are quite descriptive.

# Execution
./executible < <test_input_file>
