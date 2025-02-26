class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>qst;
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>>curr(m+1,vector<int>(n+1,INT_MIN));
        curr[0][0] = dungeon[0][0];

        int ans = INT_MAX;

        qst.push({max(0,-1*dungeon[0][0]),dungeon[0][0],0,0});
        while(!qst.empty())
        {
            vector<int>temp = qst.top();
            qst.pop();
            int num1 = temp[0];
            int num2 = temp[1];
            int x = temp[2];
            int y = temp[3];

            curr[x][y] = max(curr[x][y],num2);

            if(x == (m-1) && y == (n-1))
            {
                ans = min(ans,num1);
                break;
            }

            if((x+1) < m && curr[x+1][y] < (num2+dungeon[x+1][y]))
            {
                qst.push({max(num1,-1*(num2+dungeon[x+1][y])),dungeon[x+1][y]+num2,x+1,y});
            }

            if((y+1) < n && curr[x][y+1] < (num2+dungeon[x][y+1]))
            {
               qst.push({max(num1,-1*(num2+dungeon[x][y+1])),dungeon[x][y+1]+num2,x,y+1});   
            }
        }
        return ans+1;
    }
};