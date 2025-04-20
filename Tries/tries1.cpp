#include <bits/stdc++.h>
using namespace std;

class trieNode {

    public:
    char data;
    trieNode* children[26];
    bool isTerminal;

    trieNode(char data){
        this->data = data;
        for (int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {

    public:
    trieNode* root;

    Trie(){
        root = new trieNode('\0');
    }

    void insertUtil(trieNode* root, string word){

        if (word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0]-'a';
        trieNode* child;

        if (root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new trieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insert(string x){
        insertUtil(root, x);
    }

    bool searchUtil(trieNode* root, string x){

        if (x.length() == 0){
            return root->isTerminal;
        }

        int index = x[0] - 'a';
        trieNode* child;

        if (root->children[index] == NULL){
            return false;
        }
        else{
            child = root->children[index];
        }

        return searchUtil(child, x.substr(1));
    }

    bool search(string x){
        return searchUtil(root, x);
    }

    void deletionUtil(trieNode* root, string word){

        if (word.length() == 0){
            root->isTerminal = false;
            return;
        }

        int index = word[0]-'a';

        if (root->children[index]->data == word[0]){
            trieNode* child = root->children[index];
            deletionUtil(child, word.substr(1));
        }
        else{
            return;
        }
    }

    bool effecient_deletion(trieNode* &root, string word){

        if (word.length() == 0){
            if (root->isTerminal){
                return true;
            }
            return false;
        }

        int index = word[0]-'a';

        if (root->children[index] != NULL && root->children[index]->data == word[0]){
            trieNode* child = root->children[index];
            bool ans = effecient_deletion(child, word.substr(1));
            if (ans){
                root->children[index] = NULL;
                delete child;
                return true;
            }
            return false;
        }
        return false;
    }

    void deletion(string x){
        //deletionUtil(root, x);
        effecient_deletion(root, x);
    }
};

int main() {

    Trie* t1 = new Trie();
    cout << t1->search("abcd") << endl;
    t1->insert("go");
    t1->insert("ashok");
    t1->insert("hello");
    cout << t1->search("goo") << endl;
    cout << t1->search("g") << endl;
    cout << t1->search("go") << endl;
    cout << t1->search("ashok") << endl;
    cout << t1->search("hello") << endl;
    t1->deletion("hello");
    cout << t1->search("ashok") << endl;
    cout << t1->search("hello") << endl;

}