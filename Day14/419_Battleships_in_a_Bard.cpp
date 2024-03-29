

#include <bits/stdc++.h>
using namespace std;


// solution

class Solution {
public:

    void dfs(vector<vector<char>>& board, int i, int j) {

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'X') {
            return;
        }

        board[i][j] = '*';

        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
    }

    int countBattleships(vector<vector<char>>& board) {
        int battleships = 0;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'X') {
                    battleships++;
                    dfs(board, i, j);
                }
            }
        }

        return battleships;
    }
};