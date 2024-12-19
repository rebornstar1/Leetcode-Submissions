class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int N = arr.size();
        int i = 0, j = 0, minVal = arr[0], maxVal = arr[0];
        int ansCount = 0;
        while(j < N)
        {
           if(i == minVal && j == maxVal)
           {
              ansCount++;
              i = (j+1);
              j++;
              if(j < N)
              {
                minVal = arr[j];
                maxVal = arr[j];
              }
           }
           else
           {
             j++;
             if(j < N)
             {
                minVal = min(minVal,arr[j]);
                maxVal = max(maxVal,arr[j]);
             }
           }
        }
        return ansCount;
    }
};