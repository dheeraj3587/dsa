#include<iostream>
#include<cmath>

using namespace std;

// Function to find the square root of a number using binary search
long long int binary(int n){

    int s=0;
    int e=n;

    long long int mid=s+(e-s)/2;

    long long int ans=-1;

    // Binary search to find the square root
    while(s<=e){

        // Calculating the square of the middle point
        long long int square=mid*mid;

        // If the square is equal to the number, return the middle point
        if(square==n){
            return mid;
        }

        // If the square is less than the number, update the answer and move to the right half of the search space
        if(square<n){
            ans=mid;
            s=mid+1;
        }

        // If the square is greater than the number, move to the left half of the search space
        else{
            e=mid-1;
        }

        // Updating the middle point
        mid=s+(e-s)/2;
    }

    return ans;
}

// Function to find the square root of a number with a given precision
double prec(int n, int prec, int tempsol){

    double ans=tempsol;
    double factor=1;

    // Looping over the number of decimal places required
    for(int i=0;i<prec;i++){

        // Dividing the factor by 10 in each iteration
        factor=factor/10;

        // Looping over all the values of the answer variable that give a square less than the number
        for(double j=ans;j*j<n;j=j+factor){
            ans=j;
        }
    } 

    return ans;
}

// Driver code
int main(){

    int n;
    cout<<"Enter the number: ";
    cin>>n;
  
    int prec;
    cout<<"Enter the precision (number of decimal places): ";
    cin>>prec;
  
    long long int intsqrt=binary(n);

    double decsqrt=prec(n,prec,intsqrt);

    cout<<"The square root of "<<n<<" is "<<intsqrt<<"."<<fixed<<setprecision(prec)<<decsqrt<<endl;

    return 0;
}
