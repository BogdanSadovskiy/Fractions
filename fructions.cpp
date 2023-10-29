#include <iostream>
#include<Windows.h>
using namespace std;



class Fraction {
private:
    int num;
    int den;
    int Fnum;
    int gcd(int a, int b) { //the greatest common devision
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
public:
 // 
    Fraction() {
        this->den = 1;
        this->num = 0;
        this->Fnum = 0;
    }
    Fraction (int num, int den) {
        if (den == 0) {
            cerr << "Error: Denominator cannot be zero." << std::endl;
            this->den = 1;
            this->num = 0;
            this->Fnum = 0;
        }
        else {
            int commonDivisor = gcd(std::abs(num), std::abs(den));
            num = num / commonDivisor;
            den = den / commonDivisor;
            if (den < 0) {
                num = -num;
                den = -den;
            }
            this->num = num;
            this->den = den;
        }
    }

    bool isFnum(int n, int d) {  //check if there is a full number in fruction
        if ((n / d) > 0) {
            return true;
        }
        else {
            return false;
        }
    }
    void PrintFnum() {
        this->Fnum = this->num / this->den;
        int _num = this->num % den;
        if (_num == 0) {
            cout << Fnum;
            return;
        }
        cout << Fnum << "*" << _num << "/" << den;
    }
    // Addition
    Fraction operator+(const Fraction& other) const {
        int numerator = num * other.den + other.num * den;
        int denominator = den * other.den;
        return Fraction(numerator, denominator);
    }

    // Subtraction
    Fraction operator-(const Fraction& other) const {
        int numerator = this->num * other.den - other.num * den;
       int denominator = den * other.den;
        return Fraction(numerator, denominator);
    }

    // Multiplication
    Fraction operator*(const Fraction& other) const {
        int numerator = num * other.num;
        int denominator = den * other.den;
        return Fraction(numerator, denominator);
    }

    // Division
    Fraction operator/(const Fraction& other) const {
        if (other.num == 0) {
            std::cerr << "Error: Division by zero." << std::endl;
            return Fraction(0, 1);
        }
        int numerator = num * other.den;
        int denominator = den * other.num;
        return Fraction(numerator, denominator);
    }

    // Display the fraction
    void display()  {
        if (isFnum(num, den)) {
            PrintFnum();
            return;
        }
        cout << num << "/" << den;
    }
};

void menu(string& d, int& numerator, int& denominator, int& _numerator, int& _denominator) {
    system("cls");
    cout << "Input numerator: "; cin >> numerator;
    cout << "Input denominator : "; cin >> denominator;

    system("cls");
    cout << numerator << "/" << denominator << endl;
    cout << "Action (+, -, *, /): "; cin >> d;

    system("cls");
    cout << numerator << "/" << denominator << " " + d + " " << endl;
    cout << "Input numerator: "; cin >> _numerator;
    cout << "Input denominator : "; cin >> _denominator;
}

int main() {
    int numerator;
    int denominator;
    int _numerator;
    int _denominator;
    string d;

   
    while (true) {
    menu(d, numerator, denominator, _numerator, _denominator);

    Fraction fraction1(numerator, denominator);
    Fraction fraction2(_numerator, _denominator); 
    system("cls");
    fraction1.display();
    cout << " " + d+ " ";
    fraction2.display();
    cout << " = " ;
    if (d == "+") {
        Fraction result = fraction1 + fraction2; 
        result.display();
    }
    else if (d == "-") {
        Fraction result = fraction1 - fraction2;
        result.display();
    }
    else if (d == "*") {
        Fraction result = fraction1 * fraction2;
        result.display();
    }
    else if (d == "/") {
        Fraction result = fraction1 / fraction2;
        result.display();
    }
    cout << endl;
    Sleep(2000);
    }
   
    
    



   

 
}
