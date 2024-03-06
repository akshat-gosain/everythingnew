// #include <bits/stdc++.h>
// using namespace std;

// int main() {
    
//     double a,b,c,d;
//     cin >> a >> b >> c >> d;

//     double arrm=0;

//     if(c/d>a/b){arrm=1-(a*d)/(b*c);}
//     else{arrm=1-(b*d)/(a*c);}

//     cout << arrm << endl;
    
//     }

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    long long a,b,c,d;
    cin >> a >> b >> c >> d;

    long long numerator, denominator;

    if(static_cast<double>(a)/b < static_cast<double>(c)/d){
        numerator = b*c - d*a;
        denominator = c*b;
    }else{
        numerator = a*d - c*b;
        denominator = a*d;
    }

    long long gcd = __gcd(numerator, denominator);

    numerator /= gcd;
    denominator /= gcd;

    cout << numerator << "/" << denominator << endl;
    
    return 0;
}



