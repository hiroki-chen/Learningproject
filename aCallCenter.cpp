#include <iostream>
#include <vector>
#include <queue>
#include <functional>
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

int main(int argc, const char** argv) {
    vector<Call> waiting_call;
    int operator_num, supervisor_num, director_num;
    int call_num;

    cin >> operator_num >> supervisor_num >> director_num;

    CallCenter center(operator_num, supervisor_num, director_num);

    for (int i = 1; i <= center.operator_num; i++) center.available_operator.push(Operator(i));
    for (int i = 1; i <= center.supervisor_num; i++) center.available_supervisor.push(Supervisor(i));
    for (int i = 1; i <= center.director_num; i++) center.available_director.push(Director(i));

    cin >> call_num;
    while (call_num--) {
        int num, level, call_time, expectation;

        static const auto __Init__ = []() {
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            return nullptr;
        };
        __Init__();
        cin >> num >> level >> call_time >> expectation;
        waiting_call.push_back(Call(level, call_time, expectation));
    }

    int cur_time = 0;
    int i = 0;
    while (i < waiting_call.size()) {
        //先看看在处理电话的人有没有空。
        while (!(center.unavailable_operator.empty())) {
            if (cur_time == center.unavailable_operator.top().end_time) {
                Operator person = center.unavailable_operator.top();
                center.available_operator.push(person);
                center.unavailable_operator.pop();
            } else break;
        }

        while (!center.unavailable_director.empty()) {
            if (cur_time == center.unavailable_director.top().end_time) {
                Director person = center.unavailable_director.top();
                center.available_director.push(person);
                center.unavailable_director.pop();
            } else break;
        }

        while (!center.unavailable_supervisor.empty()) {
            if (cur_time == center.unavailable_supervisor.top().end_time) {
                Supervisor person = center.unavailable_supervisor.top();
                center.available_supervisor.push(person);
                center.unavailable_supervisor.pop();
            } else break;
        }

        if (cur_time != waiting_call[i].call_time) {
            cur_time++;
            continue;
        }

        int end_time = waiting_call[i].call_time + waiting_call[i].expectation;

        switch (waiting_call[i].level) {
            case 0: //先找符合要求的，再找下一个优先队列。
                if (!center.available_operator.empty()) {
                    i++;
                    Operator person = center.available_operator.top();
                    center.available_operator.pop();
                    person.end_time = end_time;
                    center.unavailable_operator.push(person);
                    cout << "Operator " << person.serial << " process call " << " " << i << " call_level " << 0 
                         << " end_time " << end_time << endl;
                } else {
                    if (!center.available_supervisor.empty()) {
                        i++;
                        Supervisor person = center.available_supervisor.top();
                        center.available_supervisor.pop();
                        person.end_time = waiting_call[i].call_time + waiting_call[i].expectation;
                        center.unavailable_supervisor.push(person);
                        cout << "Supervisor " << person.serial << " process call " << i << " call_level " << 0 
                             << " end_time " << end_time << endl;
                    } else {
                        if (!center.available_director.empty()) {
                            i++;
                            Director person = center.available_director.top();
                            center.available_director.pop();
                            person.end_time = waiting_call[i].call_time + waiting_call[i].expectation;
                            center.unavailable_director.push(person);
                            cout << "Director " << person.serial << " process call " << i << " call_level " << 0 
                                 << " end_time " << end_time << endl;
                        } else {
                            cout << "No Agent now, stop." << endl;
                            return 0;
                        }
                    }
                }
                break;
            case 1: 
                if (!center.available_supervisor.empty()) {
                    i++;
                    Supervisor person = center.available_supervisor.top();
                    center.available_supervisor.pop();
                    person.end_time = waiting_call[i].call_time + waiting_call[i].expectation;
                    center.unavailable_supervisor.push(person);
                    cout << "Supervisor " << person.serial << " process call " << i << " call_level " << 1 
                         << " end_time " << end_time << endl;
                } else {
                    if (!center.available_director.empty()) {
                        i++;
                        Director person = center.available_director.top();
                        center.available_director.pop();
                        person.end_time = waiting_call[i].call_time + waiting_call[i].expectation;
                        center.unavailable_director.push(person);
                        cout << "Director " << person.serial << " process call " << i << " call_level " << 2 
                             << " end_time " << end_time << endl;
                    } else {
                        cout << "No Agent now, stop." << endl;
                        return 0;
                    }
                }
                break;
            case 2: 
                if (!center.available_director.empty()) {
                    i++;
                    Director person = center.available_director.top();
                    center.available_director.pop();
                    person.end_time = waiting_call[i].call_time + waiting_call[i].expectation;
                    center.unavailable_director.push(person);
                    cout << "Director " << person.serial << " process call " << i << " call_level " << 2 
                         << " end_time " << end_time << endl;
                } else {
                    cout << "No Agent now, stop." << endl;
                    return 0;
                }
                break;
            default:
                cout << "Your have entered something wrong!" << endl;
                return 0;
        }
    }
    return 0;
}