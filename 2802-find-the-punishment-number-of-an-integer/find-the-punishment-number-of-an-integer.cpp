class Solution {
public:
    int punishmentNumber(int n) {
        
        int ans = 0;

        for(int i = 1 ; i <= n ; i++ )
        {
             int val = i*i;
             string stringOfVal = to_string(val);
             int sizeOfVal = stringOfVal.size();

             int flag = 0;

             priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
             pq.push({0,0}); // This Represents the Empty String
             while(!pq.empty())
             {
                int ind = pq.top().first;
                int temp = pq.top().second;

                if(temp == i && ind == sizeOfVal)
                {
                   flag = 1;
                   break;
                } 
                pq.pop();
                for(int j = ind ; j < sizeOfVal ; j++ )
                {
                   string tempString = stringOfVal.substr(ind,j-ind+1);
                   int addVal = stoi(tempString);
                   if((addVal+temp) <= i) pq.push({j+1,addVal+temp});
                }
             }

             if(flag) ans += (i*i);
        }
        return ans;
    }
};

// 1000 * 1000  = O(10^6) Number
// let's say 15*15 = 225 

// Time Complexity Will Become Something like O(1000 * 32)

// n = 2 1-1 & 2
// n = 3 1-1-1 & 2-1 & 1-2 & 3
// n = 4 1-1-1-1 & 1-1-2 & 1-2-1 & 2-1-1 & 2-2 & 3-1 & 1-3 & 4

// 2^(6-1) => That counts to 32 combinations

// Let's take the Subcase of 4025 
// then you can take it 
// 4
// 4 0 
// 4 0 2 
// 4 0 2 5

// try to make this in a form of the priority queue so that you can deal it better