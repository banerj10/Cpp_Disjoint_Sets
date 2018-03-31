#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <unordered_map>
using std::unordered_map;

class disjointset
{
    private:
    	/*private data*/
    	// disjointsets implemented using unordered_map data structure
        unordered_map<int, int> setMap;

        /*private functions*/
        // finds the root of a element present in the disjoint set
        // private because I wanted to abstract the actual value of
        // the root away from the user
        int _findRoot(int val);

    public:
    	/*public functions*/
    	// returns true if element already exists in the disjoint set,
    	// otherwise returns false
    	bool hasElem(int val);
    	// add an element to the disjoint set. Returns true if element
    	// is successfully added and false either if the value cannot be
    	// added (the set only accepts +ve ints) or if the value already
    	// exists inside the disjoint set
        bool addElem(int val);
    	// returns true if both elements share the same root, returns
    	// false if they don't or if either one is invalid
    	bool compareRoot(int val1, int val2);
        // joins val1 and val2 to both point to the same root. Returns
        // true if union is successfully set and false if either value
        // is invalid (-ve int, or not present in the disjoint set)
        bool setUnion(int val1, int val2);
};

#endif