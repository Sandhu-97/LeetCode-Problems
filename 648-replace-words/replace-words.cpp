class TrieNode{
    public:
    bool end;
    TrieNode* children[26];

    TrieNode(){
        end=false;
        for (auto& ch: children) ch=nullptr;
    }
};

class Trie{
    public: 
    TrieNode* root;

    Trie(){
        root=new TrieNode();
    }

    void add(string word){
        TrieNode* curr = root;
        for (char c: word){
            int idx = c-'a';
            if (curr->children[idx]==nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->end = true;
    }

    bool search(string word, string& ans){
        TrieNode* curr = root;
        int length = 0;
        int mini = length;
        for (char c: word){
            int idx = c-'a';
            if (curr->children[idx]==nullptr) break;
            if (curr->end) return true;
            ans.push_back(c);
            curr=curr->children[idx];
        }
        return curr->end;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sen) {
        Trie trie;
        for (string s: dictionary){
            trie.add(s);
        }
        sen.push_back(' ');
        int n = sen.size();
        int left=0, right=0;
        string res;
        while (right<n){
            right++;
            if (sen[right]==' ') {
                int temp = left;
                string curr = "";
                while (left<right){
                    curr.push_back(sen[left]);
                    left++;
                }

                string ans = "";
                bool find = trie.search(curr, ans);
                if (find){
                    res.append(ans);
                }
                else res.append(curr);
                res.push_back(' ');
                left++;
                right++;
            }
        }

        res.pop_back();
        return res;
    }
};