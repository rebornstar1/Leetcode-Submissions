class Solution {
public:
    vector<int> minOperations(string boxes) {
        // Naive Approach -> directly count the number of moves required
        
        // count the number of ones and the distance from first one and each iteration 
        // keep changing with the respect to current and prev boxes
        int countOfOne = 0, n = boxes.size(), curr_val = 0, countPrev = 0;
        for(int i = 1 ; i < n ; i++ )
        {
           if(boxes[i] == '1'){
              countOfOne++;
              curr_val += i;
           }
        }

        if(boxes[0] == '1') countPrev++;

        vector<int>ans;
        ans.push_back(curr_val);
        for(int i = 1 ; i < n ; i++ )
        {
            curr_val += countPrev;
            curr_val -= countOfOne;
            if(boxes[i] == '1')
            {
                countPrev++;
                countOfOne--;
            }
            ans.push_back(curr_val);
        }
        return ans;
    }
};

// 1100101
// This can be taken as the example test case
// 11 moves required 11 + 1 - 1 * 3 
// 1 + 3 + 5 