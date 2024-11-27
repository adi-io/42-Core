#pragma once
#include "AForms.hpp"

class Intern {
private:
    struct FormType {
        std::string name;
        AForm* (*create)(const std::string&);
    };

public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target);
};
