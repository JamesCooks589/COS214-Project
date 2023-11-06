/**
* @file TableComponent.h
* @brief Declaration of the TableComponent class.
*        This file contains the declaration of the TableComponent class,
*        which represents a component of a table in the restaurant derived from CustomerComponent.
* @author Lloyd Creighton
* @date 28 October 2023
*/

#pragma once
#include "CustomerComponent.h"
#include <vector>
#include <memory>

using namespace std;
/**
* @class TableComponent
* @brief Represents a component of a table in the restaurant derived from CustomerComponent.
*/
class TableComponent{
private:
    CustomerComponent* Customers = nullptr; ///< Pointer to the customer component occupying the table.
    bool occupied = false; ///< Flag indicating whether the table is occupied.
    int id; ///< The unique identifier of the table component.

public:
    /**
    * @brief Constructor for the TableComponent class.
    * @param id The unique identifier of the table component.
    * Initializes a new instance of TableComponent with the given ID.
    */
    TableComponent(int id);

    /**
    * @brief Gets the capacity of the table component (number of seats available).
    * @return The capacity of the table component.
    */
    virtual int getCapacity() = 0;

    /**
    * @brief Gets the unique identifier of the table component.
    * @return The ID of the table component.
    */
    int getID();

    /**
    * @brief Checks if the table component is occupied.
    * @return True if the table component is occupied, false otherwise.
    */
    bool isOccupied();

    /**
    * @brief Occupies the table component with the provided customer component.
    * @param Customers Pointer to the CustomerComponent object to occupy the table.
    */
    void occupy(CustomerComponent* Customers);

    /**
    * @brief Gets the customer component occupying the table.
    * @return Pointer to the CustomerComponent object occupying the table.
    */
    CustomerComponent* getCustomers();

    /**
    * @brief Vacates the table component, returning the customer component that was occupying it.
    * @return Pointer to the CustomerComponent object that was occupying the table.
    */
    CustomerComponent* vacate();

    /**
    * @brief Destructor for the TableComponent class.
    * Cleans up resources and performs necessary cleanup operations.
    */
    virtual ~TableComponent();

    /**
    * @brief Adds a table component to a group.
    * @param tableToAdd Pointer to the TableComponent object to be added to the group.
    */
    virtual void addToGroup(TableComponent* tableToAdd);

    /**
    * @brief Splits the group into individual table components.
    * @return Vector of pointers to individual TableComponent objects split from the group.
    */
    virtual vector<TableComponent*> splitGroup();

    /**
    * @brief Removes the table component from the group.
    * @return Pointer to the removed TableComponent object.
    */
    virtual TableComponent* removeFromGroup();

    /**
    * @brief Checks if the table component is empty (not part of any group).
    * @return True if the table component is not part of any group, false otherwise.
    */
    virtual bool isEmpty();
};