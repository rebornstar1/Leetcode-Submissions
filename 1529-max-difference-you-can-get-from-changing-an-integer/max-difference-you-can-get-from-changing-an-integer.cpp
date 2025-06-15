class Solution {
public:
    int maxDiff(int num) {
        int x = -1, temp = num;
        while(temp)
        {
            if((temp%10) != 9) x = temp%10;
            temp /= 10;
        }
        
        temp = num;
        int y = -1, flag = 0;
        while(temp)
        {
            if((temp%10) != 0) y = (temp%10);
            temp /= 10;
        }

        if(y == 1)
        {
            y = -1;
            temp = num;
            flag = 1;
            while(temp)
            {
                if(temp%10!= 0 && temp%10 != 1) y = (temp%10);
                temp /= 10;
            }
        }

        cout<<x<<" "<<y<<endl;

        int a = num, b = num;

        if(x != -1)
        {
            temp = num;
            a = 0;
            int fact = 1;
            while(temp)
            {
                if(temp%10 == x)
                {
                    a = (a+ 9*fact);
                }
                else
                {
                    a = (a + fact*(temp%10));
                }
                temp /= 10;
                fact *= 10;
            }
        }

        if(y != -1)
        {
            temp = num;
            b = 0;
            int fact = 1;
            while(temp)
            {
                if(temp%10 == y)
                {
                    if(flag) b = (b + 0*fact);
                    else b = (b + 1*fact);
                }
                else
                {
                    b = (b + fact*(temp%10));
                }
                fact *= 10;
                temp /= 10;
            }
        }

        cout<<a<<" "<<b<<endl;

        return (a-b);
    }
};