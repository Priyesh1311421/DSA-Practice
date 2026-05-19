#include<bits/stdc++.h>
using namespace std;


int count(int n){
    int cnt = 0; 
    while( n > 0){
        int lastDigit = n % 10;
        cnt += 1;
        n = n / 10;
    }
    return cnt;
}


int count(int n){
    int cnt = (int)(log10(n) + 1);
    return cnt;
}



// reverse a number
int reverse(int n){
    int revNum = 0;
    while(n > 0){
        int ld = n % 10;
        revNum = (revNum * 10) + ld;
        n = n / 10;
    }
    return revNum;
}

// check palindrome

bool checkPalindrome(int n){
    int revNum = 0;
    while(n > 0){
        int ld = n % 10;
        revNum = (revNum * 10) + ld;
        n = n / 10;
    }
    return revNum == n;
}


// Armstrong Number

bool armstrongNumber(int n) {
    int duplicate = n;
    int sum = 0;
    while(n > 0){
        int ld = n % 10;
        sum += (ld * ld * ld);
        n /= 10;
    }
    return duplicate == sum;
}

// GCD or HCF

void gcd(int a, int b){
    while(a> 0 && b > 0 ){
        if( a > b) a = a % b;
        else b = b % a;
    }
    if(a == 0) cout<< b;
    else cout<< a;
}


// Print all divisors
void printDivisors(int n){
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            cout<< i;
        }
    }
}

void printDivisorsbetter(int n){
    for(int i = 1; i <= n * n; i++){
        if(n % i == 0){
            cout<< i; 
            if(n/i != 1){
                cout << n/i;
            }
        }
    }
}


// check Prime
bool checkPrime(int n){
    int cnt = 0;
    for(int i = 1; i <= n * n; i++){
        if(n % i == 0){
            cnt++; 
            if(n/i != 1){
                cnt++;
            }
        }
    }
    if(cnt == 2) return true;
    return false;
}

int main(){
    return 0;
}