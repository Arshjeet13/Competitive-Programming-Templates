#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define fast() ios::sync_with_stdio(false); cin.tie(NULL)
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

/*
This program can multiply 1 large number, beyond the limits of long long data type, with a number withing C++'s
long long data type range by converting the first one to a string and performing multiplication digit by digit,
similar to how we do it manually on paper.
*/
string mult(string a, int num){

    string output = "";
    int sz = a.size();
    vector<int> carry(sz+10, 0);

    reverse(all(a));

    for(int i=0; i<sz; ++i){
        int dig = a[i] - '0';
        if(dig * num + carry[i] <= 9){
            output += to_string(dig*num + carry[i]);
        }
        else{
            carry[i+1] = (num*dig + carry[i])/10;
            int val = (num*dig + carry[i])%10;
            output += to_string(val);
        }
    }

    if(carry[sz] != 0){
        output += to_string(carry[sz]);
    }

    reverse(all(output));
    return output;

}

/*
This program can add 2 large numbers, beyond the limits of long long data type, 
by converting them to strings and performing addition digit by digit,
similar to how we do it manually on paper.
*/

string adder(string a, string b){

    if(a.size() < b.size()) swap(a,b);
    if(a.size() == b.size() && a<b) swap(a,b);

    reverse(all(a));
    reverse(all(b));
    while(b.size() < a.size()) b += '0';

    int sz = a.size();

    vector<int> carry(sz+10, 0);
    string output = "";

    for(int i=0; i<sz; ++i){
        int dig1 = a[i]-'0';
        int dig2 = b[i]-'0';

        if(dig1 + dig2 + carry[i] <= 9){
            output += to_string(dig1 + dig2 + carry[i]);
        }
        else{
            int val = dig1 + dig2 + carry[i];
            output += to_string(val%10);
            carry[i+1] = 1;
        }
    }

    if(carry[sz] == 1) output += '1';

    reverse(all(output));
    return output;
}

signed main(){
    fast();

    int tc = 1;
    //int tc; cin>>tc;
    while(tc--){

        string ans = "1";

        // EXAMPLE : Calculating 100! and sum of its digits

        for(int i=2; i<=100; ++i){
            int dig1 = (i-i%100)/100;
            int dig2 = (i%100)/10;
            int dig3 = i%10;

            string o1 = mult(ans, dig1);
            string o2 = mult(ans, dig2);
            string o3 = mult(ans, dig3);
            o1 += "00";
            o2 += '0';
            ans = adder(o2, o1);
            ans = adder(ans, o3);           
        }

        int output = 0;
        for(auto c : ans) output += (c - '0');

        cout<<output;    

    }
}