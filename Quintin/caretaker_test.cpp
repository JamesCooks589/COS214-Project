#include "gtest/gtest.h"
#include "Caretaker.h"
#include "OrderMemento.h"

TEST(CaretakerTest, AddMementoAddsToVector) {
    Caretaker& caretaker = Caretaker::getInstance();
    OrderMemento memento(1);
    caretaker.addMemento(memento);

    EXPECT_EQ(caretaker.getMementos().size(), 1);
}

TEST(CaretakerTest, GetMementoReturnsCorrectMemento) {
    Caretaker& caretaker = Caretaker::getInstance();
    OrderMemento memento1(1);
    OrderMemento memento2(2);
    caretaker.addMemento(memento1);
    caretaker.addMemento(memento2);

    OrderMemento retrievedMemento = caretaker.getMemento(1);

    EXPECT_EQ(retrievedMemento.getTableNumber(), 1);
}

TEST(CaretakerTest, GetMementoThrowsExceptionForNonExistingID) {
    Caretaker& caretaker = Caretaker::getInstance();
    OrderMemento memento(1);
    caretaker.addMemento(memento);

    EXPECT_THROW(caretaker.getMemento(2), std::runtime_error);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
