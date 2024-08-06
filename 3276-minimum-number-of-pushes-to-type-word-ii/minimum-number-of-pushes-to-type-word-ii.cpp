class Solution {
public:
    int minimumPushes(string word) {
        vector<int>vect(26,0);
        for(int i=0;i<word.size();i++){
            vect[word[i]-'a']++;
        }
        sort(vect.begin(),vect.end());
        int cnt=0,ans=0;
        for(int i=25;i>=0;i--){
            ans+=(vect[i]*(cnt/8+1));
            cnt++;
        }
        return ans;
    }
};