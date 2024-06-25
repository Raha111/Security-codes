#include<bits/stdc++.h>
using namespace std;

//int modpow(int base, int exp, int mod)
//{
//    base %= mod;
//    int result = 1;
//
//    while(exp>0)
//    {
//        if(exp&1)
//        {
//            result=(result*base)%mod;
//        }
//        base=(base*base)%mod;
//        exp >>= 1;
//    }
//
//    return result;
//}


int power(int b, int p, int mod)
{
    b = b% mod;
    if(p==0) return 1;
    int j = power(b,p/2,mod);
    j = (j*j) % mod;
    if(p%2==1){
        j = (j*b) % mod;
    }
    return j;
}


int main()
{
    int p,pm;
    cin>>p;

    for(int j=1; j<=p; j++)
    {
        set<int>s;
        cout<<"for "<<j<<endl;
        cout << "Elements in the array:";
        for(int i=0; i<p-1; i++)
        {
            int b = power(j,i,p);
            cout<<b<<" ";
            s.insert(b);
        }

        cout <<endl<< "Elements in the set:";
        for (int it : s)
        {
            cout << " " << it;
        }
        cout << endl;

        if(s.size()==p-1)
        {
            cout<<"Primitive Element"<<endl;
        }
        else
        {
            cout<<"Not a primitive element"<<endl;
        }

    }

}
