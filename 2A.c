void qsrt(int low,int high,int arr[10]); 
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/wait.h> 
#include<sys/types.h> 
int main()
 { 
 	int arr[10],arr2[10],i,n,low=0,high,piv,ser,x,status;
  	printf("\nHow many numbers you want to Enter:"); 
 	scanf("%d",&n);
  	high=n-1;
  	printf("\nEnter Numbers:"); 
 	for(i=0;i<n;i++) 
 	{ 
 	 	scanf("%d",&arr[i]); 
 	 	arr2[i]=arr[i]; 
 	} 
 	printf("\nId of main process %d\n",getpid()); 
 	pid_t cpid;
  	status=fork();
  	if(status==0) 
 	{ 	 
 	 	//child 
 	 	printf("\nChild:Hello from child!!!");
  	 	piv=arr[0]; 
 	 	qsrt(low,high,arr); 
 	 	printf("\nChild:Sorted numbers by child process\nchild:parent process id %d\n ",getppid()); 
 	 	for(i=0;i<n;i++) 
 	 	{ 
 	 	 	printf("%d\t",arr[i]); 
 	 	} 
 	 	printf("\n"); 
 	 	printf("\nChild:Exiting now..."); 
 	 	exit(1); 
 	} 
 	else 
 	{ 
 	 	//parent 
 	 	printf("\nParent:Hello from parent..."); 
	 	piv=arr2[0]; 
 	 	qsrt(low,high,arr2); 
 	 	printf("\nParent:Sorted numbers by parent process\n"); 
 	 	for(i=0;i<n;i++) 
 	 	{ 
 	 	 	printf("%d\t",arr2[i]); 
 	 	} 
 	 	wait(&status); 
 	 	printf("\nParent:In zombie state...Exiting now\n"); 
 	 	exit(1); 
 	} 
return 0;
} 
void qsrt(int low,int high,int arr[10]) 
{ 
 	 
 	int i=low,j=high,temp,piv=arr[low]; 
 	while(i<j) 
 	{ 
 	 	while(arr[i]<=piv) 
 	 	 	i++; 
 	 	while(arr[j]>piv) 
 	 	 	j--; 
 	 	 
 	 	if(i<j) 
 	 	{ 
 	 	 	temp=arr[i];
  	 	 	arr[i]=arr[j]; 
 	 	 	arr[j]=temp; 
 	 	} 
 	 	else 
 	 	{ 
 	 	 	temp=arr[j];
  	 	 	arr[j]=piv;
  	 	 	arr[low]=temp;  	 	 	
                        qsrt(low,j,arr); 
 	 	 	qsrt(i,high,arr);

 	 	} 
 	}  
}
