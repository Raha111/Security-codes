#include<boost/multiprecision/cpp_int.hpp>
#include<iostream>

using namespace boost::multiprecision;
using namespace std;

cpp_int gcd(cpp_int a, cpp_int b){

    while(b!=0){
        cpp_int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

cpp_int power( cpp_int b, cpp_int p, cpp_int mod )
{
    b = b % mod;
    if(p==0) return 1;

    cpp_int j = power(b,p/2, mod);

    j = (j*j) % mod;

    if(p%2==1){
        j= j*b % mod;
    }
    return j;

}

cpp_int modInverse(cpp_int a, cpp_int m)
{
    cpp_int m0 = m,q,t;
    cpp_int x0 = 0, x1 = 1;

    if(m==1) return 0;

    while(a>1){
        q = a/m;
        t = a%m;
        a = m;
        m = t;

        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if(x1<0){
        x1+=m0;
    }
    return x1;
}

cpp_int generate_e(cpp_int phi)
{
    cpp_int e = 3;
    while(e < phi){
        if(gcd(e,phi) == 1){
            return e;
        }
        e+=2;
    }
    return 0;
}

int main()
{
    cpp_int p,q,msg;
    cout << "Enter prime number p: ";
    cin >> p;
    cout << "Enter prime number q: ";
    cin >> q;
    cout << "Enter message (as a number): ";
    cin >> msg;

    cpp_int n = p*q;
    cpp_int phi = (p-1) * (q-1);

    cpp_int e = generate_e(phi);

    cpp_int d = modInverse(e,phi);

    cpp_int cipher = power(msg, e, n);
    cout << "Encrypted message (cipher): " << cipher << endl;

    cpp_int decrypted = power(cipher, d, n);
    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}


/*
22537211232223552133332272923531222223112175722333721931322254123743221133522347
11698896101111181609619689808818888906916986100111111691188119616009611966996889
*/
