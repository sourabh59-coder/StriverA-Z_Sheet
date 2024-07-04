/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
struct Node{
    Node* links[26];
    bool flag = false;

    bool containKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }

    void put(char ch, Node* new_node)
    {
        links[ch-'a'] = new_node;
    }

    Node* getNode(char ch)
    {
        return links[ch-'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};



class Trie {

public:

    Node* root;

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* temp = root;

        for(int i=0;i<word.size();i++)
        {
            if(!temp->containKey(word[i]))
            {
                temp->put(word[i],new Node());
            }

            temp = temp->getNode(word[i]);
        }

        temp->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* temp = root;

        for(int i=0;i<word.size();i++)
        {
            if(!temp->containKey(word[i]))   return false;

            temp = temp->getNode(word[i]);
        }

        return temp->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* temp = root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!temp->containKey(prefix[i])) return false;

            temp = temp->getNode(prefix[i]);
        }

        return true;
    }
};
