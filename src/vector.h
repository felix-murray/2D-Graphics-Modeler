#ifndef VECTOR_H_
#define VECTOR_H_

template <class T> 
class vector
{
    private:
        int size_v;             //size
        T* elem;                //pointer to elements
        int space;              //size + free_space
    public:
        /*********  CONSTRUCTORS  **********/
        vector();                                //default constructor
        explicit vector(int s);                  //alternate constructor
        vector(const vector&);                   //copy constructor
        vector& operator=vector(const vector&);  //copy assignment

        vector(const vector&&);                  //move constructor
        vector& operator=vector(const vector&&); //move assignment

        ~vector();                              //destructor

        /*********  ACCESS  **********/
        T& operator[] (int n);
        const T& operator[] (int n);
        
        /*********  VECTOR FUNCTION  **********/
        int size() const;
        int capacity() const;
        void resize(int newsize);
        void push_back(T val);
        void reserve(int newalloc);
        
        /*********  ITERATOR  **********/
        using iterator = T*;
        using const_iterator = const T*;
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        iterator insert(iterator p, const T& v);
        iterator erase(iterator p);
};

#endif