#include "Bureaucrat.hpp"
#include "AForms.hpp"

AForm::AForm(const std::string gName, const int gGrade, const int gOGrade)
    : name(gName), val(false), grade(gGrade), oGrade(gOGrade), signatory("")
{
    if (gGrade < 1 || gOGrade < 1)
        throw GradeTooHighException();
    if (gGrade > 150 || gOGrade > 150)
        throw GradeTooLowException();
}

AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(const AForm& other)
    : name(other.name), val(other.val), grade(other.grade), oGrade(other.oGrade), signatory(other.signatory)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        val = other.val;
        signatory = other.signatory;
        std::cout << "AForm copy assignment operator called" << std::endl;
    }
    return *this;
}

std::string AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return val; }
int AForm::getGradeToSign() const { return grade; }
int AForm::getGradeToExecute() const { return oGrade; }
std::string AForm::getSignatory() const { return signatory; }

void AForm::beSigned(Bureaucrat& chap) {
    if (chap.getRank() > this->grade) {
        throw GradeTooLowException();
    }
    val = true;
    signatory = chap.getName();
}

void AForm::signForm(Bureaucrat& chap) {
    try {
        beSigned(chap);
        std::cout << chap.getName() << " signed " << this->name << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << chap.getName() << " couldn't sign " << this->name
                 << " because " << e.what() << std::endl;
    }
}

void AForm::execute(Bureaucrat const & executor) const {
    if (!this->val) {
        throw FormNotSignedException();
    }
    if (executor.getRank() > this->oGrade) {
        throw GradeTooLowException();
    }
    this->action();
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "Form: " << f.getName()
       << "\nSigned: " << (f.getIsSigned() ? "Yes" : "No")
       << "\nGrade required to sign: " << f.getGradeToSign()
       << "\nGrade required to execute: " << f.getGradeToExecute();
    if (f.getIsSigned()) {
        os << "\nSigned by: " << f.getSignatory();
    }
    return os;
}
