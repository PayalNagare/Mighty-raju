#include <stdio.h> 
#include <stdbool.h>

bool isPresent(int frame[], int n)
{ 
for(int i=0;i<3;i++)
{ 
if(frame[i]==n)
{
return true;
}
}
return false;
}
void display(int frame[])
{ 
for(int i=2;i>=0;i--)
{
if(frame[i] == -1)
{
printf(" ");
}
else
{
printf("%d ", frame[i]);
}
}
}
void main()
{
int sequence[] = {1, 3, 0, 3, 5, 6, 3}; // given reference string 
int frame[3] = {-1,-1,-1}; // frame - to store the reference string in frame
int count = 0; // to count the page fault 
int first_index = 0;
// to store the least used index

for(int i=0;i<7;i++)
{
// checking if i > frame_size i.e. 2(given) for checking frame is full or not
if(i>2){
// following checking if the element is ready present in frame or not. If present then don't push anything.
if(isPresent(frame, sequence[i]))
{ 
printf("%d -> ", sequence[i]); 
display(frame);
printf(" HIT\n");
}
else
{
// if element is not present the at first_index of frame replace the element
frame[first_index] = sequence[i]; first_index++;
printf("%d -> ", sequence[i]);
display(frame); 
printf(" MISS\n"); 
count++;
}
}else{
// if frame is not full directly push the reference_string_element to frame(frame) 
frame[i] = sequence[i]; // pushing reference_string_element in frame
// following code is for printing: reference_string_element -> frame_elements MISS/HIT (according to GFG)
printf("%d -> ", sequence[i]); display(frame);
printf(" MISS\n");
count++; // increasing the page fault number; 
}
}
printf("\nTotal number of page fault = %d\n", count); 
}
