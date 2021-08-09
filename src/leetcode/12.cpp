// 剑指 Offer 12. 矩阵中的路径
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int x = 0; x < board.size(); ++x) {
            for(int y = 0; y < board[0].size(); ++y) {
                if (recursiveFind(board, word, x, y, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool recursiveFind(vector<vector<char>>& board, string& word, int x, int y, int i) {
        if (i >= word.size()) {
            return true;
        }
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[i]) {
            return false;
        }
        
        char tempt = '/';
        swap(tempt, board[x][y]);
        i++;
        bool result = 
            recursiveFind(board, word, x - 1, y, i) || 
            recursiveFind(board, word, x + 1, y, i) || 
            recursiveFind(board, word, x, y - 1, i) ||
            recursiveFind(board, word, x, y + 1, i);
        swap(tempt, board[x][y]);
        return result;
    }
};

int main(int argc, char* argv[]) {
    vector<vector<char>> arr {{'A'}};
    string s {"A"};
    Solution solution;
    bool result = solution.exist(arr, s);
    cout << result << endl;
    return 0;
}