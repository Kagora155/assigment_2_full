// File: A2_S18_20220124_8.cpp
// Purpose:  printing pattern 
// Author:doaa ayman mohamed
// Section: s18
// ID: 20220124
// TA: rana abdelkader
// Date: 12 Oct 2023
#include <bits/stdc++.h>
using namespace std;
 static void pattern(int n, int i){
         if (n==1)
		{
			for (size_t j = 0; j < i; j++)
			{
				cout<<" "; //printing spaces eaual to i;
			}
			cout<<"*"; 
			
		}
		else 
		{
			pattern(n/2,i); 
			cout<<"\n";
			for (size_t j = 0; j < i; j++)
			{
				cout<<" ";//printing spaces eaual to i;
			}
			for (size_t j = 0; j < n; j++)  
			{
				cout<<"* "; //printing stars eaual to i;
			}
			cout<<"\n";
			pattern(n/2,i+n);
		}
		
}
int main(){
   int stars, spaces;
   cin>>stars>>spaces;
   pattern(stars,spaces);
}