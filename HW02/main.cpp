
/* 
 * File:   main.cpp
 * Author: Jacob Abbott
 *
 */

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

   class IntArray{
     public:
         IntArray(int n = 0): size(n), array(new int[n]){}
         // copy constructor
         IntArray(IntArray& rhs):size(rhs.size), array(new int[rhs.size])
         {
            cout << "copy constructor"<<endl;
            for(int i = 0; i < rhs.size; i++)   
               array[i] = rhs.array[i];      
         }
         // move constructor
         IntArray(IntArray&& rhs):size(rhs.size), array(rhs.array)
         {
             cout << "move constructor"<<endl;
             rhs.array = nullptr;
         }
         // destructor
         ~IntArray()
         {
             cout << "destructor"<<endl;
             delete[] array;
         }
         void put (int  i, int value){
             array[i] = value;
         }
         int get( int i){
             return array[i];
         }
         // move assignment operator
         IntArray & operator=(IntArray & rhs);
     private:
         int * array;
         int size; 
   };
IntArray & IntArray::operator=(IntArray& rhs)
{
 if( this != & rhs ){
    size = rhs.size;
    cout << "assignment"<<endl;
    array = rhs.array;
    rhs.array = nullptr;
 }
 return *this;
}
    

int main( ) {
     
    IntArray a(5);
    for(int i =0; i < 5; i++){
        a.put(i, i);
    }
    for(int i =0; i < 5; i++){
       cout << a.get(i);
    }
    cout << endl;
    
    IntArray b(a);
    for(int i =0; i < 5; i++){
       cout << b.get(i);
    }
    cout << endl;
    
    IntArray c(std::move(b));
    for(int i =0; i < 5; i++){
       cout << c.get(i);
    }
    cout << endl;
    
    IntArray d(5);
    for(int i =5; i > 0; i--){
        d.put(i, i);
    }
    d = a; 
    for(int i =0; i < 5; i++){
       cout << d.get(i);
    }
    cout << endl;
}