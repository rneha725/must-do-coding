//Working code
//Each node can have a fixed number of children, and a marker for the end of the word
//you start adding a word from root, node does not have to have a value, just a path.

#include <bits/stdc++.h>
using namespace std;

class node {
public:	
	node* children[26];
	bool isEnd;
	
	node(){
		isEnd=false;
		for(int i=0;i<26;i++) {
			children[i]=NULL;
		}
	}
};

void insert(node* root, string s){
	node* cur=root;
	for(int i=0;i<s.size();i++) {
		if(cur->children[s[i]-'a']) {
			cur = cur->children[s[i]-'a'];
		} else {
			cur->children[s[i]-'a']=new node();
			cur = cur->children[s[i]-'a'];
		}
	}
	cur->isEnd=true;
}

bool find(node* root, string word) {
	node* cur=root;
	
	for(int i=0;i<word.size();i++) {
		if(cur->children[word[i]-'a']==NULL) return false;
		else cur = cur->children[word[i]-'a'];
	}
	if(cur->isEnd!=true) return false;
	return true;
}

vector<string> sort(node* trie, string s) {
    vector<string> result;
    if(trie->isEnd) cout<<s<<" ";
    for(int i=0;i<26;i++) {
        string t=s;
        if(trie->children[i]) {
            char a='a'+i;
            s+=a;
            sort(trie->children[i], s);
        } 
        s=t;
    }
    return result;
}

int main() {
	node* trie = new node();
	string arr[]={"the", "there", "that", "this", "he", "she", "is"};
	int SIZE=7;
	for(int i=0;i<SIZE;i++)
		insert(trie, arr[i]);
		
	cout<<find(trie, "ere");
	sort(trie, "");
	return 0;
}