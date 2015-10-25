/*
author d_knight

Hackerrank

Problem Statement

You are given a triangle where the vertices are A(x1,y1),B(x2,y2) and C(x3,y3). All three vertices have integral coordinates. An integral point is defined as the point with both X and Y coordinates as integers. Cay you find the number of integral points inside the triangle using Pick's theorem?

Input Format

The first line of input contains T i.e. number of test cases.
The next T lines will contain 6 integers x1,y1,x2,y2,x3,y3.

Constraints
1?T?100
0?x1,y1,x2,y2,x3,y3?109

Output Format

Print T lines each containing the number of integral points in that triangle.

Sample Input

2
0 0 0 2 2 0
0 0 3 0 0 3

Sample Output

0
1

Explanation

In the second test case, (1,1) is the only integral point inside the triangle.


*/















#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long points_in_lines(long long x1,long long y1,long long x2,long long y2){
    
    if(x1>x2){
        swap(x1,x2);
        swap(y1,y2);
    }
    x2=x2-x1;
    y2=y2-y1;
    x1=y1=0;
    
    if(x1==x2){
        return abs(y2)+1;
    }
    if(y1==y2){
        return abs(x2)+1;
    }
    long long gcd=__gcd(abs(x2),abs(y2));
    
    long long q=y2/gcd;
    long long r=x2/gcd;
    return abs(x2/r)+1;
    
}

int main() {
    int t;
    cin>>t;
    while(t--){
        long long  x1,x2,x3;
        long long y1,y2,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        long long  area = x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2);
        if(area<0)
            area*=-1;
        
        area+=2;
        
        long long h1=points_in_lines(x1,y1, x2,y2);
        long long h2=points_in_lines(x2,y2, x3,y3);
        long long h3=points_in_lines(x3,y3, x1,y1);
        //cout<<area<< " "<<h1<<" "<<h2<<" "<<h3<<endl;
        int ii=abs(h1)+abs(h2)+abs(h3)-3;
        
        area-=ii;
        cout<<(area>>1)<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
