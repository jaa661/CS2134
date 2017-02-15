//
//  main.cpp
//  HW08
//
//  Created by Jacob Abbott on 4/13/16.
//  Copyright © 2016 Computer Science 2134. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <map>

using namespace std;

ifstream open(string file){
    ifstream ifs(file);
    if (!ifs){
        cerr << " ahhhh shucks. the file "+ file +" could not be opened\n";
        exit(1);
    }
    return ifs;
}

void fillValues(vector<int>& pointValue){
    pointValue.push_back(1);//a
    pointValue.push_back(4);//b
    pointValue.push_back(4);//c
    pointValue.push_back(2);//d
    pointValue.push_back(1);//e
    pointValue.push_back(4);//f
    pointValue.push_back(3);//g
    pointValue.push_back(3);//h
    pointValue.push_back(1);//i
    pointValue.push_back(10);///j
    pointValue.push_back(5);//k
    pointValue.push_back(2);///l
    pointValue.push_back(4);//m
    pointValue.push_back(2);//n
    pointValue.push_back(1);//o
    pointValue.push_back(4);///p
    pointValue.push_back(10);//q
    pointValue.push_back(1);//r
    pointValue.push_back(1);//s
    pointValue.push_back(1);//t
    pointValue.push_back(2);//u
    pointValue.push_back(5);//v
    pointValue.push_back(4);//w
    pointValue.push_back(8);//x
    pointValue.push_back(3);//y
    pointValue.push_back(10);//z
}

int findValue(string word, vector<int> pointValue){
    int sum = 0;
    for(int i= 0; i < word.size(); i++){
        sum+= pointValue[(int(tolower(word[i]))-97)];
    }
    return sum;
}

void printWords(map<string, int>& values){
    map<string,int>::iterator itr;
    for(itr = values.begin();itr !=values.end();itr++){
        cout << itr->first << "  has value: "<< itr->second <<endl;
    }
}

int main() {
    string filestring = "/Users/pierules53/Downloads/ENABLE.txt";
    ifstream ifs = open(filestring);
    string nextword;
    vector<int> pointValue;
    fillValues(pointValue);
    map<string, int> WordsWithValues;
    
    
    while( ifs >> nextword){
        WordsWithValues[nextword] = findValue(nextword, pointValue);
    }
    
    printWords(WordsWithValues);
    int a = int('b');
    cout << a;
    
    return 0;
}
