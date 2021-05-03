#include <iostream>
#include <string>

#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

//Function Prototypes
void print_intro();
void play_game();
FText get_valid_guess();
bool ask_to_play_again();
void print_game_summary();

//Variables
FBullCowGame bcgame;

int32 main()
{
    do
    {
        print_intro();
        play_game();
    }
    while (ask_to_play_again());
    return 0;
}

void print_intro()
{
    std::cout << "Welcome to Bulls and Cows" << std::endl;
    std::cout << "Can you guess the " << bcgame.get_hidden_word_length() << " letter isogram ?" << std::endl;
}

void play_game()
{
    bcgame.reset();
    while (!bcgame.is_game_won() && bcgame.get_current_try() <= bcgame.get_max_tries())
    {
        FText guess = get_valid_guess();

        FBullCowCount bull_cows = bcgame.submit_valid_guess(guess);
        std::cout << "Bulls = " << bull_cows.Bulls << " , Cows = " << bull_cows.Cows << std::endl;
        std::cout << "Your guess is : " << guess << std::endl;
        std::cout << std::endl;
    }

    print_game_summary();
}

FText get_valid_guess()
{
    FText guess;
    EWordStatus status;
    do
    {
        std::cout << "Try " << bcgame.get_current_try() << "/" << bcgame.get_max_tries() << " : ";
        std::getline(std::cin, guess);
        status = bcgame.check_guess_validity(guess);
        switch (status)
        {
        case EWordStatus::Wrong_Length:
            std::cout << "Please enter a " << bcgame.get_hidden_word_length() << " letter word.";
            break;
        case EWordStatus::Not_Isogram:
            std::cout << "Please enter a word without repeating letters.";
            break;
        case EWordStatus::Not_Lowercase:
            std::cout << "Please enter all lowercase letters.";
            break;
        default:
            break;
        }
        std::cout << std::endl;
    }
    while (status != EWordStatus::OK);
    return guess;
}

bool ask_to_play_again()
{
    std::cout << "Do you want to play again (y/n) : ";
    FText response = "";
    getline(std::cin, response);

    return response[0] == 'y' || response[0] == 'Y';
}

void print_game_summary()
{
    if (bcgame.is_game_won())
    {
        std::cout << "You have won !";
    }
    else
    {
        std::cout << "You have lost !";
    }

    std::cout << std::endl;
}
