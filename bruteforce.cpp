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
  double compare(DataPoint d, int dim)
  {
    switch(dim)
    {
      case 1: return (x-d.x); break;
      case 2: return (y-d.y); break;
      default: return 0; break;
    }
  }
  // A distance function
  double l2dist(DataPoint d)
  {
    switch(dim)
    {
      case 1: return (x-d.x)*(x-d.x); break;
      case 2: return (x-d.x)*(x-d.x)+(y-d.y)*(y-d.y); break;
      default: cout<<"Error"; return -1; break;
    }
  }
};


// Puclic handle to existance check
bool doesExists(vector<DataPoint> arr, DataPoint d)
{
	bool exists = false;
  foreach(v, arr)
  {
    if((*v).equals(d))
    {
      exists = true;
      break;
    }
  }
  return exists;
}

// Public handle to rectangle count.
void countRectangle(vector<DataPoint> arr, DataPoint d1, DataPoint d2)
{
  vector<DataPoint> result;
  foreach(v, arr)
  {
    if((*v).x >= d1.x && (*v).y >= d1.y && (*v).x <= d2.x && (*v).y <= d2.y)
    {
      result.push_back(*v);
    }
  }
  cout<<result.size()<<" points lie in this rectangle."<<endl<<endl;  
}
// Public handle to rectangle query.
void reportRectangle(vector<DataPoint> arr, DataPoint d1, DataPoint d2)
{
  vector<DataPoint> result;
  foreach(v, arr)
  {
    if((*v).x >= d1.x && (*v).y >= d1.y && (*v).x <= d2.x && (*v).y <= d2.y)
    {
      result.push_back(*v);
    }
  }
  if(result.size() == 0)
    cout<<"No such points exist."<<endl;
  else
  {
    cout<<"Reported points are : "<<endl;
    foreach(v, result)
    {
      (*v).show();
    }
   cout<<"End of Report..."<<endl<<endl;
  } 
}
// Public handle to circle count.
void countCircle(vector<DataPoint> arr, DataPoint d, double radius)
{
  vector<DataPoint> result;
  foreach(v, arr)
  {
    if((*v).l2dist(d) <= radius*radius)
      result.push_back(*v);      
  }
  cout<<result.size()<<" points lie in this circle."<<endl<<endl;  
}
// Public handle to circle query.
void reportCircle(vector<DataPoint> arr, DataPoint d, double radius)
{
  vector<DataPoint> result;
  foreach(v, arr)
  {
    if((*v).l2dist(d) <= radius*radius)
      result.push_back(*v);      
  }
  if(result.size() == 0)
    cout<<"No such points exist."<<endl;
  else
  {
    cout<<"Reported points are : "<<endl;
    foreach(v, result)
    {
      (*v).show();
    }
   cout<<"End of Report..."<<endl<<endl;
  } 
}

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
	
	//Existence check
	/*REP(i,points/5)
  {
    DataPoint chk;
    cin>>chk.dim>>chk.x>>chk.y;
    chk.show();
    cout<<doesExists(arr, chk)<<endl;
  }*/
  //Rectangele Q
  /*REP(i,points/5)
  {
    DataPoint d1, d2;
    cin>>d1.dim>>d1.x>>d1.y>>d2.dim>>d2.x>>d2.y;
    d1.show();
    d2.show();
    //reportRectangle(arr,d1,d2);
    countRectangle(arr,d1,d2);
  }*/
  //Circle Q
  REP(i,points/5)
  {
    DataPoint chk;
    double radius;
    cin>>chk.dim>>chk.x>>chk.y>>radius;
    chk.show();
    reportCircle(arr, chk, radius);
    //countCircle(arr, chk, radius);
  }
	return 0;
}
