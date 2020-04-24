#include <map>
#include <sstream>
#include <iostream>

using namespace std;

const string passage = "It was the best of times, and it was the worst of times. It was the age of wisdom, and it was the age of foolishness. It was the epoch of belief, and it was the epoch of incredulity. It was the season of light, and it was the season of darkness. It was the spring of hope, and it was the winter of despair. We had everything before us, and we had nothing before us. We were all going direct to Heaven, and we were all going direct the other way. In short, the period was so far like the present period. That some of its noisiest authorities insisted on its being received, for good or for evil, in the superlative degree of comparison only.";
istringstream iss(passage);

int main(int argc, const char** argv) {
    map<string, int> myMap;
    while (true) {
        string buf;
        getline(iss, buf, ' ');
        if (!((buf.back() >= 'a' && buf.back() <= 'z') || (buf.back() >= 'A' && buf.back() <= 'Z'))) buf = buf.substr(0, buf.size() - 1);
        if (buf.empty()) break;
        myMap[buf]++;
    }
    for (auto item : myMap) {
        cout << item.first << ": " << item.second << endl;
    }
    return 0;
}