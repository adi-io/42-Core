#include "Forms.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string gName, const int gGrade, const int gOGrade)
    : name(gName), val(false), grade(gGrade), oGrade(gOGrade), signatory("")
{
    if (gGrade < 1)
        throw Form::GradeTooHighException();
    if (gGrade > 150)
        throw Form::GradeTooLowException();
}

Form::~Form() {
    std::cout << "Erasing a Form!!" << std::endl;
}

Form::Form(const Form& other)
    : name(other.name), val(other.val), grade(other.grade), oGrade(other.oGrade), signatory(other.signatory)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        val = other.val;
        signatory = other.signatory;
        std::cout << "Form copy assignment operator called" << std::endl;
    }
    return *this;
}

std::string Form::getName() const { return name; }
bool Form::getIsSigned() const { return val; }
int Form::getGradeToSign() const { return grade; }
int Form::getGradeToExecute() const { return oGrade; }
std::string Form::getSignatory() const { return signatory; }

void Form::beSigned(Bureaucrat& chap) {
    if (chap.getRank() > this->grade) {
        throw Form::GradeTooLowException();
    }
    val = true;
    signatory = chap.getName();
    std::cout << "Form " << name << " has been signed by " << chap.getName() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form: " << f.getName()
       << "\nSigned: " << (f.getIsSigned() ? "Yes" : "No")
       << "\nGrade required to sign: " << f.getGradeToSign()
       << "\nGrade required to execute: " << f.getGradeToExecute();
    if (f.getIsSigned()) {
        os << "\nSigned by: " << f.getSignatory();
    }
    return os;
}
