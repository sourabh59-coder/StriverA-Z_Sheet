class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> qe;
        
        qe.push({beginWord,1});
        if(st.count(beginWord)) st.erase(beginWord);
        
        while(!qe.empty())
        {
            auto node = qe.front();
            qe.pop();
            
            string word = node.first;
            int level = node.second;
            
            if(word==endWord)  return level;
            
            for(int i=0;i<word.size();i++)
            {
                char original = word[i];
                
                for(char ch='a';ch<='z';ch++)
                {
                    word[i] = ch;
                    
                    if(st.count(word))
                    {
                        st.erase(word);
                        qe.push({word,level+1});
                    }
                }
                
                word[i] = original;
            }
        }
        
        return 0;
    }
};
