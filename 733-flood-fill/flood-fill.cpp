class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        int n = image.size();
        int m = image[0].size();

        int originalColor = image[sr][sc];
        if (originalColor == color) return image;  /// If the color is the same, no need to do anything

        q.push({sr,sc});
        image[sr][sc] = color;
                    
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==originalColor){
                    q.push({nrow,ncol});
                    image[nrow][ncol]=color;
                }
            }
        }

        return image;
    }
};