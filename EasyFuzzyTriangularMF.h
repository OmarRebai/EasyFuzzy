//
// Created by orebai on 20/12/2024.
//

#ifndef TRIANGULARMF_H
#define TRIANGULARMF_H



#include "EasyFuzzyIMembershipFunction.h"

class TriangularMF : public IMembershipFunction {
private:
    const float a_;
    const float b_;
    const float c_;
    uint8_t mfIndex_;

public:
    TriangularMF(float a, float b, float c);

    float Evaluate(float x) const override;
    float GetCentroid() const override;
    uint8_t GetMfIndex() const override;

    void SetMfIndex(uint8_t mfIndex) override;
};


#endif //TRIANGULARMF_H
