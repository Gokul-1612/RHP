#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// Define matrix dimensions based on your notes
const int ROWS = 6;
const int COLS = 5;

int main() {
    // 1. Define the cost matrix from your image
    int cost[ROWS][COLS] = {
        {100,  50,  200,  300, 1000},
        {400,  100, 600,  700, 2000},
        {900,  50,  2,    1,   500 },
        {600,  400, 200,  100, 600 },
        {1000, 600, 1500, 700, 400 },
        {60,   700, 900,  50,  100 }
    };

    // 2. Define the 2D DP array
    int dp[ROWS][COLS];

    // Initialize the first row of the DP table
    for (int j = 0; j < COLS; ++j) {
        dp[0][j] = cost[0][j];
    }

    // 3. Process the remaining rows
    for (int i = 1; i < ROWS; ++i) {
        // Find the top two values and the column index of the maximum value in the previous row
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max1_idx = -1;

        for (int j = 0; j < COLS; ++j) {
            if (dp[i-1][j] > max1) {
                max2 = max1;
                max1 = dp[i-1][j];
                max1_idx = j;
            } else if (dp[i-1][j] > max2) {
                max2 = dp[i-1][j];
            }
        }

        // Fill the current row using the DP transition rule
        for (int j = 0; j < COLS; ++j) {
            if (j == max1_idx) {
                dp[i][j] = cost[i][j] + max2; // Cannot use same column, use second best
            } else {
                dp[i][j] = cost[i][j] + max1; // Use the best column
            }
        }
    }

    // 4. Print the entire DP table
    cout << "--- DP Table ---" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "----------------" << endl;

    // 5. Find the maximum final score from the last row
    int max_score = INT_MIN;
    for (int j = 0; j < COLS; ++j) {
        if (dp[ROWS-1][j] > max_score) {
            max_score = dp[ROWS-1][j];
        }
    }

    cout << "Maximum Path Score: " << max_score << endl;

    return 0;
}
