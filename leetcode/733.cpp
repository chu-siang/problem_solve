class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int old = image[sr][sc];
    if(old == color)return image;
    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    auto ok = [&](int r,int c){
        int H = image.size();
        int W = image[0].size();
        return r >= 0 && r < H && c >= 0 && c < W;
    };
    image[sr][sc] = color;
    for(int i = 0; i < 4; i++){
        int tmpa = sr + dir[i][0];
        int tmpb = sc + dir[i][1];
        if(ok(tmpa,tmpb)&&image[tmpa][tmpb] == old){
            floodFill(image,(tmpa),(tmpb),color);
        }
    }   
    return image;
    }
};