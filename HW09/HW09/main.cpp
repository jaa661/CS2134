//
//  main.cpp
//  HW09
//
//  Created by Jacob Abbott on 4/27/16.
//  Copyright © 2016 Computer Science 2134. All rights reserved.
//

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <list>

using namespace std;

template< class HashedObj >
class HashTable
{
public:
    explicit HashTable( int size = 101 ):currentSize(0){
        array.resize(size);
        hash<HashedObj> hf; // create a hash function object
    }
//////////////////////////////////////////////////////Find
    bool find(const HashedObj & x) const{
        int i = hf(x) % array.size();
        while (array[i].info == ACTIVE) {
            if (array[i].element == x)
                return true;
            if (i == array.size()-1)
                i = 0;
            else
                i++;
        }
        return false;
    }
//////////////////////////////////////////////////////
    void makeEmpty( );
/////////////////////////////////////////////////////Insert
    bool insert( const HashedObj & x ){
        if (find(x))
            return false;
        if ((currentSize / array.size()) >= 0.5) {
            rehash();
        }
        int i = hf(x) % array.size();
        while ( array[i].info == ACTIVE) {
            if (i == array.size()-1)
                i = 0;
            else
                i++;
        }
        array[i].element = x;
        array[i].info = ACTIVE;
        currentSize++;
        return true;
    }
/////////////////////////////////////////////////////
    bool remove( const HashedObj & x);
    enum EntryType { ACTIVE, EMPTY, DELETED };
private:
    struct HashEntry
    {
        HashedObj element;
        EntryType info;
        HashEntry( const HashedObj & e = HashedObj(), EntryType i = EMPTY )
        : element( e), info(i) {}
    };
    vector<HashEntry> array;
    int currentSize;
/////////////////////////////////////////Rehash
    void rehash() {
        vector<HashEntry> oldArray = std::move(array);
        array.clear();
        currentSize = 0;
        array.resize((2 * oldArray.size()) + 1);
        for (int index = 0; index < oldArray.size(); index++) {
            insert(oldArray[index].element);
        }
    }
////////////////////////////////////////////////
};

///////////////////////////TRAINSTRAINSTRAINS

void parseTrainData(string filename, ifstream& file, unordered_map<string, list<string>>& map){
    ifstream ifs(filename);
    if (!ifs){
        cerr << " ahhhh shucks. the file could not be opened\n";
        exit(1);
    }
    
    string currentLine;
    string ID;
    string transfer;
    getline(file, currentLine);
    
    while(ifs){
        getline(ifs, currentLine);
        stringstream datastream(currentLine);
        getline(datastream, ID, ',');
        getline(datastream, transfer, ',');
        if (map.find(ID) == map.end()) {
            list<string> transfers;
            transfers.push_back(transfer);
            map.emplace(ID, transfers);
        }
        else
            map.find(ID)->second.push_back(transfer);
    }
    
    ifs.close();
}




int main() {
    
    
    return 0;
}
