#include <iostream>
#include <vector>

using namespace std;

class Warehouse{
public:
    vector<vector<int> > map;
    Warehouse(int row, int col){
        vector<vector<int> > tmp(row + 1, vector<int>(col + 1, 0)); //Initialization of the map, and robots  
        map = tmp;                                                                //appear to be 0 -> does not exist.
    }
};

class Robots{
    int row, col;
    char direction;
public:
    Robots(int r, int c, char d) : row(r), col(c), direction(d){}
    
};


int main(int argc, const char* argv[]){
    return 0;
}