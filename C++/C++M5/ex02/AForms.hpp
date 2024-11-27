//#pragma once

#ifndef AForms_HPP
#define AForms_HPP

#include <string>
#include <iostream>

class	Bureaucrat;

class AForm {
    private:
        const std::string name;
        bool val;
        const int grade;
        const int oGrade;
        std::string signatory;

    public:
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Grade is too high";
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Grade is too low";
                }
        };
        class FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Form is not signed";
                }
        };

        // Orthodox Canonical Form
        AForm(const std::string gName, const int gGrade, const int gOGrade);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        // Getters
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        std::string getSignatory() const;

        // Member functions
        void beSigned(Bureaucrat& chap);
        void signForm(Bureaucrat& chap);

        // Pure virtual functions
        virtual void action() const = 0;
        virtual void execute(Bureaucrat const & executor) const = 0;
};

// Stream operator overload
std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
