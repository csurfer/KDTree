/* 
 * Author : Vishwas B Sharma
 * File   : kdtree.cpp
 */
#include<vector>
#include<iostream>
#include<algorithm>

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

class KDTree{
private:
	int dimLim;
	Node *root;
	int curDim;

public:
	KDTree(int d, vector<DataPoint> arr)
	{
		dimLim = d;
		root = NULL;
		curDim = 0;

		if(buildTree(root, arr))
			cout<<"Tree successfully built."<<endl;
		else
			cout<<"Flawed data."<<endl;
	}

	bool compare(DataPoint a, DataPoint b)
	{
		if(a[curDim]<=b[curDim])
			return true;
		else
			return false;
	}

	bool buildTree(Node *root, vector<DataPoint> arr)
	{
		root = new Node();
		root->dimention = curDim;
		sort(arr.begin(), arr.end(), compare);
		root->data(arr.begin(), arr.end());
		int splitInd = arr.size()/2;
		root->median = arr[splitInd];
		if(buildTree() && buildTree())
	}
};

int main()
{
	return 0;
}

