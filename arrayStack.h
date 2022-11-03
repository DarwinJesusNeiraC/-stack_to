#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
#include <assert.h>
#include "stack.h"
#define FACTOR 10

template<typename T>
class ArrayStack: public Stack<T>{
  private:
    int size; // memory size
    T* sp; // stack pointer
    void resize();
    T* data;
  public:
    /*
    ArrayStack(int s): size{s}, data{new T [s]}{
      sp=data;
      //assert(size<=0); // si el tamñao de sae es emenor a 0 no se peude crear el array
    }*/
    ArrayStack (int);
    void push(T);
    //void push(T, int);
    void pop();
    T top();
    bool empty();
};
#endif
