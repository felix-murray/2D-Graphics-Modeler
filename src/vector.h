#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
using namespace std;

template <class T> 
class vector
{
    private:
        int size_v;             //size of elements currently in the array
        T* elem;                //pointer to elements
        int space;              //size + free_space
                                //in other words, max size of array
    public:
        /*********  CONSTRUCTORS  **********/
        vector();                          //default constructor
        explicit vector(int s);            //alternate constructor
        vector(const vector&);             //copy constructor
        vector& operator=(const vector&);  //copy assignment

        vector(const vector&&);            //move constructor
        vector& operator=(const vector&&); //move assignment

        ~vector();                         //destructor

        /*********  ACCESS  **********/
        //Overloads the [] operator to allow indexing on the vector.
        //post-condition: return elem[n];
        T& operator[] (int n);
//      const T& operator[] (int n);
        
        /*********  VECTOR FUNCTION  **********/
        
        //Returns the number of elements that are currently in the list.
        //post-condition: return size_v;
        int size() const;
        
        //Returns the max number of elements that a can go into the vector.
        //post-condition: return space;
        int capacity() const;
        
        //Changes the max number of elements in the vector.
        //post-condition: space = newSize;
        void resize(int newSize);
        
        //Inserts an element at the end of the vector.
        //post-condtion: val element is inserted at the end of 
        //               vector list.
        void push_back(T val);

        //Requests that the vector has enough space to contain n(newAlloc) number of elements.
        //post-condition: if newAlloc > space, then space = newAlloc.
        //                in other cases, the function will have no affect on the vector.
        void reserve(int newAlloc);
        
        /*********  ITERATOR  **********/
        using iterator = T*;
        using const_iterator = const T*;
        
        //returns an iterator that points to the beginning of the vector.
        //pre-condition: The vector must exist.
        //post-condition: return elem;
        iterator begin();

        //returns an iterator that points to the beginning of the vector.
        //pre-condition: The vector must exist.
        //post-condition: return elem;
        const_iterator begin() const;
        
        //returns an iterator that points to the end of the vector.
        //pre-condition: The vector must exist and must have at least one element.
        //post-condition: return elem + space;
        iterator end();

        //returns an iterator that points to the end of the vector.
        //pre-condition: The vector must exist and must have at least one element.
        //post-condition: return elem + space;
        const_iterator end() const;
        
        //Inserts the element v before an element at the specified location in the vector.
        //post-condition: if(size_v + 1 > space), then the function will not add an element.
        //                Otherwise, size_v gets incremented by 1 and the new element will
        //                get inserted at the location before the location specified by iterator p.
        iterator insert(iterator p, const T& v);
        
        //deletes an element from the list.
        //post-condition: if(size_v == 0), then the function will not do anything.
        //                Otherwise, size_v get decremented by 1 and the element
        //                specified by iterator p will get deleted.
        iterator erase(iterator p);
};

template <class T>
vector<T>::vector()
{
    size_v = 0;
    elem    = nullptr;
    space  = 0;
}

template <class T>
vector<T>::vector(int s)
{
    size_v = 0;
    space  = s;
    elem   = new T[s];
}

template <class T>
vector<T>::vector(const vector& otherVector)
{
    size_v = otherVector.size_v;
    space  = otherVector.space;
    elem   = new T[space];
    for(int loop = 0; loop < size_v; loop++)    //copies the elements of otherVector into the new vector.
    {
        elem[loop] = otherVector.elem[loop];
    }
}

template <class T>
vector<T>& vector<T>::operator=(const vector& otherVector)
{
    size_v = otherVector.size_v;
    space  = otherVector.space;
    elem   = new T[space];

    for(int loop = 0; loop < size_v; loop++)    
    {
        elem[loop] = otherVector.elem[loop];    //copies the elements of otherVector into the new vector.
    }
}

template <class T>
vector<T>::vector(const vector&& otherVector)
{
    size_v = otherVector.size_v;
    space  = otherVector.space;
    elem   = otherVector.elem;          //elem points to original array.

    otherVector.size_v = 0;
    otherVector.space  = 0;
    otherVector.elem   = nullptr;       //original vector points to nullptr.
}

template <class T>
vector<T>& vector<T>::operator=(const vector&& otherVector)
{
    size_v = otherVector.size_v;
    space  = otherVector.space;
    elem   = otherVector.elem;          //elem points to original array.

    otherVector.size_v = 0;
    otherVector.space  = 0;
    otherVector.elem   = nullptr;       //original vector points to nullptr.
}

template <class T>
vector<T>::~vector()
{
    delete [] elem;
}

