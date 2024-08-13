class Solution {
public:
    int func(vector<vector<int>>& matrix, int i,int j)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        if( i >= 0 && i < n && j >= 0 && j < m)
        {
           return matrix[i][j];
        }
        else
        {
            return 0;
        }
    }

    int maxSumSubmatrix(vector<vector<int>>& matrix, int w) {
        int n = matrix.size(), m = matrix[0].size();

        // n means rows
        // m means columns

        int ans = INT_MIN;

        for(int i = 0 ; i < n ; i++ )
        {
            for(int j = 0 ; j < m ; j++ )
            {
                matrix[i][j] += (func(matrix,i-1,j)+func(matrix,i,j-1)-func(matrix,i-1,j-1));
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }

        for(int i = 0 ; i < n ; i++ )
        {
            for(int j = 0 ; j < m ; j++ )
            {
                for(int k = i ; k < n ; k++ )
                {
                    for(int s = j ; s < m ; s++)
                    {
                       int val = (func(matrix,k,s)+func(matrix,i-1,j-1)-func(matrix,k,j-1)-func(matrix,i-1,s));
                       if(val <= w)
                       {
                          ans = max(ans,val);
                       }
                       if(ans == w) return ans;
                    }
                }
            }
        }
        return ans;
    }
};

// Solve This Question Optimally