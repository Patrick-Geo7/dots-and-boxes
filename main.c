#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "colors.h"
#include "menu.h"
#include "scanint.h"
#include "struct.h"
#include "function.h"


int main(){
    system("color");
    a:;
    gamer top[100];
    int countTop = 0;
    FILE *fptr;
    fptr = fopen("C:/Users/King Fix/Desktop/test/top10.txt","r");
    fscanf(fptr,"%d ",&countTop);
    for(int i=0;i<30;i++){

        fscanf(fptr,"%s %d ",top[i].name,&top[i].score);
    }
    fclose(fptr);
    int i,flag,what,n,seconds;
    time_t time;
    char array1[5][5] =   { {'d','S','d','S','d'},
                            {'s','S','s','S','s'},
                            {'d','S','d','S','d'},
                            {'s','S','s','S','s'},
                            {'d','S','d','S','d'}};

    char array2[9][9] =  {  {'d','S','d','S','d','S','d','S','d'},
                            {'s','S','s','S','s','S','s','S','s'},
                            {'d','S','d','S','d','S','d','S','d'},
                            {'s','S','s','S','s','S','s','S','s'},
                            {'d','S','d','S','d','S','d','S','d'},
                            {'s','S','s','S','s','S','s','S','s'},
                            {'d','S','d','S','d','S','d','S','d'},
                            {'s','S','s','S','s','S','s','S','s'},
                            {'d','S','d','S','d','S','d','S','d'}};
    undo1 arrayU1[100];
    redo1 arrayR1[100];
    int R1count=0;
    int U1count=0;
    undo2 arrayU2[100];
    redo2 arrayR2[100];
    int R2count=0;
    int U2count=0;
    player one , two= {0,0,"Computer"};
    int choice = print_menu();

    //_______________________________________________________________________________________________________________
    //_______________________________________________________________________________________________________________

    if(choice==13 || choice==24){
            goto a;
    }
    //___________________________________________________________________________________________________________________
    //___________________________________________________________________________________________________________________
    else if(choice==111){ /**< play easy vs computer */
            what = 0;
            n = 5;
            seconds = 0;
            resetGrid(n,array1);
            system("cls");
            printf(yellow"\n\tenter your name : "reset);
            fgets(one.name,99,stdin);
            one.name[strcspn(one.name, "\n")] = 0;
            one.NoOfMoves = 0, one.score = 0;
            two.NoOfMoves = 0, two.score = 0;
            i = 1;
            goto b;
    }

    //__________________________________________________________________________________________________________________________
    //__________________________________________________________________________________________________________________________

    else if(choice==112){/**< play easy against friend */
            what = 1;
            n = 5;
            seconds = 0;
            resetGrid(n,array1);
            system("cls");
            printf(yellow"\n\tenter player one name : "reset);
            fgets(one.name,99,stdin);
            one.name[strcspn(one.name, "\n")] = 0;
            system("cls");
            printf(yellow"\n\tenter player two name : "reset);
            fgets(two.name,99,stdin);
            two.name[strcspn(two.name, "\n")] = 0;
            one.NoOfMoves = 0, one.score = 0;
            two.NoOfMoves = 0, two.score = 0;
            i = 1;
            goto b;
    }

    //___________________________________________________________________________________________________________________
    //___________________________________________________________________________________________________________________

    else if(choice==121){/**< play medium against computer */
            what = 0;
            n = 9;
            seconds = 0;
            resetGrid(n,array2);
            system("cls");
            printf(yellow"\n\tenter your name : "reset);
            fgets(one.name,99,stdin);
            one.name[strcspn(one.name, "\n")] = 0;
            one.NoOfMoves = 0, one.score = 0;
            two.NoOfMoves = 0, two.score = 0;
            i = 1;
            goto b;
    }

    //_______________________________________________________________________________________________________________________
    //________________________________________________________________________________________________________________________

    else if(choice==122){/**< play medium against friend */
            what = 1;
            n = 9;
            seconds = 0;
            resetGrid(n,array2);
            system("cls");
            printf(yellow"\n\tenter player one name : "reset);
            fgets(one.name,99,stdin);
            one.name[strcspn(one.name, "\n")] = 0;
            system("cls");
            printf(yellow"\n\tenter player two name : "reset);
            fgets(two.name,99,stdin);
            two.name[strcspn(two.name, "\n")] = 0;
            one.NoOfMoves = 0, one.score = 0;
            two.NoOfMoves = 0, two.score = 0;
            i = 1;
            goto b;
    }

    //__________________________________________________________________________________________________________________
    //__________________________________________________________________________________________________________________

    else if(choice==21){/**< load game 1*/
        FILE *fptr;
        fptr = fopen("C:/Users/King Fix/Desktop/test/file1.txt","r");
            fscanf(fptr,"%d %d %d %d %d %d %d %d %s %s ",&seconds,&i,&what,&n,&one.NoOfMoves,&two.NoOfMoves,&one.score,&two.score,one.name,two.name);
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(n==5){
                    fscanf(fptr,"%c ",&array1[i][j]);
                    }
                    else if(n==9){
                    fscanf(fptr,"%c ",&array2[i][j]);
                    }
                }
            }
            fclose(fptr);
            goto b;
    }
    else if(choice==22){/**< load game 2 */
        FILE *fptr;
        fptr = fopen("C:/Users/King Fix/Desktop/test/file2.txt","r");
        fscanf(fptr,"%d %d %d %d %d %d %d %d %s %s ",&seconds,&i,&what,&n,&one.NoOfMoves,&two.NoOfMoves,&one.score,&two.score,one.name,two.name);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(n==5){
                    fscanf(fptr,"%c ",&array1[i][j]);
                }
                else if(n==9){
                    fscanf(fptr,"%c ",&array2[i][j]);
                }
            }
        }
        fclose(fptr);
        goto b;

    }
    else if(choice==23){/**< load game 3 */
        FILE *fptr;
        fptr = fopen("C:/Users/King Fix/Desktop/test/file3.txt","r");
        fscanf(fptr,"%d %d %d %d %d %d %d %d %s %s ",&seconds,&i,&what,&n,&one.NoOfMoves,&two.NoOfMoves,&one.score,&two.score,one.name,two.name);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(n==5){
                    fscanf(fptr,"%c ",&array1[i][j]);
                    }
                else if(n==9){
                    fscanf(fptr,"%c ",&array2[i][j]);
                }
            }
        }
        fclose(fptr);
        goto b;
    }
    else if(choice==3){/**< top ten */
        gamer a;
        for (int i = 0; i < 30; ++i){
            for (int j = i + 1; j < 30; ++j){
                if ((top[i].score) < (top[j].score)){
                    a = top[i];
                    top[i] = top[j];
                    top[j] = a;
                }
            }
        }
        for(int i=0; i<10; i++){
            printf(blue"\n\t%d- %s\t(%d)\n"reset,i+1,top[i].name,top[i].score);
        }
        printf(yellow"\n\n enter any number to return to the main menu :"reset);
        scanint();
        goto a;
    }
    //_____________________________________________________________________________________________________________________
    //______________________________________________________________________________________________________________________
    //____________________________________ start the game __________________________________________________________________
    b:;
    time = clock();
    if((what==0)&&(n==5)){ //play easy vs computer
        while(1){
            flag = 0;
            int r1,r2,c1,c2, valid;
            system("cls");
            print_the_game(seconds,one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,n,array1);
            if(i==1){
                printf(blue"\nenter number of row : "reset);
                r1 = scanint();
                printf(blue"enter number of column : "reset);
                c1 = scanint();
                printf(blue"enter number of row : "reset);
                r2 = scanint();
                printf(blue"enter number of column : "reset);
                c2 = scanint();
                save1:;
                if((r1==0)&&(r2==0)&&(c1==0)&&(c2==0)){
                    printf(yellow"\n 1- save at file1 \n 2- save at file2 \n 3- save at file3 \n please enter a number : "reset);
                    int k = scanint();
                    while(k!=1 && k!=2 && k!=3){
                        printf(red"\n please enter a valid number : "reset);
                        k = scanint();
                    }
                    if(k==1){
                        FILE *fptr;
                        fptr = fopen("C:/Users/King Fix/Desktop/test/file1.txt","w");
                        fprintf(fptr,"%d %d %d %d %d %d %d %d %s %s ",seconds,i,what,n,one.NoOfMoves,two.NoOfMoves,one.score,two.score,one.name,two.name);
                        for(int i=0;i<n;i++){
                            for(int j=0;j<n;j++){
                                fprintf(fptr,"%c ",array1[i][j]);
                            }
                        }
                        fclose(fptr);
                    }
                    if(k==2){
                        FILE *fptr;
                        fptr = fopen("C:/Users/King Fix/Desktop/test/file2.txt","w");
                        fprintf(fptr,"%d %d %d %d %d %d %d %d %s %s ",seconds,i,what,n,one.NoOfMoves,two.NoOfMoves,one.score,two.score,one.name,two.name);
                        for(int i=0;i<n;i++){
                            for(int j=0;j<n;j++){
                                fprintf(fptr,"%c ",array1[i][j]);
                            }
                        }
                        fclose(fptr);
                    }
                    if(k==3){
                        FILE *fptr;
                        fptr = fopen("C:/Users/King Fix/Desktop/test/file3.txt","w");
                        fprintf(fptr,"%d %d %d %d %d %d %d %d %s %s ",seconds,i,what,n,one.NoOfMoves,two.NoOfMoves,one.score,two.score,one.name,two.name);
                        for(int i=0;i<n;i++){
                            for(int j=0;j<n;j++){
                                fprintf(fptr,"%c ",array1[i][j]);
                            }
                        }
                        fclose(fptr);
                    }
                    time = clock() - time;
                    seconds += time/CLOCKS_PER_SEC;
                    time = clock();
                    goto b;
                }
                if((r1==1)&&(r2==1)&&(c1==1)&&(c2==1)){
                    //to make the undo
                    if(U1count==0){
                        printf(red"Error"reset);
                        goto b;
                    }
                    arrayR1[R1count].oneMoves = one.NoOfMoves;
                    arrayR1[R1count].twoMoves = two.NoOfMoves;
                    arrayR1[R1count].oneScore = one.score;
                    arrayR1[R1count].twoScore = two.score;
                    arrayR1[R1count].i = i;
                    for(int i=0;i<n;i++){
                        for(int j=0;j<n;j++){
                            arrayR1[R1count].array1[i][j] = array1[i][j];
                        }
                    }
                    R1count++;
                    U1count--;
                    one.NoOfMoves = arrayU1[U1count].oneMoves;
                    two.NoOfMoves = arrayU1[U1count].twoMoves;
                    one.score = arrayU1[U1count].oneScore;
                    two.score = arrayU1[U1count].twoScore;
                    i = arrayU1[U1count].i;
                    for(int i=0;i<n;i++){
                        for(int j=0;j<n;j++){
                            array1[i][j] = arrayU1[U1count].array1[i][j];
                        }
                    }
                    goto b;
                    //____________________________________________
                }
                        if((r1==2)&&(r2==2)&&(c1==2)&&(c2==2)){
                            //make the redo
                            if(R1count==0){
                            printf(red"Error"reset);
                            goto b;
                        }
                        R1count--;
                        one.NoOfMoves = arrayR1[R1count].oneMoves;
                        two.NoOfMoves = arrayR1[R1count].twoMoves;
                        one.score = arrayR1[R1count].oneScore;
                        two.score = arrayR1[R1count].twoScore;
                        i = arrayR1[R1count].i;
                        for(int i=0;i<n;i++){
                            for(int j=0;j<n;j++){
                                array1[i][j] = arrayR1[R1count].array1[i][j];
                            }
                        }
                        goto b;
                        //_____________________________

                    }
                    if((r1==3)&&(r2==3)&&(c1==3)&&(c2==3)){goto a;}

                // to save the round in the array
                arrayU1[U1count].oneMoves = one.NoOfMoves ;
                arrayU1[U1count].twoMoves = two.NoOfMoves ;
                arrayU1[U1count].oneScore = one.score ;
                arrayU1[U1count].twoScore = two.score ;
                arrayU1[U1count].i = i;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        arrayU1[U1count].array1[i][j] = array1[i][j];
                    }
                }
                U1count++;


                //___________________________________
                valid = Validate_Input(r1,r2,c1,c2,n,array1);
                while(!valid){
                    time = clock() - time;
                    seconds += time/CLOCKS_PER_SEC;
                    time = clock();
                    system("cls");
                    printf(yellow"not available\n"reset);
                    print_the_game(seconds,one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,n,array1);
                    printf(blue"\nenter number of row : "reset);
                    r1 = scanint();
                    printf(blue"enter number of column : "reset);
                    c1 = scanint();
                    printf(blue"enter number of row : "reset);
                    r2 = scanint();
                    printf(blue"enter number of column : "reset);
                    c2 = scanint();
                    if(r1==0 && c1==0 && r2==0 && c2==0){goto save1;}
                    valid = Validate_Input(r1,r2,c1,c2,n,array1);
                }
                one.NoOfMoves++;
                DrawTheLine(i,r1,r2,c1,c2,n,array1);
                flag = checkBox(i,n,array1);
                if(flag!=0){
                    i = RevI(i);
                    one.score += flag;
                }
            }
            else if(i==2){
               /**< computer will play */
               ComputerTurn(n,array1);
               print_the_game(seconds,one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,n,array1);
               two.NoOfMoves++;
               flag = checkBox(i,n,array1);
                if(flag!=0){
                    i = RevI(i);
                    two.score += flag;

                }
            }
            time = clock() - time;
            seconds += time/CLOCKS_PER_SEC;
            time = clock();
            i = RevI(i);
            int endgame = ENDGAME(one.NoOfMoves,two.NoOfMoves,n);
            if (endgame==1){
                if(one.score>two.score){
                    system("cls");
                    print_the_game(seconds,one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,n,array1);
                    printf(blue"\n\t\t %s won",one.name,reset);
                }
                else if(one.score<two.score){
                    system("cls");
                    print_the_game(seconds,one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,n,array1);
                    printf(red"\n\t\t %s won",two.name,reset);
                }
                else if(one.score=two.score){
                    system("cls");
                    print_the_game(seconds,one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,n,array1);
                    printf(yellow"\n\t\t Draw",two.name,reset);
                }
                strcpy(top[countTop].name , one.name );
                top[countTop].score = one.score;
                countTop++;
                FILE *fptr;
                fptr = fopen("C:/Users/King Fix/Desktop/test/top10.txt","w");
                fprintf(fptr,"%d ",countTop);
                for(int i=0;i<30;i++){

                    fprintf(fptr,"%s %d ",top[i].name,top[i].score);
                }
                fclose(fptr);
                printf(yellow"\n\tenter any number to return to the main menu : "reset);
                scanint();
                break;
                }
        }
    }
    //_____________________________________________________________________________________________________________________
    //_____________________________________________________________________________________________________________________
    //____________________________________________________________________________________________________________________
    else if((what==1)&&(n==5)){ //play easy vs friend
        if(U1count==0){
            // to save the round in the array
            arrayU1[U1count].oneMoves = one.NoOfMoves ;
            arrayU1[U1count].twoMoves = two.NoOfMoves ;
            arrayU1[U1count].oneScore = one.score ;
            arrayU1[U1count].twoScore = two.score ;
            arrayU1[U1count].i = i;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    arrayU1[U1count].array1[i][j] = array1[i][j];
                }
            }
            U1count++;
        }
        while(1){
        int flag=0;
        int r1,r2,c1,c2, valid;
        system("cls");
        print_the_game(seconds,one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,n,array1);
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
        save2:;
        if((r1==0)&&(r2==0)&&(c1==0)&&(c2==0)){
            printf(yellow"\n 1- save at file1 \n 2- save at file2 \n 3- save at file3 \n please enter a number : "reset);
            int k = scanint();
            while(k!=1 && k!=2 && k!=3){
                printf(red"\n please enter a valid number : "reset);
                k = scanint();
            }
            if(k==1){
                FILE *fptr;
                fptr = fopen("C:/Users/King Fix/Desktop/test/file1.txt","w");
                fprintf(fptr,"%d %d %d %d %d %d %d %d %s %s ",seconds,i,what,n,one.NoOfMoves,two.NoOfMoves,one.score,two.score,one.name,two.name);
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        fprintf(fptr,"%c ",array1[i][j]);
                    }
                }
                fclose(fptr);
            }
            if(k==2){
                FILE *fptr;
                fptr = fopen("C:/Users/King Fix/Desktop/test/file2.txt","w");
                fprintf(fptr,"%d %d %d %d %d %d %d %d %s %s ",seconds,i,what,n,one.NoOfMoves,two.NoOfMoves,one.score,two.score,one.name,two.name);
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        fprintf(fptr,"%c ",array1[i][j]);
                    }
                }
                fclose(fptr);
            }
            if(k==3){
                FILE *fptr;
                fptr = fopen("C:/Users/King Fix/Desktop/test/file3.txt","w");
                fprintf(fptr,"%d %d %d %d %d %d %d %d %s %s ",seconds,i,what,n,one.NoOfMoves,two.NoOfMoves,one.score,two.score,one.name,two.name);
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        fprintf(fptr,"%c ",array1[i][j]);
                    }
                }
                fclose(fptr);
            }
            time = clock() - time;
            seconds += time/CLOCKS_PER_SEC;
            time = clock();
            goto b;
        }
        if((r1==1)&&(r2==1)&&(c1==1)&&(c2==1)){
            //to make the undo
            if(U1count==0){
                printf(red"Error"reset);
                goto b;
            }
            arrayR1[R1count].oneMoves = one.NoOfMoves;
            arrayR1[R1count].twoMoves = two.NoOfMoves;
            arrayR1[R1count].oneScore = one.score;
            arrayR1[R1count].twoScore = two.score;
            arrayR1[R1count].i = i;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    arrayR1[R1count].array1[i][j] = array1[i][j];
                }
            }
            R1count++;
            U1count--;
            one.NoOfMoves = arrayU1[U1count].oneMoves;
            two.NoOfMoves = arrayU1[U1count].twoMoves;
            one.score = arrayU1[U1count].oneScore;
            two.score = arrayU1[U1count].twoScore;
            i = arrayU1[U1count].i;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    array1[i][j] = arrayU1[U1count].array1[i][j];
                }
            }
            goto b;
            //____________________________________________
        }
        if((r1==2)&&(r2==2)&&(c1==2)&&(c2==2)){
            //make the redo
            if(R1count==0){
                        printf(red"Error"reset);
                        goto b;
                    }
            R1count--;
            one.NoOfMoves = arrayR1[R1count].oneMoves;
            two.NoOfMoves = arrayR1[R1count].twoMoves;
            one.score = arrayR1[R1count].oneScore;
            two.score = arrayR1[R1count].twoScore;
            i = arrayR1[R1count].i;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    array1[i][j] = arrayR1[R1count].array1[i][j];
                }
            }
            goto b;
            //_____________________________

        }
        if((r1==3)&&(r2==3)&&(c1==3)&&(c2==3)){goto a;}

        //___________________________________
        // to save the round in the array
        arrayU1[U1count].oneMoves = one.NoOfMoves ;
        arrayU1[U1count].twoMoves = two.NoOfMoves ;
        arrayU1[U1count].oneScore = one.score ;
        arrayU1[U1count].twoScore = two.score ;
        arrayU1[U1count].i = i;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arrayU1[U1count].array1[i][j] = array1[i][j];
            }
        }
        U1count++;


        valid = Validate_Input(r1,r2,c1,c2,n,array1);
        while(!valid){
            time = clock() - time;
            seconds += time/CLOCKS_PER_SEC;
            time = clock();
            system("cls");
            printf(yellow"not available\n"reset);
            print_the_game(seconds,one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,n,array1);
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
            if(r1==0 && c1==0 && r2==0 && c2==0){goto save2;}
            valid = Validate_Input(r1,r2,c1,c2,n,array1);
        }
        if(i==1){
            one.NoOfMoves++;
            DrawTheLine(i,r1,r2,c1,c2,n,array1);
            flag = checkBox(i,n,array1);
            if(flag!=0){
                i = RevI(i);
                one.score += flag;
            }
        }
        else{
            two.NoOfMoves++;
            DrawTheLine(i,r1,r2,c1,c2,n,array1);
            flag = checkBox(i,n,array1);
            if(flag!=0){
              i =  RevI(i);
              two.score += flag;
            }
        }
        time = clock() - time;
        seconds += time/CLOCKS_PER_SEC;
        time = clock();
        i = RevI(i);
        int endgame = ENDGAME(one.NoOfMoves,two.NoOfMoves,n);
        if (endgame==1){
            if(one.score>two.score){
                system("cls");
                print_the_game(seconds,one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,n,array1);
                printf(blue"\n\t\t %s won",one.name,reset);
            }
            else if(one.score<two.score){
                system("cls");
                print_the_game(seconds,one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,n,array1);
                printf(red"\n\t\t %s won",two.name,reset);
            }
            else if(one.score=two.score){
                system("cls");
                print_the_game(seconds,one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,n,array1);
                printf(yellow"\n\t\t Draw",two.name,reset);
            }
            strcpy(top[countTop].name , one.name );
            top[countTop].score = one.score;
            countTop++;
            strcpy(top[countTop].name , two.name );
            top[countTop].score = two.score;
            countTop++;
            FILE *fptr;
            fptr = fopen("C:/Users/King Fix/Desktop/test/top10.txt","w");
            fprintf(fptr,"%d ",countTop);
            for(int i=0;i<30;i++){

                fprintf(fptr,"%s %d ",top[i].name,top[i].score);
            }
            fclose(fptr);
            printf(yellow"\n\tenter any number to return to the main menu : "reset);
            scanint();
            break;
            }
        }
    }
    //______________________________________________________________________________________________________________________
    //______________________________________________________________________________________________________________________
    //_______________________________________________________________________________________________________________________

    if((what==0)&&(n==9)){ //play medium vs computer
        while(1){
            flag = 0;
            int r1,r2,c1,c2, valid;
            system("cls");
            print_the_game(seconds,one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,n,array2);
            if(i==1){
                printf(blue"\nenter number of row : "reset);
                r1 = scanint();
                printf(blue"enter number of column : "reset);
                c1 = scanint();
                printf(blue"enter number of row : "reset);
                r2 = scanint();
                printf(blue"enter number of column : "reset);
                c2 = scanint();
                save3:;
                if((r1==0)&&(r2==0)&&(c1==0)&&(c2==0)){
                    printf(yellow"\n 1- save at file1 \n 2- save at file2 \n 3- save at file3 \n please enter a number : "reset);
                    int k = scanint();
                    while(k!=1 && k!=2 && k!=3){
                        printf(red"\n please enter a valid number : "reset);
                        k = scanint();
                    }
                    if(k==1){
                        FILE *fptr;
                        fptr = fopen("C:/Users/King Fix/Desktop/test/file1.txt","w");
                        fprintf(fptr,"%d %d %d %d %d %d %d %d %s %s ",seconds,i,what,n,one.NoOfMoves,two.NoOfMoves,one.score,two.score,one.name,two.name);
                        for(int i=0;i<n;i++){
                            for(int j=0;j<n;j++){
                                fprintf(fptr,"%c ",array2[i][j]);
                            }
                        }
                        fclose(fptr);
                    }
                    if(k==2){
                        FILE *fptr;
                        fptr = fopen("C:/Users/King Fix/Desktop/test/file2.txt","w");
                        fprintf(fptr,"%d %d %d %d %d %d %d %d %s %s ",seconds,i,what,n,one.NoOfMoves,two.NoOfMoves,one.score,two.score,one.name,two.name);
                        for(int i=0;i<n;i++){
                            for(int j=0;j<n;j++){
                                fprintf(fptr,"%c ",array2[i][j]);
                            }
                        }
                        fclose(fptr);
                    }
                    if(k==3){
                        FILE *fptr;
                        fptr = fopen("C:/Users/King Fix/Desktop/test/file3.txt","w");
                        fprintf(fptr,"%d %d %d %d %d %d %d %d %s %s ",seconds,i,what,n,one.NoOfMoves,two.NoOfMoves,one.score,two.score,one.name,two.name);
                        for(int i=0;i<n;i++){
                            for(int j=0;j<n;j++){
                                fprintf(fptr,"%c ",array2[i][j]);
                            }
                        }
                        fclose(fptr);
                    }
                    time = clock() - time;
                    seconds += time/CLOCKS_PER_SEC;
                    time = clock();
                    goto b;
                }
                if((r1==1)&&(r2==1)&&(c1==1)&&(c2==1)){
                    //to make the undo
                    if(U2count==0){
                        printf(red"Error"reset);
                        goto b;
                    }
                    arrayR2[R2count].oneMoves = one.NoOfMoves;
                    arrayR2[R2count].twoMoves = two.NoOfMoves;
                    arrayR2[R2count].oneScore = one.score;
                    arrayR2[R2count].twoScore = two.score;
                    arrayR2[R2count].i = i;
                    for(int i=0;i<n;i++){
                        for(int j=0;j<n;j++){
                            arrayR2[R2count].array1[i][j] = array2[i][j];
                        }
                    }
                    R2count++;
                    U2count--;
                    one.NoOfMoves = arrayU2[U2count].oneMoves;
                    two.NoOfMoves = arrayU2[U2count].twoMoves;
                    one.score = arrayU2[U2count].oneScore;
                    two.score = arrayU2[U2count].twoScore;
                    i = arrayU2[U2count].i;
                    for(int i=0;i<n;i++){
                        for(int j=0;j<n;j++){
                            array2[i][j] = arrayU2[U2count].array1[i][j];
                        }
                    }
                    goto b;
                    //____________________________________________
                }
                if((r1==2)&&(r2==2)&&(c1==2)&&(c2==2)){
                    //make the redo
                    if(R2count==0){
                        printf(red"Error"reset);
                        goto b;
                    }
                    R2count--;
                    one.NoOfMoves = arrayR2[R2count].oneMoves;
                    two.NoOfMoves = arrayR2[R2count].twoMoves;
                    one.score = arrayR2[R2count].oneScore;
                    two.score = arrayR2[R2count].twoScore;
                    i = arrayR2[R2count].i;
                    for(int i=0;i<n;i++){
                        for(int j=0;j<n;j++){
                            array2[i][j] = arrayR2[R2count].array1[i][j];
                        }
                    }
                    goto b;
                    //_____________________________

                }
                if((r1==3)&&(r2==3)&&(c1==3)&&(c2==3)){goto a;}
                // to save the round in the array
                arrayU2[U2count].oneMoves = one.NoOfMoves ;
                arrayU2[U2count].twoMoves = two.NoOfMoves ;
                arrayU2[U2count].oneScore = one.score ;
                arrayU2[U2count].twoScore = two.score ;
                arrayU2[U2count].i = i;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        arrayU2[U2count].array1[i][j] = array2[i][j];
                    }
                }
                U2count++;


                //___________________________________

                valid = Validate_Input(r1,r2,c1,c2,n,array2);
                while(!valid){
                    time = clock() - time;
                    seconds += time/CLOCKS_PER_SEC;
                    time = clock();
                    system("cls");
                    printf(yellow"not available\n"reset);
                    print_the_game(seconds,one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,n,array2);
                    printf(blue"\nenter number of row : "reset);
                    r1 = scanint();
                    printf(blue"enter number of column : "reset);
                    c1 = scanint();
                    printf(blue"enter number of row : "reset);
                    r2 = scanint();
                    printf(blue"enter number of column : "reset);
                    c2 = scanint();
                    if(r1==0 && c1==0 && r2==0 && c2==0){goto save3;}
                    valid = Validate_Input(r1,r2,c1,c2,n,array2);
                }
                one.NoOfMoves++;
                DrawTheLine(i,r1,r2,c1,c2,n,array2);
                flag = checkBox(i,n,array2);
                if(flag!=0){
                    i = RevI(i);
                    one.score += flag;
                }
            }
            else if(i==2){
               /**< computer will play */
               ComputerTurn(n,array2);
               print_the_game(seconds,one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,n,array2);
               two.NoOfMoves++;
               flag = checkBox(i,n,array2);
                if(flag!=0){
                    i = RevI(i);
                    two.score += flag;

                }
            }
            time = clock() - time;
            seconds += time/CLOCKS_PER_SEC;
            time = clock();
            i = RevI(i);
            int endgame = ENDGAME(one.NoOfMoves,two.NoOfMoves,n);
            if (endgame==1){
                if(one.score>two.score){
                    system("cls");
                    print_the_game(seconds,one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,n,array2);
                    printf(blue"\n\t\t %s won",one.name,reset);
                }
                else if(one.score<two.score){
                    system("cls");
                    print_the_game(seconds,one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,n,array2);
                    printf(red"\n\t\t %s won",two.name,reset);
                }
                else if(one.score=two.score){
                    system("cls");
                    print_the_game(seconds,one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,n,array2);
                    printf(yellow"\n\t\t Draw",two.name,reset);
                }
                strcpy(top[countTop].name , one.name );
                top[countTop].score = one.score;
                countTop++;
                FILE *fptr;
                fptr = fopen("C:/Users/King Fix/Desktop/test/top10.txt","w");
                fprintf(fptr,"%d ",countTop);
                for(int i=0;i<30;i++){

                    fprintf(fptr,"%s %d ",top[i].name,top[i].score);
                }
                fclose(fptr);
                printf(yellow"\n\tenter any number to return to the main menu : "reset);
                scanint();
                break;
                }
        }
    }
    //_____________________________________________________________________________________________________________________
    //_____________________________________________________________________________________________________________________
    //____________________________________________________________________________________________________________________
    else if((what==1)&&(n==9)){ //play mesium vs friend
        while(1){
        int flag=0;
        int r1,r2,c1,c2, valid;
        system("cls");
        print_the_game(seconds,one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,n,array2);
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
        save4:;
        if((r1==0)&&(r2==0)&&(c1==0)&&(c2==0)){
            printf(yellow"\n 1- save at file1 \n 2- save at file2 \n 3- save at file3 \n please enter a number : "reset);
            int k = scanint();
            while(k!=1 && k!=2 && k!=3){
                printf(red"\n please enter a valid number : "reset);
                k = scanint();
            }
            if(k==1){
                FILE *fptr;
                fptr = fopen("C:/Users/King Fix/Desktop/test/file1.txt","w");
                fprintf(fptr,"%d %d %d %d %d %d %d %d %s %s ",seconds,i,what,n,one.NoOfMoves,two.NoOfMoves,one.score,two.score,one.name,two.name);
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        fprintf(fptr,"%c ",array2[i][j]);
                    }
                }
                fclose(fptr);
            }
            if(k==2){
                FILE *fptr;
                fptr = fopen("C:/Users/King Fix/Desktop/test/file2.txt","w");
                fprintf(fptr,"%d %d %d %d %d %d %d %d %s %s ",seconds,i,what,n,one.NoOfMoves,two.NoOfMoves,one.score,two.score,one.name,two.name);
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        fprintf(fptr,"%c ",array2[i][j]);
                    }
                }
                fclose(fptr);
            }
            if(k==3){
                FILE *fptr;
                fptr = fopen("C:/Users/King Fix/Desktop/test/file3.txt","w");
                fprintf(fptr,"%d %d %d %d %d %d %d %d %s %s ",seconds,i,what,n,one.NoOfMoves,two.NoOfMoves,one.score,two.score,one.name,two.name);
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        fprintf(fptr,"%c ",array2[i][j]);
                    }
                }
                fclose(fptr);
            }
            time = clock() - time;
            seconds += time/CLOCKS_PER_SEC;
            time = clock();
            goto b;
        }
        //________________________________________________________________________
        if((r1==1)&&(r2==1)&&(c1==1)&&(c2==1)){
            //to make the undo
            if(U2count==0){
                printf(red"Error"reset);
                goto b;
            }
            arrayR2[R2count].oneMoves = one.NoOfMoves;
            arrayR2[R2count].twoMoves = two.NoOfMoves;
            arrayR2[R2count].oneScore = one.score;
            arrayR2[R2count].twoScore = two.score;
            arrayR2[R2count].i = i;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    arrayR2[R2count].array1[i][j] = array2[i][j];
                }
            }
            R2count++;
            U2count--;
            one.NoOfMoves = arrayU2[U2count].oneMoves;
            two.NoOfMoves = arrayU2[U2count].twoMoves;
            one.score = arrayU2[U2count].oneScore;
            two.score = arrayU2[U2count].twoScore;
            i = arrayU2[U2count].i;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    array2[i][j] = arrayU2[U2count].array1[i][j];
                }
            }
            goto b;
            //____________________________________________
        }
        if((r1==2)&&(r2==2)&&(c1==2)&&(c2==2)){
            //make the redo
            if(R2count==0){
                printf(red"Error"reset);
                goto b;
            }
            R2count--;
            one.NoOfMoves = arrayR2[R2count].oneMoves;
            two.NoOfMoves = arrayR2[R2count].twoMoves;
            one.score = arrayR2[R2count].oneScore;
            two.score = arrayR2[R2count].twoScore;
            i = arrayR2[R2count].i;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    array2[i][j] = arrayR2[R2count].array1[i][j];
                }
            }
            goto b;
            //_____________________________

        }
        if((r1==3)&&(r2==3)&&(c1==3)&&(c2==3)){goto a;}

        //___________________________________
        // to save the round in the array
        arrayU2[U2count].oneMoves = one.NoOfMoves ;
        arrayU2[U2count].twoMoves = two.NoOfMoves ;
        arrayU2[U2count].oneScore = one.score ;
        arrayU2[U2count].twoScore = two.score ;
        arrayU2[U2count].i = i;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arrayU2[U2count].array1[i][j] = array2[i][j];
            }
        }
        U2count++;


        //______________________________________________________________________
        valid = Validate_Input(r1,r2,c1,c2,n,array2);
        while(!valid){
            time = clock() - time;
            seconds += time/CLOCKS_PER_SEC;
            time = clock();
            system("cls");
            printf(yellow"not available\n"reset);
            print_the_game(seconds,one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,n,array2);
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
            if(r1==0 && c1==0 && r2==0 && c2==0){goto save4;}
            valid = Validate_Input(r1,r2,c1,c2,n,array2);
        }
        if(i==1){
            one.NoOfMoves++;
            DrawTheLine(i,r1,r2,c1,c2,n,array2);
            flag = checkBox(i,n,array2);
            if(flag!=0){
                i = RevI(i);
                one.score += flag;
            }
        }
        else{
            two.NoOfMoves++;
            DrawTheLine(i,r1,r2,c1,c2,n,array2);
            flag = checkBox(i,n,array2);
            if(flag!=0){
              i =  RevI(i);
              two.score += flag;
            }
        }
        time = clock() - time;
        seconds += time/CLOCKS_PER_SEC;
        time = clock();
        i = RevI(i);
        int endgame = ENDGAME(one.NoOfMoves,two.NoOfMoves,n);
        if (endgame==1){
            if(one.score>two.score){
                system("cls");
                print_the_game(seconds,one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,n,array2);
                printf(blue"\n\t\t %s won",one.name,reset);
            }
            else if(one.score<two.score){
                system("cls");
                print_the_game(seconds,one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,n,array2);
                printf(red"\n\t\t %s won",two.name,reset);
            }
            else if(one.score=two.score){
                system("cls");
                print_the_game(seconds,one.name,one.score,one.NoOfMoves,two.name,two.score,two.NoOfMoves,n,array2);
                printf(yellow"\n\t\t Draw",two.name,reset);
            }
            strcpy(top[countTop].name , one.name );
            top[countTop].score = one.score;
            countTop++;
            strcpy(top[countTop].name , two.name );
            top[countTop].score = two.score;
            countTop++;
            FILE *fptr;
            fptr = fopen("C:/Users/King Fix/Desktop/test/top10.txt","w");
            fprintf(fptr,"%d ",countTop);
            for(int i=0;i<30;i++){

                fprintf(fptr,"%s %d ",top[i].name,top[i].score);
            }
            fclose(fptr);
            printf(yellow"\n\tenter any number to return to the main menu : "reset);
            scanint();
            break;
            }
        }
    }
    //______________________________________________________________________________________________________________________
    //_______________________________________________________________________________________________________________________
    //_________________________________________________________________________________________________________________________
    goto a;
    return 0;
}


