class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        set<char> st;
        for (int row=0;row<9;row++){
            for (int col=0;col<9;col++){
                if (board[row][col]!='.'){
                    if (st.find(board[row][col]) != st.end()) return false;
                    st.insert(board[row][col]);
                }
            }
            st.clear();
        }

        for (int col=0;col<9;col++){
            for (int row=0;row<9;row++){
                if (board[row][col]!='.') {
                    if (st.find(board[row][col]) !=st.end()) return false;
                    st.insert(board[row][col]);
                }
            }
            st.clear();
        }
        for (int row=0;row<9;row+=3){
            for (int col=0;col<9;col+=3){
                st.clear();
                for (int i=0;i<3;i++){
                    for (int j=0;j<3;j++){
                        char c = board[row+i][col+j];
                        if (c=='.') continue;
                        if (st.count(c)) return false;
                        st.insert(c);
                    }
                }
            }
            st.clear();
        }

        return true;

    }
};