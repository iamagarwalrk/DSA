#include<iostream>
using namespace std;


int main(){
    int x, n;
    cin >> x >> n;
  
    cout << power(x, n) << endl;
}


int power(int x, int n) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
int power=1;
    while(n>0){
    power=power*x;
        n--;}
return power;

}
