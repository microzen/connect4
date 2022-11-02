#include <string>
class Complex
{
private:
    int _real = 0;
    int _imaginary = 0;

public:
    Complex(double, double);
    Complex();
    Complex* Add(Complex *);
    Complex* Subtraction(Complex *);
    // std::string ToString();
    ~Complex();
};
Complex::Complex()
{
    this->_real = 0;
    this->_imaginary = 0;
}
Complex::Complex(double real, double imaginary)
{
    this->_real = real;
    this->_imaginary = imaginary;
}
Complex* Complex::Add(Complex *compl2)
{
    return compl2;
    // compl2->_imaginary;
    // if(compl2 == this){
    //     return compl2;
    // }else{

    // }
    // (this->_real + this->_imaginary) + compl2->Add();
    // return this->_real + this->_imaginary;
}
Complex* Complex::Subtraction(Complex *compl2)
{
    return compl2;
    // return this->_real / this->_imaginary;
}

// ComolexTest.Java
// int main(int argc, char const *argv[])
// {
//     Complex *com1 = new Complex(9.5, 7.7);
//     Complex *com2 = new Complex(1.2, 3.1);
//     com1->Add(com2);
//     com1->Subtraction(com2);

//     com2->Add(com1);
//     com2->Subtraction(com1);
//     // System.out.print(com.Add());
//     return 0;
// }

Complex::~Complex()
{
}
