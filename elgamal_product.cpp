//48112959837082048697
//54673257461630679457
#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;
using namespace std;

cpp_int modpower(cpp_int x, cpp_int n, cpp_int mod)
{
    cpp_int result = 1;
    x = x % mod;
    while (n > 0)
    {
        if (n & 1)
            result = (result * x) % mod;
        x = (x * x) % mod;
        n = n >> 1;
    }
    return result;
}

int main()
{
    cpp_int p("54673257461630679457");//20digits

    cpp_int r1=28, r2= 29, x=50, g=2;
    cpp_int y;
    cpp_int m1, m2;

    cout<<"Enter the two messages: ";
    cin>>m1>>m2;

    //cpp_int m = m1*m2;
    //cout<<m<<endl;
    y = modpower(g, x, p);
    cout<<"Public key: "<<y<<endl<<endl;


    //encryption
    cpp_int c11 = modpower(g, r1, p);
    cpp_int c12 = m1 * modpower(y, r1, p);

    cout<<"Cipher text for message1(c11, c12): "<<c11<<" "<<c12<<endl<<endl;

    cpp_int msg1 = c12/modpower(c11, x, p);
    cout<<"Decrypted message 1: "<<msg1<<endl<<endl;

    cpp_int c112 = modpower(g, r2, p);
    cpp_int c22 = m2 * modpower(y, r2, p);

    cout<<"Cipher text for message2(c12, c22): "<<c112<<" "<<c22<<endl<<endl;

    cpp_int msg2 = c22/modpower(c112, x, p);
    cout<<"Decrypted message 2: "<<msg2<<endl;

    //product ciphers
    cpp_int c1 = modpower(g, (r1+r2), p);
    cpp_int c2 = m1*m2 * modpower(y, (r1+r2), p);

    cout<<endl;

    //decrytion
    cpp_int m1m2 = c2/modpower(c1, x, p);//m1*m2=c2/c1^x
    cout<<"Decrypted message (m1*m2): "<<m1m2<<endl;
    cpp_int m = msg1*msg2;
    cout<<"Original message (m1*m2): "<<m<<endl;

    if((msg1*msg2)==m1m2)
        cout<<"Decrypted message is matched with original message.."<<endl;
    else
        cout<<"Message didn't match.."<<endl;

}


















