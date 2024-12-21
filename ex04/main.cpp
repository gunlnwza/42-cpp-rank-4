#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    (void) argc; (void) argv;

    if (argc != 4)
    {
        std::cerr << "Usage: ./ft_sed filename s1 s2" << std::endl;
        return (1);
    }

    std::ifstream file(argv[1]);
    if (file.fail())
    {
        std::cerr << "Error: cannot open '" << argv[1] << "' ("
            << std::strerror(errno) << ")" << std::endl;
        return (1);
    }

    std::string text = "";
    std::string line;
    while (getline(file, line))
        text += line + "\n";

    std::cout << text;

    return (0);
}
