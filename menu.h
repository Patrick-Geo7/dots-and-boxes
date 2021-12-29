void print_menu(){
    int i=0,j;
    printf(blue"\n\n\n\t\t\t\t\tWelcome to our game\n\n\t\t\t\t\t  Dots and Boxes\n\n\n\n\n");
    printf(yellow"\t 1 - new game\n \t 2 - load game\n \t 3 - top ten\n \t 4 - exit\n\n \t choose from 1 to 4 : "reset);
    while (1){
        i = scanint();
        if((i==1) || (i==2) || (i==3) || (i==4)){
            break;
        }
        else{
            printf(red"\t ERROR, please enter a number from 1 to 4 : "reset);
        }

    }
    system("cls");
    if(i==1){
        printf(yellow "\n\n\n\n\n\n\n\n\t 1 - Easy \n \t 2 - Medium \n \t 3 - Hard \n \t 4 - return to the main menu \n\t enter number from 1 to 4 : " reset);
        while(1){
            i = scanint();
            if(i==1){
                system("cls");
                printf(yellow"\n\n\n\t 1 - 1 player \n\t 2 - 2 players \n \t please enter a number: "reset);
                while(1){
                    i = scanint();
                    if(i==1){
                        //function to play easy against computer
                        return;
                    }
                    else if(i==2){
                        //function to play easy against your friend
                        return;
                    }
                    else{
                        printf(red"\t ERROR, please enter a number from 1 to 2 : "reset);
                    }
                }
            }
            else if(i==2){
                system("cls");
                printf(yellow"\n\n\n\t 1 - 1 player \n\t 2 - 2 players \n \t please enter a number: "reset);
                while(1){
                    i = scanint();
                    if(i==1){
                        //function to play medium against computer
                        return;
                    }
                    else if(i==2){
                        //function to play medium against your friend
                        return;
                    }
                    else{
                        printf(red"\t ERROR, please enter a number from 1 to 2 : "reset);
                    }
                }
            }
            else if(i==3){
                printf(yellow"\t 1 - 1 player \n\t 2 - 2 players \n \t please enter a number: "reset);
                while(1){
                    i = scanint();
                    if(i==1){
                        //function to play hard against computer
                        return;
                    }
                    else if(i==2){
                        //function to play hard against your friend
                        return;
                    }
                    else{
                        printf(red"\t ERROR, please enter a number from 1 to 2 : "reset);
                    }
                }
            }
            else if(i==4){
                system("cls");
                print_menu();
                }
            else{
                printf(red"\t ERROR, please enter a number from 1 to 4 : "reset);
            }
        }
    }
    else if(i==2){
        printf(yellow "\n\n\n\n\n\n\n\n\t 1 - Load game 1 \n \t 2 - Load game 2 \n \t 3 - Load game 3 \n \t 4 - return to the main menu \n\t Enter number from 1 to 4 : " reset);
        while(1){
            i = scanint();
            if(i==1){
                //load game one
                return;
            }
            else if(i==2){
                //load game two
                return;
            }
            else if(i==3){
                //load game three
                return;
            }
            else if(i==4){
                system("cls");
                print_menu();
            }
            else{
                printf(red"\t ERROR, please enter a number from 1 to 4 : "reset);
            }
        }
    }
    else if(i==3){
        printf(yellow "\n\n\n\n\n\n\n\n\n \t the top 10 are\n");
        printf("\t press enter to return to the main menu:"reset);
        scanint();
        system("cls");
        print_menu();

    }
    else if(i==4){
        exit(0);
    }
    return;
}

void print_the_game(char one[100],int oneScore,int oneMoves,char two[100],int twoScore,int twoMoves,int n,char array[n][n]){
    int i,j;
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t   ");
    for(i=0; i<n; i++){
        printf("%d ",i);
    }
    printf("\n");
    for(i=0; i<n; i++){

        printf("\t\t\t\t %d ",i);
        for(j=0; j<n;j++){
            if(array[i][j]=='a'){printf(blue"%c%c%c"reset,205,205,205);}  //horizontal
            else if(array[i][j]=='b'){printf(red"%c%c%c"reset,205,205,205);} //horizontal
            else if(array[i][j]=='1'){printf(blue"%c"reset,186);}
            else if(array[i][j]=='2'){printf(red"%c"reset,186);} //vertical
            else if(array[i][j]=='A'){printf(blueB"   "reset,186);}
            else if(array[i][j]=='B'){printf(redB"   "reset,186);}
            else if(array[i][j]=='s'){printf(" ");}
            else if(array[i][j]=='S'){printf("   ");}
            else if(array[i][j]=='d'){printf("%c",254);}
            //printf("%c",maro);
        }
        printf("\n");
    }
    printf("\n\n\n\n");
    printf(blue"player one name : %s \t\t"reset,one);
    printf(red"player two name : %s"reset,two);
    printf("\n");
    printf(blue"player one moves : %d \t\t\t"reset,oneMoves);
    printf(red"player two moves : %d"reset,twoMoves);
    printf("\n");
    printf(blue"player one score : %d \t\t\t"reset,oneScore);
    printf(red"player two score : %d"reset,twoScore);
    printf("\n");
    return;
}

