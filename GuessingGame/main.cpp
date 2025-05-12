#include <ctime>
#include <iostream>

class GuessingGame {
private:
    int m_guess;
    int m_secret;
    std::string m_user_buff;

public:
    GuessingGame() : m_guess(0), m_user_buff(std::string())
    {
        srand(time(NULL));
        m_secret = rand() % 10 + 1;
    }

    void start() {
        while(true) {
            std::cout << "Enter a number (1-10): ";
            std::cin >> m_user_buff;

            try {
                m_guess = std::stoi(m_user_buff);
            }
            catch(std::exception& e) {
                std::cerr << "Failure to parse guess! Try again!" << '\n';
                continue;
            }

            if(m_guess == m_secret) {
                std::cout << "Correct! You got it!\n";
                break;
            }
            else if(m_guess > m_secret) {
                std::cout << "Too high! Guess again!\n";
            }
            else if(m_guess < m_secret) {
                std::cout << "Too low! Guess again!\n";
            }
        }
    }
};

int main(void) {
    GuessingGame().start();
}

