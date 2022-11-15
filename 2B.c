#include<sys/types.h> 
#include<sys/wait.h> 
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h>
void quicksort(int[10],int,int); 
int main()
{
int pid,ppid,a[10],size,i; char*argv[12]; 
for(i=0;i<12;i++)
{
argv[i]=(char*)malloc(20);
}
printf("\nIn The main of parent process.\nMyprocess-id is%d.", getpid()); 
printf("\nEnter the number of elements in the array:\n"); 
scanf("%d",&size);
printf("Enter %dElements:",size); 
for(i=0;i<size;i++) 
scanf("%d",&a[i]); 
quicksort(a,0,size-1); 
printf("Sorted elements:"); 
for(i=0;i<size;i++)
{
printf("%d\t",a[i]);
}
printf("\n");
printf("PARENT:I am calling my child for searching now!\n"); 
printf("	");
pid=vfork(); 
if(pid==0) 
{
printf("CHILD:In child process.My process-idis%d.\n",getpid()); 
printf("CHILD:My parent's process-id is%d.\n",getppid());
printf("CHILD:Calling searching program using execv now.I will be overlayed!\n"); 
for(i=0;i<size; i++)
{
sprintf(argv[i+1],"%d", a[i]);
}
argv[0]="./b_binarysearch";
argv[size+2]=NULL; 
execv("./b_binarysearch",argv); 
printf("Error");
printf("CHILD:I am dying now\n");
}
else if(pid>0)
{
system("wait");
printf("\nPARENT:I am dying now\n");
printf("	");
printf("\n\n.");
}
return 0;
}
void quicksort(int a[10],int first,int last)
{
int pivot,j,temp,i; 
if(first<last)
{
pivot=first; i=first; j=last; 
while(i<j) 
{
while(a[i]<=a[pivot]&&i<last) 
i++; 
while(a[j]>a[pivot])
j--;
if(i<j)
{
temp=a[i]; 
a[i]=a[j];
a[j]=temp; 
} 
} 
temp=a[pivot]; 
a[pivot]=a[j]; 
a[j]=temp; 
quicksort(a,first,j-1); 
quicksort(a,j+1,last);
}
}

