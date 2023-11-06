/**
* @file Table.h
* @brief Declaration of the Table class.
*        This file contains the declaration of the Table class,
*        which represents a table in the restaurant derived from TableComponent.
* @author [Author Name]
* @date [Creation Date]
*/

#pragma once
#include "TableComponent.h"

/**
* @class Table
* @brief Represents a table in the restaurant derived from TableComponent.
*/
class Table : public TableComponent {
private:
    int capacity = 2; ///< The capacity of the table, i.e., the number of seats available.

public:
    /**
    * @brief Constructor for the Table class.
    * @param id The unique identifier of the table.
    * Initializes a new instance of Table with the given ID and default capacity.
    */
    Table(int id) : TableComponent(id) {}

    /**
    * @brief Gets the capacity of the table (number of seats available).
    * @return The capacity of the table.
    */
    int getCapacity();
};
