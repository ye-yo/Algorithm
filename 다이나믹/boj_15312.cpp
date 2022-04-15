#include <iostream>

using namespace std;
int line[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
int asciiA = (int)'A';
int a[4000];
int main(){
    string A, B;
    cin >> A;
    cin >> B;

    int j = 0;
    for(int i = 0; i<= A.length() * 2; i += 2,j++){
        a[i] = line[(int)A[j] - asciiA];
        a[i+1]= line[(int)B[j] - asciiA];
    }
    
    int i = 0;
    int max = A.length() * 2;
    while(max > 2){
        for(int i = 1; i< max; i++){
            a[i - 1] = (a[i - 1] +  a[i]) % 10;
        }
        max--;
    }
    cout << a[0]<<a[1];

    return 0;
}