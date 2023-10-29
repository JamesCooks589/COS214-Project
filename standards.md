# C++ Coding Standards

## Naming Conventions
- Variables and Functions: `camelCase`
- Classes and Structs: `PascalCase`
- Constants: `ALL_CAPS_WITH_UNDERSCORES`
- Enums: `PascalCase` for names, uppercase for values
- Braces: `Stroustrup Style`for consistent bracing style throughout the codebase

## Git Standards
- Branching Strategy: Git Flow
- Commit Messages: Descriptive, include issue numbers if applicable
- Merging: Use pull requests, conduct code reviews

## Comments
- Inline Comments: Use inline comments sparingly and only when necessary. Code should be self-explanatory through good naming practices.
- Function Comments: Include comments before functions describing what the function does, parameters, return values, and any exceptions thrown.
  - Example: 
    ```cpp
    /**
    * @brief Calculates the square of a number.
    * @param num The input number.
    * @return The square of the input number.
    */
    int square(int num) {
        return num * num;
    }
    ```
- File Comments: Include a comment block at the beginning of each source file describing the purpose of the file, author, creation date, and modification history if applicable.

## Memory Handling
- RAII (Resource Acquisition Is Initialization): Prefer RAII principles. Use smart pointers (std::unique_ptr, std::shared_ptr) and RAII-based classes to manage resources automatically.
- Manual Memory Management: If manual memory management is necessary, always pair new with delete and new[] with delete[] to deallocate memory.
- Avoid Raw Pointers: Avoid using raw pointers whenever possible. Use smart pointers or container classes (like std::vector, std::map) that manage memory for you.
- Memory Leaks: Always deallocate memory properly. Use tools like Valgrind to check for memory leaks.

## Example Naming
- `void processOrder(Order newOrder);`
- `class RestaurantManager;`
- `const int MAX_SEATING_CAPACITY = 100;`
- `enum class CuisineType { ITALIAN, CHINESE, AMERICAN };`
- `if (condition) {}`

## Documentation
- Inline Comments: Use comments to explain complex logic
- External Documentation: Maintain README.md with project overview, setup, and usage instructions
