/*C-program to find the speed of an obstacle*/
#include<stdio.h>
#include<math.h>
int main(){
float distance, time, speed;
printf("Enter the distance and time covered by the obstacle : \n");
scanf("%f %f", &distance, &time);
printf("Speed of the given obstacle is : %.2f", speed = distance/time);
return 0;
}