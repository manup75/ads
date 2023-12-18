#include<iostream>
#include<queue>
using namespace std;

class node
{  
    public:
       int data;
       node*left;
       node*right;
       node(int d)
       {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
       }
   
};
node* buildTree(node* root)
{   
     cout<<"enter the data";
     int data;
     cin>>data;

     root=new node(data);
     if(data==-1)
     {
        return NULL;
     }
   cout<<"Enter data for left of"<<data<<endl;
   root->left=buildTree(root->left);
     cout<<"Enter data for right of"<<data<<endl;
   root->right=buildTree(root->right);

   return root;
     
      
}
//level order
void levelorderTrav(node* root)
{
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
    cout<<temp->data<<" ";
    if(temp->left)
    {
        q.push(temp->left);
    }
    if(temp->right)
    {
        q.push(temp->right);
    }
        }
    }
}  
  //inorder
void inorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
  //postorder
void postorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
//mirror
void mirror(node* root)
{
    if(root==NULL)
    {
        return ;
    }
    else{
        node* temp;
        mirror(root->left);
        mirror(root->right);

        temp=root->left;
        root->left=root->right;
        root->right=temp;

    }

}
//count height of tree
   int height(node* root)
   {
    if(root==NULL)
    {
        return 0;
    }
    int r=height(root->right);
    int l=height(root->left);
    if(r>l)
    {
        return r+1;
    }
    else
    {
        return l+1;
    }
   }

//child node
   void childnode(node* root)
   {
    if(root==NULL)
    {
        return;
    }
    if(!root->left&&!root->right)
    {
           cout<<root->data;
    }
     if(root->left)
     {
         childnode(root->left);
     }
   if(root->right)
   {
    childnode(root->right);
   } 
   }

   // count all nodes
   int countnode(node* root)
   {
    if(root==NULL){
        return 0;
    }
int l=countnode(root->left);
int r=countnode(root->right);
return l+r+1;
   }
int main()
{
         node* root;
         root=buildTree(root);
         inorder(root);
        // cout<<endl;
       //  postorder(root);
         //2 4 -1 -1 5 -1 -1
         
          //call node count
          cout<<"total node "<<countnode(root);

         cout<<"After mirror the tree"<<endl;
         mirror(root);
          inorder(root);

          cout<<endl<<"height of tree"<<height(root)<<endl;

          childnode(root);


    return 0;
}