#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//ascending order declaration
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
//ascending order + multiset declaration
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

//descending order declaration
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
//descending order + multiset declaration
typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
    //declaration
    indexed_set st;

    //inserting elements
    st.insert(5);
    st.insert(6);
    st.insert(7);
    st.insert(8);

    //finding kth element, (0 based indexing)
    cout<<"first element : "<<*st.find_by_order(0)<<"\n";
    cout<<"second element : "<<*st.find_by_order(1)<<"\n";
    cout<<"third element : "<<*st.find_by_order(2)<<"\n";
    cout<<"fourth element : "<<*st.find_by_order(3)<<"\n";
    // cout<<"kth element : "<<*st.find_by_order(k-1)<<"\n";

    //finding number of elements strictly smaller than x
    cout<<"no. of elements smaller than 5"<<st.order_of_key(5); //outputs 0
    cout<<"no. of elements smaller than 6"<<st.order_of_key(6); //outputs 1
    cout<<"no. of elements smaller than 9"<<st.order_of_key(9); //outputs 4

    //erasing elements
    st.erase(6);
    st.erase(8);
    st.erase(5);
    st.erase(7);
}
