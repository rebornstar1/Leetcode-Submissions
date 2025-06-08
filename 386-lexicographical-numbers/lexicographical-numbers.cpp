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
           vector<int>flex;
           int val = i;
           if(val <= n) flex.push_back(val);
           while(val%10 == 0)
           {
              val /= 10;
              if(val <= n) flex.push_back(val);
           }

           int flexsize = flex.size();
           for(int j = (flexsize-1) ; j >= 0 ; j-- )
           {
              ans.push_back(flex[j]);
           }
       }
       return ans;
    }
};

// I may try a recursive loop in which I'll prioritly take values in the each digits order itself
// To Be Implemented As soon as I'm up with the Codeforces Contest Now

// Write Algorithm That Runs in O(N) Run Time and O(1) extra space