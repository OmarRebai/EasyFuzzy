//
// Created by orebai on 20/12/2024.
//

#include "EasyFuzzyVariable.h"

// Initialize static members
FuzzyVariable* FuzzyVariable::allVariables_[FUZZY_VAR_MAX_VARIABLES] = {nullptr};
uint8_t FuzzyVariable::variableCount_ = 0;

FuzzyVariable::FuzzyVariable() : mfCount_(0), input_(0.0f) {
    for (uint8_t i = 0; i < FUZZY_VAR_MAX_MF; i++) {
        mfs_[i] = nullptr;
        activations_[i] = 0.0f;
    }
    if (variableCount_ < FUZZY_VAR_MAX_VARIABLES) {
        allVariables_[variableCount_++] = this;
    }
}

FuzzyVariable::FuzzyVariable(IMembershipFunction* mfs[], uint8_t count) : mfCount_(0), input_(0.0f) {
    for (uint8_t i = 0; i < FUZZY_VAR_MAX_MF; i++) {
        mfs_[i] = nullptr;
        activations_[i] = 0.0f;
    }
    // Add up to count or FUZZY_VAR_MAX_MF membership functions
    for (uint8_t i = 0; i < count && i < FUZZY_VAR_MAX_MF; i++) {
        AddMF(mfs[i]);
    }
    if (variableCount_ < FUZZY_VAR_MAX_VARIABLES) {
        allVariables_[variableCount_++] = this;
    }
}

FuzzyVariable::~FuzzyVariable() {
    // Remove this instance from allVariables_
    for (uint8_t i = 0; i < variableCount_; i++) {
        if (allVariables_[i] == this) {
            allVariables_[i] = allVariables_[--variableCount_];
            allVariables_[variableCount_] = nullptr;
            break;
        }
    }
}

bool FuzzyVariable::AddMF(IMembershipFunction* mf) {
    if (mfCount_ >= FUZZY_VAR_MAX_MF || mf == nullptr) {
        return false;
    }
    mf->SetMfIndex(mfCount_);
    mfs_[mfCount_++] = mf;
    return true;
}

FuzzyVariable* FuzzyVariable::GetVariableForMF(const IMembershipFunction* mf) {
    if (mf == nullptr) {
        return nullptr;
    }
    for (uint8_t i = 0; i < variableCount_; i++) {
        if (allVariables_[i] == nullptr) {
            continue;
        }
        for (uint8_t j = 0; j < allVariables_[i]->mfCount_; j++) {
            if (allVariables_[i]->mfs_[j] == mf) {
                return allVariables_[i];
            }
        }
    }
    return nullptr;
}

void FuzzyVariable::SetInput(float input) {
    input_ = input;
    for (uint8_t i = 0; i < mfCount_; i++) {
        activations_[i] = 0.0f;
    }
}

float FuzzyVariable::EvaluateMF(const IMembershipFunction* mf) const {
    if (mf == nullptr || mf->GetMfIndex() >= mfCount_) {
        return 0.0f;
    }
    for (uint8_t i = 0; i < mfCount_; i++) {
        if (mfs_[i] == mf) {
            return mfs_[i]->Evaluate(input_);
        }
    }
    return 0.0f;
}

void FuzzyVariable::SetMFActivation(const IMembershipFunction* mf, float strength) {
    if (mf == nullptr || mf->GetMfIndex() >= mfCount_) {
        return;
    }
    if (mf->GetMfIndex() < mfCount_ && strength > activations_[mf->GetMfIndex()]) {
        activations_[mf->GetMfIndex()] = strength;
    }
}

void FuzzyVariable::ResetMFActivation() {
    for (uint8_t i = 0; i < mfCount_; i++) {
        activations_[i] = 0.0f;
    }
}

float FuzzyVariable::Defuzzify() {
    float numerator = 0.0f;
    float denominator = 0.0f;

    for (uint8_t i = 0; i < mfCount_; i++) {
        float activation = activations_[i];
        if (activation > 0.0f) {
            float centroid = mfs_[i]->GetCentroid();
            numerator += activation * centroid;
            denominator += activation;
        }
    }

    ResetMFActivation();

    if (denominator == 0.0f) {
        return 0.0f;
    }

    return numerator / denominator;
}

uint8_t FuzzyVariable::GetMFCount() const {
    return mfCount_;
}

IMembershipFunction* FuzzyVariable::GetMf(uint8_t index) const {
    if (index >= mfCount_) {
        return nullptr;
    }
    return mfs_[index];
}