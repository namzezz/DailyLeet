class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        int n = image.size();
        int m = image[0].size();

        int originalColor = image[sr][sc];
        if (originalColor == color) return image;  /// If the color is the same, no need to do anything

        int vis[n][m];

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i==sr && j==sc){
                    image[i][j] = color;
                    q.push({i,j});
                    vis[i][j] = 1;
                }else{
                    vis[i][j]=0;
                }
            }
        }
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && image[nrow][ncol]==originalColor){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                    image[nrow][ncol]=color;
                }
            }
        }

        return image;
    }
};