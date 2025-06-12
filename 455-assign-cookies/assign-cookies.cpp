class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i=0,j=0,cnt=0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        while(i!=g.size() && j!=s.size()){
            if(s[j]>=g[i]){
                i++;
                j++;
                cnt++;
            } else{
              j++;
            }
        }
        return cnt;
    }
};