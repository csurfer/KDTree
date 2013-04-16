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

class DataPoint{
public:
	//Which dimentional point does this object represent?
	int dim;
	//The points are stored in the following vector.
	double x,y,z;
	//A display function to show the co-ordinate values.
	void show()
	{
		if(dim == 1)
			cout<<"x : "<<x<<endl;
		else if(dim == 2)
			cout<<"x : "<<x<<" y : "<<y<<endl;
		else
			cout<<"x : "<<x<<" y : "<<y<<" z : "<<z<<endl;
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
	//The pointers which lead to trees which hold less than or = median and greater
	//than median data points
	struct Node *less, *more;
};

bool comp1(DataPoint a, DataPoint b)
{
	if(a.x <= b.x)
		return true;
	else
		return false;
}

bool comp2(DataPoint a, DataPoint b)
{
	if(a.y <= b.y)
		return true;
	else
		return false;
}

bool comp3(DataPoint a, DataPoint b)
{
	if(a.z<=b.z)
		return true;
	else
		return false;
}

class KDTree{
public:
	int dimLim;
	Node* root;
	int curDim;

	KDTree(int d, vector<DataPoint> arr)
	{
		dimLim = d;
		root = NULL;
		curDim = 0;

		root = buildTree(arr);
	}

	~KDTree()
	{
		destroyTree(root);
	}

	Node* buildTree(vector<DataPoint> arr)
	{
		if(curDim == 0)
			sort(arr.begin(), arr.end(), comp1);
		else if(curDim == 1)
			sort(arr.begin(), arr.end(), comp2);
		else
			sort(arr.begin(), arr.end(), comp3);
		Node *root = new Node();
		root->dimention = curDim;
		root->data = arr;
		root->less = root->more = NULL;
		if(arr.size() == 1)
		{
			root->median = arr[0];
		}
		else if(arr.size() == 2)
		{
			root->median = arr[1];
		}
		else
		{
			int splitAt = arr.size()/2;
			root->median = arr[splitAt];
			curDim = (curDim + 1) % dimLim;
			vector<DataPoint> lesserSubset(arr.begin(), arr.begin()+splitAt+1);
			root->less = buildTree(lesserSubset);
			vector<DataPoint> higherSubset(arr.begin()+splitAt+1,arr.end());
			root->more = buildTree(higherSubset);
		}
		return root;
	}

	void destroyTree(Node *root)
	{
		if(root->less != NULL)
			destroyTree(root->less);
		if(root->more != NULL)
			destroyTree(root->more);
		free(root);
	}
};

void display(Node* root)
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

		cout<<endl<<"Less Children"<<endl;
		display(root->less);
		cout<<endl<<"More Children"<<endl;
		display(root->more);
	}
}

int main()
{
	int dim;
	cout<<"Input Dimentions : ";
	cin>>dim;
	int points;
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
		else
			cin>>d.x>>d.y>>d.z;
		arr.push_back(d);
	}
	
	KDTree k(dim, arr);
	display(k.root);
	return 0;
}