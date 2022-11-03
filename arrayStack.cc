#include <assert.h>
#include "arrayStack.h"
#include <iostream>
#include "gtest/gtest.h"
#include <string.h>

template<typename T>
ArrayStack<T>::ArrayStack(int s){
  size = s;
  data = new T[s];
  sp=data;
}
template<typename T>
void ArrayStack<T>::push(T e){
  int numelem = sp - data;
  if(numelem==size)
    resize();
  *sp = e;
  sp++;
}

template<typename T>
void ArrayStack<T>::pop(){
  assert(data<=sp);
  int numelem = sp - data;
  if(empty())
    return;
  sp--;
}

template<typename T>
T ArrayStack<T>::top(){
  assert(!empty());
  return *(sp-1);
}

template<typename T>
bool ArrayStack<T>::empty(){
  int numelem = sp - data;
  return numelem == 0;
  assert(numelem==0);
}

template<typename T>
void ArrayStack<T>::resize(){
  T *newData = new T [size+FACTOR];
  for(int i=0;i<size;i++)
    newData[i] = data[i];
  delete[] data;
  data = newData;
  sp = data + size;
  size+=FACTOR;
  assert(size>FACTOR);
}
class ArrayStackTest : public ::testing::Test {
 protected:
  void SetUp() override {//constructor
    stack1->push(1);
    stack1->push(2);

    stack2->push(9);
    stack2->push(12);

  }

  // void TearDown() override {}
    void TearDown() override { // destructor
     // Code here will be called immediately after each test (right
     std::cout<< " Eliminando objetos\n";
     delete (stack1);
     delete (stack2);
     delete (stack3);
  }

  ArrayStack<int>*stack1 = new ArrayStack<int>(2);
  ArrayStack<int>*stack2 = new ArrayStack<int>(2);
  ArrayStack<std::string>*stack3 = new ArrayStack<std::string>(2);
};

TEST_F(ArrayStackTest, IsEmpty) {
  EXPECT_EQ(stack1->empty(), false);
  EXPECT_EQ(stack3->empty(), true);
}


TEST_F(ArrayStackTest, WhenTop) {
  EXPECT_EQ(stack2->top(), 9); // fallo
  EXPECT_EQ(stack2->top(), 12);
  //EXPECT_EQ(stack3->top(), nullptr);
}

/*
TEST_F(ArrayStackTest, WhenResize) {
  stack3->push(1);
  stack3->push(2);
  stack3->push(3);
  EXPECT_EQ(stack2->top(), 12);
}
*/

/* 
int main(int argc, char**argv){
  ::testing::INItGOOgleTest(&argc, argv);
  //ArrayStack<int>as(5);
  ArrayStack<int>as(2);
  as.push(1);
  as.push(2);
  as.push(3);
  as.push(4);
  as.push(5);
  as.push(6);
  std::cout<<as.top();
  as.pop();
  std::cout<<as.top();
  as.pop();
  std::cout<<as.top();
  as.pop();
  return RUN_ALL_TEST();
}
*/
