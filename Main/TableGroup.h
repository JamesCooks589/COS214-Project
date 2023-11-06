/**
* @file TableGroup.h
* @brief Declaration of the TableGroup class.
*        This file contains the declaration of the TableGroup class,
*        which represents a group of tables in the restaurant derived from TableComponent.
* @author Lloyd Creighton
* @date 28 October 2023
*/

#pragma once
#include "TableComponent.h"
#include <vector>

using namespace std;
/**
* @class TableGroup
* @brief Represents a group of tables in the restaurant derived from TableComponent.
*/
class TableGroup : public TableComponent {
private:
    vector<TableComponent*> tables; ///< Vector of pointers to individual TableComponent objects in the group.

public:
    /**
    * @brief Constructor for the TableGroup class.
    * @param id The unique identifier of the table group.
    * Initializes a new instance of TableGroup with the given ID and an empty vector of tables.
    */
    TableGroup(int id) : TableComponent(id) {
        this->tables = vector<TableComponent*>();
    }

    /**
    * @brief Adds a table component to the group.
    * @param tableToAdd Pointer to the TableComponent object to be added to the group.
    */
    void addToGroup(TableComponent* tableToAdd);

    /**
    * @brief Gets the combined capacity of all tables in the group.
    * @return The total capacity of the table group.
    */
    int getCapacity();

    /**
    * @brief Removes a table component from the group.
    * @return Pointer to the removed TableComponent object.
    */
    TableComponent* removeFromGroup();

    /**
    * @brief Splits the group into individual table components.
    * @return Vector of pointers to individual TableComponent objects split from the group.
    */
    virtual vector<TableComponent*> splitGroup() override;

    /**
    * @brief Checks if the table group is empty (does not contain any tables).
    * @return True if the table group does not contain any tables, false otherwise.
    */
    bool isEmpty();

    /**
    * @brief Destructor for the TableGroup class.
    * Cleans up resources and performs necessary cleanup operations.
    */
    ~TableGroup();
};
