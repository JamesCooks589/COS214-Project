#include "gtest/gtest.h"
#include "Bill.h"
#include "Caretaker.h"

TEST(BillTest, CalculateTotalAmountReturnsCorrectAmount) {
    Bill bill(1);
    // Assuming food items in the order cost 20 each (excluding base cost of 50)
    double expectedTotalAmount = 50 + 20 * bill.foodItems.size();
    
    double actualTotalAmount = bill.calculateTotalAmount();
    
    EXPECT_EQ(actualTotalAmount, expectedTotalAmount);
}

TEST(BillTest, PrintBillOutputsCorrectFormat) {
    Bill bill(2);
    ::testing::internal::CaptureStdout();
    bill.printBill();
    std::string output = ::testing::internal::GetCapturedStdout();
    
    // Assuming food items in the order cost 20 each (excluding base cost of 50)
    std::string expectedOutput = "Order ID: 2\n"
                                 "Food Items:\n"
                                 "- Flour (R20)\n"
                                 "- Cheese (R20)\n"
                                 "- Veggies (R20)\n"
                                 "Total Amount: R110\n";
    
    EXPECT_EQ(output, expectedOutput);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
