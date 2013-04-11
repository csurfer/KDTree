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
	vector<double> co_ord;

	void show()
	{
		cout<<"(";
		REP(i,co_ord.size())
		{
			cout<<co_ord[i]<<",";
		}
		cout<<")";
	}
};

class Node{
public:
	//Dimention in which it divides the available data points
	int dimention;
	//Available DaraPoints at this node
	vector<DataPoint> data;
	//Median of split
	DataPoint median;
	//The pointers which lead to trees which hold less than or = median and greater
	//than median data points
	struct Node *less, *more;
};

/*class KDTree{
public:
	int dimLim;
	Node *root;
	int curDim;

	KDTree(int d, vector<DataPoint> arr)
	{
		dimLim = d;
		root = NULL;
		curDim = 0;

		if(buildTree(root, arr))
			cout<<"Tree successfully built."<<endl;
		else
		{
			cout<<"Flawed data."<<endl;
			destroyTree(root);
		}
	}

	~KDTree()
	{
		destroyTree(root);
	}

	bool comp(DataPoint a, DataPoint b)
	{
		if(a.co_ord[curDim]<=b.co_ord[curDim])
			return true;
		else
			return false;
	}

	bool buildTree(Node *root, vector<DataPoint> arr)
	{
		sort(arr.begin(), arr.end(), comp);
		root = new Node();
		root->dimention = curDim;
		root->data(arr.begin(),arr.end());
		root->less = root->more = NULL;
		if(arr.size() == 1)
		{
			root->median = arr[0];
			return true;
		}
		else if(arr.size() == 2)
		{
			root->median = arr[1];
			return true;
		}
		else
		{
			int splitAt = arr.size()/2;
			root->median = arr[splitAt];
			curDim = (curDim + 1) % dimLim;
			bool buildLess = buildTree(root->less, new vector<DataPoint>(arr.begin(), arr.begin()+splitAt+1));
			bool buildMore = buildTree(root->more, new vector<DataPoint>(arr.begin()+splitAt+1,arr.end()));
			if(buildLess && buildMore)
				return true;
			else
				return false;
		}
	}

	void destroyTree(Node *root)
	{
		if(root->less != NULL)
			destroyTree(root->less);
		if(root->more != NULL)
			destroyTree(root->more);
		free(root);
	}

	void display(Node* root)
	{
		if(root != NULL)
		{
			cout<<endl<<"Current Array"<<endl;
			foreach(it, root->data)
			{
				(*it).show();
			}
			cout<<endl<<"Current Median : "<<root->median.show()<<endl;

			cout<<endl<<"Less Children"<<endl;
			display(root->less);
			cout<<endl<<"More Children"<<endl;
			display(root->more);
		}
	}
};*/

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
		REP(j, dim)
		{
			double coord;
			cin>>coord;
			d.co_ord.push_back(coord);
		}
		arr.push_back(d);
	}
	
	//KDTree k(dim, arr);
	//k.display(k.root);
	return 0;
}

