#include <iostream>

#include "disjointset.h"

using std::cout;
using std::endl;

int disjointset::_findRoot(int val)
{
    // only finds root if element is valid
    if(hasElem(val))
    {
        // if val is mapped to -1, it is it's own root
        // and hence is sent back
        if(setMap[val] < 0)
            return val;
        // else, val's root is recursively found. Path
        // compression is achieved by directly connecting
        // val to its final root using setMap[val] =
        // _findRoot(setMap[val]);
        else 
        {
            setMap[val] = _findRoot(setMap[val]);
            return setMap[val];
        }
    }
    // invalid element case
    else
        return -1;
}

bool disjointset::hasElem(int val)
{
    // valid if map has a key corresponding to val 
    return setMap.count(val);
}

bool disjointset::addElem(int val)
{
    // adds element if it is valid and does not already
    // exist in the set
    if(val >= 0 && !hasElem(val))
    {
        setMap[val] = -1;
        return true;
    }
    // case for invalid element / already present
    else 
        return false;
}

bool disjointset::compareRoot(int val1, int val2)
{
    // checks if roots are the same via _findRoot. Second 
    // condition ensures 'true' is not returned for two
    // invalid elems (i.e., if both _findRoots return -1) 
    return (_findRoot(val1) == _findRoot(val2)) 
            && (_findRoot(val1) != -1);
}

bool disjointset::setUnion(int val1, int val2)
{
    // finds roots of both elements
    int root1 = _findRoot(val1), root2 = _findRoot(val2);
    // if both are valid, sets root of first to the second
    if(root1 != -1 && root2 != -1)
    {
        setMap[val1] = root2;
        return true;
    }
    // case for if either one is invalid
    else
        return false;
}