#include <iostream>
#include <vector>
using namespace std;
bool isPrime(long long n);
long long mod_mul(long long a,long long b,long long mod);
long long mod_pow(long long a,long long b,long long mod);
vector<long long> vcc = {2,3,5,7,11,13,17,19};//米勒拉賓中的a，與p互質所以都是質數
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long a,b;
    while(cin>>a>>b)
    {
        int cnt = 0;
        for(int i=a;i<=b;i++)
        {
            if(isPrime(i))
            {
                cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}

bool isPrime(long long n)//判斷n是否為prime
{
    if(n < 2)
    {
        return false;
    }
    for(auto &p : vcc)
    {
        if(n == p)
        {
            return true;
        }
        else if(n % p == 0)//是小質數的倍數
        {
            return false;
        }
    }
    long long d = n - 1;
    int s = 0;
    while(!(d&1))//當d是偶數
    {
        d >>= 1;
        s++;
    }
    // n-1被拆成2^s * d
    for(auto &a : vcc)
    {
        if(n % a == 0)//不是互質就跳過
        {
            continue;
        }
        long long x = mod_pow(a,d,n);//s是0時，a^(p-1) = a^(2^s * d) = a^(d)
        if(x == 1 || x == n-1)//有可能是質數
        {
            continue;
        }

        bool composite = true;
        for(int i=1;i<s;i++)//只要檢查到s-1就好，若都沒出現-1則判定為合數
        {
            x = mod_mul(x,x,n);
            if(x == n-1)
            {
                composite = false;//目前的a測試為非合數
                break;
            }
        }
        if(composite)//只要有一組是合數就return
        {
            return false;
        }
    }
    return true;
}

long long mod_mul(long long a,long long b,long long mod)
{
    return a * b % mod;
}

long long mod_pow(long long a,long long b,long long mod)//計算a^b % mod 快速冪
{
    long long base = 1;
    while(b)
    {
        if(b & 1)
        {
            base = mod_mul(a,base,mod);
        }
        a = mod_mul(a,a,mod);
        b >>= 1;
    }
    return base;
}
