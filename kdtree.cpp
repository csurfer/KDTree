/* 
 * Author : Vishwas B Sharma
 * File   : kdtree.cpp
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define INF (int)1e9
#define LINF (long long)1e18
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x) ((x)<0?(-(x)):(x))
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define foreach(v,c) for( typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)

#define DEBUG false

class DataPoint{
public:
	// This data represents a point in which dimention ?
	int dim;
	// The point co-ordinate values
	double x,y;
	// A display function to show the co-ordinate values.
	void show()
	{
		switch(dim)
    {
			case 1: cout<<"x : "<<x<<endl; break;
			case 2: cout<<"x : "<<x<<" y : "<<y<<endl; break;
      default: cout<<"Erreneous dimentional point."<<endl; break;
    }
	}
  // A function to check equality of two points.
	bool equals(DataPoint d)
	{
		if(dim == d.dim)
		{
      switch(dim)
      {
        case 1: return (x == d.x)?true:false; break;
        case 2: return (x == d.x && y == d.y)?true:false; break;
        default: return false; break;
      }
		}
		else
			return false;
	}
  // A function to compare two data points.
  int compare(DataPoint d, int dim)
  {
    switch(dim)
    {
      case 1: return (x-d.x); break;
      case 2: return (y-d.y); break;
      default: return 0; break;
    }
  }
};

class Node{
public:
	//Dimention in which it divides the available data points
	int dimention;
	//Available DataPoints at this node
	vector<DataPoint> data;
	//Median of split
	DataPoint median;
  //Is it a leaf?
  bool leaf;
	//The pointers which lead to trees which hold less than or = median and greater
	//than median data points
	struct Node *less, *more;
};

bool comp1(DataPoint a, DataPoint b)
{
  return (a.x <= b.x)?true:false;
}

bool comp2(DataPoint a, DataPoint b)
{
  return (a.y <= b.y)?true:false;
}

class KDTree{
private:
	int dimLim;
	Node* root;
  // Function to display the tree for debugging purposes.
	void disp(Node* root)
	{
		if(root != NULL)
		{
			cout<<endl<<"Current Array"<<endl;
			REP(i, root->data.size())
			{
				root->data[i].show();
			}

			cout<<endl<<"Current Median : "<<endl;
			root->median.show();

      if(root->less != NULL)
      {
			  cout<<endl<<"Less Children"<<endl;
			  disp(root->less);
      }
      if(root->more != NULL)
			{
        cout<<endl<<"More Children"<<endl;
			  disp(root->more);
      }
		}
	}
  // Function to check the existance of a point.
	bool exists(Node* root, DataPoint key)
	{
		if(root != NULL && !root->leaf)
		{
			if(root->median.equals(key)) return true;
      else if(root->median.compare(key, root->dimention) < 0)
      {
        if(DEBUG) 
          cout<<"Checking Right subtree"<<endl;
        return exists(root->more, key);
      }
      else
      {
        if(DEBUG) 
          cout<<"Checking Left subtree"<<endl;
        return exists(root->less, key);			
      }
		}
		else if(root != NULL && root->leaf)
    {
      foreach(v, root->data)
      {
        if(key.equals(*v))
          return true;
      }
      return false;
    }
    else
			return false;
	}

  /*void split(Node *root, DataPoint d1, DataPoint d2)
  {
    foreach(v, root->data)
    {
      bool flag = true;
      for(int i=1;i<=d1.dim && flag;i++)
      {
        switch(i)
        {
          case 1:if(!((*v).x>=d1.x && (*v).x<=d2.x)) flag = false;break;
          case 2:if(!((*v).y>=d1.y && (*v).y<=d2.y)) flag = false;break;
          case 3:if(!((*v).x>=d1.z && (*v).z<=d2.z)) flag = false;break; 
        }
      }
      if(flag)
      {
        (*v).show();
      }
    }
  }

  void rectangleQ(Node *root, DataPoint d1, DataPoint d2)
  {
    if(root == NULL)
      return;
    else
    {
      if(root->leaf)
      {
        //Scan through everything in this array
        foreach(v, root->data)
        {
          bool flag = true;
          for(int i=1;i<=d1.dim && flag;i++)
          {
            switch(i)
            {
              case 1:if(!((*v).compare(d1,1)>=0 && (*v).compare(d2,1)<=0)) flag = false;break;
              case 2:if(!((*v).compare(d1,2)>=0 && (*v).compare(d2,2)<=0)) flag = false;break;
            }
          }
          if(flag)
          {
            (*v).show();
          }
        }
      }
      else
      {
        if(root->dimention == 1)
        {
          if(d2.x <= root->median.x)
            return rectangleQ(root->less, d1, d2);
          else if(d1.x > root->median.x)
            return rectangleQ(root->more, d1, d2);
          else
          {
            split(root->less, d1, d2);
            split(root->more, d1, d2);
          }
        }
        else if(root->dimention == 2)
        {
          if(d2.y <= root->median.y)
            return rectangleQ(root->less, d1, d2);
          else if(d1.y > root->median.y)
            return rectangleQ(root->more, d1, d2);
          else
          {
            split(root->less, d1, d2);
            split(root->more, d1, d2);
          }
        }
        else if(root->dimention == 3)
        {
          if(d2.z <= root->median.z)
            return rectangleQ(root->less, d1, d2);
          else if(d1.z > root->median.z)
            return rectangleQ(root->more, d1, d2);
          else
          {
            split(root->less, d1, d2);
            split(root->more, d1, d2);
          }
        }
      }
    }
  }*/

