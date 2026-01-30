/*
This program can multiply 1 large number, beyond the limits of long long data type, 
with a 1 digit number, by converting the first one to a string and performing 
multiplication digit by digit, similar to how we do it manually on paper.
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