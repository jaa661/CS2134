//
//  main.cpp
//  Maze
//
//  Created by Jacob Abbott on 4/6/16.
//  Copyright © 2016 Computer Science 2134. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;

struct position
{
    int x;
    int y;
    
    position(int j, int i): x{j}, y{i}
    { }
    position(): x{0}, y{0}
    { }
    
};

ostream& operator<<(ostream& os, const position pos) {
    os << "[" << pos.x << "," << pos.y << "]" << endl;
    return os;
}

class Maze{
    
public:
    Maze( ifstream& ifs, int i = 0, int j = 0 ) : raw{""}, l{i}, w{j}
    {
        if (!ifs){
            cerr << " ahhhh shucks. the file text.txt could not be opened\n";
            exit(1);
            }
        string next;
        string sum;
        while(ifs >> next){
            sum = sum+next;
        }
        raw = sum;
        fillMaze();
    }

    position getpos(){
        return pos;
    }
    void printMaze(){
        for (int i = 0; i < l; i++){
            for (int j = 0; j < w; j++)
                cout << myMaze[i][j] ;
            cout << endl;
        }
        cout <<endl;
    }
    
    void solution1Rec(position sent){
        if (myMaze[sent.y][sent.x] == 'e'){
            end.x = sent.x;
            end.y = sent.y;
            cout << "You've completed the maze! The end was found at " << end <<endl;
            found = true;
            return;
        }
        if (!(myMaze[sent.y][sent.x]== 's') || (myMaze[sent.y][sent.x]== 'e'))
            myMaze[sent.y][sent.x] = 'O';
        
        if ((sent.y > 0) && (found == false) &&
            ((myMaze[sent.y - 1][sent.x] == 'e')||(myMaze[sent.y - 1][sent.x] == '.'))){
            position newpos(sent.x,sent.y-1);
            solution1Rec(newpos);
        }
        if ((sent.y < l) && (found == false) &&
            ((myMaze[sent.y +1][sent.x] == 'e')||(myMaze[sent.y +1][sent.x] == '.'))){
            position newpos(sent.x,sent.y+1);
            solution1Rec(newpos);
        }
        if ((sent.x > 0) && (found == false) &&
            ((myMaze[sent.y][sent.x - 1] == 'e')||(myMaze[sent.y][sent.x - 1] == '.'))){
            position newpos(sent.x-1,sent.y);
            solution1Rec(newpos);
        }
        if ((sent.x < w) && (found == false) &&
            ((myMaze[sent.y][sent.x+1] == 'e')||(myMaze[sent.y][sent.x+1] == '.'))){
            position newpos(sent.x+1,sent.y);
            solution1Rec(newpos);
        }
    }
    void solution1(){
        solution1Rec(start);
    }
    
