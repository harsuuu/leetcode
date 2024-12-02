class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord){
        //Basically it will convert sentense into token 
        //Ex: "this is home" -> "this","is","home"
        stringstream ss(sentence);

        string token = "";
        int index = 1;
        while(getline(ss,token,' ')) {    //it will read the first word.
            if(token.find(searchWord, 0) == 0) {
                return index;
            }
            index++;
        }
        return -1;
    }
};