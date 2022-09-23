#include<stdio.h>
#include <math.h>
#include <unistd.h>

int main() {
	
// Intializing Variables
 float A = 0, B = 0;
 float i, j;
 int k;
 float z[1760];
 char b[1760];


 for(;;) { 	
//setting a value 32 and 0 in b and z Charcter Array
 memset(b,32,1760);
 memset(z,0,7040);
 
//looping it in term of i and j condition
 for(j=0; j < 6.28; j += 0.07) {
 for(i=0; i < 6.28; i += 0.02) {
 	
 float c = sin(i); //value of sin changing in every i iteration
 float d = cos(j); //value of cos changing in every j iteration
 float e = sin(A); 
 float f = sin(j); //value of sin changing in every j iteration
 float g = cos(A); 
 float h = d + 2;  
 float D = 1 / (c * h * e + f * g + 5);
 float l = cos(i); //value of cos changing in every i iteration
 float m = cos(B); 
 float n = sin(B);
 
 
//Mathematical Calculation
 float t = c * h * g - f * e;
 int x = 40 + 30 * D * (l * h * m - t * n);
 int y= 12 + 15 * D * (l * h * n + t * m); 
 int o = x + 80 * y;
 int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
 
 
//Using condition-statement
 if(22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
 z[o] = D;
 b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
 }
 }
 }


//printing donut in loop by ternary-operator
 for(k = 0; k < 1761; k++) {
putchar(k % 80 ? b[k] : 10);
 A += 0.00004;
 B += 0.00002;
 }
 usleep(50000);// It is a C API that suspends the current process for the number for 50000 microseconds/0.05 seconds.
 }
 return 0;
}
