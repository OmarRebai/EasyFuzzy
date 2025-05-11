//
// Created by orebai on 20/12/2024.
//

#include "EasyFuzzyTriangularMF.h"


TriangularMF::TriangularMF(float const a, float const b, float const c)
    : a_(a), b_(b), c_(c), mfIndex_(0) {
    // In an embedded environment, you might skip extensive checks to save code size.
    // Just ensure a < b < c is correct before deployment.
}

float TriangularMF::Evaluate(float const x) const {
    if (x <= a_ || x >= c_) {
        return 0.0f;
    }
    if (x <= b_) {
        return (x - a_) / (b_ - a_); // Rising slope
    }
    return (c_ - x) / (c_ - b_); // Falling slope
}


// Get the centroid of the triangular membership function
float TriangularMF::GetCentroid() const {
    // The centroid of a triangle is the average of its vertices
    return (a_ + b_ + c_) / 3.0f;
}

uint8_t TriangularMF::GetMfIndex() const {
    return this->mfIndex_;
}

void TriangularMF::SetMfIndex(uint8_t const mfIndex) {
    this->mfIndex_ = mfIndex;
}
