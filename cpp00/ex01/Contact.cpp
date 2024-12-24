#include "Contact.hpp"

void Contact::set_fields(std::string fields[5])
{
    this->first_name = fields[0];
    this->last_name = fields[1];
    this->nickname = fields[2];
    this->phone_number = fields[3];
    this->darkest_secret = fields[4];
}
