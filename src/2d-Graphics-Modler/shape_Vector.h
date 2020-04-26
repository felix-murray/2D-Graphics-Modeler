#ifndef SHAPE_VECTOR_H
#define SHAPE_VECTOR_H

#include <iostream>

template <class T>
class Shape_Vector
{
    private:
        int size_v;             //size of elements currently in the array
        T* elem;                //pointer to elements
        int space;              //size + free_space
                                //in other words, max size of array
    public:
        /*********  CONSTRUCTORS  **********/
        Shape_Vector();                          //default constructor
        explicit Shape_Vector(int s);            //alternate constructor
        Shape_Vector(const Shape_Vector&);             //copy constructor
        Shape_Vector& operator=(const Shape_Vector&);  //copy assignment

        Shape_Vector(const Shape_Vector&&);            //move constructor
        Shape_Vector& operator=(const Shape_Vector&&); //move assignment

        ~Shape_Vector();                         //destructor

        /*********  ACCESS  **********/
        //Overloads the [] operator to allow indexing on the Shape_Vector.
        //post-condition: return elem[n];
        T& operator[] (int n);
//      const T& operator[] (int n);

        /*********  Shape_Vector FUNCTION  **********/

        //Returns the number of elements that are currently in the list.
        //post-condition: return size_v;
        int size() const;

        //Returns the max number of elements that a can go into the Shape_Vector.
        //post-condition: return space;
        int capacity() const;

        //Changes the max number of elements in the Shape_Vector.
        //post-condition: space = newSize;
        void resize(int newSize);

        //Inserts an element at the end of the Shape_Vector.
        //post-condtion: val element is inserted at the end of
        //               Shape_Vector list.
        void push_back(T val);

        //Requests that the Shape_Vector has enough space to contain n(newAlloc) number of elements.
        //post-condition: if newAlloc > space, then space = newAlloc.
        //                in other cases, the function will have no affect on the Shape_Vector.
        void reserve(int newAlloc);

        /*********  ITERATOR  **********/
        using iterator = T*;
        using const_iterator = const T*;

        //returns an iterator that points to the beginning of the Shape_Vector.
        //pre-condition: The Shape_Vector must exist.
        //post-condition: return elem;
        iterator begin();

        //returns an iterator that points to the beginning of the Shape_Vector.
        //pre-condition: The Shape_Vector must exist.
        //post-condition: return elem;
        const_iterator begin() const;

        //returns an iterator that points to the end of the Shape_Vector.
        //pre-condition: The Shape_Vector must exist and must have at least one element.
        //post-condition: return elem + space;
        iterator end();

        //returns an iterator that points to the end of the Shape_Vector.
        //pre-condition: The Shape_Vector must exist and must have at least one element.
        //post-condition: return elem + space;
        const_iterator end() const;

        //Inserts the element v before an element at the specified location in the Shape_Vector.
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
Shape_Vector<T>::Shape_Vector()
{
    size_v = 0;
    elem    = nullptr;
    space  = 0;
}

template <class T>
Shape_Vector<T>::Shape_Vector(int s)
{
    size_v = 0;
    space  = s;
    elem   = new T[s];
}

template <class T>
Shape_Vector<T>::Shape_Vector(const Shape_Vector& otherShape_Vector)
{
    size_v = otherShape_Vector.size_v;
    space  = otherShape_Vector.space;
    elem   = new T[space];
    for(int loop = 0; loop < size_v; loop++)    //copies the elements of otherShape_Vector into the new Shape_Vector.
    {
        elem[loop] = otherShape_Vector.elem[loop];
    }
}

template <class T>
Shape_Vector<T>& Shape_Vector<T>::operator=(const Shape_Vector& otherShape_Vector)
{
    size_v = otherShape_Vector.size_v;
    space  = otherShape_Vector.space;
    elem   = new T[space];

    for(int loop = 0; loop < size_v; loop++)
    {
        elem[loop] = otherShape_Vector.elem[loop];    //copies the elements of otherShape_Vector into the new Shape_Vector.
    }
}

template <class T>
Shape_Vector<T>::Shape_Vector(const Shape_Vector&& otherShape_Vector)
{
    size_v = otherShape_Vector.size_v;
    space  = otherShape_Vector.space;
    elem   = otherShape_Vector.elem;          //elem points to original array.

    otherShape_Vector.size_v = 0;
    otherShape_Vector.space  = 0;
    otherShape_Vector.elem   = nullptr;       //original Shape_Vector points to nullptr.
}

template <class T>
Shape_Vector<T>& Shape_Vector<T>::operator=(const Shape_Vector&& otherShape_Vector)
{
    size_v = otherShape_Vector.size_v;
    space  = otherShape_Vector.space;
    elem   = otherShape_Vector.elem;          //elem points to original array.

    otherShape_Vector.size_v = 0;
    otherShape_Vector.space  = 0;
    otherShape_Vector.elem   = nullptr;       //original Shape_Vector points to nullptr.
}

template <class T>
Shape_Vector<T>::~Shape_Vector()
{
    delete [] elem;
}

template <class T>
T& Shape_Vector<T>::operator[](int n)
{
    return elem[n];
}

/*********************************************************************
 * Conflicts with the implementation of the operator[] overload above
 *********************************************************************/
/*
template <class T>
const T& Shape_Vector<T>::operator[](int n)
{
    return elem[n];
}
*/

template <class T>
int Shape_Vector<T>::size()const
{
    return size_v;
}

template <class T>
int Shape_Vector<T>::capacity()const
{
    return space;
}

template <class T>
void Shape_Vector<T>::resize(int newSize)
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
        elem = newArray;                          //makes the Shape_Vector point to the new resized array.
    }
    else
    {
        std::cout << "ERROR: Newly specified max size is the same as original max size." << std::endl;
    }

}

template <class T>
void Shape_Vector<T>::push_back(T val)
{
    if(size_v + 1 <= space)         //checks to see if adding an element will cause an overflow.
    {
        elem[size_v] = val;         //adds element and increments size_v by 1
        size_v++;
    }
    else
    {
        std::cout << "ERROR: adding new element will go over max size." << std::endl;
    }
}

template <class T>
void Shape_Vector<T>::reserve(int newAlloc)
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
            elem = tempArray;       //the Shape_Vector now points to the new array.
        }
        else
        {
            std::cout << "ERROR: Specified size is too small. Shape_Vector size will stay the same." << std::endl;
        }
    }
    else
    {
        std::cout << "ERROR: Specified size is the same as Shape_Vector size. " << std::endl;
    }
}

template <class T>
typename Shape_Vector<T>::iterator Shape_Vector<T>::begin()
{
    return elem;    //returns a pointer to the first element of the array
}

template <class T>
typename Shape_Vector<T>::const_iterator Shape_Vector<T>::begin()const
{
    return elem;    //returns a pointer to the first element of the array
}

template <class T>
typename Shape_Vector<T>::iterator Shape_Vector<T>::end()
{
    return elem + (size_v - 1);  //returns a pointer to the last element of the array
}

template <class T>
typename Shape_Vector<T>::const_iterator Shape_Vector<T>::end()const
{
    return elem + (size_v - 1); //returns a pointer to the last element of the array
}

template <class T>
typename Shape_Vector<T>::iterator Shape_Vector<T>::insert(iterator p, const T& v)
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
typename Shape_Vector<T>::iterator Shape_Vector<T>::erase(iterator p)
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

#endif // Shape_Vector_H
