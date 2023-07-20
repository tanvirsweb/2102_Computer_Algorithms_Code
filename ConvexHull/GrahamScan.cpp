#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int cnt=0;

struct Point
{
	int x;
    int y;
};

// A global point needed for sorting points with reference
// to the first point Used in compare function of qsort()
Point p0;
Point cp[1000];//convex hull lines points
Point points[1000];
int pnt_no;

Point nextToTop(stack<Point> &S)
{
    //remove top element
    cnt=cnt+5;
	Point presentTop = S.top();
	S.pop();
	Point nextTop = S.top();
    //store next top element

    //push previous top element in top again
	S.push(presentTop);
	return nextTop;
}
//-----------------------------------------------------------
//swap two user defined datatype : points
void swap(Point &point1, Point &point2)
{
    cnt=cnt+3;
	Point temp = point1;
	point1 = point2;
	point2 = temp;
}


int distSq(Point p1, Point p2)
{// A utility function to return square of distance between p1 and p2
    cnt++;
	return (p1.x - p2.x)*(p1.x - p2.x) +
		(p1.y - p2.y)*(p1.y - p2.y);
}

//--------------------------------------------------------------
int orientation(Point p, Point q, Point r)
{
    cnt=cnt+2;
	int val = (q.y - p.y) * (r.x - q.x) -
			(q.x - p.x) * (r.y - q.y);
    // To find orientation of ordered triplet (p, q, r).
	if (val == 0) return 0; // collinear those 3 points are in same line
    else if(val>0) return 1;//clockwise
    else return 2;//counter clockwise
}

// A function used by library function qsort() to sort an array of
// points with respect to the first point
int comparatorFunction(const void *vp1, const void *vp2)
{
    cnt=cnt+3;
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;

    // Find orientation
    int o = orientation(p0, *p1, *p2);
    cnt++;
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;
    //if p0,p1 & p3 are in same line
    //if p0-p2 distance > p0-p1 : return -1
    //else return 1;
    cnt++;
    return (o == 2)? -1: 1;
    //if p0 p1 p2 -->counter clock wise return -1
    //if clockwise return 1;
}

// Prints convex hull of a set of n points.
void convexHull(Point points[], int n)
{
    // Find the bottommost point
    //Let 1st point in array of points is the bottomost point
    cnt++;
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        cnt=cnt+2;
        int y = points[i].y;

        // Pick the bottom-most or choose the left
        // most point in case of tie
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }

    cnt=cnt+4;
    // Place the bottom-most point at first position
    swap(points[0], points[min]);

    // Sort n-1 points with respect to the first point.
    // A point p1 comes before p2 in sorted output if p2
    // has larger polar angle (in counterclockwise
    // direction) than p1
    p0 = points[0];
    qsort(&points[1], n-1, sizeof(Point),comparatorFunction);

    // If two or more points make same angle with p0,
    // Remove all but the one that is farthest from p0
    //--> keep the farthest point at the end when more than
    // one points have same angle.
    int m = 1; // Initialize size of modified array
    for (int i=1; i<n; i++)
    {
        // Keep removing i while angle of i and i+1 is same
        // with respect to p0
        while (i < n-1 && orientation(p0, points[i], points[i+1]) == 0)
        {
            i++;
            cnt++;
        }

        cnt=cnt+2;
        points[m] = points[i];
        m++; // Update size of modified array
    }

    // If modified array of points has less than 3 points,
    // convex hull is not possible
    cnt++;
    if (m < 3) return;

    // Create an empty stack and push first three points
    // to it.
    cnt=cnt+4;
    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    // Process remaining n-3 points
    for (int i = 3; i < m; i++)
    {
        cnt=cnt+2;;
        // Keep removing top while the angle formed by
        // points next-to-top, top, and points[i] makes
        // a non-left turn
        while (S.size()>1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
        {
            S.pop();
            cnt++;
        }
        S.push(points[i]);
    }

    // Now stack has the output points, print contents of stack
    cnt=cnt+2;
    pnt_no=0;
    cout<<"Border points of Convex Hull(using Grahams Algorithm):"<<endl;
    while (!S.empty())
    {
        cnt=cnt+4;
        //Point cp[]
        cp[pnt_no]= S.top();
        cout << "(" << cp[pnt_no].x << ", " << cp[pnt_no].y <<") ";
        pnt_no++;
        S.pop();
    }
}
//-------------------------------

int main()
{
    ifstream in("convexHullPoints.txt");
	int n =380;
    for(int i=0;i<n;i++)
    {
        in>>points[i].x>>points[i].y;
    }
    in.close();

	convexHull(points, n);
	cout<<"\n For n="<<n<<" step count="<<cnt<<endl;

	/*int gd = DETECT, gm=0;
	// initgraph initializes the graphics system
	// by loading a graphics driver from disk
	initgraph(&gd, &gm, "");

	// line for x1, y1, x2, y2
	//line(150, 150, 450, 150);
	for(int i=0;i<pnt_no;i++)
    {
        if(i==pnt_no-1) line(cp[i].x,cp[i].y,cp[0].x,cp[0].y);
        else line(cp[i].x,cp[i].y,cp[i+1].x,cp[i+1].y);
    }
    getch();

	// closegraph function closes the graphics
	// mode and deallocates all memory allocated
	// by graphics system .

	closegraph();*/

	return 0;
}
