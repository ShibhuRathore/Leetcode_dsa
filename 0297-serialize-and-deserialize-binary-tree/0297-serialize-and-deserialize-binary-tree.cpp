/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
      void serializeHelper(TreeNode*root,string &result){
        if(!root){
            result+="null,";
            return;
        }
        result+=to_string(root->val)+",";
        serializeHelper(root->left,result);
        serializeHelper(root->right,result);
      }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       string result;
       serializeHelper(root,result);
       return result; 
    }
     TreeNode* deserializeHelper(vector<string>&tokens,int &index){
        if(index>=tokens.size()||tokens[index]=="null"){
            index++;
            return nullptr;
        }
        TreeNode* node= new TreeNode(stoi(tokens[index]));
        index++;
        node->left=deserializeHelper(tokens,index);
        node->right=deserializeHelper(tokens,index);
        return node;
     }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>tokens;
        string token;
        stringstream ss(data); // converts data string into tokens-> "123"->"1,2,3"
        while(getline(ss,token,',')){
            tokens.push_back(token);
        }
        int index=0;
        return deserializeHelper(tokens,index);

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));