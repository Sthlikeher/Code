#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Nhập vào số nguyên dương n (n<200): ";
    cin >> n;
    
    int total = 2 * n;
    vector<int> initial;
    for (int i = 1; i <= total; i++) {
        initial.push_back(i);
    }
    
    vector<vector<int>> states;
    states.push_back(initial);
    
    vector<int> current = initial;
    while (true) {
        vector<int> newDeck;
        for (int i = 0; i < n; i++) {
            newDeck.push_back(current[n + i]);
            newDeck.push_back(current[i]);
        }
        current = newDeck;
        states.push_back(current);
        if (current == initial) {
            break;
        }
    }
    
    cout << states.size() - 1 << endl;
    for (const auto& state : states) {
        for (int card : state) {
            cout << card << " ";
        }
        cout << endl;
    }
    
    return 0;
}