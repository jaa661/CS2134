//
//  main.cpp
//  Hw10
//
//  Created by Jacob Abbott on 5/3/16.
//  Copyright © 2016 Computer Science 2134. All rights reserved.
//



/*

template <class Comparable>
void BinaryHeap::insert(const Comparable &element){
    array.resize();
    array[theSize] = element;
    theSize++;
    int index = theSize - 1;
    int parent = (index -1)/2;
    while(array[parent] < array[index]){
        int temp = array[parent];
        array[parent] = array[index];
        array[index] = temp;
    }
}
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;


template <class Comparable>
void print_kth_largest_items(const vector<Comparable> & a, int k){
    priority_queue<int> mypq;
    for(int i = 0; i < a.size(); i++)
        mypq.push(a[i]);
    for(int i = 0; i < k; i++){
        cout << " " << mypq.top()<< endl;
        mypq.pop();
    }
}

template <class Comparable>
void print_kth_largest(const vector<Comparable> & a, int k){
    priority_queue<int> mypq;
    for(int i = 0; i < a.size(); i++)
        mypq.push(a[i]);
    for(int i = 0; i < k-1; i++)
        mypq.pop();
    cout << " " << mypq.top()<< endl;
}

int main() {
    vector<int> mypq;
    //priority_queue<int> mypq;
    //so i wasn't sure if i was supposed to print all items up to the kth largest or just it cause of weird wording, so i did both
    mypq.push_back(30);
    mypq.push_back(100);
    mypq.push_back(25);
    mypq.push_back(40);
    mypq.push_back(30);
    mypq.push_back(100);
    mypq.push_back(25);
    mypq.push_back(40);
    mypq.push_back(30);
    mypq.push_back(100);
    mypq.push_back(25);
    mypq.push_back(40);
    print_kth_largest(mypq, 4);
    return 0;
}




TMEPPPPPPP


/*
 * Complete the function below.
 */
int Counter(string s, char c){
    int count = 0;
    for (int i = 0; i < s.size() < i++){
        if (s[i] == c)
            count ++;
    }
    return count;
}
vector < string > checkIP(vector < string > ip) {
    for (string s : checkIP){
        if(Counter(s,':') = 7){
            cout << "IPv6"<< endl;
        }
        else if(Counter(s,'.') = 3){
            cout << "IPv4"<< endl;
        }
        else{
            cout << "Neither"<< endl;
        }
    }
    
}
