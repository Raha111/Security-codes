#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using namespace boost::multiprecision;
using namespace std;

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

cpp_int gcd(cpp_int a, cpp_int b) {
    while (b != 0) {
        cpp_int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

cpp_int generate_e(cpp_int phi_n) {
    cpp_int e = 3;
    while (e < phi_n) {
        if (gcd(e, phi_n) == 1) {
            return e;
        }
        e+=2;
    }
    return 0;
}


cpp_int modInverse(cpp_int a, cpp_int m){

    cpp_int m0 =m, t,q;
    cpp_int x0 = 0, x1 = 1;

    if(m==1){
        return 0;
    }

    while(a>1){
        q = a/m;
        t = m;
        m = a%m, a = t;
        t = x0;
        x0=x1-q*x0;
        x1 = t;
    }
    if(x1<0){
        x1 += m0;
    }

    return x1;

}

int main()
{
    cpp_int c, p, q, n, phi, msg1, msg2, m1, m2, m;

    cout << "Enter the value for p: ";
    cin >> p;
    cout << "Enter the value for q: ";
    cin >> q;
    cout << "Enter the message: ";
    cin >> msg1;
    cout << "Enter the message: ";
    cin >> msg2;

    n = p*q;

    phi = (p - 1) * (q - 1);

    cpp_int e = generate_e(phi);

    cout << "Message: " << msg1 << endl;
    cpp_int c1 = power(msg1, e, n);
    cout << "Cipher c1: " << c1 << endl;

    cout << "Message: " << msg2 << endl;
    cpp_int c2 = power(msg2, e, n);
    cout << "Cipher c2: " << c2 << endl;

    cpp_int mainmsg = msg1 * msg2;

    c = power(mainmsg,e ,n);
    cout<< "Cipher c: " << c << endl;

    cpp_int d = modInverse(e,phi);

    cout<< "Decryption_key: "<< d <<endl;


    m1 = power(c1,d,n);
    cout<<endl<< "Decrypt Message1: " << m1 << endl;

    m2 = power(c2,d,n);
    cout << "Decrypt Message2: " << m2 << endl;

    m = c1 * c2;
    cout<<c<<" " <<m<<endl;

    if ((m1*m2)==mainmsg){
        cout<<"Decryption successful"<<endl;
    }
    return 0;

}

/*

c1 = m1^e mod n
c2 = m2^e mod n

c = c1*c2 = (m1*m2)^e mod n

m1 = c1^d mod n
m2 = c2^d mod n

m1m2 = c^d mod n





22537211232223552133332272923531222223112175722333721931322254123743221133522347
11698896101111181609619689808818888906916986100111111691188119616009611966996889

*/
