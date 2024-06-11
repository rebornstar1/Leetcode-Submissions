class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
       map<int,int>mp;
       for(int i = 0 ; i < arr1.size() ; i++ )
       {
         mp[arr1[i]]++;
       }

       int ind = 0;
       for(int i = 0 ; i < arr2.size() ; i++)
       {
          while(mp[arr2[i]]!=0)
          {
             arr1[ind] = arr2[i];
             ind++;
             mp[arr2[i]]--;
          }
       }    

       for(auto it : mp)
       {
         int cnt = it.second;
         while(cnt--)
         {
             arr1[ind] = it.first;
             ind++;
         }
       }
       return arr1;
    }
};