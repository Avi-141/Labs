    #include <bits/stdc++.h>
    using namespace std;
    #define lli long long int
    lli sum_prime_fac[1000001];
    void PSIEVE(){
        sum_prime_fac[1000001] = {0};
        for(int i=2;i<=1000000;i++){
                if(!sum_prime_fac[i]){
                        for(int j=i;j<=1000000;j+=i)
                            sum_prime_fac[j]+=i;
                }
        }
    }
     
    lli inverse(lli a,lli b,lli p){
        lli an=1;
        while(b){
            if(b%2)
                an=(an*1ll*a)%p;
            a=(a*1ll*a)%p;
            b/=2;
        }
        return an;
    }
     
    int getSubsets(int k, int n, vector<int> arr) {
        PSIEVE();
        long int mod = 1000000007;
        int sum=0,i,j;
        for(i=0;i<arr.size();i++)
            sum= (sum%1000000 + sum_prime_fac[arr[i]]%1000000)%1000000;
        lli fac1=1,fac2=1,fac3=1;
        for(int i=1;i<=sum+k-1;i++)
            fac1 = (fac1*1LL*i)%mod;
        for(int i=1;i<=sum;i++)
            fac2 = (fac2*1LL*i)%mod;
        for(int i=1;i<k;i++)
            fac3 = (fac3*1LL*i)%mod;
        lli fac2in = inverse(fac2,mod-2,mod);
        lli fac3in = inverse(fac3,mod-2,mod);
        fac1 = ((fac1%mod)*(fac2in%mod))%mod;
        fac1 = ((fac1%mod)*(fac3in%mod))%mod;
        return(fac1);
    }
    using namespace std;
     
    int main() {
    	vector<int>vec({1,2,6});
    	int n=3;
    	int k=3;
    	cout<<getSubsets(3,3,vec);
    	return 0;
    }

