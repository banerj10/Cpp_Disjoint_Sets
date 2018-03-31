#include <iostream>

#include "disjointSet.h"

using std::cout;
using std::endl;

int main()
{
    disjointset dset;
    int numElems = 25;
    for(int i = 0; i < numElems; i++)
        dset.addElem(i);
    cout << "Comparing roots of first and last elems: " << dset.compareRoot(0, numElems-1) << endl;
    cout << "Checking valid elem: " << dset.hasElem(0) << endl;
    cout << "Checking invalid elem: " << dset.hasElem(numElems) << endl;
    for(int i = 0; i < numElems-2; i += 2)
        dset.setUnion(i, i+2);
    cout << "Comparing roots of elem 1 and 2: " << dset.compareRoot(0, 1) << endl;
    cout << "Comparing roots of elem 1 and 3: " << dset.compareRoot(0, 2) << endl;
    cout << "Comparing roots of elem 1 and 4: " << dset.compareRoot(0, 3) << endl;
    cout << "Comparing roots of elem 1 and 5: " << dset.compareRoot(0, 4) << endl;
    cout << "Comparing roots of elem 2 and 3: " << dset.compareRoot(1, 2) << endl;
    cout << "Comparing roots of elem 3 and 5: " << dset.compareRoot(2, 4) << endl;
    dset.setUnion(3, 0);
    cout << "Comparing roots of elem 1 and 2: " << dset.compareRoot(0, 1) << endl;
    cout << "Comparing roots of elem 1 and 3: " << dset.compareRoot(0, 2) << endl;
    cout << "Comparing roots of elem 1 and 4: " << dset.compareRoot(0, 3) << endl;
    cout << "Comparing roots of elem 1 and 5: " << dset.compareRoot(0, 4) << endl;
    cout << "Comparing roots of elem 2 and 3: " << dset.compareRoot(1, 2) << endl;
    cout << "Comparing roots of elem 3 and 5: " << dset.compareRoot(2, 4) << endl;
    
    return 0;
}