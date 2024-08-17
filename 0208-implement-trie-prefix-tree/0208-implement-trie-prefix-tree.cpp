class Trie {
public:
    struct trieNode{
        bool isEndofWord;
        trieNode* children[26];
    };
    trieNode* getNode()
    {
        trieNode* newNode = new trieNode();
        newNode->isEndofWord=false;

        for(int i=0;i<26;i++)
        {
            newNode->children[i]=NULL;
        }
    return newNode;
    }

    trieNode* root;
    Trie() {
        root = getNode();    
    }
    
    void insert(string word) {
        trieNode* temp = root;

        for(int i=0;i<word.length();i++)
        {
            char ch = word[i];
            int idx = ch-'a';

            if(temp->children[idx]==NULL)
            {
                temp->children[idx] = getNode();
            }

            temp=temp->children[idx];
        }
    temp->isEndofWord = true;
    }
    
    bool search(string word) {
        trieNode* temp = root;
      
        for(int i=0;i<word.length();i++)
        {
            char ch = word[i];
            int idx = ch-'a';

            if(temp->children[idx]==NULL)
            {
                return false;
            }
            temp=temp->children[idx];
        }
        if(temp!=NULL && temp->isEndofWord==true)
        {
            return true;
        }
    return false;
    }
    
    bool startsWith(string prefix) {
        trieNode* temp = root;
        int i=0;
        for(;i<prefix.length();i++)
        {
            char ch = prefix[i];
            int idx = ch-'a';

            if(temp->children[idx]==NULL)
            {
                return false;
            }

            temp=temp->children[idx];
        }
        if(i==prefix.length())
        {
            return true;
        }
    return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */