#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <unordered_map>
#include <vector>

class Tokenizer {
private:
    std::unordered_map<std::string, int> wordToToken;
    std::vector<std::string> tokenToWord;
    std::regex wordRegex;

public:
    Tokenizer() : wordRegex("\\b\\w+\\b") {}

    void tokenizeFile(const std::string &filename) {
        std::ifstream infile(filename);
        if (!infile) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        std::string text((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());

        std::sregex_iterator begin(text.begin(), text.end(), wordRegex);
        std::sregex_iterator end;
        for (auto it = begin; it != end; ++it) {
            std::string word = it->str();
            addWord(word);
        }
    }

    int addWord(const std::string &word) {
        if (wordToToken.find(word) == wordToToken.end()) {
            int token = static_cast<int>(tokenToWord.size());
            tokenToWord.push_back(word);
            wordToToken[word] = token;
            return token;
        }
        return wordToToken[word];
    }

    int getToken(const std::string &word) const {
        auto it = wordToToken.find(word);
        if (it != wordToToken.end()) {
            return it->second;
        }
        return -1;
    }

    std::string getWord(int token) const {
        if (token >= 0 && token < static_cast<int>(tokenToWord.size())) {
            return tokenToWord[token];
        }
        return "";
    }

    void outputTokens() const {
        std::cout << "Token mapping:" << std::endl;
        for (int i = 0; i < static_cast<int>(tokenToWord.size()); i++) {
            std::cout << i << " => " << tokenToWord[i] << std::endl;
        }
    }
};

int main() {
    Tokenizer tokenizer;
    std::string filename = "input.txt";

    tokenizer.tokenizeFile(filename);
    tokenizer.outputTokens();

    std::string queryWord = "example";
    int token = tokenizer.getToken(queryWord);
    if (token != -1)
        std::cout << "Token for word '" << queryWord << "': " << token << std::endl;
    else
        std::cout << "Word '" << queryWord << "' not found." << std::endl;

    int queryToken = 2;
    std::string word = tokenizer.getWord(queryToken);
    if (!word.empty())
        std::cout << "Word for token " << queryToken << ": " << word << std::endl;
    else
        std::cout << "Invalid token: " << queryToken << std::endl;

    return 0;
}
