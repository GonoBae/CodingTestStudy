#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> S;
    for(int i = 0; i < moves.size(); ++i) {
        int n = moves[i];
        for(int j = 0; j < board.size(); ++j) {
            int doll = board[j][n - 1];
            if(doll == 0) continue;
            if(!S.empty() && doll == S.top()) {
                S.pop();
                answer += 2;
            }
            else S.push(doll);

            board[j][n - 1] = 0;
            break;
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> board = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 3},
        {0, 2, 5, 0, 1},
        {4, 2, 4, 4, 2},
        {3, 5, 1, 3, 1}
    };
    vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};
    int result = solution(board, moves);
    cout << result;
    
    return 0;
}