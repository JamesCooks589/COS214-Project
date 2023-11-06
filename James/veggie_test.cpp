#include "gtest/gtest.h"
#include "Veggies.h"
#include "Plate.h"

class MockPlate : public Plate {
public:
    void addFood(const std::string& food) override {
        addedFood.push_back(food);
    }

    const std::vector<std::string>& getAddedFood() const {
        return addedFood;
    }

private:
    std::vector<std::string> addedFood;
};

TEST(VeggiesTest, CookFoodAddsCorrectFoodToPlate) {
    Veggies veggies;
    MockPlate plate;
    std::vector<std::string> orderDetails = {"Veggies"};

    ::testing::internal::CaptureStdout();
    veggies.cookFood(orderDetails, &plate);
    std::string output = ::testing::internal::GetCapturedStdout();

    const auto& addedFood = plate.getAddedFood();
    ASSERT_EQ(addedFood.size(), 1);
    EXPECT_TRUE(addedFood[0] == "Veggies(burnt)" || addedFood[0] == "Veggies(fine)" || addedFood[0] == "Veggies(great)");
    EXPECT_TRUE(output.find(addedFood[0]) != std::string::npos);
}

TEST(VeggiesTest, CookFoodDelegatesToNextChef) {
    Veggies veggies;
    MockPlate plate;
    std::vector<std::string> orderDetails = {"Carrots"};

    ::testing::internal::CaptureStdout();
    veggies.cookFood(orderDetails, &plate);
    std::string output = ::testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Carrots") != std::string::npos);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
