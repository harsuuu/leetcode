class Solution {
public:
    char solveop(vector<char>&temp,char op)
    {
        if(op=='!')
        {
            return temp[0]=='t'?'f':'t';
        }
        if(op=='&')
        {
            for(auto it:temp)
            {
                if(it=='f') //khi bhi false mil jaye to uska & hmesa false hi aayega.
                {
                    return 'f';
                }
            }
        return 't';
        }
        if(op=='|')
        {
            for(auto it:temp)
            {
                if(it=='t') return 't';
            }
            return 'f';
        }
    return 't';
    }
    bool parseBoolExpr(string expression) {
        stack<char>st;
        for(auto it:expression)
        {
            if(it==',') continue;
            if(it==')')
            {
                vector<char>temp;
                while(st.top()!='(')
                {
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();   //remove '('
                char op = st.top();
                st.pop();
                st.push(solveop(temp,op));
            }
            else{
                st.push(it);
            }
        }
    return st.top() == 't' ? true : false;
    }
};