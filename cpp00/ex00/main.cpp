#include <iostream>
#include <cerrno>

void print_lower(char *str)
{
    while (*str)
    {
        std::cout << (char) std::toupper(*str);
        str++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 1; i < argc; i++)
            print_lower(argv[i]);
    }
    std::cout << std::endl;

    return (EXIT_SUCCESS);
}
