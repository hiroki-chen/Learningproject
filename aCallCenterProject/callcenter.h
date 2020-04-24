#ifndef _CALL_CENTER__
#define _CALL_CENTER__

#include <queue>
#include <vector>
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

struct cmp1 {
    bool operator () (const Operator& a, const Operator& b) {return a.serial >= b.serial;}
    bool operator () (const Supervisor& a, const Supervisor& b) {return a.serial >= b.serial;}
    bool operator () (const Director& a, const Director& b) {return a.serial >= b.serial;}
};

struct cmp2 {
    bool operator () (const Operator& a, const Operator& b) {return a.end_time >= b.end_time;}
    bool operator () (const Supervisor& a, const Supervisor& b) {return a.end_time >= b.end_time;}
    bool operator () (const Director& a, const Director& b) {return a.end_time >= b.end_time;}
};

class CallCenter {
//定义一个函数么？
public:
    int operator_num, supervisor_num, director_num;

    priority_queue<Operator, vector<Operator>, cmp1> available_operator;
    priority_queue<Supervisor, vector<Supervisor>, cmp1> available_supervisor;
    priority_queue<Director, vector<Director>, cmp1> available_director;

    priority_queue<Operator, vector<Operator>, cmp2> unavailable_operator;
    priority_queue<Supervisor, vector<Supervisor>, cmp2> unavailable_supervisor;
    priority_queue<Director, vector<Director>, cmp2> unavailable_director;

    CallCenter(int _operator_num, int _supervisor_num, int _director_num) : \
        operator_num(_operator_num), supervisor_num(_supervisor_num), director_num(_director_num) {}
};

#endif