    void solution2(){
        stack<position> visits;
        while (found == false){
            if (myMaze[pos.y][pos.x] == 'e'){
                end.x = pos.x;
                end.y = pos.y;
                cout << "You've completed the maze! The end was found at " << end <<endl;
                found = true;
                return;
            }
            if (!(myMaze[pos.y][pos.x]== 's') || (myMaze[pos.y][pos.x]== 'e'))
                myMaze[pos.y][pos.x] = 'O';
            
            if ((pos.y > 0) && (found == false) &&
                ((myMaze[pos.y - 1][pos.x] == 'e')||(myMaze[pos.y - 1][pos.x] == '.'))){
                position newpos(pos.x,pos.y-1);
                visits.push(newpos);
            }
            else if ((pos.y < l) && (found == false) &&
                ((myMaze[pos.y +1][pos.x] == 'e')||(myMaze[pos.y +1][pos.x] == '.'))){
                position newpos(pos.x,pos.y+1);
                visits.push(newpos);
            }
            else if ((pos.x > 0) && (found == false) &&
                ((myMaze[pos.y][pos.x - 1] == 'e')||(myMaze[pos.y][pos.x - 1] == '.'))){
                position newpos(pos.x-1,pos.y);
                visits.push(newpos);
            }
            else if ((pos.x < w) && (found == false) &&
                ((myMaze[pos.y][pos.x+1] == 'e')||(myMaze[pos.y][pos.x+1] == '.'))){
                position newpos(pos.x+1,pos.y);
                visits.push(newpos);
            }
            else
                visits.pop();
            pos.x = visits.top().x;
            pos.y = visits.top().y;
        }
    }
    void solution3(){
        queue<position> visits;
        visits.push(start);
        printMaze();
        while (found == false){
            for(int i = 0; i < visits.size();i++){
            if (myMaze[visits.front().y][visits.front().x] == 'e'){
                end.x = visits.front().x;
                end.y = visits.front().y;
                cout << "You've completed the maze! The end was found at " << end <<endl;
                found = true;
                return;
            }
            if (!(myMaze[visits.front().y][visits.front().x]== 's') || (myMaze[visits.front().y][visits.front().x]== 'e'))
                myMaze[visits.front().y][visits.front().x] = 'O';
            
            if ((visits.front().x > 0) && (found == false) &&
                     ((myMaze[visits.front().y][visits.front().x - 1] == 'e')||(myMaze[visits.front().y][visits.front().x - 1] == '.'))){
                position newpos(visits.front().x-1,visits.front().y);
                visits.push(newpos);
            }
            if ((visits.front().x < w) && (found == false) &&
                     ((myMaze[visits.front().y][visits.front().x+1] == 'e')||(myMaze[visits.front().y][visits.front().x+1] == '.'))){
                position newpos(visits.front().x+1,visits.front().y);
                visits.push(newpos);
            }
            if ((visits.front().y > 0) && (found == false) &&
                ((myMaze[visits.front().y - 1][visits.front().x] == 'e')||(myMaze[visits.front().y - 1][visits.front().x] == '.'))){
                position newpos(visits.front().x,visits.front().y-1);
                visits.push(newpos);
            }
            if ((visits.front().y < l) && (found == false) &&
                     ((myMaze[visits.front().y +1][visits.front().x] == 'e')||(myMaze[visits.front().y +1][visits.front().x] == '.'))){
                position newpos(visits.front().x,visits.front().y+1);
                visits.push(newpos);
            }
                visits.pop();
                printMaze();
        }
    }
    }
    stack<position> bestPath(){
        stack<position> visits;
        while (found == false){
            if (myMaze[pos.y][pos.x] == 'e'){
                end.x = pos.x;
                end.y = pos.y;
                cout << "You've completed the maze! The end was found at " << end <<endl;
                found = true;
            }
            if (!(myMaze[pos.y][pos.x]== 's') || (myMaze[pos.y][pos.x]== 'e'))
                myMaze[pos.y][pos.x] = 'O';
            
            if ((pos.y > 0) && (found == false) &&
                ((myMaze[pos.y - 1][pos.x] == 'e')||(myMaze[pos.y - 1][pos.x] == '.'))){
                position newpos(pos.x,pos.y-1);
                visits.push(newpos);
            }
            else if ((pos.x < w) && (found == false) &&
                     ((myMaze[pos.y][pos.x+1] == 'e')||(myMaze[pos.y][pos.x+1] == '.'))){
                position newpos(pos.x+1,pos.y);
                visits.push(newpos);
            }
            else if ((pos.y < l) && (found == false) &&
                ((myMaze[pos.y +1][pos.x] == 'e')||(myMaze[pos.y +1][pos.x] == '.'))){
                position newpos(pos.x,pos.y+1);
                visits.push(newpos);
            }
            else if ((pos.x > 0) && (found == false) &&
                ((myMaze[pos.y][pos.x - 1] == 'e')||(myMaze[pos.y][pos.x - 1] == '.'))){
                position newpos(pos.x-1,pos.y);
                visits.push(newpos);
            }
            else if ((pos.y > 0) && (found == false) &&
                ((myMaze[pos.y - 1][pos.x] == 'e')||(myMaze[pos.y - 1][pos.x] == '.'))){
                position newpos(pos.x,pos.y-1);
                visits.push(newpos);
            }
            else
                visits.pop();
            pos.x = visits.top().x;
            pos.y = visits.top().y;
        }
        return visits;
    }
    void best(){
        stack<position> visits = bestPath();
        fillMaze();
        for(int i = visits.size(); i > 0; i--){
            myMaze[visits.top().y][visits.top().x] = 'O';
            visits.pop();
        }
    }
private:
    vector<vector<char>> myMaze;
    string raw;
    int w;
    int l;
    position start;
    position end;
    position pos;
    bool found = false;
    
    void fillMaze(){
        myMaze.clear();
        vector<char> row;
        for (int i = 0; i < l; i++){
            for (int j = 0; j < w; j++){
                row.push_back(raw[(i*w)+j]);
                if (raw[(i*w)+j] == 's'){
                    pos.x = j;
                    pos.y = i;
                    start.x = j;
                    start.y = i;
                }
            }
            myMaze.push_back(row);
            row.clear();
        }
    }

};

int main() {
    ifstream ifs("/Users/pierules53/Desktop/text.txt");
    
    //cout << sum;
    Maze myMaze(ifs,9,18);
    myMaze.printMaze();
    //myMaze.solution1();
    //myMaze.solution2();
    //myMaze.solution3();
    myMaze.best();
    myMaze.printMaze();
    return 0;
}
