#include <iostream>
#include <vector>
#include <algorithm>

/*某种聊天工具，每个好友的id都是唯一的，当用户接收到信息后，如果会话窗口之前没有与该好友的聊天信息，则在通信列表里，会将新接收的消息的好友id置顶，
如果会话窗口中已有与该好友的聊天信息，则将该好友的id移动到通讯列表的顶端。请根据要求实现该功能。
输入：第一行是整数N，代表有N组测试数据，接下来的N组测试中，第一行为整数T，代表有T条通讯，第二行有T个整数，按时间先后顺序表示接收到讯息的好友id。
输出：按照通讯列表从上到下的顺序输出好友id，每个id以空格分隔。
*/

using namespace std;

int main(int argc, const char** argv) {
    int loop;
    int val;
    int size;
    vector<vector<int> > ans;
    cin >> loop;
    while (loop--) {
        cin >> size;
        vector<int> arr;
        for (int i = 0; i < size; i++) {
            cin >> val;
            auto it = find(arr.begin(), arr.end(), val);
            if (it == arr.end()) arr.insert(arr.begin(), val);
            else {
                int v = *it;
                arr.erase(it);
                arr.insert(arr.begin(), v);
            }
        }
        ans.push_back(arr);
    }
    for (auto item : ans) {
        for (auto i : item) cout << i << " ";
        cout << endl;
    }
    return 0;
}