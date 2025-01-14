class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {

        int maxOf = max(red,blue);
        if(maxOf < 2) return 1;

        int temp = 1;

        // Case I RBRB
        int even = 0;
        int fred = red, fblue = blue;
        while(1)
        {
           if(even%2 == 0)
           {
              if(red < temp) break;
                red -= temp;
           }
           else
           {
              if(blue < temp) break;
                blue -= temp;
           }
           even++;
           temp++;
        }

        int odd = 0;
        temp = 1;
        while(1)
        {
            if(odd%2 == 0)
            {
                if(fblue < temp) break;
                  fblue -= temp;
            }
            else
            {
                if(fred < temp) break;
                   fred -= temp;
            }
            odd++;
            temp++;
        }

        cout<<even<<" "<<odd<<endl;

        return max(even,odd);
    }
};