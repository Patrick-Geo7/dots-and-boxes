#include <stdio.h>
#include <stdlib.h>
//function to reverse the value of of i

int RevI(int n){
    if(n==1){
        n=2;
    }
    else{
        n=1;
    }
return n;
}

int ENDGAME(int player1NoOfMoves,int player2NoOfMoves,int n){
    int k;
    if(n==5){
        k = 3;
    }
    else if(n==9){
        k = 5;
    }
    int flag=0;
    if ((player1NoOfMoves+player2NoOfMoves)==(2*(k-1)*k)){
        flag=1;}
    return flag;}


//function to check if the input is valid
int Validate_Input(int r1,int r2,int c1,int c2,int n,char a[n][n]){
    int valid=0;
    if(r1==r2&&(abs(c1-c2)==2)){
        if(c1<c2){
            if(a[r1][c1+1]=='s' || a[r1][c1+1]=='S'){
                valid = 1;
            }
        }
        else{
            if(a[r1][c2+1]=='s' || a[r1][c2+1]=='S'){
                valid = 1;
            }
        }


    }
    else if (c1==c2&&(abs(r1-r2)==2)){
        if(r1<r2){
            if(a[r1+1][c1]=='s' || a[r1+1][c1]=='S'){
                valid = 1;
            }
        }
        else{
            if(a[r2+1][c2]=='s' || a[r2+1][c2]=='S'){
                valid = 1;
            }
        }
    }
    return valid;
 }


//function to get index of the line
//function call if valid=1
    int DrawTheLine(int i,int r1,int r2,int c1,int c2,int n,char array1[n][n]){
    if (c1==c2){
            if(r1<r2){
                if(i==1){array1[r1+1][c1]='1';}
                else{array1[r1+1][c1]='2';}
            }
            else{
                if(i==1){array1[r2+1][c1]='1';}
                else{array1[r2+1][c1]='2';}
            }
            }
        else {
            if(c1<c2){
                if(i==1){array1[r1][c1+1]='a';}
                else {array1[r1][c1+1]='b';}
            }
            else {
                if(i==1){array1[r1][c2+1]='a';}
                else {array1[r1][c2+1]='b';}
            }
        }
    }
//check if a player completed a box function
 int checkBox(int round,int n,char a[n][n]){
     int flag = 0;
    for (int i=1;i<n;i+=2){
        for (int j=1;j<n;j+=2){
            if(((a[i][j-1]=='1')||(a[i][j-1]=='2'))&&((a[i][j+1]=='1')||(a[i][j+1]=='2'))&&((a[i-1][j]=='a')||(a[i-1][j]=='b'))&&((a[i+1][j]=='a')||(a[i+1][j]=='b'))&&(a[i][j]=='S')){
                    if(round==1){
                        a[i][j]='A';
                        flag++;
                    }
                    else if(round==2){
                        a[i][j]='B';
                        flag++;

                    }
            }
        }
    }
   return flag; }



int ComputerTurn(int n,char a[n][n]){
    int i,j;
    for (i=1;i<n;i+=2){
        for (j=1;j<n;j+=2){
            if(((a[i][j]=='S'))){
                //if the computer founds a move that will close a box he will play it (that means if he found 3 drawn lines around a box he draws the fourth one)
                if((a[i][j-1]!='s')&&((a[i][j+1]!='s'))&&(a[i-1][j]!='S'))
                    {
                    a[i+1][j]='b';
                    return 1;

                }
                else if((a[i][j-1]!='s')&&(a[i][j+1]!='s')&&(a[i+1][j]!='S')){
                    a[i-1][j]='b';
                    return 1;

                }
                else if((a[i][j-1]!='s')&&(a[i+1][j]!='S')&&(a[i-1][j]!='S')){
                    a[i][j+1]='2';
                    return 1;
                }
                else if((a[i+1][j]!='S')&&(a[i-1][j]!='S')&&(a[i][j+1]!='s')){
                    a[i][j-1]='2';
                    return 1;
                }
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if((i%2!=1)||(j%2!=1)){
                if(a[i][j]=='S'){
                    a[i][j] = 'b';
                    return 0;
                }
                else if(a[i][j]=='s'){
                    a[i][j] = '2';
                    return 0;
                }
            }
        }
    }
}
void resetGrid(int n,char arr[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(((i%2)==0)&&((j%2)==0)){arr[i][j] = 'd';}
            else if((i%2==1)&&(j%2==0)){arr[i][j] = 's';}
            else {arr[i][j] = 'S';}
        }
    }
}



