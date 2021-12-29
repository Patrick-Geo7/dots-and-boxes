#include <stdio.h>
#include <stdlib.h>
#include "colors.h"
#include "menu.h"
#include "scanint.h"
#include "struct.h"
#include "Grid.h"
#include "function.h"
#include "string.h"
int main()
{   system("color");

    player one={0,0,"ahmed"},two={0,0,"maro"};
    int i = 1,flag=0;


    char array1[5][5] = {{'d','S','d','S','d'},
                   {'s','S','s','S','s'},
                   {'d','S','d','S','d'},
                   {'s','S','s','S','s'},
                   {'d','S','d','S','d'}};
    while(1){
        int r1,r2,c1,c2, valid;
        system("cls");
        print_the_game(one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,5,array1);
        if(i==1){
            printf(blue"\nenter number of row : "reset);
            r1 = scanint();
            printf(blue"enter number of column : "reset);
            c1 = scanint();
            printf(blue"enter number of row : "reset);
            r2 = scanint();
            printf(blue"enter number of column : "reset);
            c2 = scanint();
        }
        else if(i==2){
            printf(red"\n\t\t\t\t\tenter number of row : "reset);
            r1 = scanint();
            printf(red"\t\t\t\t\tenter number of column : "reset);
            c1 = scanint();
            printf(red"\t\t\t\t\tenter number of row : "reset);
            r2 = scanint();
            printf(red"\t\t\t\t\tenter number of column : "reset);
            c2 = scanint();
        }
        valid = Validate_Input(r1,r2,c1,c2,5,array1);
        while(!valid){
            system("cls");
            printf(yellow"not available\n"reset);
            print_the_game(one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,5,array1);
            if(i==1){
                printf(blue"\nenter number of row : "reset);
                r1 = scanint();
                printf(blue"enter number of column : "reset);
                c1 = scanint();
                printf(blue"enter number of row : "reset);
                r2 = scanint();
                printf(blue"enter number of column : "reset);
                c2 = scanint();
            }
            else if(i==2){
                printf(red"\n\t\t\t\t\tenter number of row : "reset);
                r1 = scanint();
                printf(red"\t\t\t\t\tenter number of column : "reset);
                c1 = scanint();
                printf(red"\t\t\t\t\tenter number of row : "reset);
                r2 = scanint();
                printf(red"\t\t\t\t\tenter number of column : "reset);
                c2 = scanint();
            }
            valid = Validate_Input(r1,r2,c1,c2,5,array1);
        }
        if(i==1){
            one.NoOfMoves++;
            DrawTheLine(i,r1,r2,c1,c2,5,array1);
            flag = checkBox(i,5,array1);
            if(flag==1){
                RevI(i);
            }
        }
        else{
            two.NoOfMoves++;
            DrawTheLine(i,r1,r2,c1,c2,5,array1);
            flag = checkBox(i,5,array1);
            if(flag==1){
              i =  RevI(i);
            }
        }
        i = RevI(i);
        int endgame = ENDGAME(one.NoOfMoves,two.NoOfMoves,5);
        if (endgame==1){
            if(i==1){
                system("cls");
                print_the_game(one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,5,array1);
                printf(red"\n\t\t %c won",two.name,reset);
            }
            else if(i==2){
                system("cls");
                print_the_game(one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,5,array1);
                printf(blue"\n\t\t %c won",two.name,reset);
            }
            printf("enter any number to return to the main menu : ");
            scanint();

            break;
        }
    }


    return 0;
}
