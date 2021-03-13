#pragma once

#include "format.hpp"
#include "filePosition.hpp"
#include "token.hpp"

#include <vector>
#include <set>
#include <regex>
#include <string>
#include <cstdio>

class Lexer {
    private:
        static const std::string CHAR_DELIMS;
        static const std::set<std::string> DELIMITERS;
        static const std::set<std::string> KEYWORDS;
        static const std::regex IDENT_REGEX;

        std::string sourceStream;
        std::vector<Token> tokenStream;

        FilePosition currentPosition;
        std::string currentTokenBlock;
        
        bool updateFilePosition = false;
        bool inComment = false;
        bool error = false;

        void lexCharacter(const char character);
        bool filterComments(const char character);
        bool filterWhitespace(const char character);
        const Token makeToken(const std::string & tokenString);

        static bool isValidCharacter(const char character);
        static bool isCharDelimiter(const char character);
        static bool isDelimiter(const std::string & tokenString);
        static bool isKeyword(const std::string & tokenString);
        static bool isValue(const std::string & tokenString);
        static bool isIdentity(const std::string & tokenString);

        void printError(const std::string culprit);

    public:
        Lexer(std::string && sourceStream);
        const std::vector<Token> makeTokenStream();
        bool errorOccurred() const { return error; }
};