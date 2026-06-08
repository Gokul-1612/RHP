#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int ROWS = 6;
const int COLS = 5;

int main() {
    int cost[ROWS][COLS] = {
        {100,  50,  200,  300, 1000},
        {400,  100, 600,  700, 2000},
        {900,  50,  2,    1,   500 },
        {600,  400, 200,  100, 600 },
        {1000, 600, 1500, 700, 400 },
        {60,   700, 900,  50,  100 }
    };

    int dp[ROWS][COLS];

    // 1. Initialize the first COLUMN of the DP table
    for (int i = 0; i < ROWS; ++i) {
        dp[i][0] = cost[i][0];
    }

    // 2. Process column-by-column (from Column 1 to COLS-1)
    for (int j = 1; j < COLS; ++j) {
        
        // For each cell in the current column, find the best option from the previous column
        for (int i = 0; i < ROWS; ++i) {
            int max_prev_col = INT_MIN;
            
            // Look through all rows of the previous column (j-1)
            for (int k = 0; k < ROWS; ++k) {
                if (k != i) { // Skip the same row to respect the restriction
                    max_prev_col = max(max_prev_col, dp[k][j-1]);
                }
            }
            
            // Transition formula
            dp[i][j] = cost[i][j] + max_prev_col;
        }
    }

    // 3. Print the Column-based DP table
    cout << "--- Column-Based DP Table ---" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "-----------------------------" << endl;

    // 4. Find the maximum final score from the last column
    int max_score = INT_MIN;
    for (int i = 0; i < ROWS; ++i) {
        if (dp[i][COLS-1] > max_score) {
            max_score = dp[i][COLS-1];
        }
    }

    cout << "Maximum Path Score (Column-based): " << max_score << endl;

    return 0;
}
