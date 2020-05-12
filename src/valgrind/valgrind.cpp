#include <iostream>
#include "shape_Vector.h"
using namespace std;

int main()
{
    //Test default constructor
    Shape_Vector<int> testVector;

    //Test resize()
    cout << "Testing resize(10)..." << endl;
    testVector.resize(10);
    cout << "Current Vector Capacity: " << testVector.capacity() << endl;
    cout << "Current Vector size: " << testVector.size() << endl
         << endl;

    //Test push_back()
    cout << "adding elements 10,11,12 with push_back()..." << endl;
    testVector.push_back(10);
    testVector.push_back(11);
    testVector.push_back(12);
    cout << "Current Vector size: " << testVector.size() << endl
         << endl;

    //test reserve()
    cout << "Testing reserve() function..." << endl;
    testVector.reserve(10);
    testVector.reserve(9);
    testVector.reserve(15);
    cout << "Current Vector Capacity: " << testVector.capacity() << endl;
    cout << "Current Vector size: " << testVector.size() << endl
         << endl;

    //filling vector and testing what happens when you use push_back() on a full vector.
    cout << "filling vector..." << endl;
    cout << "test push_back() on full vector..." << endl;
    testVector.push_back(13);
    testVector.push_back(14);
    testVector.push_back(15);
    testVector.push_back(16);
    testVector.push_back(17);
    testVector.push_back(18);
    testVector.push_back(19);
    testVector.push_back(20);
    testVector.push_back(21);
    testVector.push_back(22);
    testVector.push_back(23);
    testVector.push_back(24);
    testVector.push_back(25);
    cout << "Current Vector Capacity: " << testVector.capacity() << endl;
    cout << "Current Vector size: " << testVector.size() << endl
         << endl;

    cout << "Vector contents: [";
    for (int loop = 0; loop < testVector.size(); loop++)
    {
        cout << testVector[loop];
        if (loop < testVector.size() - 1)
        {
            cout << ", ";
        }
        else
        {
            cout << ']' << endl;
        }
    }
    cout << endl;

    //Testing the begin() function
    cout << "Testing iterator begin() function..." << endl;
    Shape_Vector<int>::iterator type = testVector.begin();

    cout << "Beginning of vector: " << *type << endl
         << endl;

    //Testing the end() function
    cout << "Testing iterator end() function..." << endl;
    type = testVector.end();
    cout << "End of vector: " << *type << endl
         << endl;

    type = testVector.begin();
    type = type + 2;

    //Testing the erase() function
    cout << "testing erase() on the third element..." << endl;
    cout << "BEFORE ERASE:" << endl;
    cout << "Vector contents(before erase): [";
    for (int loop = 0; loop < testVector.size(); loop++)
    {
        cout << testVector[loop];
        if (loop < testVector.size() - 1)
        {
            cout << ", ";
        }
        else
        {
            cout << ']' << endl;
        }
    }
    cout << "Current Vector Capacity: " << testVector.capacity() << endl;
    cout << "Current Vector size: " << testVector.size() << endl
         << endl;

    cout << "AFTER ERASE:" << endl;
    testVector.erase(type);
    cout << "Vector contents(after erase): [";
    for (int loop = 0; loop < testVector.size(); loop++)
    {
        cout << testVector[loop];
        if (loop < testVector.size() - 1)
        {
            cout << ", ";
        }
        else
        {
            cout << ']' << endl;
        }
    }
    cout << "Current Vector Capacity: " << testVector.capacity() << endl;
    cout << "Current Vector size: " << testVector.size() << endl
         << endl;

    //Testing the insert() function
    cout << "testing insert() on the third element..." << endl;
    cout << "BEFORE INSERT:" << endl;
    cout << "Vector contents(before insert): [";
    for (int loop = 0; loop < testVector.size(); loop++)
    {
        cout << testVector[loop];
        if (loop < testVector.size() - 1)
        {
            cout << ", ";
        }
        else
        {
            cout << ']' << endl;
        }
    }
    cout << "Current Vector Capacity: " << testVector.capacity() << endl;
    cout << "Current Vector size: " << testVector.size() << endl
         << endl;

    cout << "AFTER INSERT:" << endl;
    testVector.insert(type, 12);
    cout << "Vector contents(after insert): [";
    for (int loop = 0; loop < testVector.size(); loop++)
    {
        cout << testVector[loop];
        if (loop < testVector.size() - 1)
        {
            cout << ", ";
        }
        else
        {
            cout << ']' << endl;
        }
    }
    cout << "Current Vector Capacity: " << testVector.capacity() << endl;
    cout << "Current Vector size: " << testVector.size() << endl
         << endl;

    //Testing the constructor(int s), which allows you to set the size of the vector
    cout << "Testing constructor(int s), this sets the max size of the vector..." << endl;
    Shape_Vector<int> sizeTest(10);

    cout << "Current Vector Capacity(variable: sizeTest): " << sizeTest.capacity() << endl
         << endl;

    //testing the copy constructor
    cout << "testing copy constructor..." << endl;
    Shape_Vector<int> copyTest(testVector);

    cout << "Vector contents(variable: copyTest): [";
    for (int loop = 0; loop < copyTest.size(); loop++)
    {
        cout << copyTest[loop];
        if (loop < copyTest.size() - 1)
        {
            cout << ", ";
        }
        else
        {
            cout << ']' << endl;
        }
    }
    cout << endl;

    //Testing the copy assignment operation
    cout << "testing copy assignment..." << endl;
    Shape_Vector<int> assignmentTest = testVector;
    cout << "Vector contents(variable: assignmentTest): [";
    for (int loop = 0; loop < assignmentTest.size(); loop++)
    {
        cout << assignmentTest[loop];
        if (loop < assignmentTest.size() - 1)
        {
            cout << ", ";
        }
        else
        {
            cout << ']' << endl;
        }
    }
    cout << endl;

    return 0;
}