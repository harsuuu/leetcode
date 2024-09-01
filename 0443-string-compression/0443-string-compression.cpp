class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int index=0;
        while(i<chars.size())
        {
            char curr_ch = chars[i];
            int cnt = 0;

            //find count of duplicate.
            while(i<chars.size() && chars[i]==curr_ch)
            {
                i++;
                cnt++;
            }

            //Now do that assign work
            chars[index]=curr_ch;
            index++;
            if(cnt>1)
            {
                string count = to_string(cnt);

                for(auto it:count)
                {
                    chars[index]=it;
                    index++;
                }
            }
        }
    return index;
    }
};