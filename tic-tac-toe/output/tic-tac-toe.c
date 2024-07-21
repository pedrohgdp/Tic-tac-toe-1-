#include <stdio.h>

void initialize_board(char board[3][3]){
    //This function put in every place of matriz a empty space
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}

void print_board(char board[3][3]){
    //This is function for print the board
    printf("0   1   2\n");
    for(int i = 0; i < 3; i++){
        //This loop is for the lines
        for(int j = 0; j < 3; j++){
            //For each loop of line there one loop for the column
            printf("%c", board[i][j]);
            if( j < 2){
                printf(" | ");
            }
        }
        printf("\n");
        if( i < 2){
            printf("----------\n");
        }
    }
}

int turn_x(char board[3][3], int line, int column){
    //This function is for player X's move
    while (1)
    //This is a infinite loop
    {
        printf("Turn of the plays who plays X \n");
        printf("Enter the line you want to play: ");
        scanf("%d", &line);
        printf("Enter the column you want to play: ");
        scanf("%d", &column);
        //We "listen" to the player's row and column and check if it is the size of the matrix
        if (line < 0 || line > 2 || column < 0 || column > 2){
            //If it leaves the matrix limit, we try again
            printf("Try again invalid position \n");
            continue;
        }
        //If the place where we want to put it is empty, we put X
        //And leave the loop
        if (board[line][column] == ' '){
            board[line][column] = 'X';
            break;
        //If there's something we'll tell you to try again
        }else{
            printf("Try again\n");
            continue;
        }
    }
    //return 0 ( that means we return to main function )
    return 0;
}

int turn_o(char board[3][3], int lines, int column){
    //This function is for player O's move
    //Does the same thing as the previous function
    while (1)
    {
        printf("Turn of the plays who plays O \n");
        printf("Enter the line you want to play: ");
        scanf("%d", &lines);
        printf("Enter the column you want to play: ");
        scanf("%d", &column);
        if (lines < 0 || lines > 2 || column < 0 || column > 2){
            printf("Try again invalid position\n");
            continue;
        }
        if (board[lines][column] == ' '){
            board[lines][column] = 'O';
            break;
        }else {
            printf("Try Again!\n");
            continue;
        }
    }
        return 0;
}


int check_x_win(char board[3][3]){
    //We check if someone won in the column, in the row or vertically, if yes, return 1
    if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X'){
        return 1;
    }else if(board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X'){
        return 1;
    }
    for(int i = 0; i < 3; i++){
        if(board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X'){
            return 1;
        }
        if(board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X'){
            return 1;
        }
    }
    //If no, return 0
    return 0;
}

int check_o_win(char board[3][3]){
    //Do the same thing
    if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'){
        return 1;
    }else if(board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O'){
        return 1;
    }
    for(int i = 0; i < 3; i++){
        if(board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O'){
            return 1;
        }
        if(board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O'){
            return 1;
        }
    }
    return 0;
}

int draw(char board[3][3]){
    int draw  = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != ' '){
                draw += 1;
            }
        }
    }
    if(draw == 9){
        return 1;
    }
    return 0;
}


int main(){
    //The main function here we actually create the variable board, row, column and player's turn
    char board[3][3];
    int lines;
    int column; 
    int playerToPlay = 1;

    //We start the board and welcome
    initialize_board(board);
    printf("WELCOME TO PEDRO’S TIC-TAC-TOE!!!!! \n");

    while(1){
        //Infinite Loop
        print_board(board);
        //Print the board
        //if player to play is equal 1 so turn of Player X
        if(playerToPlay == 1){
            //we call the function for player X plays
            turn_x(board, lines, column);
            //We change player to play variable for 0, for player O plays
            playerToPlay = 0;
            if(check_x_win(board)){
                //If it returns 1 (true), our function checks victory
                printf("X win\n");
                print_board(board);
                break;
            }else if(draw(board)){
                printf("\n");
                print_board(board);
                printf("Draw!!\n");
                break;
            }
        }else if(playerToPlay == 0){
            //Here is when the player to play is 0 This is the player's turn O
            turn_o(board, lines, column);
            //We change to player X 
            playerToPlay = 1;
            if(check_o_win(board)){
                printf("O win\n");
                print_board(board);
                break;
            }else if(draw(board)){
                printf("\n");
                print_board(board);
                printf("Draw\n");
                break;
            }
        }
    
    }

    printf("End of the game");
    return 0;
}