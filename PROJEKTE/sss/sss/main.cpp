#include <iostream>
#include <vector>

using namespace std;

class Warehouse{
public:
    vector<vector<int> > matrix;
    void setWarehouse(int row, int col){
        vector<vector<int> > tmp(row, vector<int>(col, 0));
        matrix = tmp;
    }
};

class Robots{
    int row;
    int col;
    char cur_direction;
    int isvalid = 0;
public:
    void setPos(int i, int j, char direction, Warehouse& warehouse){
        row = i;
        col = j;
        warehouse.matrix[row-1][col-1] = 1;
        cur_direction = direction;
    }
    
    int changePos(Warehouse& warehouse){
        switch(cur_direction){
            case 'E':
                if(warehouse.matrix[row-1][col] && col + 1 < warehouse.matrix[0].size()) return 1;
                if(col == warehouse.matrix[0].size()) return 2;
                warehouse.matrix[row-1][col-1] = 0;
                col++;
                warehouse.matrix[row-1][col-1] = 1;
                break;
            case 'W':
                if(warehouse.matrix[row-1][col-1] && col - 1 >= 1) return 1;
                if(col == 0) return 2;
                warehouse.matrix[row-1][col-1] = 0;
                col--;
                warehouse.matrix[row-1][col-1] = 1;
                break;
            case 'N':
                if(warehouse.matrix[row][col-1] && row - 1 <warehouse.matrix.size()) return 1;
                if(row == warehouse.matrix.size()) return 2;
                warehouse.matrix[row-1][col-1] = 0;
                row--;
                warehouse.matrix[row-1][col-1] = 1;
                break;
            case 'S':
                if(warehouse.matrix[row][col-1] && row + 1 >= 1) return 1;
                if(row == 0) return 2;
                warehouse.matrix[row-1][col-1] = 0;
                row++;
                warehouse.matrix[row-1][col-1] = 1;
                break;
        }
        return 0;
    }
    
    void Reverse(char direction, int repeat){
        switch(direction){
            case 'L':
                if(cur_direction == 'E') {
                    int tmp = repeat % 4;
                    switch(tmp){
                        case 1:
                            cur_direction = 'N';
                            break;
                        case 2:
                            cur_direction = 'W';
                            break;
                        case 3:
                            cur_direction = 'S';
                            break;
                        default:
                            break;
                    }
                    
                }
                if(cur_direction == 'W') {
                    
                    int tmp = repeat % 4;
                    switch(tmp){
                        case 1:
                            cur_direction = 'S';
                            break;
                        case 2:
                            cur_direction = 'E';
                            break;
                        case 3:
                            cur_direction = 'N';
                            break;
                        default:
                            break;
                    }
                }
                if(cur_direction == 'N'){
                    int tmp = repeat % 4;
                    switch(tmp){
                        case 1:
                            cur_direction = 'W';
                            break;
                        case 2:
                            cur_direction = 'S';
                            break;
                        case 3:
                            cur_direction = 'E';
                            break;
                        default:
                            break;
                    }}
                if(cur_direction == 'S') {
                        int tmp = repeat % 4;
                        switch(tmp){
                            case 1:
                                cur_direction = 'E';
                                break;
                            case 2:
                                cur_direction = 'N';
                                break;
                            case 3:
                                cur_direction = 'W';
                                break;
                            default:
                                break;
                        }
                }
                break;
            case 'R':
                if(cur_direction == 'E') {
                        int tmp = repeat % 4;
                        switch(tmp){
                            case 1:
                                cur_direction = 'S';
                                break;
                            case 2:
                                cur_direction = 'W';
                                break;
                            case 3:
                                cur_direction = 'N';
                                break;
                            default:
                                break;
                        }
                }
                if(cur_direction == 'W') {
                        int tmp = repeat % 4;
                        switch(tmp){
                            case 1:
                                cur_direction = 'N';
                                break;
                            case 2:
                                cur_direction = 'E';
                                break;
                            case 3:
                                cur_direction = 'S';
                                break;
                            default:
                                break;
                        }
                }
                if(cur_direction == 'N') {
                        int tmp = repeat % 4;
                        switch(tmp){
                            case 1:
                                cur_direction = 'E';
                                break;
                            case 2:
                                cur_direction = 'S';
                                break;
                            case 3:
                                cur_direction = 'W';
                                break;
                            default:
                                break;
                        }
                }
                if(cur_direction == 'S') {
                        int tmp = repeat % 4;
                        switch(tmp){
                            case 1:
                                cur_direction = 'W';
                                break;
                            case 2:
                                cur_direction = 'N';
                                break;
                            case 3:
                                cur_direction = 'E';
                                break;
                            default:
                                break;
                        }
                    
                }
                break;
            default:
                break;
        }
    }
};

struct Instructions{
public:
    int robot_serial;
    char direction;
    int repeat;
    void set(int s, char d, int r){
        robot_serial = s;
        direction = d;
        repeat = r;
    }
};

int main(int argc, const char* argv[]){
    int loop;
    //warehouse part.
    int row, col;
    //nums
    int robot_num, instruction_num;
    //set for robots initial positions.
    int pos_row, pos_col;
    //all about instructions.
    int robot_serial;
    char direction;
    int rep;

    
    cin>>loop;
    vector<string> ans(loop, "OK!");
    for(int i = 1; i <= loop; i++){
        cin>>row>>col;
        Warehouse warehouse;
        warehouse.setWarehouse(col, row);
        cin>>robot_num>>instruction_num;
        vector<Robots> robots(robot_num);
        vector<Instructions> instructions(instruction_num);
        
        for(int j = 0; j < robots.size(); j++){
            cin>>pos_row>>pos_col>>direction;
            robots[j].setPos(pos_col, pos_row, direction, warehouse);
            warehouse.matrix[pos_col-1][pos_row-1] = 1; // 1 stands for the existence of any of these robots.
            
        } //Initialization of robots ends here.
        
        for(int j = 0; j < instructions.size(); j++){
            cin>>robot_serial>>direction>>rep;
            instructions[j].set(robot_serial, direction, rep);
        } //Initialization of instructions ends here.
        
        for(int j = 0; j < instructions.size(); j++){
            robots[instructions[j].robot_serial - 1].Reverse(instructions[j].repeat,instructions[j].direction); //Reverse the direction of the robot,
            if(robots[instructions[j].robot_serial - 1].changePos(warehouse)){
                if(robots[instructions[j].robot_serial - 1].changePos(warehouse) == 1){
                    ans[i-1] = ("Robot " + to_string(instructions[j].robot_serial) + " crashed into wall.");
                    break;
                } else {
                    ans[i-1] = ("Two robots crashed!");
                    break;
                }
            }

        }
    }
    for(int i = 0; i < ans.size(); i++) cout<<ans[i]<<endl;
    return 0;
}
