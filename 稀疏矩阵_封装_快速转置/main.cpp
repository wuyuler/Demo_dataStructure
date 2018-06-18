#include <iostream>

using namespace std;
#include"SparseMatrix.hpp"

int main()
{
    //²âÊÔÊı¾İ
    SparseMatrix<int> m(6,7);
    m.append(Triplet<int>(0,1,2));
    m.append(Triplet<int>(0,2,9));
    m.append(Triplet<int>(2,0,-3));
    m.append(Triplet<int>(2,4,14));
    m.append(Triplet<int>(3,2,24));
    m.append(Triplet<int>(4,1,18));
    m.append(Triplet<int>(5,0,15));
    m.append(Triplet<int>(5,3,-7));
    cout << "Hello world!" << endl;
    return 0;
}
