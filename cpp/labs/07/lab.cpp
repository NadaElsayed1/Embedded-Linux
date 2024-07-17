#include <iostream>
#include <cstdlib>
#include <ctime>

class Battleship
{
private:
    bool board[5][5];
    int guesses;
    int maxGuesses;
    int locationX;
    int locationY;

public:
    Battleship(int maxGuesses) : maxGuesses(maxGuesses), guesses(0)
    {
        // Initialize the board to false
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                board[i][j] = false;
            }
        }

        // Seed the random number generator
        std::srand(std::time(0));

        // Place the battleship at a random location
        locationX = std::rand() % 5;
        locationY = std::rand() % 5;
    }

    bool guess(int x, int y)
    {
        guesses++;
        if (x == locationX && y == locationY)
        {
            std::cout << "Hit! You've sunk the battleship!" << std::endl;
            return true;
        }
        else
        {
            std::cout << "Miss." << std::endl;
            if (x == locationX)
            {
                std::cout << "Hint: The battleship is in row " << locationX << "." << std::endl;
            }
            else if (y == locationY)
            {
                std::cout << "Hint: The battleship is in column " << locationY << "." << std::endl;
            }
            std::cout << "Remaining guesses: " << (maxGuesses - guesses) << std::endl;
            return false;
        }
    }

    bool gameOver() const
    {
        return guesses >= maxGuesses;
    }

    int getGuesses() const
    {
        return guesses;
    }
};

int main()
{
    Battleship game(5);
    int x, y;
    bool found = false;

    std::cout << "Welcome to Battleship! You have 5 guesses to find the hidden battleship." << std::endl;

    while (!game.gameOver() && !found)
    {
        std::cout << "Enter your guess (row and column separated by a space): ";
        std::cin >> x >> y;

        if (x < 0 || x >= 5 || y < 0 || y >= 5)
        {
            std::cout << "Invalid input. Please enter values between 0 and 4." << std::endl;
            continue;
        }

        found = game.guess(x, y);

        if (!found && game.gameOver())
        {
            std::cout << "Game over! You've used all your guesses." << std::endl;
        }
    }

    if (found)
    {
        std::cout << "Congratulations! You found the battleship in " << game.getGuesses() << " guesses." << std::endl;
    }

    return 0;
}