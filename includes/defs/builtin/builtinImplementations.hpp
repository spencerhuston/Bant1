#pragma once

#include "../values.hpp"
#include "../token.hpp"
#include "../../utils/format.hpp"
#include "builtinDefinitions.hpp"

class BuiltinImplementations {
    private:
        template<class ValueType>
        static std::shared_ptr<ValueType> getArgumentValue(const int & index, Values::FunctionValuePtr functionValue, Values::Environment & environment);
        
        static Values::ListValuePtr makeListType(Values::ListValuePtr listValue, std::vector<Values::ValuePtr> listData);

        static Values::ValuePtr insertBuiltin(const Token & token, Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr removeBuiltin(const Token & token, Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr replaceBuiltin(const Token & token, Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr pushFrontBuiltin(const Token & token, Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr pushBackBuiltin(const Token & token, Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr insertInPlaceBuiltin(const Token & token, Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr removeInPlaceBuiltin(const Token & token, Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr replaceInPlaceBuiltin(const Token & token, Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr pushFrontInPlaceBuiltin(const Token & token, Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr pushBackInPlaceBuiltin(const Token & token, Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr frontBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr backBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr headBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr tailBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr combineBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr appendBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr sizeBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr rangeBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr isEmptyBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr sumBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr productBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr maxBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr minBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr sortlhBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr sorthlBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr containsBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr findBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr mapBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr filterBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr fillBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr reverseBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr foldlBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr foldrBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr zipBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr unionBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr intersectBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr equalsBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr intToCharBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr charToIntBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr stringToCharListBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr charListToStringBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr printIntBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr printBoolBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr printListBuiltin(const Token & token, Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr print2TupleBuiltin(const Token & token, Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr print3TupleBuiltin(const Token & token, Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr print4TupleBuiltin(const Token & token, Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr readCharBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr printCharBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr readStringBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr printStringBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);
        static Values::ValuePtr haltBuiltin(Values::FunctionValuePtr functionValue, Values::Environment & environment);

        static std::shared_ptr<Values::NullValue> nullValue;
        static bool error;

        static void printTuple(const Token & token, const std::vector<Values::ValuePtr> & tupleData, const std::string & collectionType);
        static void printValue(const Token & token, Values::ValuePtr value, const std::string & collectionType);
        static void printError(const Token & token, const std::string & errorMessage);

    public:
        static Values::ValuePtr runBuiltin(const Token & token, Values::FunctionValuePtr functionValue, Values::Environment & environment);
};