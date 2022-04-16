
//          Copyright CM0use.
// Distributed under the Boost Software License, Version 1.0.
//    https://github.com/CM0use/Hangman/blob/main/LICENSE
//          https://www.boost.org/LICENSE_1_0.txt

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
