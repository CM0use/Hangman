/**
 ** This file is part of https://github.com/CM0use/Hangman
 ** Copyright 2023 CM0use <dilanuzcs@gmail.com>.
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

# ifndef HANGMAN_H
# define HANGMAN_H

#include <string>
# ifdef _WIN32
# define CLEAN_SCREEN system("CLS");
# elif __APPLE__
# define CLEAN_SCREEN system("clear");
# elif __linux__ 
# define CLEAN_SCREEN system("clear");
# endif

namespace Hangman {
    void wordSecret(std::string&, std::string&, std::string&);
    void board(const std::uint16_t&, const std::uint8_t& = 0);
    void input(std::string&);
    std::uint16_t hits(const std::string_view&);
}
# endif
