//
// Created by orebai on 23/12/2024.
//

#include "EasyFuzzyRule.h"

// Constructor infers variables from membership functions
FuzzyRule::FuzzyRule(const IMembershipFunction *mfIn1, RuleType type, const IMembershipFunction *mfIn2,
                     const IMembershipFunction *mfOut)
    : mfIn1_(mfIn1), type_(type), mfIn2_(mfIn2), mfOut_(mfOut) {
    // Infer variables
    input1_ = FuzzyVariable::GetVariableForMF(mfIn1);
    input2_ = mfIn2 ? FuzzyVariable::GetVariableForMF(mfIn2) : nullptr;
    output_ = FuzzyVariable::GetVariableForMF(mfOut);
}


float FuzzyRule::Evaluate() const {
    float const degree1 = input1_->EvaluateMF(mfIn1_);

    float const degree2 = input2_ ? input2_->EvaluateMF(mfIn2_) : 1.0f;

    return CombineValues(degree1, degree2);
}

void FuzzyRule::Apply() const {
    float const strength = Evaluate();

    output_->SetMFActivation(mfOut_, strength);
}
