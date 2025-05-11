//
// Created by orebai on 20/12/2024.
//

#ifndef TRAPEZOIDALMF_H
#define TRAPEZOIDALMF_H


#include "EasyFuzzyIMembershipFunction.h"

class TrapezoidalMF : public IMembershipFunction {
private:
    const float a_;
    const float b_;
    const float c_;
    const float d_;
    uint8_t mfIndex_;


public:
    TrapezoidalMF(float a, float b, float c, float d);

    float Evaluate(float x) const override;

    float GetCentroid() const override;

    uint8_t GetMfIndex() const override;

    void SetMfIndex(uint8_t mfIndex) override;
};


#endif //TRAPEZOIDALMF_H
