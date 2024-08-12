class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long curr = 1, maxi = nums[0], n = nums.size(),check = INT_MIN,temp = 1;
        for(int i = 0 ; i < n ; i++ )
        {
            temp *= nums[i];
            curr *= nums[i];

            if(temp > INT_MAX || temp < INT_MIN)
            {
                temp = 1;
                curr = 1;
                check = INT_MIN;
            }

            if(curr < 0 && check != INT_MIN)
            {
                maxi = max(maxi,curr/check);
            }
            else
            {
                maxi = max(maxi,curr);
            }
            maxi = max(maxi,curr);
            if(curr == 0)
            {
                temp = 1;
                curr = 1;
                check = INT_MIN;
            }// curr = 1;
            if(check == INT_MIN && nums[i] < 0) check = temp;
            cout<<maxi<<" "<<curr<<endl;
        }
        return maxi;
    }
};

// First Negative of the Array;