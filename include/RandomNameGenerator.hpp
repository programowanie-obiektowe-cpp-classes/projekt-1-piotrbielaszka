#ifndef P1_CPP_LAB_RANDOMNAMEGENERATOR_HPP
#define P1_CPP_LAB_RANDOMNAMEGENERATOR_HPP

#include <array>
#include <format>
#include <random>

inline constexpr std::array first_names{"Ann",     "Andrew", "John",  "Jane",   "Bob",       "Alice",
                                        "Bertram", "Monica", "Laura", "Eric",   "Richard",   "Karen",
                                        "Clara",   "Rupert", "Bruce", "Martha", "Elizabeth", "Corey",
                                        "Nancy",   "Joe",    "Amy",   "Mike",   "James",     "Naomi"};

inline constexpr std::array last_names{
    "Hendricks", "Smith",  "Gates",     "Stein",   "Warren", "Booker",   "Williamson", "Walters", "Dunn",
    "Swanson",   "Knope",  "Haverford", "Ludgate", "Meagle", "Favreau",  "Vietor",     "Lovett",  "Pfeifer",
    "Rhodes",    "Abrams", "McFaul",    "Stone",   "Sisley", "Hanneman", "Holden",     "Nagata"};

inline constexpr std::array wydzialy{"WAiNS",
                                     "architektury",
                                     "budownictwa",
                                     "chemicznym",
                                     "EiTI",
                                     "fizyki",
                                     "GiK",
                                     "IChiP",
                                     "inzynierii ladowej",
                                     "inzynierii materialowej",
                                     "MiNI",
                                     "MEiL",
                                     "technologicznym",
                                     "mechatroniki",
                                     "SiMR",
                                     "transportu",
                                     "zarzadzania"};

inline auto getRandomName() -> std::string
{
    static auto prng       = std::mt19937{std::random_device{}()};
    auto        fnd        = std::uniform_int_distribution< std::size_t >{0, first_names.size() - 1};
    auto        lnd        = std::uniform_int_distribution< std::size_t >{0, last_names.size() - 1};
    const auto  first_name = first_names[fnd(prng)];
    const auto  last_name  = last_names[lnd(prng)];
    return std::format("{} {}", first_name, last_name);
}

inline auto getRandomWydzial() -> std::string
{
    static auto generator = std::mt19937{std::random_device{}()};
    auto        dist      = std::uniform_int_distribution< std::size_t >{0, wydzialy.size() - 1};
    const auto  wydz      = wydzialy[dist(generator)];
    return wydz;
}

inline bool getRandomObslugaWozka()
{
    static auto generator = std::mt19937{std::random_device{}()};
    auto        dist      = std::uniform_int_distribution< int >{0, 1};
    return dist(generator) == 1;
}

inline int getRandomFollows()
{
    static auto generator = std::mt19937{std::random_device{}()};
    auto        dist      = std::uniform_int_distribution< int >{0, 10000000};
    return dist(generator);
}

inline double getRandomBut()
{
    static auto generator = std::mt19937{std::random_device{}()};
    auto        dist      = std::uniform_int_distribution< int >{60, 88};
    double      but       = dist(generator);
    return but / 2;
}

#endif // P1_CPP_LAB_RANDOMNAMEGENERATOR_HPP
