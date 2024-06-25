#include<bits/stdc++.h>
using namespace std;
int main(){
    string plain,key;
    cin >> plain >> key;
    // plain = "GIVEMESOMEFOOD";
    // key = "MONEY";

    int x=0;
    int kl = key.length();
    int pl = plain.length();
    char tk[kl];

    if(pl%kl == 0){
        x = pl/kl;
    }
    else{
        int n = pl/kl;
        for(int i=1;i<n;i++){
            plain = plain + '*';
        }
        pl = plain.length();
        x = pl/kl;
    }

    char m1[x][kl],m2[x][kl];
    int t1 = 0;
    for(int i=0; i<x; i++){
        for(int j=0; j<kl; j++){
            m1[i][j] = plain[t1];
            t1++;
        }
    }
    cout << "1st matrix - " << endl;
    for(int i=0; i<kl; i++){
        cout << key[i] << " ";
        tk[i] = key[i];
    }
    cout << endl;
    for(int i=0; i<kl; i++){
        cout << '_' << " ";
    }
    cout << endl;
    for(int i=0; i<x; i++){
        for(int j=0; j<kl; j++){
            cout << m1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    sort(tk,tk+kl);

    // for(int i=0; i<kl; i++){
    //     cout << tk[i] << " ";
    // }
    string cipher;

    cout << "Cipher text - ";
    int t = kl, j=0;
    while(t!=0){
        for(int i=0;i<kl;i++){
            if(key[i] == tk[j]){
                for(int p=0;p<x;p++){
                    cipher = cipher + m1[p][i];
                }
                break;
            }
        }
        j++;
        t--;
    }
    cout << cipher << endl;
    cout << endl;

    int cl = cipher.length();
    t = cl, j=0 ;
    int tj=0;
    while(t!=0){
        for(int i=0;i<kl;i++){
            if(key[i] == tk[j]){
                for(int p=0;p<x;p++){
                    m2[p][i] = cipher[tj];
                    tj++;
                }
                break;
            }
        }
        j++;
        t--;
    }

    cout << "2nd matrix - " << endl;
    for(int i=0; i<kl; i++){
        cout << key[i] << " ";
        tk[i] = key[i];
    }
    cout << endl;
    for(int i=0; i<kl; i++){
        cout << '_' << " ";
    }
    cout << endl;
    for(int i=0; i<x; i++){
        for(int j=0; j<kl; j++){
            cout << m2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Plain Text - " ;
    for(int i=0;i<x;i++){
        for(int j=0;j<kl;j++){
            cout << m2[i][j];
        }
    }



    return 0;
}
