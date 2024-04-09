#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<string> s;
    for (int i = 0; i < K; i++) {
        string str;
        cin >> str;
        s.push_back(str);
    }
    for (int i = 0; i < N - K; i++) {
        string str;
        cin >> str;
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < K; i++) {
        cout << s[i] << endl;
    }
}
