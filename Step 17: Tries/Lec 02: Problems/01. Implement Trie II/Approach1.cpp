#include <bits/stdc++.h> 


struct Node{
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefixWith = 0;


    bool containKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }

    Node* getNext(char ch)
    {
        return links[ch-'a'];
    }

    Node* put(char ch, Node* new_node)
    {
        links[ch-'a'] = new_node;
    }

    void increasePrefix()
    {
        cntPrefixWith++;
    }

    void increaseEnd()
    {
        cntEndWith++;
    }

    void reducePrefix()
    {
        cntPrefixWith--;
    }

    void decreaseEnd()
    {
        cntEndWith--;
    }
};

class Trie{

    public:

    Node* root;

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;

        for(int i=0;i<word.size();i++)
        {
            if(!node->containKey(word[i]))
            {
                node->put(word[i],new Node());
            }

            node = node->getNext(word[i]);

            node->increasePrefix();
        }

        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containKey(word[i]))  return 0;

            node = node->getNext(word[i]);
        }

        return (node->cntEndWith);
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node = root;

        for(int i=0;i<word.size();i++)
        {
            if(!node->containKey(word[i]))  return 0;

            node = node->getNext(word[i]);
        }

        return (node->cntPrefixWith);
    }

    void erase(string &word){
        // Write your code here.
        Node* node = root;

        for(int i=0;i<word.size();i++)
        {
            if(!node->containKey(word[i]))  return;

            node = node->getNext(word[i]);
            node->reducePrefix();
        }

        node->decreaseEnd();
    }
};
