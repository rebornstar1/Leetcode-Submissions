class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int area = 0;

        for(int i = 0 ; i < n ; i++ )
        {
            for(int j = 0 ; j < m ; j++ )
            {
                if(matrix[i][j] == '1')
                {
                    int left=j,right=j,up=i,down=i;
                    // 4 Extremities of a Rectangle
                    // (Now From here onwards I will grow this as rectangle)
                    int flag = 1;
                    while(flag == 1)
                    {
                      flag = 0;
                      // Upward Increment
                      if(up!=0)
                      {
                         int temp = 1;
                         for(int k = left ; k <= right ; k++ )
                         {
                            if(matrix[up-1][k] == '0')
                            {
                              temp = 0;
                            }
                         }
                         if(temp == 1)
                         {
                            flag = 1;
                            up--;
                         }
                      }

                      // Downward Increment
                      if(down != (n-1))
                      {
                         int temp = 1;
                         for(int k = left ; k <= right ; k++ )
                         {
                            if(matrix[down+1][k] == '0')
                            {
                              temp = 0;
                            }
                         }
                         if(temp == 1)
                         {
                            flag = 1;
                            down++;
                         }
                      }

                      // Leftward Increment
                      if(left!=0)
                      {
                        int temp = 1;
                        for(int k = up ; k <= down ; k++ )
                        {
                          if(matrix[k][left-1] == '0')
                          {
                            temp = 0;
                          }
                        }
                        if(temp == 1)
                        {
                            flag = 1;
                            left--;
                        }
                      }

                      // Rightward Increment
                      if(right != (m-1))
                      {
                        int temp = 1;
                        for(int k = up ; k <= down ; k++ )
                        {
                          if(matrix[k][right+1] == '0')
                          {
                            temp = 0;
                          }
                        }
                        if(temp == 1)
                        {
                            flag = 1;
                            right++;
                        }
                      }
                    }
                    area = max((right-left+1)*(down-up+1),area);
                }
            }
        }
        return area;
    }
};