/**
* @file Caretaker.h
* @brief Declaration of the Caretaker class.
*        This file contains the declaration of the Caretaker class,
*        which is responsible for managing the order mementos and providing
*        access to them.
* @author [Author Name]
* @date [Creation Date]
*/

#pragma once
#include "OrderMemento.h"
#include <map>

/**
* @class Caretaker
* @brief Represents the caretaker responsible for managing order mementos.
*/
class Caretaker {
public:
    /**
    * @brief Gets the singleton instance of Caretaker.
    * @return The singleton instance of Caretaker.
    */
    static Caretaker& getInstance();

    /**
    * @brief Adds a new order memento to the caretaker's collection.
    * @param memento The OrderMemento object to be added.
    */
    void addMemento(const OrderMemento& memento);

    /**
    * @brief Retrieves an order memento based on the provided order ID.
    * @param id The unique identifier for the order memento.
    * @return The OrderMemento object corresponding to the given order ID.
    */
    OrderMemento getMemento(int id);

private:
    std::vector<OrderMemento> mementos; ///< Collection of order mementos managed by the caretaker.
};
