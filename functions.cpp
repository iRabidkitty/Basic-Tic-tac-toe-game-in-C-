#include <iostream>
#include <vector>
#include <string>
#include <cctype>

void assign_spaces(std::vector <std::vector<std::string>>& main_square){
  std::string empty = "         ";                    // This string will be printed to fill the game board with empty spaces.
  for (int i = 0; i < main_square.size(); i++){       // This loop iterates in the 9 spaces of the game board.
    for(int j = 0; j < 5; j++){                       // Every space has 5 lines and every line can hold 8 characters.
        main_square[i].push_back(empty);              // Each space in the game board is fill with empty spaces.
    }
}

}
bool check_input(std::string& input,int& player,std::vector <int>& availability){
  for(char c : input){                                                        // This loop iterates in every string's character.
    if(!std::isdigit(c)){                                                     // If every character is not a digit a message will be printed and the function returns a falsy value.
      std::cout << "Invalid input. Must input a number from 1 to 9.\n";
      return false;
    }    
  }
  player = std::stoi(input);                                                  // Player is assigned the string value
           
  if (player < 1 || player > 9){                                              // If the value out of the 1-9 range, a message will be printed and the function returns a falsy value.
    std::cout << "Invalid input. Must input a number from 1 to 9.\n";
    return false;                
  }
  for(int i = 0; i < availability.size(); i ++){                              // This loop iterates in the vector availability;
    if(availability[i] == player){                                            // If the number in the vector matches the input value, a message will be printed and the function returns a falsy value.
      std::cout << "Already Occupied\n";
      return false;
    }
  }
  return true;                                                                // If the digit is correct, the function returns a true value.
}

void assign_move(std::vector <std::vector<std::string>>& main_square,int player,int move,std::vector <std::string>& assign_color){

  std::vector <std::string> cross; // Cross is for player 1. This will be assigned in the game board.
    cross.push_back("...   ...");
    cross.push_back(" ... ... ");
    cross.push_back("   ...   ");
    cross.push_back(" ... ... ");
    cross.push_back("...   ...");

  std::vector <std::string> circle; // Circle is for player 2. This will be assigned in the game board.
    circle.push_back("   ...   ");
    circle.push_back("...   ...");
    circle.push_back("...   ...");
    circle.push_back("...   ...");
    circle.push_back("   ...   ");

  std::string GREEN = "\033[32m"; // Green color is for player 2.
  std::string BLUE = "\033[34m";  // Blue color is for player 1.

  for(int i = 0; i < main_square.size();i++){         // This loop iterates over the game board vector.
    if(player - 1 == i){                              // Player is substracted by 1 so the value could be assigned correctly in the game board.
      if(move % 2 == 0){                              // Player 1 moves are odd numbers. Player 2 moves are even numbers.
        for(int j = 0; j < circle.size(); j++){       // Iterates over the 5 lines in a space of the game board. For player 2.  
          main_square[i][j] = circle[j];
        }
        assign_color[i] = GREEN;                      // Also assign the green color for every line for player 2.
      }
      else{
        for(int j = 0; j < cross.size(); j++){        // Iterates over the 5 lines in a space of the game board. For player 1.  
          main_square[i][j] = cross[j];
        }
        assign_color[i] = BLUE;                       // // Also assign the green color for every line for player 2.
      }
                
    }
  }
}

void print_result(std::vector <std::vector<std::string>> main_square, std::vector <std::string> assign_color){
  std::string YELLOW = "\033[33m"; // The game board grid is color yellow. 
  std::string RESET = "\033[0m";
    for(int i = 0; i < 5; i++){   // Every color and space is ready to be printed according to the assigned values the vectors have. 
      std::cout << assign_color[0] << main_square[0][i] << RESET << YELLOW << " | " << RESET << assign_color[1] <<  main_square[1][i] << RESET << YELLOW << " | " << RESET << assign_color[2] << main_square[2][i] << RESET << "\n";
    }
    std::cout << YELLOW <<"----------------------------------" << RESET << "\n";
    for(int i = 0; i < 5; i++){
      std::cout << assign_color[3] << main_square[3][i] << RESET << YELLOW << " | " << RESET << assign_color[4] <<  main_square[4][i] << RESET << YELLOW << " | " << RESET << assign_color[5] << main_square[5][i] << RESET << "\n";
    }
    std::cout << YELLOW <<"----------------------------------" << RESET << "\n";
    for(int i = 0; i < 5; i++){
      std::cout << assign_color[6] << main_square[6][i] << RESET << YELLOW << " | " << RESET << assign_color[7] <<  main_square[7][i] << RESET << YELLOW << " | " << RESET << assign_color[8] << main_square[8][i] << RESET << "\n";
    }
    std::cout << "\n";
}

bool game_progress(std::vector <int> player_spaces, bool& win){
  std::vector <std::vector<int>> victory = {{1,2,3},{1,4,7},{3,6,9},{7,8,9},{2,5,8},{4,5,6},{1,5,9},{3,5,7,}}; // These are the possible combinations for a victory in the game.
  for(int i = 0; i < victory.size(); i++){                         // Iterates over every vector of integers.
    int victory1count = 0;                                         // This value is set to 0 after checking every integer vector.
    for(int j = 0; j < victory[i].size(); j++){                    // Iterates over every integer.
      for(int k = 0; k < player_spaces.size(); k++){               // Iterates over every space assigned of the player.
        if(player_spaces[k] == victory[i][j]){                     // If the space assigned is equal to an integer in the vector, victory1count adds up.
          victory1count++;
        }
      }
    }            
    if(victory1count == 3){                                        // If victory reach to 3, it means the player assigned spaces are equal to a set of integers of the victory vector and won the game.
      win = true;
      return true;
    }
  }
  return false;
}