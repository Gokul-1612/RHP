#include <iostream>
#include <string>
#include <cctype> // Needed for tolower
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int flag = 0;
    
    for(int i = 0; i < s.length(); i++) {
        // Convert character to lowercase to handle both cases
        char ch = tolower(s[i]); 
        if(ch >= 'a' && ch <= 'z') {
            flag = flag | (1 << (ch - 'a'));
        }
    }
    
    if(flag == (1 << 26) - 1) {
        cout << "It is a pangram";
    } else {
        cout << "It is not a pangram";
    }

    return 0;
}
