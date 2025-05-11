//
// Created by orebai on 24/12/2024.
//

#ifndef FUZZYRULEBASE_H
#define FUZZYRULEBASE_H

#include "EasyFuzzyRule.h"
#include "EasyFuzzyConfig.h"

class FuzzyVariable; // Forward declaration

// Struct to hold a FuzzyVariable pointer and its input value
struct FuzzyInput {
    FuzzyVariable* variable;
    float value;
};

class FuzzyRuleBase {
public:
    // Default constructor
    FuzzyRuleBase();

    // Constructor with array of rules
    FuzzyRuleBase(FuzzyRule* rules[], uint8_t count);

    // Add a rule to the base
    bool AddRule(FuzzyRule* rule);

    // Apply all rules
    void ApplyAll();

    // Set input values for variables
    static void SetInputs(const FuzzyInput inputs[], uint8_t count);

    // Evaluate inputs and return the output
    float Evaluate(const FuzzyInput inputs[], uint8_t count, FuzzyVariable* output);

private:
    FuzzyRule* rules_[FUZZY_RULE_BASE_MAX_RULES]; // Fixed-size array of rules
    uint8_t ruleCount_; // Number of rules in the array
};

#endif //FUZZYRULEBASE_H