public:
  // Constructor
	KDTree(int d, vector<DataPoint> arr)
	{
		dimLim = d;
		root = NULL;

		root = buildTree(arr, 1);
		if(DEBUG)
			if(root != NULL)
				cout<<"Tree Built."<<endl;
			else
				cout<<"Error."<<endl;
	}
  // Destructor
	~KDTree()
	{
		destroyTree(root);
	}
  // Function to build a tree given the data.
	Node* buildTree(vector<DataPoint> arr, int curDim)
	{
    // Sort the given data points provided according to the current
    // dimention.
		if(curDim == 1)
			sort(arr.begin(), arr.end(), comp1);
		else
			sort(arr.begin(), arr.end(), comp2);

    // Create a new node to represent this point in tree
    // with initial initializations.
		Node *root = new Node();
		root->dimention = curDim;
		root->data = arr;
    root->leaf = false;
		root->less = root->more = NULL;

    // Handle special cases of one or two element arrays.
		if(arr.size() == 1)
    {
			root->median = arr[0];
      root->leaf = true;
    }
		else if(arr.size() == 2)
		{
			root->median = arr[1];
      root->leaf = true;
		}
		else
		{
			int splitAt = arr.size()/2;
			root->median = arr[splitAt];
			curDim = (curDim + 1) % dimLim + 1;

			vector<DataPoint> lesserSubset(arr.begin(), arr.begin()+splitAt+1);
			root->less = buildTree(lesserSubset, curDim);
			vector<DataPoint> higherSubset(arr.begin()+splitAt+1,arr.end());
			root->more = buildTree(higherSubset, curDim);
		}
		return root;
	}
  // Function to destroy the tree and free memory.
	void destroyTree(Node *root)
	{
		if(DEBUG)
			cout<<"Destroying..."<<endl;
		if(root->less != NULL)
			destroyTree(root->less);
		if(root->more != NULL)
			destroyTree(root->more);
		free(root);
	}
  // Public handle to display
	void display()
	{
		disp(root);
	}
  // Puclic handle to existance check
	bool doesExists(DataPoint d)
	{
		return exists(root, d);
	}
  // Public handle to rectangle query.
  /*void reportRectangle(DataPoint d1, DataPoint d2)
  {
    rectangleQ(root, d1, d2);
  }*/
};

int main()
{
	int dim;
	if(DEBUG)
		cout<<"Input Dimentions : ";
	cin>>dim;
	int points;
	if(DEBUG)
		cout<<"Input no of points :";
	cin>>points;
	vector<DataPoint> arr;
	REP(i, points)
	{
		DataPoint d;
		d.dim = dim;
		if(dim == 1)
			cin>>d.x;
		else if(dim == 2)
			cin>>d.x>>d.y;
		arr.push_back(d);
	}
	
	KDTree k(dim, arr);
	//k.display();
	//Existence check
	DataPoint chk;
  chk.dim = 2;
  cin>>chk.x>>chk.y;
  cout<<k.doesExists(chk);
  cin>>chk.x>>chk.y;
  cout<<k.doesExists(chk);
	return 0;
}
