# Google Testing Standards for C++

## Introduction
This document outlines the standards and best practices for writing unit tests in C++ using Google Test framework.

## 1. Test Naming Conventions
- **Test names should be descriptive:** Clearly indicate what aspect of the code is being tested.
  - Example: `TEST(LinkedList, Insertion)`

## 2. Test Structure
- **Use Arrange-Act-Assert (AAA) pattern:**
  - Arrange: Set up the preconditions for the test.
  - Act: Perform the operation being tested.
  - Assert: Verify the expected behavior.
- **Use fixtures when appropriate:** Share common setup and teardown code in a fixture.
  - Example: 
    ```cpp
    class LinkedListTest : public ::testing::Test {
    protected:
        void SetUp() override {
            // Setup code
        }
        
        void TearDown() override {
            // Teardown code
        }
        
        // Declare common variables used in tests
    };
    ```

## 3. Assertions
- **Use ASSERT_* for essential assertions:** If the assertion fails, the test is terminated.
  - Example: `ASSERT_EQ(expected, actual)`
- **Use EXPECT_* for non-essential assertions:** If the assertion fails, the test continues to execute.
  - Example: `EXPECT_TRUE(condition)`

## 4. Test Organization
- **Group related tests using test suites:**
  - Example:
    ```cpp
    TEST(LinkedList, Insertion) {
        // Test insertion functionality
    }
    
    TEST(LinkedList, Deletion) {
        // Test deletion functionality
    }
    ```
  
## 5. Mocking and Dependency Injection
- **Use mocking frameworks when dealing with external dependencies.**
- **Prefer dependency injection over direct instantiation of objects.**

## 6. Continuous Integration
- **Integrate tests into CI/CD pipelines:** Ensure tests are automatically run with every code push.

## 7. Documentation
- **Include comments explaining test rationale and edge cases.**
- **Maintain a testing documentation:** Describe the purpose of each test suite and major test cases.

## 8. Miscellaneous
- **Keep tests independent and isolated:** Tests should not rely on the order of execution.
- **Run tests in isolation:** Tests should not depend on the state left by other tests.
- **Regularly review and refactor tests:** Eliminate redundant tests and update tests when code behavior changes.

## Conclusion
Adhering to these standards will lead to consistent, readable, and maintainable C++ tests using the Google Test framework.
