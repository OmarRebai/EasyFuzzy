//
// Created by orebai on 09/01/2025.
//

#include "SpeedController.h"
#include "EasyFuzzy.h"

// Membership functions for Speed
static TrapezoidalMF        speedLowMF(0.0f, 0.0f, 100.0f, 300.0f);
static TriangularMF         speedMediumMF(100.0f, 300.0f, 500.0f);
static TrapezoidalMF        speedHighMF(300.0f, 500.0f, 600.0f, 600.0f);

// Membership functions for Error
static TrapezoidalMF        errorSmallMF(0.0f, 0.0f, 20.0f, 50.0f);
static TriangularMF         errorMediumMF(20.0f, 50.0f, 80.0f);
static TrapezoidalMF        errorLargeMF(50.0f, 80.0f, 100.0f, 100.0f);

// Membership functions for Acceleration/Deceleration
static TrapezoidalMF        accelNegLargeMF(-10.0f, -10.0f, -7.5f, -2.5f);
static TriangularMF         accelNegSmallMF(-7.5f, -2.5f, 2.5f);
static TriangularMF         accelPosSmallMF(-2.5f, 2.5f, 7.5f);
static TrapezoidalMF        accelPosLargeMF(2.5f, 7.5f, 10.0f, 10.0f);

// Fuzzy Variables
static IMembershipFunction *speedMFs[] = {
    &speedLowMF, &speedMediumMF, &speedHighMF};
static FuzzyVariable        speedVarInput(speedMFs, 3);

static IMembershipFunction *errorMFs[] = {
    &errorSmallMF, &errorMediumMF, &errorLargeMF};
static FuzzyVariable        errorVarInput(errorMFs, 3);

static IMembershipFunction *accelDecelMFs[] = {
    &accelNegLargeMF, &accelNegSmallMF, &accelPosSmallMF, &accelPosLargeMF};
static FuzzyVariable accelDecelVarOutput(accelDecelMFs, 4);

// Fuzzy Rules
static FuzzyRule     rule1(&errorSmallMF, AND, &speedLowMF, &accelPosLargeMF);
static FuzzyRule  rule2(&errorSmallMF, AND, &speedMediumMF, &accelPosLargeMF);
static FuzzyRule  rule3(&errorSmallMF, AND, &speedHighMF, &accelPosSmallMF);
static FuzzyRule  rule4(&errorMediumMF, AND, &speedLowMF, &accelPosSmallMF);
static FuzzyRule  rule5(&errorMediumMF, AND, &speedMediumMF, &accelPosSmallMF);
static FuzzyRule  rule6(&errorMediumMF, AND, &speedHighMF, &accelNegSmallMF);
static FuzzyRule  rule7(&errorLargeMF, AND, &speedLowMF, &accelPosSmallMF);
static FuzzyRule  rule8(&errorLargeMF, AND, &speedMediumMF, &accelNegSmallMF);
static FuzzyRule  rule9(&errorLargeMF, AND, &speedHighMF, &accelNegLargeMF);

// Rule Base
static FuzzyRule *rules[] = {
    &rule1, &rule2, &rule3, &rule4, &rule5, &rule6, &rule7, &rule8, &rule9};
static FuzzyRuleBase ruleBase(rules, 9);

// Function to calculate acceleration/deceleration value
float GetAccelDecelValue(float currentError, float currentSpeed) {
  FuzzyInput inputs[] = {
      {&errorVarInput, currentError},
      {&speedVarInput, currentSpeed}
  };
  return ruleBase.Evaluate(inputs, 2, &accelDecelVarOutput);
}