# EasyFuzzy

EasyFuzzy is a lightweight, fuzzy logic library designed for embedded systems, such as ESP32, STM32, and other microcontrollers with limited memory and processing power. It provides a simple and efficient way to implement fuzzy logic control systems, ideal for applications like motor speed control, temperature regulation, and sensor-based decision-making. The library uses static memory allocation to ensure deterministic memory usage and is highly configurable for various hardware constraints.

## Features
- **Static Memory Allocation**: Fixed-size arrays ensure predictable RAM usage, critical for embedded systems.
- **Configurable**: Centralized configuration via FuzzyConfig.h for membership functions, variables, and rules.
- **Modular Design**: Includes FuzzyVariable, FuzzyRule, FuzzyRuleBase, and SpeedController modules.
- **Embedded-Optimized**: Lightweight error handling, const-correctness, and minimal dependencies.
- **Example Application**: Speed controller for acceleration/deceleration based on error and speed inputs.

## Installation

To clone EasyFuzzy, use the following command:

```bash
git clone https://github.com/OmarRebai/EasyFuzzy.git
```
For better memory optimization, you can adjust the default settings in `EasyFuzzyConfig.h`. Then simply integrate the library into your project files, and you’re all set!


## Usage

The **EasyFuzzy** library makes it easy to create your own fuzzy logic controller by adapting the **SpeedController** module as a template. By adjusting variable names and membership function values, you can build a custom controller tailored to your application.

Congratulations, you’ve got your own fuzzy controller!
## Contributing

Contributions are welcome! Please follow these steps:
1. Fork the repository.
2. Create a new branch for your feature or bugfix.
3. Commit your changes and push the branch.
4. Submit a pull request.
