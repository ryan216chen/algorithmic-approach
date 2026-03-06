#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;
using ll = long long;
static constexpr int MAXN = 1040;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<bool> isPrime(MAXN+1,1);
    vector<int> primes;

    isPrime[0] = false;
    for(int i=2;i<=MAXN;i++)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
        }
        for(auto &p : primes)
        {
            ll x = p * i;
            if(x > MAXN)
            {
                break;
            }
            isPrime[x] = false;
            if(i % p == 0)
            {
                break;
            }
        }
    }

    string tmp;
    while(cin>>tmp)
    {
        int sum = 0;
        for(auto &p : tmp)
        {
            if(islower(p))
            {
                sum += p - 'a' + 1;
            }
            else
            {
                sum += tolower(p) - 'a' + 27; 
            }
        }
        if(isPrime[sum])
        {
            cout<<"It is a prime word.\n";
        }
        else
        {
            cout<<"It is not a prime word.\n";
        }
    }
    return 0;
}
