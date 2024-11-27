#ifndef FORMS_HPP
#define FORMS_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form {
    private:
        const std::string name;
        bool val;
        const int grade;      // grade required to sign
        const int oGrade;     // grade required to execute
        std::string signatory;

    public:
        // Exception classes
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Form grade is too high";
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Form grade is too low";
                }
        };

        // Constructors & Destructor
        Form(const std::string gName, const int gGrade, const int gOGrade);
        ~Form();
        Form(const Form& other);
        Form& operator=(const Form& other);

        // Getters
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        std::string getSignatory() const;

        // Member functions
        void beSigned(Bureaucrat& chap);

        friend std::ostream& operator<<(std::ostream& os, const Form& f);
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
