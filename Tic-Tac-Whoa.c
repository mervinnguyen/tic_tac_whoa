/*
 * ==================================================
 *               TIC-TAC-WHOA GAME
 * ==================================================
 * Author: Mervin Nguyen
 * Course: EECS20 - Lab Assignment 5
 * Last Modified Date: September 15, 2025
 * Description: A console-based Tic-Tac-Toe game
 *              with menu system and game logic
 * ==================================================
 */

#include <stdio.h>      //library to printf and scanf
#include <unistd.h>     //library for sleep(delay) function 
#include <stdlib.h>     //library to exit game

//global variables
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';
char board[3][3];

//Function prototypes for function calls
void Menu();
void rulesAndInstructions();
void displayBoard();
void resetBoard();
void turnPlayer1();
void turnPlayer2();
char gameWinner();
void gameOver(char);
int checkSpaces();
int startGame();
void quit();

//Prompt the menu for the first item in the program
void Menu(){
    printf("\n\n--------------------------------------------------\n");
    printf("Welcome to Tic-Tac-Whoa! (EECS20-Lab Assignment 5)\n");
    printf("--------------------------------------------------\n\n");
    printf("Game Menu\n\n");
    printf("(1)Start a New Game\n");
    printf("(2)Rules and Instructions\n");
    printf("(3)Quit\n\n");
    printf("Enter an option(1-3):  ");
}
//Initialized Tic-Tac-Whoa game when user selects "Start a New Game"
int startGame() {
    char winner = ' ';                                          
    resetBoard();                                               //Reset board
    printf("\n\n");
    printf("Player 1 will be assigned to X.\n");
    sleep(1);
    printf("Player 2 will be assigned to O.\n");
    sleep(1);
    printf("Player 1 will start the game.\n");
    sleep(1);
    while(winner == ' ' && checkSpaces() != 0){                 //As long as there is no winner and there are open spaces, continue game 
       displayBoard(); 
       
       turnPlayer1();                                           //Start with Player1
       winner = gameWinner();                                   
       if(winner != ' ' || checkSpaces() == 0){                 //Check if Player1 is a winner OR if there is no open spaces, if so display winner
           break;
       }
       
       turnPlayer2();                                           //Check if Player2 is a winner OR if there is no open spaces, if so display winner
       winner = gameWinner();
       if(winner != ' ' || checkSpaces() == 0){
           break;
       }
    }
    
    displayBoard();
    gameOver(winner);
    
return 0;
}

//Prompts for user input to select from the main menu
[]
//printing out *option prints out value of *option
//printing out option prints out the value that *option is pointing to
//printing out &option prints out the address of *option
int main() {
    
    int option; //option is in memory and holds an integer
    Menu();
    
    scanf("%d", &option);   //scan for an integer and place it into the address of option
    
        //direct user to a specific page depending on their input from menu
        switch (option) {
            case 1:
                printf("Downloading a new game...\n\n"); 
                sleep(1);
                startGame();
                break;
                
            case 2:
                printf("Loading rules and instructions...\n"); 
                sleep(1);
                rulesAndInstructions();
                break;
            
            case 3:
                printf("Quitting Game...\n"); 
                sleep(1);
                exit(0);
                break;
            
            //create a case statement to handle incorrect/invalid inputs during menu option 
            default: 
                printf("Invalid Option! Please select 1, 2, or 3.");
                sleep(3);
                Menu();
                break;
      
        }
    

    return 0;

}

//Prompts description of rules and instructions when user selects "Rules and Instructions"
void rulesAndInstructions() {
    int option;
    
    printf("\n\n-----------------------------Tic-Tac-Whoa Rules and Instructions-------------------------------\n");
    printf("-----------------------------------------------------------------------------------------------\n\n");
    printf("Objective:\n");
    printf("Originated from the childhood game 'Tic-Tac-Toe', Tic-Tac Tow game is a classic two-player game \n");
    printf("where the goal is to be the first person to get three of your symbols in a row (either 'X' or 'O')\n");
    printf("in a row, horizontally, vertically, or diagonally, on a 3x3 grid.\n\n");
    printf("Game Setup:\n");
    printf("1) 3x3 GRID\n");
    printf("2) Two players take turns to make moves. One player chooses 'X' and the other person uses 'O'\n");
    printf("in a row, horizontally, vertically, or diagonally, on a 3x3 grid.\n\n\n");
    sleep(3);
    
    //Prompt user for the options of returning to menu, continue to game, quitting
    printf("(1)Back to Menu\n");
    printf("(2)Continue to game\n");
    printf("(3)Quit\n\n");
    printf("Enter an option(1-3)");
    scanf("%d", &option);
    
    //direct user to a specific page depending on their input from mneu
    switch (option) {
        case 1:
            printf("Returning to Main Menu...\n\n"); 
            sleep(2);
            main();
            break;
            
        case 2:
            printf("Loading contents of game...\n"); 
            sleep(2);
            startGame();
            break;
        
        case 3:
            printf("Quitting Game...\n"); 
            sleep(2);
            quit();
            break;

        default: 
            printf("Invalid Option! Please select 1,2, or 3!");
            sleep(3);
           rulesAndInstructions();
            break;
    }
}

