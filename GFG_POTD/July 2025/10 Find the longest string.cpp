class TrieNode {
    public:
    TrieNode* child[26];
    bool isleaf;
    TrieNode(){
        isleaf=false;
        for(int i=0;i<26;i++)
            child[i]=nullptr;
    }
};

class Solution {
  public:
    string longestString(vector<string> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        
        TrieNode* root=new TrieNode();
        root->isleaf=true;
        int maxSize=0;
        string str;
        for(string&s:arr)
        {
            TrieNode* curr=root;
            int c=s.size(),f=1;
            for(int i=0;i<s.size();i++)
            {
                if( !curr->isleaf) {
                    c=1;
                    f=0;
                    break;
                }
                
                if(curr->child[s[i]-'a'])
                    curr=curr->child[s[i]-'a'];
                else {
                    TrieNode* node=new TrieNode();
                    curr->child[s[i]-'a']=node;
                    curr=node;
                }
            }
            // cout<<"for s="<<s<<", c="<<c<<endl;
            if(f)   curr->isleaf=true;
            if(c>maxSize) {
                maxSize=c;
                str=s;
            }
        }
        return str;
    }
};
