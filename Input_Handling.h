#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void validate_input(int r1,int r2,int c1,int c2){
    if(r1==r2&&c1==c2){
        printf(red "Invalid,cannot draw line to the same point");
    }
    else if(r1==r2&&(abs(c1-c2)==1))
            f();
    else if (c1==c2&&(abs(r1-r2)==1))
        f();
    else if (abs(c1-c2)==1&&abs(r1-r2)==1)
        printf("You can't draw a line in such position");
  return;}

