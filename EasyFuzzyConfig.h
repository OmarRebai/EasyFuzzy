#ifndef FUZZY_CONFIG_H
#define FUZZY_CONFIG_H

/// @brief Maximum number of membership functions per FuzzyVariable (used in FuzzyVariable).
/// Adjust based on system requirements (e.g., 5–20). Each membership function
/// consumes ~12–20 bytes of RAM (depending on type and configuration).
#ifndef FUZZY_VAR_MAX_MF
#define FUZZY_VAR_MAX_MF 5
#endif

/// @brief Maximum number of FuzzyVariable instances in the system (used in FuzzyVariable).
/// Adjust based on system complexity (e.g., 5–20). Each variable consumes
/// ~48–60 bytes of RAM (assuming FUZZY_VAR_MAX_MF=10 and float activations).
#ifndef FUZZY_VAR_MAX_VARIABLES
#define FUZZY_VAR_MAX_VARIABLES 5
#endif

/// @brief Maximum number of FuzzyRule instances in FuzzyRuleBase (used in FuzzyRuleBase).
/// Adjust based on rule complexity (e.g., 10–50). Each rule consumes
/// ~16–20 bytes of RAM.
#ifndef FUZZY_RULE_BASE_MAX_RULES
#define FUZZY_RULE_BASE_MAX_RULES 9
#endif

#endif // FUZZY_CONFIG_H