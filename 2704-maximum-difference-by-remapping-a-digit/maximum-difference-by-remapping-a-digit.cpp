class Solution {
public:
    int minMaxDifference(int num) {
        // reconstruct the numbers
        int temp = num;
        int flex = (num%10), jump = (num%10);
        while(temp >= 10)
        {
            temp /= 10;
            if(temp%10 != 9) flex = (temp%10);
            if(temp%10 != 0) jump = (temp%10);
        }

        cout<<flex<<" "<<jump<<endl;

        // now we know left most number
        int firstConstruct = 0, firstTemp = 1;
        int secondConstruct = 0, secondTemp = 1;
        while(num)
        {
            int NumModulo = (num%10);
            if(NumModulo == flex)
            {
                firstConstruct += (firstTemp*9);
            }
            
            if(NumModulo == jump)
            {
                secondConstruct += (secondTemp*0);
            }

            if(NumModulo != flex) firstConstruct += (firstTemp*NumModulo);
            if(NumModulo != jump) secondConstruct += (secondTemp*NumModulo);

            firstTemp *= 10;
            secondTemp *= 10;
            num /= 10;
        }

        cout<<firstConstruct<<" "<<secondConstruct<<endl;

        return (firstConstruct - secondConstruct);
    }
};