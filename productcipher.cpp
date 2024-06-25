#include <boost/multiprecision/cpp_int.hpp>
#include <bits/stdc++.h>

using namespace boost::multiprecision;
using namespace std;

cpp_int gcd(cpp_int a, cpp_int b)
{
    cpp_int result = min(a, b);
    while (result > 0)
    {
        if (a % result == 0 && b % result == 0)
        {
            break;
        }
        result--;
    }
    return result;
}

cpp_int power(cpp_int x, cpp_int n, cpp_int mod)
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


/*
35201546659608842026088328007565866231962578784643756647773109869245232364730066609837018108561065242031153677
10513733234846849736873637829838635104309714688896631127438692162131857778044158273164093838937083421380041997
*/
int main()
{
    cpp_int p, q, m1, m2, e=5;
    cout << "Enter the original two msg: ";
    cin >> m1 >> m2;
    cout << "Enter the value of p and q (prime): ";
    cin >> p >> q;
    cpp_int n = p * q;
    cpp_int phi_n = (p - 1) * (q - 1);

    while (e < phi_n)
    {
        if (gcd(e,phi_n) == 1)
            break;
        else
            e++;
    }

    cpp_int k = 1;
    while (1)
    {
        if ((1+k*phi_n) % e == 0)
            break;
        else
        k++;
    }

    cpp_int d = (1 + (k*phi_n)) / e;

   // cout<<"Original message: "<<m<<endl;

    cpp_int c1 = power(m1, e, n);
    cout<<"encrypted message1: "<<c1<<endl;

     cpp_int c2 = power(m2, e, n);

     cout<<"encrypted message2: "<<c2<<endl;

      cpp_int mainmsg = m1*m2;
     cpp_int c = power(mainmsg, e, n);//concatenation

     cpp_int mm1 = power(c1, d, n);
     cpp_int mm2 = power(c2, d, n);


     cout<<endl;
     cout<<"decrypted message1: "<<mm1<<endl;
     cout<<"decrypted message2: "<<mm2<<endl;
     //cout<<mm1<<mm2;
     cpp_int m1m2 = power(c, d, n);
     cpp_int cc = c1*c2;
     cpp_int mm12 = power(cc, d, n);

    // int mainmsg = m1*m2;
    //cout<<mm12<<" "<<m1m2;
     if((mm1*mm2)==(mainmsg))
        cout<<"Successfully decrypted.."<<endl;





    return 0;
}



