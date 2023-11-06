#include "gtest/gtest.h"
#include "Customer.h"
#include "TableComponent.h"
#include "IngredientFactory.h"

TEST(CustomerTest, GetOrderReturnsValidOrder) {
    Customer customer("John", 1);
    TableComponent table(1);
    customer.setTableID(1);
    table.addCustomer(&customer);

    Order* order = customer.getOrder();
    std::vector<std::vector<std::string>> orderDetails = order->getOrderDetails();

    EXPECT_EQ(orderDetails.size(), 1);
    EXPECT_EQ(orderDetails[0][0], "John"); // Customer name
    EXPECT_GE(orderDetails[0].size(), 2); // At least base ingredient and customer name

    delete order;
}

TEST(CustomerTest, GetSizeReturnsOne) {
    Customer customer("Alice", 2);

    EXPECT_EQ(customer.getSize(), 1);
}

TEST(CustomerTest, EatFoodUpdatesHappiness) {
    Customer customer("Bob", 3);
    Plate* plate = new Plate();
    plate->addFood("Pizza(great)");
    plate->addFood("Burger(burnt)");

    int initialHappiness = customer.getHappiness();
    customer.givePlate(plate);
    int updatedHappiness = customer.getHappiness();

    EXPECT_GT(updatedHappiness, initialHappiness); // Eating food should increase happiness
}

TEST(CustomerTest, PayBillCalculatesTipCorrectly) {
    Customer customer("Eva", 4);
    double billAmount = 50.0;
    bool split = true;

    double initialHappiness = customer.getHappiness();
    ::testing::internal::CaptureStdout();
    customer.payBill(billAmount, split);
    std::string output = ::testing::internal::GetCapturedStdout();

    double expectedTip = billAmount * (initialHappiness / 800);
    double expectedTotal = billAmount + expectedTip;

    EXPECT_EQ(output, "CustomerEva paid:" + std::to_string(expectedTotal) + " including tip: " +
                      std::to_string(expectedTip) + "for their share of the bill.\n");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
