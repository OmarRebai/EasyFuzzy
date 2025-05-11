//
// Created by orebai on 20/12/2024.
//

#ifndef FUZZYVARIABLE_H
#define FUZZYVARIABLE_H

#include <stdint.h>
#include "EasyFuzzyIMembershipFunction.h"
#include "EasyFuzzyConfig.h"

class FuzzyVariable {
private:
    IMembershipFunction* mfs_[FUZZY_VAR_MAX_MF]{}; // Array of membership function pointers
    uint8_t mfCount_; // Current count of membership functions
    float input_; // Input value for this variable
    float activations_[FUZZY_VAR_MAX_MF]{}; // Activation levels for each membership function

    static FuzzyVariable* allVariables_[FUZZY_VAR_MAX_VARIABLES]; // Fixed-size array to track all variables
    static uint8_t variableCount_; // Number of variables in allVariables_

public:
    // Default constructor
    FuzzyVariable();

    // Constructor with array of membership functions
    FuzzyVariable(IMembershipFunction* mfs[], uint8_t count);

    // Destructor
    ~FuzzyVariable();

    // Add a membership function to the variable
    bool AddMF(IMembershipFunction* mf);

    // Static method to get the variable managing a membership function
    static FuzzyVariable* GetVariableForMF(const IMembershipFunction* mf);

    // Set the input value for this variable
    void SetInput(float input);

    // Evaluate a specific membership function by index
    float EvaluateMF(const IMembershipFunction* mf) const;

    // Set the activation level of a specific membership function
    void SetMFActivation(const IMembershipFunction* mf, float strength);

    void ResetMFActivation();

    // Get the defuzzified value (e.g., using the centroid method)
    float Defuzzify();

    // Get the current number of membership functions
    uint8_t GetMFCount() const;

    IMembershipFunction* GetMf(uint8_t index) const;
};

#endif //FUZZYVARIABLE_H