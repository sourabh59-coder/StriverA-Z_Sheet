#include <bits/stdc++.h>

struct Node {
    Node* links[26];
    bool flag = false;

    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
        flag = false;
    }

    bool containKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* new_node) {
        links[ch - 'a'] = new_node;
    }

    Node* getNext(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Tries {
public:
    Node* root;
    int cnt;

    Tries() {
        root = new Node();
        cnt = 0;
    }

    void InsertSuffix(const std::string& word) {
        Node* node = root;

        for (char ch : word) {
            if (!node->containKey(ch)) {
                node->put(ch, new Node());
                cnt++;
            }
            node = node->getNext(ch);
        }
        node->setEnd();
    }

    int getCount() {
        return cnt;
    }
};

int countDistinctSubstrings(const std::string& s) {
    Tries obj;

    for (int i = 0; i < s.length(); ++i) {
        obj.InsertSuffix(s.substr(i));
    }

    return obj.getCount() + 1; // Including the empty substring
}
