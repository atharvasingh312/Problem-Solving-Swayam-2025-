//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            for(int k=0;k<sz;k++)
            {
                TreeNode* f=q.front();
                q.pop();
                if(!f) s+="N";
                else{
                    s+=to_string(f->val)+"$";
                        q.push(f->left);
                        q.push(f->right);
                }
            }
        }
        cout<<s<<endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        TreeNode* root=NULL;
        int i=0,v=0,neg=0;
        if(data[i]=='-'){                
            neg=1;
            i++;
        }
        while(i<data.size() && data[i]!='$'){
            v=(v*10)+(data[i]-'0');
            i++;
        }
        i++;
        if(neg) v*=-1;
        root=new TreeNode(v);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            for(int k=0;k<sz;k++)
            {
                TreeNode* f=q.front();
                q.pop();
                if(i<data.size() && data[i]!='N')
                {
                    int val=0;
                    int neg=0;//negative flag
                    if(data[i]=='-'){
                        neg=1;
                        i++;
                    }
                    int j;
                    for(j=i;j<data.size() && data[j]!='$';j++)
                    {
                        val=(val*10)+(data[j]-'0');
                    }
                    if(neg) val*=-1;
                    f->left=new TreeNode(val);
                    q.push(f->left);
                    i=j+1;
                }
                else i++;
                if(i<data.size() && data[i]!='N')
                {
                    int val=0;
                    int neg=0;//negative flag
                    if(data[i]=='-'){
                        neg=1;
                        i++;
                    }
                    int j;
                    for(j=i;j<data.size() && data[j]!='$';j++)
                    {
                        val=(val*10)+(data[j]-'0');
                    }
                    if(neg) val*=-1;
                    f->right=new TreeNode(val);
                    q.push(f->right);
                    i=j+1;
                }
                else i++;
            }
        }
        return root;
    }
};
