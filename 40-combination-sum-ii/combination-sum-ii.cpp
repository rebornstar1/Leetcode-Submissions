class Solution {
public:
    vector<int>temp;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      set<vector<int>>val;
      vector<vector<int>>ans;
      int index=0;
      int sum=0;
      sort(candidates.begin(),candidates.end());
      check(index,candidates,target,val,sum);
      for( auto it :  val){
          ans.push_back(it);
      }
      return ans;
    }

    void check(int index,vector<int>&candidates,int target,set<vector<int>>&val,int sum){
        if(index==candidates.size()){
            if(sum==target){
                val.insert(temp);
            }
            return;
        }
        if(sum>target){
            return;
        }
            sum+=candidates[index];
            temp.push_back(candidates[index]);
            check(index+1,candidates,target,val,sum);
            temp.pop_back();
            sum-=candidates[index];
            while(index<(candidates.size()-1)){
                if(candidates[index]==candidates[index+1]){
                    index++;
                } else{
                    break;
                }
            }
            check(index+1,candidates,target,val,sum);
    }
};