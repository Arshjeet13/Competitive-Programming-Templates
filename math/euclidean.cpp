// Note that this is the same algorithm used by std::gcd
// So, as is this isn't very useful
// However, the idea behind the euclidean algorithm is a core
// part of the extended euclidean algorithm
int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}

