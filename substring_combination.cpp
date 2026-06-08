#include <iostream>
#include <string>

using namespace std;

int main() {
   
    string s;
    cin >> s;
    
    int L = s.length();
    
    // Loop through all numbers from 1 to (2^L) - 1
    for (int ctr = 1; ctr < (1 << L); ctr++) {
        string combi = "";
        
        // Check each bit of the counter
        for (int sh = 0; sh < L; sh++) {
            if ((ctr & (1 << sh)) > 0) {
                // If bit is set, include the corresponding character
                combi += s[sh];
            }
        }
        
        cout << combi << "\n";
    }

    return 0;
}
