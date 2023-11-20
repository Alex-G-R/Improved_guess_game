#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <fstream>


void print_array(std::vector<int> vector);
void guessGame(int anwser, std::vector<int> &guesses);
int show_menu(int anwser, std::vector<int> guesses);
void save_score(std::vector<int> guesses);
void print_leaderboard();
void clear_leaderboard();


int main(){

    /* Get a seed and generate a number */
    srand(time(NULL));
    int anwser = rand() % 20 + 1;

    /* Declare a new guesses vector */
    std::vector<int> guesses;
    
    show_menu(anwser, guesses);

    return 0;
}

void guessGame(int anwser, std::vector<int> &guesses){

    std::cout << "Please provide your guess: \n";
    int guess;
    std::cin >> guess;


    if(guess == anwser){
        guesses.push_back(guess);
        std::cout << "Congratulations! You won in only " << guesses.size() << " guesses. \n";
        std::cout << "Guess history: "; print_array(guesses); std::cout << std::endl;
        save_score(guesses);
        print_leaderboard();
        main();
    } else if(guess > anwser){
        std::cout << "Your guess is too high, try again! \n";
        guesses.push_back(guess);

        guessGame(anwser, guesses);
    } else if(guess < anwser){
        std::cout << "Your guess is too low, try again! \n";
        guesses.push_back(guess);

        guessGame(anwser, guesses);
    }
}

void print_array(std::vector<int> vector) {
    for (int i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << " ";
    }
}

int show_menu(int anwser, std::vector<int> guesses) {
    std::cout << "| - - - - Main Menu - - - - | \n";
    std::cout << "|                           | \n";
    std::cout << "| 1 - Start a guess game    | \n";
    std::cout << "|                           | \n";
    std::cout << "| 2 - Clear leaderboard     | \n";
    std::cout << "|                           | \n";
    std::cout << "| 3 - Show leaderboard      | \n";
    std::cout << "|                           | \n";
    std::cout << "| 4 - Quit the program      | \n";
    std::cout << "|___________________________| \n";
    std::cout << "Please choose one option:  \n";

    /* Get the users option on choice */
    int option;
    std::cin >> option;

    /* Depening on the users option, start the game or turn the program off */
    if(option == 1)
    {
        std::cout << "You are now guessing a number betwen 1 and 20, good luck! \n";
        guessGame(anwser, guesses);
    } 
    else if(option == 2)
    {
        std::cout << "Leaderboard cleared \n";
        clear_leaderboard();
        show_menu(anwser, guesses);
    } 
    else if(option == 3)
    {
        print_leaderboard();
        show_menu(anwser, guesses);
    } 
    else if (option == 4)
    {
        std::cout << "Shutting down the program. \n";
        return -1;
    } 
    else 
    {
        std::cout << "Option unaveliabale. \n";
        return -1;
    }
}

void save_score(std::vector<int> guesses){
    std::ofstream leaderboard ("leaderboard.txt", std::ios::app);
    leaderboard << guesses.size() << "\n";
}

void clear_leaderboard(){
    std::ofstream leaderboard ("leaderboard.txt");
    leaderboard << "";
}

void print_leaderboard(){
    std::ifstream leaderboard("leaderboard.txt");

    std::vector<std::string> scores;

    std::string input;
    while( leaderboard >> input){
        scores.push_back(input);
    }

    std::cout << "Previous scores: \n";
    for(std::string n : scores){
        std::cout << n << " ";
    }
    std::cout << "\n";
}