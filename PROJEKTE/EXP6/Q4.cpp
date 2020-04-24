#include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char** argv) {
    int loop;
    vector<int> ans;
    cin >> loop;
    while (loop--) {
        priority_queue<int, vector<int>, greater<int>> treasure;
        int size;
        cin >> size;
        for (int i = 0; i < size; ++i) {
            int val;
            cin >> val;
            treasure.push(val);
        }
        int tmp = 0;
        while (!treasure.empty()) {
            if (treasure.size() == 1) {
                ans.push_back(tmp);
                treasure.pop();
            } else {
                int first = treasure.top();
                treasure.pop();
                int second = treasure.top();
                treasure.pop();
                treasure.push(first + second);
                tmp += first + second;
            }
        }
    }
    cout << endl;
    for (auto item : ans) cout << item << endl;
    return 0;
}