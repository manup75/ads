#include<iostream>
#include<queue>
using namespace std;


class node{
public:
int data;
node* left;
node*right;
node(int d)
{
    this->data=d;
    this->left=NULL;
    this->right=NULL;
}
};
    node* insertdata(node* root,int d)
    {    
          if(root==NULL)
          {
            root=new node(d);
            return root;
          }
           if(d>root->data)
           {
            root->right=insertdata(root->right,d);

           }
           else
           {
            root->left=insertdata(root->left,d);
           }
     return root;
    }

 void userinput(node* &root)
 {   int data;
    cout<<"Enter user data";
    cin>>data;
    while(data!=-1)
    {
        root=insertdata(root,data);
        cin>>data;
    }
    
 }
//preorder
void preorder(node*root)
{
 if(root==NULL)
 {
    return;
 }  
 cout<<root->data<<" ";
 preorder(root->left);
 preorder(root->right); 
}
   //inorder 
void inorder(node* root)
{
   if(root==NULL)
   {
    return ;
   }
   inorder(root->left);
   cout<<root->data<<"";
   inorder(root->right);
}
  //post order
void postorder(node* root)
{
   if(root==NULL)
   {
    return ;
   }
   postorder(root->left); 
   postorder(root->right);
    cout<<root->data<<"";
}
 
 //mirror
    void mirror(node* root)
    {  
        if(root==NULL)
        {
            return;
        }
        else
        {
        
        mirror(root->left);
        mirror(root->right);
        node* temp;
        temp=root->left;
        root->left=root->right;
        root->right=temp;

        }
    }
  //levelorder
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
int main()
{
   node* root=NULL;
   userinput(root);
    //3 4 5 -1
    cout<<endl<<"preorder"<<endl;
    preorder(root);

    cout<<endl<<"inorder"<<endl;
    inorder(root);
    
    cout<<endl<<"postorder"<<endl;
    postorder(root);

    // mirror
    mirror(root);
    cout<<endl<<"inorder of mirror"<<endl;
    inorder(root);

return 0;
}