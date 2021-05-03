#pragma once
#include <string>

using int32 = int;
using FString = std::string;

struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EWordStatus
{
    Invalid_Status,
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase
};

class FBullCowGame
{
public:
    FBullCowGame();
    void reset(); //todo make return value
    int32 get_current_try();
    EWordStatus check_guess_validity(FString);
    FBullCowCount submit_valid_guess(FString);
private:
    int32 current_try;
    FString hidden_word;
    bool gameIsWon;
public:
    //Getters & Setters
    int32 get_current_try() const;
    void set_current_try(int32 current_try);
    int32 get_max_tries() const;
    int32 get_hidden_word_length() const;
    bool is_game_won() const;
private:
    bool is_isogram(FString) const;
    bool is_lower_case(FString) const;
};
