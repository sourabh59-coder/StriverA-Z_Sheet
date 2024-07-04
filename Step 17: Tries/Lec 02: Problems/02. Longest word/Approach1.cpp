#include <vector>
#include <string>
using namespace std;

struct Node {
    Node* links[26];
    bool flag = false;

    bool containKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    Node* getNext(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* new_node) {
        links[ch - 'a'] = new_node;
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    ~Trie() {
        deleteNode(root);
    }

    void InsertNode(const string& word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->getNext(ch);
        }
        node->setEnd();
    }

    bool isPossible(const string& word) {
        Node* node = root;
        for (char ch : word) {
            if (node->containKey(ch)) {
                node = node->getNext(ch);
                if (!node->isEnd()) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }

private:
    void deleteNode(Node* node) {
        for (int i = 0; i < 26; ++i) {
            if (node->links[i] != NULL) {
                deleteNode(node->links[i]);
            }
        }
        delete node;
    }
};

string completeString(int n, vector<string>& a) {
    Trie obj;
    for (const string& word : a) {
        obj.InsertNode(word);
    }

    string ans = "";
    int len = 0;

    for (const string& word : a) {
        if (obj.isPossible(word)) {
            if (len < word.size()) {
                len = word.size();
                ans = word;
            } else if (len == word.size() && ans 
            > word) {
                ans = word;
            }
        }
    }

    return (ans=="") ? "None":ans;
}