//Display board using 2D arrays
void displayBoard(){
    printf("\n\n");
    printf("3  %c  |  %c   |  %c \n", board[0][0], board[0][1], board[0][2]);
    printf("  ————  —————  ————    \n"); 
    printf("2  %c  |  %c   |  %c \n", board[1][0], board[1][1], board[1][2]);
    printf("  ————  —————  ————    \n"); 
    printf("1  %c  |  %c   |  %c \n", board[2][0], board[2][1], board[2][2]);
    printf("    A     B     C     \n"); 
    printf("\n\n");
}

//Create a function to reset a board among starting a new game. Clears entire array back to empty spaces
void resetBoard(){
   for(int i = 0; i < 3; i++){
         for(int j = 0; j < 3; j++){
                board[i][j] = ' ';
            } 
        }
    }

//Function to keep track of the number of available spaces. Decrements after every player's turn to keep track of "Draw". 
int checkSpaces(){
    int freeSpaces = 9;
    
    for(int i = 0; i < 3; i++){
         for(int j = 0; j < 3; j++){
            if(board[i][j] != ' '){
                freeSpaces--;
            } 
        }
    }
    return freeSpaces;                          //Returns the number of current free spaces
}

//Prompts Player1 input
void turnPlayer1(){
    int row;
    int col;
    
    do{
        printf("Player 1's move: \n");
        printf("Enter a row 1-3: \n");
        scanf("%d", &row);
        row--;                              //Decrement the row to match rows 1-3, instead of 0-2 (from arrays)
    
        printf("Enter a column 1-3: ");
        scanf("%d", &col);
        col--;                              //Decrement the row to match cols 1-3, instead of 0-2 (from arrays)
        
        
        //Check if the slot in the array is empty. If it isn't empty reprompt user for input
        if(board[row][col] != ' '){
            printf("Incorrect Action, Try Again.\n");
        }
        //if it is empty, allow for player input
        else{
            board[row][col] = PLAYER1;
            break;
        }

    } while (board[row][col] != ' ');
        
}

//Same routine as turnPlayer1
void turnPlayer2(){
    int row;
    int col;
    
    do{
        printf("Player 2's move: \n");
        printf("Enter a row 1-3: \n");
        scanf("%d", &row);
        row--;
    
        printf("Enter a column 1-3: ");
        scanf("%d", &col);
        col--;
        
        
        //Check if the coordinate is empty or not
        if(board[row][col] != ' '){
            printf("Incorrect Action, Try Again.\n");
        }
        //if it is empty, allow for player input
        else{
            board[row][col] = PLAYER2;
            break;
        }

    } while (board[row][col] != ' ');
        
}

//Check for 3-in-a-row (rows, columns, diagonals )
char gameWinner(){
    //check each rows to see player has won
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){           //increments each row to check all 3 rows
            return board[i][0];
        }
    }
    //check each column to see if player has won
    for(int j = 0; j < 3; j++){
        if(board[0][j] == board[1][j] && board[0][j] == board[2][j]){           //increments each column to check all 3 col
            return board[0][j];
        }
    }
    //Check diagonal from top left to bottom right
    for(int k = 0; k < 3; k++){
        if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
            return board[0][0];
        }
    }
    //Check diagonal from top right to bottom left
    for(int l = 0; l < 3; l++){
        if(board[0][2] == board[1][1] && board[0][2] == board[2][0]){
            return board[0][2];
        }
    }
    return ' ';
    
}

//Prompt a message for the end of the game, whether it is a draw, or a winner
void gameOver(char winner) {
    int option;
    
    if(winner == PLAYER1){
        printf("Player1 Wins!\n\n");
    }
    else if (winner == PLAYER2){
        printf("Player2 Wins!\n\n");
    }
    else{
        printf("It's a DRAW! Play again!\n\n");
    }
    //Prompt for user to go back to menu, play a new game, or quit.
    sleep(1);
        printf("(1)Back to Menu\n");
        printf("(2)New Game\n");
        printf("(3)Quit\n\n");
        printf("Enter an option(1-3)");
        scanf("%d", &option);
    
        switch (option) {
            case 1:
                printf("Returning to Main Menu...\n\n"); 
                sleep(2);
                main();
                break;
                    
            case 2:
                printf("Loading contents of New Game...\n"); 
                sleep(2);
                startGame();
                break;
                
            case 3:
                printf("Quitting Game...\n"); 
                sleep(2);
                quit();
                break;
        
            default: 
                printf("Invalid Option! Please select 1,2, or 3!");
                sleep(3);
                rulesAndInstructions();
                break;
            }
}

//Quits the console application
void quit(){
    exit(0);
}