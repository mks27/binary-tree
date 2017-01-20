#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;


class bintree
{
  int data;
  bintree *left;
  bintree *right;

  public:
      bintree()
      {
          data=0;
          left=NULL;
          right=NULL;
      }
      void insert();
      void pre(bintree*);
      void in(bintree*);
      void post(bintree*);
      int height(bintree*);
      void bfs();
      void inorderwithstack();
      void numofnodes(bintree*);
      void clone();
};

bintree *head=NULL;
bintree *head1=NULL;
int l=0;
int r=0;
int ht;

void bintree::insert()
{
  bintree *p ,*p1;
  int d;
  char c;
  cout<<"\n enter the data u want to enter";
  cin>>d;
  if(head==NULL)
  {
      p=new bintree();
      p->data=d;
      p->left=NULL;
      p->right=NULL;
      head=p;
  }

  else
  {
    p1=head;
    p=new bintree;
    p->data=d;
    p->left=NULL;
    p->right=NULL;


    while(p1->left!=NULL||p1->right!=NULL)
    {
       cout<<"\n want to put insert data in left or right,press(r/l)";
       cin>>c;
       if(c=='l'&&p1->left==NULL)
        break;
        if(c=='r'&&p1->right==NULL)
          break;

       if(c=='l')
        p1=p1->left;
        else if(c=='r')
        p1=p1->right;
    }
    if(p1->left==NULL&&p1->right==NULL)
       {
          cout<<"\n want to put insert data in left or right,press(r/l)";
          cin>>c;
       }

    if(c=='l')
        p1->left=p;
    else
        p1->right=p;

 }

}

void bintree::pre(bintree *h)
{
  if(head==NULL)
  {
      cout<<"\n create binary tree first";
      return;
  }

  if(h==NULL)
    return;

   cout<<h->data<<" ";
   pre(h->left);
   pre(h->right);
}

void bintree::in(bintree *h)
{
   if(head==NULL)
  {
      cout<<"\n create binary tree first";
      return;
  }

  if(h==NULL)
    return;

   in(h->left);
   cout<<h->data<<" ";
   in(h->right);
}

void bintree::post(bintree *h)
{
   if(head==NULL)
  {
      cout<<"\n create binary tree first";
      return;
  }

  if(h==NULL)
    return;

   post(h->left);
   post(h->right);
   cout<<h->data<<" ";
}

int bintree::height(bintree *h)
{
  if(head==NULL)
  {
	  cout<<"\n create binary tree first";
	  return 0;
  }

  if(h==NULL)
    return 0;

   return( max(height(h->left),height(h->right))+1);
}

void bintree::bfs()
{
  queue<bintree*>q;
  if(head==NULL)
  {
	  cout<<"\n create binary tree first";
	  return;
  }

  bintree *p;
  p=head;
  q.push(p);
  while(q.empty()==0)
  {

	  cout<<q.front()->data<<" ";
	  if(q.front()->left!=NULL)
	  {
		  q.push(q.front()->left);
	  }
	  if(q.front()->right!=NULL)
		  q.push(q.front()->right);

	  q.pop();
  }
}

void bintree::inorderwithstack()
{
    stack<bintree*>s;
   if(head==NULL)
  {
      cout<<"\n create binary tree first";
      return;
  }

  bintree *p;
  p=head;

  while(p!=NULL)
        {
          s.push(p);
            p=p->left;
           while(p==NULL&&s.empty()==0)
           {
               p=s.top();
               s.pop();
               cout<<p->data<<" ";
               p=p->right;
           }

        }

}

int z=0;
int y=0;
void bintree::numofnodes(bintree *p)
{

   if(head==NULL)
   {
       cout<<"\n create tree first";
       return;
   }

   if(p==NULL)
    return;

   z++;
   numofnodes(p->left);
   numofnodes(p->right);

}

void bintree::clone()
{
    queue<bintree*>q;
    queue<bintree*>q1;
  if(head==NULL)
  {
      cout<<"\n create the tree first then cloning is possible";
      return;
  }

  bintree *p;
  bintree *p1, *p2;
  p=head;
  q.push(p);
  while(q.empty()==0)
  {
      if(q.front()==p)
      {
          p1=new bintree();
        p1->data=q.front()->data;
          head1=p1;
           q1.push(p1);
      }

	  if(q.front()->left!=NULL)
	  {
		  q.push(q.front()->left);
		  p1=new bintree();
		  p1->data=q.front()->left->data;
		  q1.front()->left=p1;
		  q1.push(p1);
	  }
	  if(q.front()->right!=NULL)
      {
         q.push(q.front()->right);
         p1=new bintree();
         p1->data= q.front()->right->data;
          q1.front()->right=p1;
          q1.push(p1);
      }

        p2=q.front();
	    q.pop();
	    delete p2;
        q1.pop();
  }
  cout<<"\n clone formed";
  cout<<"\n printing clone of tree:";
  pre(head1);
  head=NULL;
  return;
}



int main()
{
   bintree obj;
   char ch;
   int n;
   cout<<"-------------------binary tree implementation---------------------";
   do
   {
     cout<<"\n 1)to insert a node";
     cout<<"\n 2)for pre order traversal";
     cout<<"\n 3)for in order traversal";
     cout<<"\n 4)for post order traversal";
     cout<<"\n 5)find height of tree";
     cout<<"\n 6)breadth first traversal";
     cout<<"\n 7)cloning and delete original tree";
     cout<<"\n 8)in order traversal without recursion";
     cout<<"\n 9)count no. of nodes in tree";
     cout<<"\n 10)exit";
     cout<<"\n select option";
     cin>>n;

     switch(n)
     {
        case 1: obj.insert();
                  break;

        case 2: cout<<"\n pre order traversal:";
        	  obj.pre(head);
                  break;

        case 3: cout<<"\n in order traversal:";
        	 obj.in(head);
                   break;

        case 4:  cout<<"\n post order traversal:";
        	obj.post(head);
                  break;

        case 5:  cout<<"\n height of tree is:";
                   ht=obj.height(head);
                   cout<<ht;
                   break;

        case 6: cout<<"\n bfs:";
                 obj.bfs();
                   break;

        case 7:   obj.clone();
                    break;

        case 8: cout<<"\n in order:";
            obj.inorderwithstack();
                break;

        case 9: obj.numofnodes(head);
                z=z-y;
              cout<<"\n total no. of nodes are:"<<z;
                y=z;
                break;

        case 10: cout<<"\n exiting...";
                      return 0;
                     break;

        default:
            cout<<"\n  choose a valid option";

     }
        cout<<"\n do you want to continue,press(y/n)";
        cin>>ch;

   }while(ch=='y'||'Y');



    return 0;
}
