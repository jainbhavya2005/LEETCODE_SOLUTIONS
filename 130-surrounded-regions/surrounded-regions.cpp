class Solution {
    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>&vis){
        vis[row][col]=1;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
for(int i=0;i<4;i++){
   int nrow= row+drow[i];
   int ncol= col+dcol[i];
   if(nrow>=0 && nrow<board.size()&& ncol>=0 && ncol<board[0].size()){
    if(board[nrow][ncol]=='O' && vis[nrow][ncol]==0){
        dfs(nrow,ncol,board,vis);
    }
   }
}
    }
public:
    void solve(vector<vector<char>>& board) {
        int rows=board.size();
        int col=board[0].size();
        vector<vector<int>>vis(rows,vector<int>(col,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                if((i==0||i==rows-1||j==0||j==col-1)){
                   
                     if(board[i][j]=='O' && vis[i][j]==0){
                        dfs(i,j,board,vis);
                     }


                    
                }
            }
        }
    for(int i=0;i<rows;i++){
        for(int j=0;j<col;j++){
            if(board[i][j]=='O' && vis[i][j]==0){
                board[i][j]='X';
            }
        }
    }
    
    
    }
};