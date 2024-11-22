#ifndef PROCESSING_H
#define PROCESSING_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>

#include <filesystem>

#include <fstream>
#include <sstream>


using std::vector;
using std::string;

class Card {
public:
    string suit;
    string rank;
    int value;

    Card(string suit, string rank, int value)
        : suit(suit), rank(rank), value(value) {}

    Card() : suit("Unknown"), rank("Unknown"), value(0) {}

    string yourCard() const {
        return rank + suit;
    }
};

class Deck {
private:
    vector<Card> cards;

public:
    Deck(bool includeJokers) {
        vector<string> suits = { "h", "d", "c", "s" };
        vector<string> ranks = { "2", "3", "4", "5", "6", "7", "8", "9", "10",
                                 "J", "Q", "K", "A" };


        

        for (const auto& suit : suits) {
            for (size_t i = 0; i < ranks.size(); ++i) {
                cards.emplace_back(suit, ranks[i], i + 2);
            }
        }

        if (includeJokers) {
            cards.emplace_back("None", "Joker", 0);
            cards.emplace_back("None", "Joker", 0);
        }

        shuffle();
    }

    void shuffle() {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(cards.begin(), cards.end(), g);
    }

    Card draw() {
        if (cards.empty()) {
            return Card("None", "None", 0); // Handle empty deck
        }
        Card topCard = cards.back();
        cards.pop_back();
        return topCard;
    }

    bool isEmpty() const {
        return cards.empty();
    }
};

class Game {
private:
    Deck deck;
    Card currentCard;
    Card nextCard;

public:
    Game(bool includeJokers) : deck(includeJokers) {}

    string getDealersCard() {
        if (deck.isEmpty()) return "Deck is empty!";
        currentCard = deck.draw();
        return currentCard.yourCard();
    }

    string showNextCard() {
        if (deck.isEmpty()) return "Deck is empty!";
        nextCard = deck.draw();
        return nextCard.yourCard();
    }

    bool processChoice(char choice) {
        if (nextCard.rank == "Joker") {
            return false; // Automatically lose on Joker
        }
        if ((choice == 'h' && nextCard.value > currentCard.value) ||
            (choice == 'l' && nextCard.value < currentCard.value)) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isDeckEmpty() const {
        return deck.isEmpty();
    }

    string advanceToNextCard() {
        if (deck.isEmpty()) return "Deck is empty!";
        currentCard = nextCard;
        return currentCard.yourCard();
    }
};

class ScoreManager {
private:
    vector<string> names;
    vector<int> scores;
    const size_t maxScores = 7;

public:
    // Reads high scores from a file
    void readHighScores(const std::string& filename) {
        names.clear();
        scores.clear();

        std::ifstream inFile(filename);
        if (!inFile) {
            std::cerr << "Error: Unable to open file for reading: " << filename << std::endl;
            return;
        }

        std::string line;
        while (std::getline(inFile, line)) {
            std::istringstream ss(line);
            std::string name;
            std::string scoreStr;
            if (std::getline(ss, name, ',') && std::getline(ss, scoreStr)) {
                names.push_back(name);
                scores.push_back(std::stoi(scoreStr));
            }
        }

        inFile.close();
    }

    // Updates the top scores with a new entry
    void updateTopScores(const std::string& playersName, int score) {
        names.push_back(playersName);
        scores.push_back(score);

        std::vector<size_t> indices(names.size());
        for (size_t i = 0; i < indices.size(); ++i) indices[i] = i;

        std::sort(indices.begin(), indices.end(), [this](size_t a, size_t b) {
            return scores[a] > scores[b];
            });

        std::vector<std::string> sortedNames;
        std::vector<int> sortedScores;

        for (size_t i = 0; i < indices.size(); ++i) {
            sortedNames.push_back(names[indices[i]]);
            sortedScores.push_back(scores[indices[i]]);
        }

        // Retain only the top 7 entries
        if (sortedNames.size() > maxScores) {
            sortedNames.resize(maxScores);
            sortedScores.resize(maxScores);
        }

        names = sortedNames;
        scores = sortedScores;
    }

    // Checks if a given score qualifies as a high score
    bool checkIfHighScore(int score) const {
        return scores.size() < maxScores || score > scores.back();
    }

    // Writes high scores to a file
    void writeHighScores(const std::string& filename) const {
        std::ofstream outFile(filename);
        if (!outFile) {
            std::cerr << "Error: Unable to open file for writing: " << filename << std::endl;
            return;
        }
        for (size_t i = 0; i < names.size(); ++i) {
            outFile << names[i] << "," << scores[i] << std::endl;
        }

        outFile.close();
    }


    vector<string> getScoreNames() {
        return names;
    }
    vector<int> getScores() {
        return scores;
    }

    void writeDemoDataToFile(const std::string& filename) {
        // Open the file in write mode
        std::ofstream outFile(filename);

        if (!outFile) {
            std::cerr << "Error: Unable to open file for writing: " << filename << std::endl;
            return;
        }

        // Demo data to write
        outFile << "Zoe,50" << std::endl;
        outFile << "Alice,45" << std::endl;
        outFile << "Bob,40" << std::endl;
        outFile << "Charlie,38" << std::endl;
        outFile << "David,35" << std::endl;
        outFile << "Eve,30" << std::endl;
        outFile << "Frank,25" << std::endl;

        // Close the file
        outFile.close();
    }


};
#endif // PROCESSING_H
