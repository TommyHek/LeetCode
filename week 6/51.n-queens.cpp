/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    void backtrack(int row, int n,
                   vector<int>& positions,
                   vector<bool>& usedCol,
                   vector<bool>& usedDiag,
                   vector<bool>& usedAntiDiag,
                   vector<vector<string>>& solutions) 
    {
        if (row == n) {
            solutions.push_back(buildBoard(positions));
            return;
        }

        for (int col = 0; col < n; col++) {
            int diagIndex = row - col + (n - 1); 
            int antiDiagIndex = row + col;       

            if (!usedCol[col] && !usedDiag[diagIndex] && !usedAntiDiag[antiDiagIndex]) {
                positions[row] = col;
                usedCol[col] = true;
                usedDiag[diagIndex] = true;
                usedAntiDiag[antiDiagIndex] = true;

                backtrack(row + 1, n, positions, usedCol, usedDiag, usedAntiDiag, solutions);

                usedCol[col] = false;
                usedDiag[diagIndex] = false;
                usedAntiDiag[antiDiagIndex] = false;
            }
        }
    }

    vector<string> buildBoard(const vector<int>& positions) {
        int n = positions.size();
        vector<string> board(n, string(n, '.'));
        for (int row = 0; row < n; row++) {
            int col = positions[row];
            board[row][col] = 'Q'; 
        }
        return board;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        // Create a vector to store the solutions
        vector<vector<string>> solutions;
        // Create a vector to store the positions of queens in each row
        vector<int> positions(n, -1);
        // Create vectors to track used columns, diagonals, and anti-diagonals
        vector<bool> usedCol(n, false);             
        vector<bool> usedDiag(2*n-1, false);        
        vector<bool> usedAntiDiag(2*n-1, false);    

        backtrack(0, n, positions, usedCol, usedDiag, usedAntiDiag, solutions);
        return solutions;
    }

};

// @lc code=end

