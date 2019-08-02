class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size()==0||word2.size()==0)
            return max(word1.size(),word2.size());
        int row=word1.size();
        int col=word2.size();
        vector<vector<int>> f(row+1,vector<int>(col+1,0));
        for(int i=0;i<=row;++i)
            f[i][0]=i;
        for(int j=0;j<=col;++j)
            f[0][j]=j;
        for(int i=1;i<=row;++i)
        {
            for(int j=1;j<=col;++j)
            {
		   //选增加和删除中较小的一个
                f[i][j]=min(f[i-1][j],f[i][j-1])+1;
                if(word1[i-1]==word2[j-1])
		   //不需替换
                    f[i][j]=min(f[i][j],f[i-1][j-1]);
                else
                    f[i][j]=min(f[i][j],f[i-1][j-1]+1);
            }
        }
        return f[row][col];
    }
};