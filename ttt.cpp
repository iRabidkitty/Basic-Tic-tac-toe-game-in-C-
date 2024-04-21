#include <iostream>
#include <vector>
#include <string>
#include <cctype>

#include "functions.hpp"


int main(){

// Variables
std::vector <std::vector<std::string>> main_square(9);
std::vector <std::string> assign_color(9);
std::vector <int> availability;
std::vector <int> player1_spaces(5);
std::vector <int> player2_spaces(4);
std::string input1, input2;
int player1, player2;
int assigner1 = 0; int assigner2 = 0;
int move = 0;
bool win = false; bool tie = false;



// Intro
std::cout << "This is Tic Tac Toe\n";
std::cout << "Select a number from 1 to 9.\n";

// Game begins

assign_spaces(main_square); // Assign empty spaces to the game board.

do{     
    // Player 1

    do{
        std::cout << "Player 1 X: "; // Player 1 is prompted to input a numeric value.
        std::cin >> input1;

        if(check_input(input1,player1,availability)){ // This function confirms if the value is a numeric value between 1-9 and it's not already occupied by any player.
            break;
        }
    }
    while(true);  

    
    player1_spaces[assigner1] = player1;    // The numeric value is assigned to a space in the game board.
    assigner1++;                            // Counts the players' moves.
    availability.push_back(player1);        // The numeric value is assigned so that can't be occupied.
    move++;                                 
    

    // Assign move to game board

    assign_move(main_square,player1,move,assign_color); // Player 1 is X and color blue. X is being replaced in an empty space in the game board according to the input value.

    //Print game board

    print_result(main_square,assign_color); // Prints the game board with the recent player's move.

    // Game progress

    if(game_progress(player1_spaces,win) && win == true){ // There are certain moves that can lead to a victory. Check function.
        std::cout << "Player 1 wins!\n";
        break;
    }

    if(move == 9 && win == false){ // Only for player 1 since this player is has 5 moves.
        std::cout << "Tie!\n";
        tie = true;
        break;
    }


    // Player 2

    do{ 
        std::cout << "Player 2 X: "; // Player 2 is prompted to input a numeric value.
        std::cin >> input2;

        if(check_input(input2,player2,availability)){ // This function confirms if the value is a numeric value between 1-9 and it's not already occupied by any player.
            break;
        }

    }   
    while(true);

    player2_spaces[assigner2] = player2;   // The numeric value is assigned to a space in the game board.
    assigner2++;                           // Counts the players' moves.
    availability.push_back(player2);       // The numeric value is assigned so that can't be occupied.
    move++;


    // Assign move to grid

    assign_move(main_square,player2,move,assign_color); // Player 2 is O and color green. X is being replaced in an empty space in the game board according to the input value.

    // Print result 2

    print_result(main_square, assign_color);    // Prints the game board with the recent player's move.

    // Game progress

    if(game_progress(player2_spaces,win) && win == true){   // There are certain moves that can lead to a victory. Check function.
        std::cout << "Player 2 wins!\n";
        break;
    }
  

}
while(win == false || tie == false);
    
}
