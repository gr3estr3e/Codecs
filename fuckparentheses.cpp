#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string a;
    bool found;
    stack<char> temps;
    for (int i = 0; i < n; i++) {
        while(!temps.empty()) temps.pop(); // Flush out the stack
        cin >> a;
        found = true;
        for (int j= 0; j < a.size(); j++) {
            if (a[j] == '(') temps.push(')'); // If its "()" opening, add the end
            if (a[j] == '[') temps.push(']'); // Same for "[]"
            if (a[j] == ')' or a[j] == ']') { // check if its the end
                if (temps.empty()) { // if stack is empty
                    found = false;
                    break;
                } if (temps.top() == a[j]) { // if the top element of the stack is the same as the current in string
                    temps.pop();
                } else {
                    found = false;
                    break;
                }
            }
        }
        if (!temps.empty()) found = false; // well, if the stack is not empty
        if (found) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
}