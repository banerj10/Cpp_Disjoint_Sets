Implementation of a disjoint-set/union-find data structure, made primarily to test using MinGW's g++ compiler on Windows.

To make the executable and object files, run 'make' in the Windows command line (requires MingW to have been set up, as well as some additional setup to run the 'make' command, which can be in the link below).
https://stackoverflow.com/questions/12881854/how-to-use-gnu-make-on-windows

Files:
disjointset.cpp, disjointset.h - disjoint set implementation
testdset.cpp - tests working of disjoint set

Implementation:
The disjointset class can create a disjoint-set data structure for non-negative integers. The actual implementation uses a private unordered_map<int, int> to map element values onto roots. The values of the roots have been abstracted away from the user using the private int _findRoot(int val) function. The public functions available are:

• bool hasElem(int val) - returns true if element already exists in the disjoint set, otherwise returns false
• bool addElem(int val) - add an element to the disjoint set. Returns true if element is successfully added and false either if the value cannot be added (the set only accepts +ve ints) or if the value already exists inside the disjoint set
• bool compareRoot(int val1, int val2) - returns true if both elements share the same root, returns false if they don't or if either one is invalid
• bool setUnion(int val1, int val2) - joins val1 and val2 to both point to the same root. Returns true if union is successfully set and false if either value is invalid (-ve int, or not present in the disjoint set)
