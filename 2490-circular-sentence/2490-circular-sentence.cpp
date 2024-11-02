class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        int i=0;
        int j=0;
        while(j<n)
        {
            if(sentence[j]==' ')
            {
                if(j+1<n &&  sentence[j-1]!=sentence[j+1])
                {
                    return false;
                }
            }
            i++;
            j++;
        }
        if(sentence[n-1]!=sentence[0])
        {
            return false;
        }
    return true;
    }
};