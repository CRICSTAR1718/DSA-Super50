#include<bits/stdc++.h>
using namespace std;
#define maxi 100001
int main()
{
    vector<int> spf(maxi);
    for (int i = 2; i < maxi; i++)
    {
        spf[i] = i;
    }
    for (int i = 2; i*i < maxi; i++)
    {
        if(spf[i]==i)
        {
            for (int j = i; j < maxi; j+=i)
            {
                if(spf[j]==j)
                {
                    spf[j] = i;
                }
                
            }
        }
    }
    int n;
    int m;
    cin >> n >> m;
    vector<bool> isOn(n+1, false);
    vector<int> primeOwner(n+1);
    while(m--)
    {
        char sign;
        int x;
        cin >> sign >> x;
        if(sign=='+')
        {
            if(isOn[x])
            {
                cout << "Already on" << endl;
                continue;
            }
            int temp = x;
            vector<int> primes;
            while(temp!=1)
            {
                int p = spf[temp];
                temp = temp / p;
                primes.push_back(p);
                while(temp%p==0)
                {
                    temp = temp / p;
                }
            }
            int conflict = 0;
            for(int p:primes)
            {
                if(primeOwner[p]!=0)
                {
                    conflict = primeOwner[p];
                    break;
                }
            }
            if(conflict)
            {
                cout << "Conflict with " << conflict << endl;
            }
            else{
                for(int p: primes)
                {
                    primeOwner[p] = x;
                }
                isOn[x] = true;
                cout << "Success" << endl;
            }
        }
        //sign= '-'
        else{
            if(!isOn[x])
            {
                cout << "Already off" << endl;
                continue;
            }
            int temp = x;
            while(temp>1)
            {
                int p = spf[temp];
                primeOwner[p] = 0;
                while(temp%p==0)
                {
                    temp = temp / p;
                }
            }
            isOn[x] = false;
            cout << "Success" << endl;
        }
    }
    return 0;
}