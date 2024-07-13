#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

bool removeLast(string &s, int &l) {
    if (s.size() < 5) {
        return false;
    }
    if (s.substr(l - 5) == "dream") {
        s = s.substr(0, l - 5);
        return true;
    } else if (s.substr(l - 5) == "erase") {
        s = s.substr(0, l - 5);
        return true;
    } else if (s.substr(l - 6) == "eraser") {
        s = s.substr(0, l - 6);
        return true;
    } else if (s.substr(l - 7) == "dreamer") {
        s = s.substr(0, l - 7);
        return true;
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    int l = s.size();
    while (removeLast(s, l)) {
        l = s.size();
    }
    if (s.size() == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
