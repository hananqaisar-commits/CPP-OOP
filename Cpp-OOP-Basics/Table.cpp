/*/ Tom’s Trap Table 
 
Tom wants to trap Jerry using a cheese table. But he can’t lay traps randomly. He must 
generate a number table from a given start to end to trick Jerry into stepping on the right 
one.  
Input num, start, and end. Print the multiplication table of num from start to end. Use 
while loop. 
 
Sample Input/output:  
 
Input:  
 
num = 5, start = 11, end =15   
 
Output:  
 
5 * 11 = 55  
5 * 12 = 60  
5 * 13 = 65  
5 * 14 = 70  
5 * 15 = 75 */

#include<iostream>
using namespace std;
int main(){
int num;
int i=1;                       //i=start
int Fazool;
int end;
    cout<<"Enter number:";
    cin>>num;
    cout<<"Enter start number:";
    cin>>i;
    cout<<"Enter end number:";
    cin>>end;

    while (i<=end)
    {
        cout<<num<<"*"<<i<<"="<<num*i<<endl;
        i++;
    }


    cout<<"Thanks for using this";
    cin>>Fazool;
 return 0;   
}