#include <iostream>
#include <vector>
using namespace std;

class Warehouse{
public:
    int row_size, col_size;
    Warehouse(int a, int b) : row_size(a), col_size(b) {}
};

class Robot {
public:
    int row, col; //The coordination of each robot//
    int direction; //The serial number of each robot。 0 go north; 1 go east; 2 go south; 3 go west//
};

inline bool isValidPosition(int& serial_number, Warehouse& warehouse, int& robot_num, vector<Robot>& robot) {
    if(robot[serial_number].row <= 0 || robot[serial_number].row > warehouse.row_size || robot[serial_number].col <= 0 || robot[serial_number].row > warehouse.col_size) {
        cout << "Robot " << serial_number << " crashes into the wall" << endl;
        return false;
    }
    for(int i = 1; i <= robot_num; i++) {
        if(i == serial_number) continue; //Traverse all the possibilites.
        if(robot[i].row == robot[serial_number].row && robot[i].col == robot[serial_number].col) { //Judge if there are any robots in the same position//
            cout << "Robot " << serial_number << " crashes into robot "<< i << endl;
            return false; 
        }
    }
    return true;
}

int main(int argc, const char* argv[]) {
    int a, b;
    int robot_num, instruction_num;
    int serial, repeat, loop;
    bool notcollision;
    char dir;
    cin >> loop;
    while(loop--) {
        cin >> a >> b
            >> robot_num >> instruction_num;
        vector<Robot> robot(robot_num);
        Warehouse warehouse(a, b);
        for(int i = 0; i < robot_num; i++) { //convert directions into numbers...
            cin >> robot[i].row >> robot[i].col
                         >> dir;
            if(dir == 'N') robot[i].direction = 0;
            if(dir == 'E') robot[i].direction = 1;
            if(dir == 'S') robot[i].direction = 2;
            if(dir == 'W') robot[i].direction = 3;
        }
        notcollision = true; //Initlization here, all robots stay in the non-collisive position.
        for(int i = 1; i <= instruction_num; ++i) {
            cin >> serial >> dir >> repeat;//serial denotes the serialnum of robot and dir denotes the directions of each robot, btw, repeat is the repetition.
            if(dir == 'F') { 
                if(notcollision) {
                    for(int j = 1; j <= repeat; ++j) {
                        if(robot[serial].direction == 0) ++robot[serial].col;
                        if(robot[serial].direction == 1) ++robot[serial].row;
                        if(robot[serial].direction == 2) --robot[serial].col;
                        if(robot[serial].direction == 3) --robot[serial].row;
                        ; //Judge is the pos is valid, is not, throw wrong answer and quit.
                        if(!(notcollision = isValidPosition(serial, warehouse, robot_num, robot))) break;
                    }
                }
            } else if(dir == 'L') {
                robot[serial].direction = (robot[serial].direction - repeat % 4 + 4) % 4; //Left denotes countercolckwise. But if repeat % 4 > direction, then direction may be negativ, so we have to plus another 4.
            } else if(dir == 'R') {
                robot[serial].direction = (robot[serial].direction + repeat % 4 ) % 4; //Right denotes clockwise.
            }
        }
        if(notcollision) cout << "OK!" << endl;  //Judge here last, if no crash happens.
    }
    return 0;
}
