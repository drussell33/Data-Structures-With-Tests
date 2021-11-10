#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include "array.hpp"
#include "adt_exception.hpp"

using namespace data_structures;

template <class T>
class Polynomial
{
public:
	Polynomial() = delete; // Delete the default constructor
	Polynomial(const T* coefficients, const size_t& number_of_coefficients) noexcept(false); // The constructor to initialize a polynomial with the given coefficient array and number of coefficients  
	Polynomial(Array<T> coefficients, const size_t& number_of_coefficients) noexcept(false); // The constructor to initialize a polynomial with the given coefficient array and number of coefficients  
	Polynomial(const Polynomial& polynomial) noexcept(false); // The copy constructor
	Polynomial(Polynomial&& polynomial) noexcept; // The move constructor
	~Polynomial() = default; //The trivial deconstructor       

	Polynomial operator+(const Polynomial& polynomial) const noexcept(false); // Add two polynomials
	Polynomial operator-(const Polynomial& polynomial) const noexcept(false); // Subtract two polynomials
	Polynomial& operator=(const Polynomial& polynomial) noexcept(false); // Assignment operator
	Polynomial& operator=(Polynomial&& polynomial) noexcept;

	friend bool operator==(const Polynomial& lhs, const Polynomial& rhs) noexcept(false) 	// Determine if two polynomials are equal
	{
		if (lhs.NumberOfCoefficients() != rhs.NumberOfCoefficients())
			return false;

		for (auto i = 0u; i < lhs.NumberOfCoefficients(); ++i)
			if (lhs.coefficients_[i] != rhs.coefficients_[i])
				return false;

		return true;
	}

	Array<T> Coefficients() const noexcept; // Return a copy of the coefficient array
	Array<T>& Coefficients() noexcept; // Return a reference to the coefficient array for modification
	size_t NumberOfCoefficients() const noexcept; // Return the number of coefficients in this polynomial

private:
	Array<T> coefficients_; // This will be the array where we store the coefficients 
	size_t number_of_coefficients_{ 0 }; // This is the number of coefficients of the polynomial  
};


template <class T>
Polynomial<T>::Polynomial(const T* coefficients, const size_t& number_of_coefficients) noexcept(false)
	:coefficients_(number_of_coefficients), number_of_coefficients_(number_of_coefficients)
{
	for (auto i = 0u; i < NumberOfCoefficients(); ++i)
	{
		coefficients_[i] = coefficients[i];
	}

}

template <class T>
Polynomial<T>::Polynomial(Array<T> coefficients, const size_t& number_of_coefficients) noexcept(false)
	:coefficients_(number_of_coefficients), number_of_coefficients_(number_of_coefficients)
{
	for (auto i = 0u; i < NumberOfCoefficients(); ++i)
	{
		coefficients_[i] = coefficients[i];
	}
}

template <class T>
Polynomial<T>::Polynomial(const Polynomial& polynomial) noexcept(false)
{
	*this = polynomial;
}

template <class T>
Polynomial<T>::Polynomial(Polynomial&& polynomial) noexcept
{
	*this = polynomial;
}

template <class T>
Polynomial<T> Polynomial<T>::operator+(const Polynomial& polynomial) const noexcept(false)
{
	Polynomial<T> result(*this);
	auto loop_counter = polynomial.NumberOfCoefficients();

	if(this->NumberOfCoefficients() < polynomial.NumberOfCoefficients())
	{
		result = polynomial;
		loop_counter = this->NumberOfCoefficients();
	}
		

	for (auto i = 0u; i < loop_counter; ++i)
	{
		result.coefficients_[i] = this->coefficients_[i] + polynomial.coefficients_[i];
	}
	return result;
}

template <class T>
Polynomial<T> Polynomial<T>::operator-(const Polynomial& polynomial) const noexcept(false)
{
	Polynomial<T> result(*this);
	auto loop_counter = polynomial.NumberOfCoefficients();

	if (this->NumberOfCoefficients() < polynomial.NumberOfCoefficients())
	{
		result = polynomial;
		loop_counter = this->NumberOfCoefficients();
	}

	for (auto i = 0u; i < loop_counter; ++i)
	{
		result.coefficients_[i] = this->coefficients_[i] - polynomial.coefficients_[i];
	}
	return result;
}

template <class T>
Polynomial<T>& Polynomial<T>::operator=(const Polynomial& polynomial) noexcept(false)
{
	if(this != &polynomial)
	{
		coefficients_ = polynomial.coefficients_;
		number_of_coefficients_ = polynomial.number_of_coefficients_;
	}
	return *this;
}

template <class T>
Polynomial<T>& Polynomial<T>::operator=(Polynomial&& polynomial) noexcept
{
	if (this != polynomial)
	{
		coefficients_ = std::move(polynomial.coefficients_);
		number_of_coefficients_ = polynomial.number_of_coefficients_;
	}
	return *this;
}

template <class T>
Array<T> Polynomial<T>::Coefficients() const noexcept
{
	return coefficients_;
}

template <class T>
Array<T>& Polynomial<T>::Coefficients() noexcept
{
	return &coefficients_;
}

template <class T>
size_t Polynomial<T>::NumberOfCoefficients() const noexcept
{
	return number_of_coefficients_;
}
#endif
