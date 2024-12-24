#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
    : n(0), i(0)
{}

void PhoneBook::add(void)
{
    std::string fields[5];
    std::string field_names[5] = {
        "First Name",
        "Last Name",
        "Nickname",
        "Phone Number",
        "Darkest Secret"
    };

    std::cout << "Please enter all of the following infomation." << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "- " << field_names[i] << ": ";
        if (!std::getline(std::cin, fields[i]))
            return ;
        if (fields[i] == "")
        {
            std::cerr << "phonebook: adding contact but field is empty, stop" << std::endl;
            return ;
        }
    }

    this->contacts[i].set_fields(fields);
    if (this->n < 8)
        this->n++;
    this->i = (this->i + 1) % 8;
    std::cout << "Contact added." << std::endl;
}

std::string trim(std::string s)
{
    if (s.size() <= 10)
        return (s);
    else
        return (s.substr(0, 9) + ".");
}

void display_row(std::string a, std::string b, std::string c, std::string d)
{
    std::cout << "|" << std::setw(10) << trim(a)
              << "|" << std::setw(10) << trim(b)
              << "|" << std::setw(10) << trim(c)
              << "|" << std::setw(10) << trim(d) << "|" << std::endl;
}

void display_contact(int i, Contact contact)
{
    std::string s(1, static_cast<char>(i + '0'));
    display_row(s, contact.first_name, contact.last_name, contact.nickname);
}

void PhoneBook::search(void)
{
    std::cout << std::endl;
    display_row("Index", "First Name", "Last Name", "Nickname");
    for (int i = 0; i < this->n; i++)
        display_contact(i, this->contacts[i]);
    std::cout << std::endl;
    
    if (this->n == 0)
    {
        std::cout << "Phonebook is empty." << std::endl;
        return ;
    }

    std::string input;
    std::cout << "Please enter the index of the entry to display." << std::endl
              << "- Index: ";
    if (!std::getline(std::cin, input))
        return ;
    if (input == "")
    {
        std::cerr << "phonebook: index not entered, stop" << std::endl;
        return ;
    }

    int i = input[0] - '0';
    if (!(0 <= i && i < this->n))
    {
        std::cerr << "phonebook: got bad index, stop" << std::endl;
        return ;
    }

    std::cout << "- First Name: " << contacts[i].first_name << std::endl
              << "- Last Name: " << contacts[i].last_name << std::endl
              << "- Nickname: " << contacts[i].nickname << std::endl
              << "- Phone Number: " << contacts[i].phone_number << std::endl
              << "- Darkest Secret: " << contacts[i].darkest_secret << std::endl;
}

void PhoneBook::main_loop(void)
{
    std::string command;

    while (true)
    {
        std::cout << "phonebook$ ";
        if (!std::getline(std::cin, command))
            return ;
        if (command == "")
            continue ;

        if (command == "ADD")
            this->add();
        else if (command == "SEARCH")
            this->search();
        else if (command == "EXIT")
        {
            std::cout << "EXIT" << std::endl;
            break ;
        }
        else
            std::cerr << "phonebook: " << command << ": command not found" << std::endl;
    }
}
