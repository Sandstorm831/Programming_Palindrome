// Question Link - https://www.interviewbit.com/problems/red-zone/
// Solution

// int Solution::solve(vector<vector<int> > &A, int B) {
// }
// Imagine the points as radiating circles, circle radius r is number of days that have passed

// as soon as B circles intersect each other at xth day, that xth day is our answer


// Brute Force - select B points from N points and keep increasing there radius(r), till all B points Eucaldian distance d 

// with one another is less than radius + radius(2*r), repeat this process, answer is minimum number of radius that satisfies this condition

// Time Complexity - choose b from n * choose 2 from B * max(distance between two choosen point/2)

// Which is O(n!*B^2*INT_MAX) in the worst case


// Optimized - Lower bound Binary Search radius r from 1 to INT_MAX, check if r gives sufficiant expansion so that 

// any two points eucaldian distance d <= r+r, if so, let the intersected area be X, check if every other point with a radius

// of r can reach this area X, if yes, increase the count, keep max count for r and if max count of r >= B that means r has

// sufficiant given sufficiant radial expansion

// Time Complexity O(n^3*log(INT_MAX))


// But how to we keep track of this Area X i.e intersection of 2 circles and check if point lies between them ?

// refer to this article: https://stackoverflow.com/questions/3349125/circle-circle-intersection-points#:~:text=The%20following%20note%20describes%20how,P1%20%2D%20P0%7C%7C.

// here a = d/2, so h = r^2 - d^2/4

// Px1 = midx - (y1-y0)h/d  Px2 = midx + (y1-y0)h/d

// Py1 = midy + (x1-x0)h/d  Py2 = midy - (x1-x0)h/d

// whatever be the order of the points, p1 and p2 get switched accordingly

// Eucaldian distance between (P1,Point) <= r for r to reach it, similarly for (P2,Point) <= r,

// if point with r is able to reach P1, count 1 gets increased, if able to reach P2 count 2 gets increased, if able to reach

// both, then both count 1 and count 2 will increase


// function for Eucaldian Distance


double dist(double x1,double x2,double y1,double y2){

    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

}

bool check(int r,vector<vector<int>> &A,int B){

    int maximum_reachable_points=0;

    for(int i = 0;i<A.size();i++){

        for(int j = i+1;j<A.size(); j++){

            double d = dist(A[i][0],A[j][0],A[i][1],A[j][1]);

            if(d <= 2*r){

                // i and j have been seleted, calculating all the points that are able to reach the area of intersection of 

                // circle i and circle j with help of circle of radius r using maths

                

                double midx = (double)(A[i][0] + A[j][0]) * (1.0/2);

                double midy = (double)(A[i][1] + A[j][1]) * (1.0/2);

                double h = sqrt(r*1.0*r - d*d/4);

                double Px1 = midx - (double)(A[i][1]-A[j][1])*(h/d);

                double Px2 = midx + (double)(A[i][1]-A[j][1])*(h/d);

                double Py1 = midy + (double)(A[i][0]-A[j][0])*(h/d);

                double Py2 = midy - (double)(A[i][0]-A[j][0])*(h/d);
                
                int count_px1 = 2, count_px2 = 2;

                for(int k = 0; k < A.size(); k++){

                    if(k == i || k == j){

                        continue;

                    } 

                    if(dist(Px1,A[k][0],Py1,A[k][1]) <= r){

                        ++count_px1;

                    }

                    if(dist(Px2,A[k][0],Py2,A[k][1]) <= r){

                        ++count_px2;

                    }

                }

                maximum_reachable_points=max(maximum_reachable_points,max(count_px1,count_px2));    

            }

        }

    }

    return (maximum_reachable_points>=B);
}


int Solution::solve(vector<vector<int>> &A, int B) {

    // doing a lower bound binaray search on number of days x

    int ans;

    int l = 1, r = INT_MAX;

    while(r >= l){

        int m = (l+r)/2;

        if(check(m,A,B)){

            ans = m;

            // cout << ans << " ";

            r = m-1;

        }

        else l = m+1;

    }

    return ans;

}

/////////

long double dist(pair<long double,long double>a, pair<long double,long double>b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
bool check(vector<pair<long double,long double>>A, int B,long double d){
    d*=d;
    for(int i=0;i<A.size();i++){
        for(int j=i+1;j<A.size();j++){
           // pair<long double,long double> A[i] = A[i], A[j] = A[j];
            long double h = dist(A[i],A[j]);
            long double D = (4*d-h)/h;
            if(4*d-h>=0.0){
                int cn1=0,cn2=0;
                pair<long double,long double>x,y;
                x.first = ((A[i].first+A[j].first)+sqrt(D)*(A[i].second-A[j].second))/2;
                x.second = ((A[i].second+A[j].second)+sqrt(D)*(A[j].first-A[i].first))/2;
                y.first = ((A[i].first+A[j].first)-sqrt(D)*(A[i].second-A[j].second))/2;
                y.second = ((A[i].second+A[j].second)-sqrt(D)*(A[j].first-A[i].first))/2;
                for(int k=0;k<A.size();k++){
                    if(dist(x,A[k])<=d+0.1)cn1++;
                    if(dist(y,A[k])<=d+0.1)cn2++;
                }
                if(cn1>=B){
                    return true;
                }
                if(cn2>=B){
                    return true;
                }
            }
        }
    }
    return false;
}
int Solution::solve(vector<vector<int> > &A, int B) {
    vector<pair<long double,long double>>C;
    int r = 0, l=0;
    for(int i=0;i<A.size();i++){
        long double xcoor=A[i][0]*(1.0);
        long double ycoor=A[i][1]*(1.0);
        r=max({r,A[i][0],A[i][1]});
        C.push_back({xcoor,ycoor});
    }
    while(l<=r){
        int mid = l + (r-l)/2;
        if(check(C,B,mid))
            r = mid-1;
        else l = mid+1;
    }
    return l;
}

