#include <iostream>
using namespace std;

char matrix[80][80];
int main(){
    int n;
    char a,b;
    bool firstCase=true;
    while(cin>>n>>a>>b){
        if(firstCase==true){
            firstCase=false;
        }else{
            printf("\n");
        }
        for(int i=0;i<=n/2;i++){
            int j=n-i-1;
            int length=n-2*i;
            char c;
            if((n/2-i)%2==0){
                c=a;
            }else{
                c=b;
            }
            for(int k=0;k<length;k++){
                matrix[i][i+k]=c;
                matrix[i+k][i]=c;
                matrix[j][j-k]=c;
                matrix[j-k][j]=c;
            }
        }
        if(n!=1){
            matrix[0][0]=' ';
            matrix[0][n-1]=' ';
            matrix[n-1][0]=' ';
            matrix[n-1][n-1]=' ';
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%c",matrix[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}