template <class T>
T& vector<T>::operator[](int n)
{
    return elem[n];
}

/*********************************************************************
 * Conflicts with the implementation of the operator[] overload above 
 *********************************************************************/
/*
template <class T>
const T& vector<T>::operator[](int n)
{
    return elem[n];
}
*/

template <class T>
int vector<T>::size()const
{
    return size_v;
}

template <class T>
int vector<T>::capacity()const
{
    return space;
}

template <class T>
void vector<T>::resize(int newSize)
{
    if(newSize != space)
    {
        T* newArray = new T[newSize];             //Dynamically allocates a new array with the size of newSize.
    
        if(newSize > space) //if newSize > space, then all original array elements will be added to the new array.
        {
            for(int loop = 0; loop < size_v; loop++)  //adds the original array elements into the new array.
            {
                newArray[loop] = elem[loop];         
            }
        }
        else       //if newSize < space, then all array elements 
        {          //up to the new max size will be added to the new array.
            size_v = 0;
            for(int loop = 0; loop < newSize; loop++) //adds the original array elements into the new array.
            {
                newArray[loop] = elem[loop];         
                if(elem[loop])
                {
                    size_v++;
                }
            }
        }
    
        space = newSize;
        delete [] elem;                           //deletes old array
        elem = newArray;                          //makes the vector point to the new resized array.
    }
    else
    {
        cout << "ERROR: Newly specified max size is the same as original max size." << endl;
    }
    
}

template <class T>
void vector<T>::push_back(T val)
{
    if(size_v + 1 <= space)         //checks to see if adding an element will cause an overflow.
    {
        elem[size_v] = val;         //adds element and increments size_v by 1
        size_v++;
    }
    else
    {
        cout << "ERROR: adding new element will go over max size." << endl;
    }
}

template <class T>
void vector<T>::reserve(int newAlloc)
{
    if(newAlloc != space)       //checks to see if the specified size is the same as the original size.
    { 
        if(newAlloc > space)    //checks to see if the specified size is smaller than the original size.
        {
            space = newAlloc;
            T* tempArray = new T[space];    //creates a new array with a max size equal to the specified size.

            for(int loop = 0; loop < size_v; loop++)    //fills the new array with the elements from the original array
            {
                tempArray[loop] = elem[loop];
            }

            delete [] elem;         //deletes the old array
            elem = tempArray;       //the vector now points to the new array.
        }
        else
        {
            cout << "ERROR: Specified size is too small. Vector size will stay the same." << endl;
        }
    }
    else
    {
        cout << "ERROR: Specified size is the same as vector size. " << endl;
    }
}

template <class T>
typename vector<T>::iterator vector<T>::begin()
{
    return elem;    //returns a pointer to the first element of the array
}

template <class T>
typename vector<T>::const_iterator vector<T>::begin()const
{
    return elem;    //returns a pointer to the first element of the array
}

template <class T>
typename vector<T>::iterator vector<T>::end()
{
    return elem + (size_v - 1);  //returns a pointer to the last element of the array
}

template <class T>
typename vector<T>::const_iterator vector<T>::end()const
{
    return elem + (size_v - 1); //returns a pointer to the last element of the array
}

template <class T>
typename vector<T>::iterator vector<T>::insert(iterator p, const T& v)
{
    T tempVariable;
    T tempVariableTwo;
    int difference = &elem[space - 1] - p;     //finds the difference between the max size of the array
                                               //and the insert point.
    
    if(size_v + 1 <= space)
    {
        tempVariable = *p;
        for(int loop = 0; loop < difference; loop++) //Shifts all elements after the insert point to the right by one
        {
            tempVariableTwo = *(p + 1);     
            p = p + 1;
            *p = tempVariable;
            tempVariable = tempVariableTwo;
        }
        
        for(int revert = 0; revert < difference; revert++)  //reverts the interator back to it's starting point
        {
            p = p - 1;
        }
        *p = v;     //inserts the element at the insert point.
        size_v++;
    }
    return p;
}

template <class T>
typename vector<T>::iterator vector<T>::erase(iterator p)
{
    T tempVariable;
    int difference = &elem[space - 1] - p;

    *p = 0; 
    for(int loop = 0; loop < difference; loop++) //shifts all elements on the right side of the deletion point
    {                                            //to the left in order to fill up the "hole" in the array after deletion
        tempVariable = *(p + 1);
        *p = tempVariable;
        p = p + 1;
    }
    *p = 0;

    for(int revert = 0; revert < difference; revert++) // reverts the iterator back to it's starting point
    {
        p = p - 1;
    }
    size_v--;   //decrements the number of elements in the array.

    return p;
}

#endif