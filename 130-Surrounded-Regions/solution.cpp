class Solution {
public:
    void solve(vector<vector<char>> &board) {
      vector<int> xIndex;
      vector<int> yIndex;
      int rowNum = board.size();
      if( rowNum == 0) return;
      int colNum = board[0].size();
      for( int i = 0; i< rowNum;++i){
          if(board[i][0] == 'O') {
              xIndex.push_back(i);
              yIndex.push_back(0);
          }
          if( board[i][colNum - 1] == 'O'){
              xIndex.push_back(i);
              yIndex.push_back(colNum - 1);
          }
      }
      
      for( int i = 0;i<colNum;++i){
          if( board[0][i] == 'O'){
              xIndex.push_back(0);
              yIndex.push_back(i);
          }
          if( board[rowNum-1][i] == 'O'){
              xIndex.push_back(rowNum);
              yIndex.push_back(i);
          }
      }
      int neighbor[] = {0,1,0,-1,1,0,-1,0};
      for( int i = 0; i< xIndex.size();++i){
          int xInd = xIndex[i];
          int yInd = yIndex[i];
          board[xInd][yInd] = 'Y';
          cout<<xInd+neighbor[i]<<endl;
          for(int i =0;i<8;i +=2){
              if( xInd+neighbor[i] >=0 && xInd+neighbor[i] <rowNum && yInd+neighbor[i+1] >=0 && yInd+neighbor[i+1] <colNum && board[xInd+neighbor[i]][yInd+neighbor[i+1]] == 'O'){
                  xIndex.push_back(xInd+neighbor[i]);
                  yIndex.push_back(yind+beighbor[i+1]);
              }
          }
      }
      for( int r = 0;r<rowNum;++r){
          for( int c = 0; c<colNUm;++c){
              if( board[r][c] == 'Y'){
                  board[r][c] = 'O';
              }
              else{
                  board[r][c] = 'X';
              }
          }
      }
      
    }
};