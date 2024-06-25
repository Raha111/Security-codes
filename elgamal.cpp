#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
#include <boost/random.hpp>

using namespace std;
using namespace boost::multiprecision;


cpp_int power(cpp_int b, cpp_int p, cpp_int mod)
{
    b = b % mod;
    if(p == 0)
        return 1;
    cpp_int j = power(b, p / 2, mod);
    j = (j * j) % mod;
    if(p % 2 == 1)
        j = (j * b) % mod;
    return j;
}

cpp_int modInverse(cpp_int A, cpp_int M)
{
    cpp_int m0 = M;
    cpp_int y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1) {
        cpp_int q = A / M;
        cpp_int t = M;

        M = A % M, A = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}

cpp_int generate_random(const cpp_int& q)
{
    return cpp_int(rand()) % q;
}

int main(){
    cpp_int g,a,c1,c2,dec,m,r,beta;
    cpp_int p("212559481678916012965440078089");
    a = generate_random(p-1);
    m = 1289091;
    r = generate_random(p-1);
    g = 2;

    beta = power(g,a,p);

    c1 = power(g,r,p);
    c2 = (m%p) * power(beta,r,p);

    cpp_int mi,t1 = power(c1,a,p);
    mi = modInverse(t1,p);
    dec = (c2*mi) % p;

    cout<<dec<<endl;

}
