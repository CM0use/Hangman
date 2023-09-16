/**
 ** This file is part of Hangman project
 ** Copyright 2023 CM0use dilanuzcs@gmail.com
 ** URL: https://github.com/CM0use/Hangman
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

# include <iostream>
# include <random>
# include <array>

# include "../header/hangman.h"

void Hangman::board(const std::uint16_t& attempts, const std::uint8_t& flag)
{
    static const std::array<std::string, 9> drawing 
    {
        "   +---+\n   |   |\n       |\n       |\n       |\n       |\n=========",
        "   +---+\n   |   |\n   O   |\n       |\n       |\n       |\n=========",
        "   +---+\n   |   |\n   O   |\n   |   |\n       |\n       |\n=========",
        "   +---+\n   |   |\n   O   |\n  /|   |\n       |\n       |\n=========",
        "   +---+\n   |   |\n   O   |\n  /|\\  |\n       |\n       |\n=========",
        "   +---+\n   |   |\n   O   |\n  /|\\  |\n  /    |\n       |\n=========",
        "   +---+\n   |   |\n   O   |\n  /|\\  |\n  / \\  |\n       |\n=========",
        "   +---+\n   |   |\n  [O   |\n  /|\\  |\n  / \\  |\n       |\n=========",
        "   +---+\n   |   |\n  [O]  |\n  /|\\  |\n  / \\  |\n       |\n========="
    };

    if (!flag)
        std::cout << drawing.at(attempts) << '\n';
    else
        std::cout << drawing.at(8) << '\n';
}

void Hangman::wordSecret(std::string& secret, std::string& secretEmpty, std::string& wrongLetters)
{
    static const std::array<std::string, 21> words
    {
        "System", "Mountain", "Sentence",
        "Country", "Different", "Second",
        "Sometimes", "Together", "Between",
        "Through", "Increase", "Change",
        "Something", "Problem", "Program",
        "Consider", "However", "Because",
        "Public", "Without", "Develop"
    };

    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<std::uint8_t> dist(0, words.size() -1);
    
    secret.assign(words.at(dist(engine)));
    secretEmpty.append(secret.size(), '_');
    wrongLetters.append(secret.size(), ' ');
}

void Hangman::input(std::string& letter)
{
    std::cin >> letter;
    while (letter.size() > 1)
    {
        std::cout << "Enter only one character per entry.\nGuess: ";
        std::cin >> letter;
    }
}

std::uint16_t Hangman::hits(const std::string_view& secretEmpty)
{
    std::uint16_t hits = 0;
    const std::uint16_t size = secretEmpty.size();
    for (std::uint16_t i = 0; i < size; i++)
        if (secretEmpty[i] != '_')
            hits++;
    return hits;
}
