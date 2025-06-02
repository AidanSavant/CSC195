#pragma once

#include <iostream>
#include <numeric>
#include <stdexcept>

namespace mathlib {    
    template<typename T>
    class Fraction {
    public:
        Fraction() = default;

        // For operator overload copying:
        Fraction(const Fraction&) = default;
    
        Fraction(T top, T bottom) :
        m_top(top), m_bottom(bottom)
        {
            if(bottom == 0) {
                throw std::logic_error("Denominator cannot be 0!");
            }
        }

        double to_double() const {
            // NOTE: m_bottom can NEVER be 0 due to class invariant
            return (double)(m_top)/m_bottom;
        }

        Fraction simplify() {
            // NOTE: Omitting negative fractions, never was told to handle that
            int gcd = std::gcd(m_top, m_bottom);

            m_top /= gcd;
            m_bottom /= gcd;
        
            return *this;
        }

        Fraction operator+(const Fraction& rhs) const {
            return Fraction(
                m_top * rhs.m_bottom + rhs.m_top * m_bottom,
                m_bottom * rhs.m_bottom
            )
            .simplify();
        }

        Fraction operator-(const Fraction& rhs) const {
            return Fraction(
                m_top * rhs.m_bottom - rhs.m_top * m_bottom,
                m_bottom * rhs.m_bottom
            )
            .simplify();
        }

        Fraction operator*(const Fraction& rhs) const {
            return Fraction(
                m_top * rhs.m_top,
                m_bottom * rhs.m_bottom
            )
            .simplify();
        }

        Fraction operator/(const Fraction& rhs) const {
            return Fraction(
                m_top * rhs.m_bottom,
                m_bottom * rhs.m_top
            )
            .simplify();
        }

        bool operator==(const Fraction& rhs) const {
            return m_top == rhs.m_top && m_bottom == rhs.m_bottom;
        }

        bool operator!=(const Fraction& rhs) const {
            // Leverage existing ==operator
            return !(*this == rhs);
        }

        bool operator<(const Fraction& rhs) const {
            return m_top * rhs.m_bottom < rhs.m_top * m_bottom;
        }

        bool operator<=(const Fraction& rhs) const {
            return (*this < rhs || *this == rhs);
        }

        bool operator>(const Fraction& rhs) const {
            // The inversion of > is <=, so we can leverage existing operator<=
            return !(*this <= rhs);
        }

        bool operator>=(const Fraction& rhs) const {
            // The inversion of >= is <, so just leverage existing operator<
            return !(*this < rhs);
        }

        friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
            os << fraction.m_top << "/" << fraction.m_bottom;
            return os;
        }

        friend std::istream& operator>>(std::istream& is, Fraction& fraction) {
            char delim = 0; // Accepts '-' or '/'
            T top = 0, bottom = 1;

            is >> top >> delim >> bottom;
            
            if(is && (delim == '-' || delim == '/')) {
                if(bottom == 0) {
                    std::cerr << "Denominator cannot be 0!\n";
                    std::exit(1);
                }
                
                try {
                    fraction = Fraction(top, bottom);
                }
                
                catch(std::logic_error& e) {
                    std::cout << e.what() << '\n';
                    is.setstate(std::ios_base::failbit);
                }
            }

            else {
                is.setstate(std::ios_base::failbit);
            }

            return is;
        }

    private:
        T m_top, m_bottom;
    };
};

