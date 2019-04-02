#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    vector<string> a;
    string now = "";
    for (char x : s) {
        if (x == ' ' || x == ',' || x == ';') {
            if (now.length() > 0) { 
                a.push_back(now);
            }
            now = "";
        } else {
            now += x;
        }
    }
    string base = a[0];
    for (int i=1; i<a.size(); i++) {
        string t = base;
        string s = a[i];
        while (s.length() > 0 && !('a' <= s.back() && s.back() <= 'z')) {
            if (s.back() == '[') {
                t += ']';
            } else if (s.back() == ']') {
                t += '[';
            } else {
                t += s.back();
            }
            s.pop_back();
        }
        cout << t << ' ' << s << ';' << '\n';
    }
    return 0;
}
