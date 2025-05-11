//
// Created by orebai on 23/12/2024.
//

#ifndef FUZZYRULE_H
#define FUZZYRULE_H

#include "EasyFuzzyVariable.h"

enum RuleType {
    AND,
    OR
};

class FuzzyRule {
private:
    const FuzzyVariable *input1_;
    const IMembershipFunction *mfIn1_;
    const RuleType type_;
    const FuzzyVariable *input2_;
    const IMembershipFunction *mfIn2_;
    FuzzyVariable *output_;
    const IMembershipFunction *mfOut_;

    float CombineValues(float const a, float const b) const {
        return (type_ == AND)
                   ? ((a < b) ? a : b) // AND = min(a, b)
                   : ((a > b) ? a : b); // OR = max(a, b)
    }

public:

    FuzzyRule(const IMembershipFunction* mfIn1, RuleType type, const IMembershipFunction* mfIn2,
              const IMembershipFunction* mfOut);

    float Evaluate() const;

    void Apply() const;
};


#endif //FUZZYRULE_H
