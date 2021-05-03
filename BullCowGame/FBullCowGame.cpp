#include "FBullCowGame.h"

#include <iostream>
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame()
{
    reset();
}

void FBullCowGame::reset()
{
    current_try = 1;
    hidden_word = "planet";
    gameIsWon = false;
}

int FBullCowGame::get_current_try()
{
    return current_try;
}

EWordStatus FBullCowGame::check_guess_validity(std::string guess)
{
    if (!is_isogram(guess))
    {
        return EWordStatus::Not_Isogram;
    }
    if (!is_lower_case(guess))
    {
        return EWordStatus::Not_Lowercase;
    }
    if (guess.length() != get_hidden_word_length())
    {
        return EWordStatus::Wrong_Length;
    }

    return EWordStatus::OK;
}

FBullCowCount FBullCowGame::submit_valid_guess(FString guess)
{
    current_try++;
    FBullCowCount count;
    for (int32 i = 0; i < guess.length(); i++)
    {
        for (int32 j = 0; j < hidden_word.length(); j++)
        {
            if (guess[i] == hidden_word[j])
            {
                if (i == j)
                {
                    count.Bulls++;
                }
                else
                {
                    count.Cows++;
                }
            }
        }
    }

    if (count.Bulls == hidden_word.length())
    {
        gameIsWon = true;
    }
    else
    {
        gameIsWon = false;
    }
    return count;
}

int32 FBullCowGame::get_hidden_word_length() const
{
    return hidden_word.length();
}

bool FBullCowGame::is_game_won() const
{
    return gameIsWon;
}

int FBullCowGame::get_current_try() const
{
    return current_try;
}

void FBullCowGame::set_current_try(int current_try)
{
    this->current_try = current_try;
}

int FBullCowGame::get_max_tries() const
{
    TMap<int32, int32> WordLengthToMaxTries{
        {3, 5},
        {4, 5},
        {5, 5},
        {6, 5}
    };

    return WordLengthToMaxTries[hidden_word.length()];
}

bool FBullCowGame::is_isogram(std::string word) const
{
    //Single & Double Letter words are isograms   
    if (word.length() <= 1)
    {
        return true;
    }
    //Checking for isogram
    TMap<char, bool> charMap;
    for (auto letter : word)
    {
        letter = tolower(letter);
        if (charMap[letter])
        {
            return false;
        }
        charMap[letter] = true;
    }
    return true;
}

bool FBullCowGame::is_lower_case(FString word) const
{
    for (auto letter : word)
    {
        if (!islower(letter))
        {
            return false;
        }
    }
}
