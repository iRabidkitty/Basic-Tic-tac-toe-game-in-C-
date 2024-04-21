#include <iostream>
#include <vector>
#include <string>
#include <cctype>

void assign_spaces(std::vector <std::vector<std::string>>& main_square);
bool check_input(std::string& input,int& player,std::vector <int>& availability);
void assign_move(std::vector <std::vector<std::string>>& main_square,int player,int move,std::vector <std::string>& assign_color);
void print_result(std::vector <std::vector<std::string>> main_square, std::vector <std::string> assign_color);
bool game_progress(std::vector <int> player_spaces,bool& win);