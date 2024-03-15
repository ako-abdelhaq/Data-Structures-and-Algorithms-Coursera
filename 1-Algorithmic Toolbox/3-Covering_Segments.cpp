#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Point{
    int x;
    int y;
    Point(){
        x=0;y=0;
    }
    Point(int x_ , int y_){
        x = x_;
        y = y_;
    }
    
};

struct comp{
    bool operator() (Point p1 , Point p2){
        return p1.y<p2.y;
    }
}comp;

int main()
{
   int n;
   cin>>n;
   vector<Point> Points(n);
   Point p;
   for(int i = 0 ; i < n ; i++){
       cin>>Points[i].x>>Points[i].y;
   }
   sort(Points.begin(),Points.end(),comp);
   vector<int> points;
   int i = 1 , point = Points[0].y;
   points.push_back(point);
   while( i < n){
       if(point <= Points[i].y && point >= Points[i].x){
           i++;
       }
       else{
           point = Points[i].y;
           points.push_back(point);
           i++;
       }
   }
   points.shrink_to_fit();
   cout<<points.size()<<endl;
   for(int point : points){
       cout<<point<<" ";
   }
   cout<<endl;
   return 0;
}