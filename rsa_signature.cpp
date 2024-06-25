#include<boost/multiprecision/cpp_int.hpp>
#include<iostream>

using namespace std;
using namespace boost::multiprecision;

cpp_int gcd(cpp_int a, cpp_int b)
{
    while(b!=0){
        cpp_int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

cpp_int power(cpp_int b, cpp_int p, cpp_int mod)
{
    b = b%mod;
    if(p==0) return 1;

    cpp_int j = power(b,p/2,mod);

    j = (j*j) % mod;

    if(p%2==1){
        j = (j*b) % mod;
    }

    return j;
}

cpp_int modInverse(cpp_int a, cpp_int m)
{
    cpp_int m0 = m,q,t;
    cpp_int x0 = 0, x1 = 1;

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
    while(e<phi){
        if(gcd(e,phi)==1){
            return e;
        }
        e+=2;
    }
    return 0;
}


int main()
{
    cpp_int p = 61;
    cpp_int q = 53;
    cpp_int n = p*q;
    cpp_int phi = (p-1)*(q-1);

    cpp_int e = generate_e(phi);
    cpp_int d = modInverse(e,phi);

    cout << "Public key (n, e): (" << n << ", " << e << ")\n";
    cout << "Private key (d): " << d << endl;

    cpp_int message = 42;
    cout << "Original Message: " << message << endl;

    cpp_int sign = power(message,d,n);
    cout << "Signature: " << sign << endl;

    cpp_int verification = power(sign,e,n);
    cout<<"Decrypted message: "<<verification<<endl;

    if (verification == message) {
        cout << "Signature verified successfully!" << endl;
    } else {
        cout << "Signature verification failed!" << endl;
    }

    return 0;


}


