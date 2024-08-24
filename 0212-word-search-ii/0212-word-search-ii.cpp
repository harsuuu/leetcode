class Solution {
public:
    vector<string>result;
    int row,col;
    vector<pair<int,int>>direction{{-1,0},{1,0},{0,1},{0,-1}};

    struct trieNode{
        bool endOfword;
        trieNode* children[26];
        string word;
    };

    trieNode* getNode(){
        trieNode* temp = new trieNode;
        temp->endOfword = false;
        temp->word="";
        for(int i=0;i<26;i++)
        {
            temp->children[i]=NULL;
        }

    return temp;
    }

    void insert(trieNode* root, string str)
    {
        trieNode* crowl = root;
        for(int i=0;i<str.length();i++)
        {
            char ch = str[i];
            if(crowl->children[ch-'a']==NULL)
            {
                crowl->children[ch-'a']=getNode();
            }
            crowl = crowl->children[ch-'a']; 
        }
        crowl->endOfword = true;
        crowl->word=str;
    }

    void DFS(vector<vector<char>>& board,int i,int j,trieNode* root)
    {
        if(i<0 || i>=row || j<0 || j>=col){
            return;
        }
        //agr phle se hi visited ya board ka staring bala trie m hi nhi to return mar jao.
        if(board[i][j]=='$' || root->children[board[i][j]-'a']==NULL)
        {
            return;
        }

        root = root->children[board[i][j]-'a'];

        if(root->endOfword==true)
        {
            result.push_back(root->word);
            root->endOfword = false;
        }

        char temp   = board[i][j];
        board[i][j] = '$';
        //then aage ki dfs
        for(pair<int,int>p:direction)
        {
            int new_i = i + p.first;
            int new_j = j  +p.second;

            DFS(board,new_i,new_j,root);
        }  

        board[i][j] = temp;
    } 


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        row = board.size();
        col = board[0].size();
 
        trieNode* root = getNode();

        for(auto &str :words)
        {
            insert(root,str);
        }

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                char ch = board[i][j];
                if(root->children[ch-'a'] != NULL)
                {
                    DFS(board,i,j,root);
                }
            }
        }
    return result;
    }
};