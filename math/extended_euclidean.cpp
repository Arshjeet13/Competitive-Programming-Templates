#include <bits/stdc++.h>
using namespace std;

// This algorithm aims to find 
// an integer pair {x,y} which is a solution to ax + by = c
// A solution exists iff gcd(a,b) | c
// This makes use of the intermediate values created during 
// the computation of the euclidean algorithm 

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
