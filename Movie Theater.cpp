#include <iostream>
#include <vector>
#include <string>

// Simulating an email sending functionality
void sendEmail(const std::string &email, const std::string &movie, int screen, int row, int col) {
    std::cout << "\nBooking confirmation email sent to " << email << ":\n";
    std::cout << "-------------------------------------------\n";
    std::cout << "Thank you for booking the movie \"" << movie << "\" at Screen " << screen << ".\n";
    std::cout << "Your seat is Row: " << row + 1 << ", Column: " << col + 1 << ".\n";
    std::cout << "Enjoy your movie!\n";
    std::cout << "-------------------------------------------\n";
}

class MovieTheater {
private:
    std::vector<std::vector<char>> seats;  // 2D vector to represent seats ('A' = available, 'B' = booked)
    int rows, cols;
    int bookedSeats;  // Track the number of seats booked

public:
    // Constructor to initialize the theater with the given number of rows and columns
    MovieTheater(int r, int c) : rows(r), cols(c), bookedSeats(0) {
        seats.resize(rows, std::vector<char>(cols, 'A'));  // All seats start as 'A' (Available)
    }

    // Display the seating arrangement
    void displaySeats() {
        std::cout << "\nSeating Arrangement: \n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << seats[i][j] << " ";  // 'A' for Available, 'B' for Booked
            }
            std::cout << std::endl;
        }
    }

    // Book a seat if it's available and within 90% capacity
    bool bookSeat(int row, int col, const std::string &email, const std::string &movie, int screen) {
        // Check if the capacity has reached 90%
        if ((bookedSeats + 1) > (rows * cols * 0.9)) {
            std::cout << "\nBooking not allowed. Capacity has reached more than 90% for Screen " << screen << ".\n";
            return false;
        }

        // Check if the seat is available
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            if (seats[row][col] == 'A') {
                seats[row][col] = 'B';  // Change seat to 'B' (Booked)
                bookedSeats++;
                std::cout << "Seat (" << row + 1 << "," << col + 1 << ") successfully booked!\n";
                sendEmail(email, movie, screen, row, col);  // Simulate sending an email after booking
                return true;
            } else {
                std::cout << "Seat is already booked.\n";
                return false;
            }
        } else {
            std::cout << "Invalid seat number. Please try again.\n";
            return false;
        }
    }

    // Get the number of booked seats
    int getBookedSeats() const {
        return bookedSeats;
    }

    // Get the total capacity
    int getTotalSeats() const {
        return rows * cols;
    }
};

class MovieTheaterSystem {
private:
    std::vector<MovieTheater> screens;  // Vector of screens (theaters)
    std::string movieName;              // Movie name shown on all screens

public:
    // Constructor to create a theater system with multiple screens
    MovieTheaterSystem(int numScreens, int rows, int cols, const std::string &movie)
        : movieName(movie) {
        for (int i = 0; i < numScreens; i++) {
            screens.push_back(MovieTheater(rows, cols));  // Initialize each screen with given rows and cols
        }
    }

    // Display the seating arrangement of a particular screen
    void displayScreenSeats(int screenNumber) {
        if (screenNumber >= 1 && screenNumber <= screens.size()) {
            std::cout << "\nDisplaying seating arrangement for Screen " << screenNumber << ":\n";
            screens[screenNumber - 1].displaySeats();
        } else {
            std::cout << "Invalid screen number.\n";
        }
    }

    // Book a seat in a particular screen
    void bookScreenSeat(int screenNumber, int row, int col, const std::string &email) {
        if (screenNumber >= 1 && screenNumber <= screens.size()) {
            screens[screenNumber - 1].bookSeat(row, col, email, movieName, screenNumber);
        } else {
            std::cout << "Invalid screen number.\n";
        }
    }
};

int main() {
    int numScreens = 3;
    int rows = 5, cols = 5;  // Number of rows and columns in each screen
    std::string movie = "The Matrix Resurrections";

    // Create a MovieTheaterSystem with 3 screens
    MovieTheaterSystem theaterSystem(numScreens, rows, cols, movie);

    int choice;
    do {
        std::cout << "\nMovie Seat Booking System for \"" << movie << "\"\n";
        std::cout << "1. View seating arrangement for a screen\n";
        std::cout << "2. Book a seat in a screen\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int screen;
                std::cout << "Enter screen number (1 to " << numScreens << "): ";
                std::cin >> screen;
                theaterSystem.displayScreenSeats(screen);  // Display seats for a particular screen
                break;
            }
            case 2: {
                int screen, row, col;
                std::string email;
                std::cout << "Enter screen number (1 to " << numScreens << "): ";
                std::cin >> screen;
                std::cout << "Enter row number (1 to " << rows << "): ";
                std::cin >> row;
                std::cout << "Enter column number (1 to " << cols << "): ";
                std::cin >> col;
                std::cout << "Enter your email address: ";
                std::cin >> email;

                theaterSystem.bookScreenSeat(screen, row - 1, col - 1, email);  // Book seat in the chosen screen
                break;
            }
            case 3:
                std::cout << "Exiting the system...\n";
                break;

            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
