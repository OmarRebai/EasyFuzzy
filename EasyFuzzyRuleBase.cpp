//
// Created by orebai on 24/12/2024.
//

#include "EasyFuzzyRuleBase.h"
#include "EasyFuzzyVariable.h"

// Default constructor
FuzzyRuleBase::FuzzyRuleBase() : ruleCount_(0) {
    for (uint8_t i = 0; i < FUZZY_RULE_BASE_MAX_RULES; i++) {
        rules_[i] = nullptr;
    }
}

// Constructor with array of rules
FuzzyRuleBase::FuzzyRuleBase(FuzzyRule* rules[], uint8_t count) : ruleCount_(0) {
    for (uint8_t i = 0; i < FUZZY_RULE_BASE_MAX_RULES; i++) {
        rules_[i] = nullptr;
    }
    for (uint8_t i = 0; i < count && i < FUZZY_RULE_BASE_MAX_RULES; i++) {
        AddRule(rules[i]);
    }
}

// Add a rule to the base
bool FuzzyRuleBase::AddRule(FuzzyRule* rule) {
    if (ruleCount_ >= FUZZY_RULE_BASE_MAX_RULES || rule == nullptr) {
        return false;
    }
    rules_[ruleCount_++] = rule;
    return true;
}

// Apply all rules
void FuzzyRuleBase::ApplyAll() {
    for (uint8_t i = 0; i < ruleCount_; i++) {
        if (rules_[i] != nullptr) {
            rules_[i]->Apply();
        }
    }
}

// Set input values for variables
void FuzzyRuleBase::SetInputs(const FuzzyInput inputs[], uint8_t count) {
    if (inputs == nullptr || count > FUZZY_VAR_MAX_VARIABLES) {
        return;
    }
    for (uint8_t i = 0; i < count; i++) {
        FuzzyVariable* variable = inputs[i].variable;
        float value = inputs[i].value;
        if (variable != nullptr) {
            variable->SetInput(value);
        }
    }
}

// Evaluate the rule base with inputs and defuzzify the output
float FuzzyRuleBase::Evaluate(const FuzzyInput inputs[], uint8_t count, FuzzyVariable* output) {
    if (output == nullptr) {
        return 0.0f;
    }
    // Set the inputs for the fuzzy variables
    SetInputs(inputs, count);

    // Apply all rules
    ApplyAll();

    // Defuzzify the output variable
    return output->Defuzzify();
}