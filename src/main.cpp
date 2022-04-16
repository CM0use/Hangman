
//          Copyright CM0use.
// Distributed under the Boost Software License, Version 1.0.
//    https://github.com/CM0use/Hangman/blob/main/LICENSE
//          https://www.boost.org/LICENSE_1_0.txt

# include <iostream>

# include "../header/hangman.h"

int main(void)
{
    std::string repeat;
    do
    {
        std::string secret, secretEmpty, wrongLetters, letter;
        Hangman::wordSecret(secret, secretEmpty, wrongLetters);
        std::uint16_t attempts{0};
        const std::uint16_t secretLength = secret.size();
        while (attempts < (secretLength/2))
        {
            CLEAN_SCREEN
            std::uint16_t letterCorrect{0};
            Hangman::board(attempts);
            std::cout << "Word: " << secretEmpty
                      << "\nIncorrect letters: " << wrongLetters
                      << "\nAttempts: "  << attempts << '/' << (secretLength/2)
                      << "\nGuess: ";

            Hangman::input(letter);

            for (std::uint16_t i = 0; i < secretLength; i++)
            {
                while (std::tolower(letter[0]) == std::tolower(secretEmpty[i])
                       || std::tolower(letter[0]) == std::tolower(wrongLetters[i]))
                {
                    i = 0;
                    std::cout << "You've already written that letter.\nChoose another one.\nGuess: ";
                    Hangman::input(letter);
                }
            }
            for (std::uint16_t i = 0; i < secretLength; i++)
            {
                if (std::tolower(letter[0]) == std::tolower(secret[i])) {
                    secretEmpty[i] = secret[i];
                    letterCorrect = 1;
                }
            }

            if (!letterCorrect) {
                wrongLetters.replace(wrongLetters.find(' '), 1, 1, letter[0]);
                attempts++;
            }

            if (secret == secretEmpty) {
                std::cout << "Yes! the secret word is \"" << secretEmpty
                          << "\" You won!\n";
                break;
            }

            if (attempts == (secretLength/2)) {
                CLEAN_SCREEN
                const std::uint16_t lenHits = Hangman::hits(secretEmpty);
                Hangman::board(attempts, 1);
                std::cout << "Word: " << secretEmpty
                          << "\nIncorrect letters: " << wrongLetters
                          << "\nAttempts: "  << attempts << '/' << (secretLength/2)
                          << "\nGuess: " << letter
                          << "\nYou have run out of attempts!"
                          << "\nAfter " << attempts
                          << " failed attempts and " << lenHits
                          << " hits, the word was \"" << secret << "\"\n";
            }
        }
        std::puts("Do you want to play again? [Y/y/S/s/n/N]");
        std::cin >> repeat;
        CLEAN_SCREEN
    } while (std::tolower(repeat[0]) == 'y' || std::tolower(repeat[0]) == 's');

    return EXIT_SUCCESS;
}
