class Solution {
public:
    vector<int> lexicalOrder(int n) {
        // Naive Approach
       vector<int>ans;

       // find number of digits in n
       int temp = n, cnt = 1;
       while(temp != 0)
       {
          temp /= 10;
          cnt *= 10;
       }

       cnt/=10;

       for(int i = cnt ; i < (10*cnt) ; i++ )
       {
           int val = i;
           while(val%10 == 0) val/=10;

           while(val <= i)
           {
              if(val <= n ) ans.push_back(val);
              val *= 10;
           }
       }
       return ans;
    }
};