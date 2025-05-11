//
// Created by orebai on 20/12/2024.
//

#include "EasyFuzzyTrapezoidalMF.h"


TrapezoidalMF::TrapezoidalMF(float a, float b, float c, float d)
    : a_(a), b_(b), c_(c), d_(d) {
    // Ensure parameters are correct before deployment.
}

float TrapezoidalMF::Evaluate(float const x) const {
    if (x <= a_ || x >= d_) {
        return 0.0f;
    }
    if (x < b_) {
        return (x - a_) / (b_ - a_); // Rising slope
    }
    if (x <= c_) {
        return 1.0f; // Plateau
    }

    return (d_ - x) / (d_ - c_); // Falling slope
}


// Get the centroid of the trapezoidal membership function
float TrapezoidalMF::GetCentroid() const {
    // Calculate base lengths and offset
    float topBase = c_ - b_; // Length of the top base
    float bottomBase = d_ - a_; // Length of the bottom base
    float offset = b_ - a_; // Offset of the top base from the left side of the bottom base

    // Calculate centroid using the correct formula
    float centroidX = (2 * topBase * offset + topBase * topBase + topBase * bottomBase + bottomBase * bottomBase)
                      / (3 * (topBase + bottomBase));

    return centroidX + a_; // Add a_ to shift back to the correct x-position
}


uint8_t TrapezoidalMF::GetMfIndex() const {
    return this->mfIndex_;
}

void TrapezoidalMF::SetMfIndex(uint8_t const mfIndex) {
    this->mfIndex_ = mfIndex;
}


