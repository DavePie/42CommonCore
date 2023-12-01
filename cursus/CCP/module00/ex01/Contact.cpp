#include "Contact.hpp"

Contact::Contact()
{
}
void Contact::set(std::string f, std::string l, std::string n, std::string p, std::string s)
{
	this->firstname = f;
	this->lastname = l;
	this->nickname = n;
	this->phonenumber = p;
	this->darkestsecret = s;
}

int Contact::is_set()
{
	return this->firstname.length();
}

void Contact::print_contact()
{
	std::cout << "First name: " << this->firstname << std::endl;
	std::cout << "Last name: " << this->lastname << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phonenumber << std::endl;
	std::cout << "Darkest secret: " << this->darkestsecret << std::endl;
}

void Contact::print_contact_tab()
{
	this->print_element_tab(this->firstname);
	this->print_element_tab(this->lastname);
	this->print_element_tab(this->nickname);
}

void Contact::print_element_tab(std::string input)
{
	if (input.length() > 10)
	{
		std::cout << "|" << input.substr(0, 9) << ".";
		return ;
	}
	std::cout << "|";
	for (int i = input.length(); i < 10; i++)
		std::cout << " ";
	std::cout << input;

}
