int gcd(int a, int b){
    if(!a)  return b;
    return gcd(b%a,a);
}
