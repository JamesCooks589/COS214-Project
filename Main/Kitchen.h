/**
* @file Kitchen.h
* @brief Declaration of the Kitchen class.
*        This file contains the declaration of the Kitchen class,
*        which represents the kitchen area of the restaurant with chefs and orders.
* @author [Author Name]
* @date [Creation Date]
*/

#pragma once
#include "BaseChef.h"
#include "ToppingChef.h"
#include "Order.h"
#include "Waiter.h"
#include <vector>

// Forward declaration of waiter
class PrototypeWaiter;

class Floor;

/**
* @class Kitchen
* @brief Represents the kitchen area of the restaurant with chefs and orders.
*/
class Kitchen {
private:
    ChefCreator* baseChefFactory; ///< Pointer to the factory for creating base chefs.
    ChefCreator* toppingChefFactory; ///< Pointer to the factory for creating topping chefs.
    Chef* chefChain; ///< Pointer to the chain of chefs.
    Order* order; ///< Pointer to the current order being prepared in the kitchen.
    std::vector<Plate*> plates; ///< Vector to store pointers to plates containing cooked food.
    Floor* floor = nullptr; ///< Pointer to the Floor object where chefs deliver plates.

public:
    /**
    * @brief Constructor for the Kitchen class.
    * Initializes a new instance of Kitchen with default values.
    */
    Kitchen();

    /**
    * @brief Destructor for the Kitchen class.
    * Cleans up resources and performs necessary cleanup operations.
    */
    ~Kitchen();

    /**
    * @brief Sets the current order and associated waiter for the kitchen.
    * @param order Pointer to the Order object representing the current order.
    * @param waiter Pointer to the PrototypeWaiter object associated with the order.
    */
    void setOrder(Order* order, PrototypeWaiter* waiter);

    /**
    * @brief Sets the Floor object where chefs deliver plates.
    * @param floor Pointer to the Floor object where chefs deliver plates.
    */
    void setFloor(Floor* floor);

    /**
    * @brief Gets the vector of plates containing cooked food.
    * @return Vector of pointers to Plate objects representing cooked food.
    */
    std::vector<Plate*> getPlates();

    /**
    * @brief Splits the order based on the current row number.
    * @param currentRow The current row number indicating the progress of order preparation.
    * @return Vector of strings representing the split portion of the order.
    */
    std::vector<std::string> splitOrder(int currentRow);

    /**
    * @brief Creates plates for the prepared food.
    */
    void createPlates();

    /**
    * @brief Allows the chef to visit the table and deliver food.
    */
    void letChefVisitTable();
};
