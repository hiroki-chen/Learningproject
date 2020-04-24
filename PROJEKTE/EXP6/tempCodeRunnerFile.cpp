//题目二在一项比赛中，有五位参赛选手分别是A、B、C、D、E，设计一个Player类，数据成员包括选手的姓名和分数。选手的分数按照如下方式产生：10名裁判对每位选手打分，去掉一个最高分，再去掉一个最低分，剩余的分数取平均值。最后按照分数从高到低的顺序输出选手的姓名和得分信息。
//提示和要求：用STL完成本题目，用vector容器存放每位选手的信息，每位选手的分数可放入双端队列中，用sort()排序后去掉两端，再求平均值，用sort（）对vector排序（需用到自定义排序规则，网上自行搜索）
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <numeric>
using namespace std;

class Player {
public:
    string name;
    deque<double> score;
    double res;
    void constructor(const string& _name){
        this -> name = _name;
        for (int i = 0; i < 10; i++) {
            double judge;
            cin >> judge;
            score.push_back(judge);
        }
    }
    void getScore(void) {
        std::sort(score.begin(), score.end(), [](const double& a, const double& b) -> bool {return a <= b;});
        res = accumulate(score.begin() + 1, score.end() - 1, 0) / 8.0;
    }
};

int main(int argc, const char** argv) {
    vector<Player> player(5);
    for (int i = 0; i < 5; i++) {
        string name;
        cin >> name;
        player[i].constructor(name);
        player[i].getScore();
    }
    int i = 0;
    std::sort(player.begin(), player.end(), [](const Player& a, const Player& b) {return a.res >= b.res;});
    for (auto item : player) cout << item.name << "的成绩是：" << item.res << endl;
    return 0;

}
