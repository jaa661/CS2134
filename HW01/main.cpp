/* 
 * File:   main.cpp
 * Author: Jacob Abbott
 *
 * 
 */

#include <cstdlib>
#include <vector>
#include <time.h>
#include <ctime>
#include <math.h>
#include <iostream>
using namespace std;


class timer {
public:
    timer() : start(clock()) {}
    double elapsed() 
    { 
        return ( clock() - start ) / CLOCKS_PER_SEC; 
    }
    
    void reset() { 
        start = clock(); 
        }
private:
    double start;
};
/////////////////////////////////////////////////////////////////////////////
int maxSubSum1( const vector<int> & a );
int maxSubSum2( const vector<int> & a );
int maxSubSum4( const vector<int> & a );
void writtenQa(int n);
void writtenQb(int n);
void writtenQc(int n);
void writtenQd(int n);
void fillVector(vector<int>& toFill, int size);
void findTimes(vector<int>& myVector, int size);
void findWrittenTimes(int n);
/////////////////////////////////////////////////////////////////////////////
int main() {

    vector<int> myVector;
    for (int i = 7; i<13; i++)
        findTimes(myVector, i);
    
    for (int n = 8; n<13; n++)
        findWrittenTimes(n);
    
    return 0;
}
/////////////////////////////////////////////////////////////////////////////
void writtenQa(int n){    
    int sum=0;
    for (int i = 0; i < n; i++)
        ++sum;   
}
void writtenQb(int n){ 
    int sum=0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; ++j)
            ++sum;
}
void writtenQc(int n){ 
    int sum =0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; ++j)
            ++sum;   
}
void writtenQd(int n){ 
    int sum=0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; ++j)
            for(int k = 0; k < n; ++k)
                ++sum;
}
void findWrittenTimes(int n){
    timer t;
    double numClicks;
    //cout << CLOCKS_PER_SEC << endl;
    cout.precision(numeric_limits<double>::digits10 + 1);
    t.reset();
    writtenQa(5000);
    numClicks = t.elapsed();
    cout << "2a took "<< (numClicks/5000) * pow(2,n)<< " seconds... with n = 2^"<< n<<endl;
    
    t.reset();
     writtenQb(5000);
    numClicks = t.elapsed();
    cout << "2b took "<< (numClicks/5000) * pow(2,n) << " seconds... with n = 2^"<< n<<endl;
    
    t.reset();
     writtenQc(5000);
    numClicks = t.elapsed();
    cout << "2c took "<< (numClicks/5000) * pow(2,n) << " seconds... with n = 2^"<< n<<endl;
    
    t.reset();
     writtenQd(1000);
    numClicks = t.elapsed();
    cout << "2d took "<< (numClicks/1000) * pow(2,n) << " seconds... with n = 2^"<< n<<endl<<endl<<endl;
}

void findTimes(vector<int>& myVector, int size){
    timer t;
    double numClicks;
    //cout << CLOCKS_PER_SEC << endl;
    cout.precision(numeric_limits<double>::digits10 + 1);
    fillVector(myVector, pow(2,size));
    t.reset();
    maxSubSum1(myVector);
    numClicks = t.elapsed();
    cout << "maxSubSum1 took "<< numClicks << " seconds... with n = 2^"<< size<<endl;
    
    t.reset();
    maxSubSum2(myVector);
    numClicks = t.elapsed();
    cout << "maxSubSum2 took "<< numClicks << " seconds... with n = 2^"<< size<<endl;
    
    t.reset();
    maxSubSum4(myVector);
    numClicks = t.elapsed();
    cout << "maxSubSum4 took "<< numClicks << " seconds... with n = 2^"<< size<<endl<<endl<<endl;
    myVector.clear();
}


void fillVector(vector<int>& toFill, int size){
    for(int i = 0; i <size; i++){
        toFill.push_back((rand() % 2001) - 1000);
    }
}

/**
 * Cubic maximum contiguous subsequence sum algorithm.
 */
int maxSubSum1( const vector<int> & a )
{
    int maxSum = 0;

    for( int i = 0; i < a.size( ); ++i )
        for( int j = i; j < a.size( ); ++j )
        {
            int thisSum = 0;

            for( int k = i; k <= j; ++k )
                thisSum += a[ k ];

            if( thisSum > maxSum )
                maxSum   = thisSum;
        }

    return maxSum;
}

/**
 * Quadratic maximum contiguous subsequence sum algorithm.
 */
int maxSubSum2( const vector<int> & a )
{
    int maxSum = 0;

    for( int i = 0; i < a.size( ); ++i )
    {
        int thisSum = 0;
        for( int j = i; j < a.size( ); ++j )
        {
            thisSum += a[ j ];

            if( thisSum > maxSum )
                maxSum = thisSum;
        }
    }

    return maxSum;
}

/**
 * Linear-time maximum contiguous subsequence sum algorithm.
 */
int maxSubSum4( const vector<int> & a )
{
    int maxSum = 0, thisSum = 0;

    for( int j = 0; j < a.size( ); ++j )
    {
        thisSum += a[ j ];

        if( thisSum > maxSum )
            maxSum = thisSum;
        else if( thisSum < 0 )
            thisSum = 0;
    }

    return maxSum;
}


