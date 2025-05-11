//
// Created by orebai on 20/12/2024.
//

#ifndef IMEMBERSHIPFUNCTION_H
#define IMEMBERSHIPFUNCTION_H
#include "stdint.h"

class IMembershipFunction {
public:
    virtual ~IMembershipFunction() = default;

    virtual float Evaluate(float x) const = 0;

    virtual float GetCentroid() const = 0;

    virtual uint8_t GetMfIndex() const = 0;

    virtual void SetMfIndex(uint8_t mfIndex_) = 0;
};

#endif //IMEMBERSHIPFUNCTION_H
