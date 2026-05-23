#include <bits/stdc++.h>
using namespace std;

// This algorithm aims to find 
// an integer pair {x,y} which is a solution to ax + by = g, where g = gcd(a,b)
// This makes use of the intermediate values created during the computation of the euclidean algorithm
// This can be generalized to find {x,y} for ax + by = c
// Note that a solution exists iff  gcd(a,b) | c
// Moreover if there exists a solution, then there exist infinitely many solutions

vector<int> extended_euclidean(int a, int b){

    if(b == 0){
        return {1, 0};
    }

    auto v = extended_euclidean(b, a%b);
    int x1 = v[0], y1 = v[1];

    int x = y1;
    int y = x1 - y1 * (a/b);

    return {x,y};    
    
}
