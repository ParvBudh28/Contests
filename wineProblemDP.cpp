#include<iostream>
#include<cstring>
using namespace std;
int noOfCalls=0;
int memo[100][100];

// function to take input
void takeInput(int* wine,int n){
	for (int i = 0; i<n; ++i)
	{
		/* code */
		cin>>wine[i];
	}	
}

// // function to find max cost possible just by recursion 		time complexity-> O(2^n)
// int findMaxRec(int* wine,int n,int start,int end,int year){
// 	++noOfCalls;
// 	// base case 
// 	if(start==end){
// 		return wine[start]*year;
// 	}

// 	// recursive case
// 	// case 1 sell from start
// 	int q1=wine[start]*year+findMaxRec(wine,n,start+1,end,year+1);

// 	// case 2- sell from the end
// 	int q2=wine[end]*year+findMaxRec(wine,n,start,end-1,year+1);

// 	return max(q1,q2);

// }

// function to find max cost possible using memoization
int findMaxMemo(int* wine,int n,int start,int end,int year){
	noOfCalls++;
	// base case 
	if(start==end){
		return wine[start]*year;
	}

	// we will check if the sub problem has already been calculated then we will simply return
	if(memo[start][end]!=-1){
		return memo[start][end];
	}

	// recursive case
	// case 1 sell from start
	int q1=wine[start]*year+findMaxMemo(wine,n,start+1,end,year+1);

	// case 2- sell from the end
	int q2=wine[end]*year+findMaxMemo(wine,n,start,end-1,year+1);
	int ans=max(q1,q2);
	memo[start][end]=ans;
	return ans;

}

int main(){
	int n;
	cin>>n;
	memset(memo, -1, sizeof(memo));

	// array to store the cost of wine in first year
	int wine[n];
	takeInput(wine,n);
	//cout<<findMaxRec(wine,n,0,n-1,1)<<endl;

	cout<<findMaxMemo(wine,n,0,n-1,1)<<endl;

	cout<<noOfCalls<<endl;
	return 0;
}