#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Operator {
public:
    int serial;
    int end_time;
    Operator(int n) : serial(n) {}
};

class Supervisor {
public:
    int serial;
    int end_time;
    Supervisor(int n) : serial(n) {}
};

class Director {
public:
    int serial;
    int end_time;
    Director(int n) : serial(n) {}
};

class Call {
public:
    int level;
    int call_time;
    int expectation;
    Call (int a, int b, int c) : level(a), call_time(b), expectation(c) {}
};

struct cmp {
    bool operator () (Operator a, Operator b) {
        return a.serial >= b.serial;
    }
    bool operator () (Supervisor a, Supervisor b) {
        return a.serial >= b.serial;
    }
    bool operator () (Director a, Director b) {
        return a.serial >= b.serial;
    }
};

struct cmp_end_time {
    bool operator () (Operator a, Operator b) {
        return a.end_time <= b.end_time;
    }
    bool operator () (Supervisor a, Supervisor b) {
        return a.end_time <= b.end_time;
    }
    bool operator () (Director a, Director b) {
        return a.end_time <= b.end_time;
    }
};

class CallCenter {
    //定义一个函数么？
public:
    int operator_num, supervisor_num, director_num;
    priority_queue<Operator, vector<Operator>, cmp> available_operator;
    priority_queue<Supervisor, vector<Supervisor>, cmp> available_supervisor;
    priority_queue<Supervisor, vector<Director>, cmp> available_director;
    
    priority_queue<Operator, vector<Operator>, cmp_end_time> unavailable_operator;
    priority_queue<Operator, vector<Supervisor>, cmp_end_time> unavailable_supervisor;
    priority_queue<Operator, vector<Director>, cmp_end_time> unavailable_director;
    
    CallCenter(int _operator_num, int _supervisor_num, int _director_num) : \
    operator_num(_operator_num), supervisor_num(_supervisor_num), director_num(_director_num) {}
};

int main(int argc, const char** argv) {
    vector<Call> waiting_call;
    int operator_num, supervisor_num, director_num;
    int call_num;
    
    cin >> operator_num >> supervisor_num >> director_num;
    
    CallCenter center(operator_num, supervisor_num, director_num);
    
    for (int i = 1; i <= operator_num; i++) center.available_operator.push(Operator(i));
    for (int i = 1; i <= supervisor_num; i++) center.available_supervisor.push(Supervisor(i));
    for (int i = 1; i <= director_num; i++) center.available_director.push(Director(i));
    
    cin >> call_num;
    while (call_num--) {
        int level, call_time, expectation;
        cin >> level >> call_time >> expectation;
        waiting_call.push_back(Call(level, call_time, expectation));
    }
    
    int cur_time = 0;
    
    for (int i = 0; i < waiting_call.size(); i++, cur_time++) {
        //先看看在处理电话的人有没有空。
        
        while (!(center.unavailable_operator.empty())) {
            if (cur_time >= center.unavailable_operator.top().end_time) {
                auto person = center.available_director.top();
                center.available_operator.push(person);
                center.unavailable_operator.pop();
            } else break;
        }
        while (!center.unavailable_director.empty()) {
            if (cur_time >= center.unavailable_director.top().end_time) {
                auto person = center.unavailable_director.top();
                center.available_director.push(person);
                center.unavailable_director.pop();
            } else break;
        }
        while (!center.unavailable_supervisor.empty()) {
            if (cur_time >= center.unavailable_supervisor.top().end_time) {
                auto person = center.unavailable_supervisor.top();
                center.available_supervisor.push(person);
                center.unavailable_director.pop();
            } else break;
        }
        
        
        if (!center.available_director.empty()) {
            //do something.
        } else {
            if (!center.available_supervisor.empty()) {
                // do something.
            } else {
                if (!center.available_director.empty()) {
                    //do something
                } else {
                    cout << "No agent can answer, stop" << endl;
                    break;
                }
            }
        }
    }
    
    return 0;
}
