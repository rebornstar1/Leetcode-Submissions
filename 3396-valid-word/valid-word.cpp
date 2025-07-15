class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        if(n < 3) return false;

        int vowel = 0, consonant = 0;
        unordered_set<char>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');

        for(int i = 0 ; i < n ; i++ )
        {
            if(!((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= '0' && word[i] <= '9'))) return false;
            else if(!(word[i] >= '0' && word[i] <= '9'))
            {
                if(st.find(word[i]) != st.end()) vowel++;
                else consonant++;
            }
        }

        // one vowel and one consonant must
        if(vowel > 0 && consonant > 0) return true;
        return false;
    }
};