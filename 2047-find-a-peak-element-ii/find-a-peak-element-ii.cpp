class Solution {
public:
    int func(vector<vector<int>>&mat,int p)
    {
        int ans = INT_MIN,ind = -1;
        for(int i = 0 ; i < mat.size() ; i++ )
        {
           if(mat[i][p] > ans)
           {
              ans = mat[i][p];
              ind = i;
           }
        }
        return ind; 
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        int s = 0, e = (m-1), p;
        while(s<=e)
        {
            p = (s+e)/2;
            int ind = func(mat,p);
            cout<<p<<" "<<ind<<endl;
            
            if(p > 0 && mat[ind][p-1] > mat[ind][p])
            {
               cout<<"yes"<<endl;
               e = (p-1);
            }
            else if(p < (m-1) && mat[ind][p+1] > mat[ind][p])
            {
                cout<<"no"<<endl;
                s = (p+1);
            }
            else
            {
                return {ind,p};
            }
        }

        return {-1,-1};
    }
};