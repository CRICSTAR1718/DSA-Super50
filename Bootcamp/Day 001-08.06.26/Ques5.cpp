#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool check(int row, int col, int n, vector<string> &board)
    {
        int r = row;
        int c = col;
        while (c >= 0)
        {
            if (board[r][c] == 'Q')
            {
                return false;
            }
            c--;
        }
        c = col;
        while (r >= 0 && col >= 0)
        {
            if (board[r][c] == 'Q')
            {
                return false;
            }
            r--;
            c--;
        }
        r = row;
        c = col;
        while (r < n && col >= 0)
        {
            if (board[r][c] == 'Q')
            {
                return false;
            }
            r++;
            c--;
        }
        return true;
    }
    void solve(int col, int n, vector<string> &board, vector<vector<string>> &res)
    {
        if (col == n)
        {
            res.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (check(row, col, n, board))
            {
                board[row][col] = 'Q';
                solve(col + 1, n, board, res);
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n)
    {
        // Write your logic here
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        solve(0, n, board, res);
        return res.size();
    }
};

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n)
    {
        Solution obj;
        cout << obj.totalNQueens(n) << "\n";
    }
    return 0;
}