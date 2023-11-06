#include "gtest/gtest.h"
#include "Chef.h"
#include "Plate.h"

TEST(ChefTest, CookFoodPrintsPlateWhenNoNextChef) {
    Chef chef;
    Plate plate;
    std::vector<std::string> orderDetails = {"Burger", "Fries"};

    ::testing::internal::CaptureStdout();
    chef.cookFood(orderDetails, &plate);
    std::string output = ::testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Burger, Fries\n");
}

TEST(ChefTest, CookFoodDelegatesToNextChef) {
    Chef chef1;
    Chef chef2;
    Plate plate;
    std::vector<std::string> orderDetails = {"Pizza", "Salad"};

    chef1.Add(&chef2);

    ::testing::internal::CaptureStdout();
    chef1.cookFood(orderDetails, &plate);
    std::string output = ::testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Pizza, Salad\n");
}

TEST(ChefTest, CookFoodDoesNotCrashOnEmptyOrderDetails) {
    Chef chef;
    Plate plate;
    std::vector<std::string> orderDetails;

    ::testing::internal::CaptureStdout();
    chef.cookFood(orderDetails, &plate);
    std::string output = ::testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "\n");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
