#include "gtest/gtest.h"
#include "floor.h"

TEST(FloorTest, GetTableReturnsCorrectTable) {
    Floor floor;
    TableComponent* table1 = new TableComponent(1);
    TableComponent* table2 = new TableComponent(2);

    floor.addTable(table1);
    floor.addTable(table2);

    EXPECT_EQ(floor.getTable(1), table1);
    EXPECT_EQ(floor.getTable(2), table2);
    EXPECT_EQ(floor.getTable(3), nullptr); // Non-existing table should return nullptr
}

TEST(FloorTest, GetTableReturnsNullForEmptyFloor) {
    Floor floor;

    EXPECT_EQ(floor.getTable(1), nullptr);
    EXPECT_EQ(floor.getTable(2), nullptr);
    EXPECT_EQ(floor.getTable(3), nullptr);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
