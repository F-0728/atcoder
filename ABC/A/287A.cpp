#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    int F = 0;
    int A = 0;
    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        if (s == "For"){
            F += 1;
        } else {
            A += 1;
        }
    }
    if (F > A) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
