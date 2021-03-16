#pragma once

#include "defs/expressions.hpp"

#include "parser.hpp"

#include <map>

class TypeChecker {
    private:
        ExpPtr rootExpression;
        bool error = false;

        using Environment = std::map<std::string, Types::TypePtr>;

        ExpPtr eval(const ExpPtr & expression, Environment & environment, Types::TypePtr expectedType);
        
        ExpPtr evalProgram(const ExpPtr & expression, Environment environment, Types::TypePtr expectedType);
        ExpPtr evalLiteral(const ExpPtr & expression, Environment environment, Types::TypePtr expectedType);
        ExpPtr evalPrimitive(const ExpPtr & expression, Environment environment, Types::TypePtr expectedType);
        ExpPtr evalLet(const ExpPtr & expression, Environment environment, Types::TypePtr expectedType);
        ExpPtr evalReference(const ExpPtr & expression, Environment environment, Types::TypePtr expectedType);
        ExpPtr evalBranch(const ExpPtr & expression, Environment environment, Types::TypePtr expectedType);
        ExpPtr evalArgument(const ExpPtr & expression, Environment environment, Types::TypePtr expectedType);
        ExpPtr evalTypeclass(const ExpPtr & expression, Environment & environment, Types::TypePtr expectedType);
        ExpPtr evalApplication(const ExpPtr & expression, Environment environment, Types::TypePtr expectedType);
        ExpPtr evalListDefinition(const ExpPtr & expression, Environment environment, Types::TypePtr expectedType);
        ExpPtr evalTupleDefinition(const ExpPtr & expression, Environment environment, Types::TypePtr expectedType);
        ExpPtr evalBlockGet(const ExpPtr & expression, Environment environment, Types::TypePtr expectedType);
        ExpPtr evalMatch(const ExpPtr & expression, Environment environment, Types::TypePtr expectedType);

        bool compare(Types::TypePtr leftType, Types::TypePtr rightType);

        void addName(Environment & environment, std::string name, Types::TypePtr type);
        Types::TypePtr getName(const Token & token, Environment & environment, std::string name);

        void printMismatchError(const Token & token, const Types::TypePtr & type, const Types::TypePtr & expectedType);
        void printError(const Token & token, const std::string & errorMessage);

    public:
        explicit TypeChecker(const ExpPtr & rootExpression);
        
        ExpPtr check();
        bool errorOccurred() const { return error; }
};