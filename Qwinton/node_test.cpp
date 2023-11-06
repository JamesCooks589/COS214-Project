#include "gtest/gtest.h"
#include "Node.h"
#include "CustomerComponent.h"

TEST(NodeTest, GetGroupReturnsCorrectPointer) {
    CustomerComponent* customer = new CustomerComponent(1);
    Node node(customer);

    EXPECT_EQ(node.getGroup(), customer);
}

TEST(NodeTest, GetNextReturnsNullInitially) {
    CustomerComponent* customer = new CustomerComponent(1);
    Node node(customer);

    EXPECT_EQ(node.getNext(), nullptr);
}

TEST(NodeTest, SetNextUpdatesNextPointer) {
    CustomerComponent* customer1 = new CustomerComponent(1);
    Node node1(customer1);

    CustomerComponent* customer2 = new CustomerComponent(2);
    Node node2(customer2);

    node1.setNext(&node2);

    EXPECT_EQ(node1.getNext(), &node2);
}

TEST(NodeTest, DestructorRecursivelyDeletesNextNodes) {
    CustomerComponent* customer1 = new CustomerComponent(1);
    Node* node1 = new Node(customer1);

    CustomerComponent* customer2 = new CustomerComponent(2);
    Node* node2 = new Node(customer2);

    node1->setNext(node2);
    delete node1; // Destructor should delete node2 as well

    // Check if node2 is deleted
    EXPECT_EQ(node2->getGroup(), nullptr);
    EXPECT_EQ(node2->getNext(), nullptr);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
