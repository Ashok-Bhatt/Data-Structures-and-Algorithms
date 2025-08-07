#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    vector<TrieNode*> next;
    int wordCount;
    int prefixCount;

    TrieNode() {
        this->next.resize(26, NULL);
        this->wordCount = 0;
        this->prefixCount = 0;
    }

    bool hasNext(int pos) {
        return next[pos] != NULL;
    }

    void setNext(int pos) {
        next[pos] = new TrieNode();
    }

    void unsetNext(int pos) {
        TrieNode* temp = next[pos];
        delete temp;
        next[pos] = NULL;
    }

    TrieNode* getNext(int pos) {
        return next[pos];
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string &word) {
        TrieNode* node = root;
        int n = word.size(), index = 0;
        while (index < n) {
            int pos = word[index] - 'a';
            if (!node->hasNext(pos)) {
                node->setNext(pos);
            }
            node = node->getNext(pos);
            node->prefixCount++;
            if (index == n - 1) node->wordCount++;
            index++;
        }
    }

    int countWordsEqualTo(string &word) {
        TrieNode* node = root;
        int n = word.size(), index = 0;

        while (node && index < n) {
            int pos = word[index] - 'a';
            if (!node->hasNext(pos)) return 0;
            node = node->getNext(pos);
            index++;
        }

        return node ? node->wordCount : 0;
    }

    int countWordsStartingWith(string &word) {
        TrieNode* node = root;
        int n = word.size(), index = 0;

        while (node && index < n) {
            int pos = word[index] - 'a';
            if (!node->hasNext(pos)) return 0;
            node = node->getNext(pos);
            index++;
        }

        return node ? node->prefixCount : 0;
    }

    void eraseNode(string &word, int index, int n, TrieNode* &root){
        if (index==n) return; 
        TrieNode* current = root->getNext(word[index]-'a');
        current->prefixCount--;
        if (index==n-1) current->wordCount--;
        eraseNode(word, index+1, n, current);
        if (current->prefixCount == 0){
            root->next[word[index]-'a'] = NULL;
            delete current;
        }
    }

    void erase(string &word) {
        int n = word.size(), index = 0;
        eraseNode(word, index, n, root);
    }
};
