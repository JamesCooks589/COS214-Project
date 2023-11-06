/**
* @file Floor.h
* @brief Declaration of the Floor class.
*        This file contains the declaration of the Floor class,
*        which represents the floor of the restaurant with tables and waiters.
* @author [Author Name]
* @date [Creation Date]
*/

#pragma once
#include <vector>
#include "TableComponent.h"
#include "TableGroup.h"
#include "Waiter.h"

/**
* @class Floor
* @brief Represents the floor of the restaurant with tables and waiters.
*/
class Floor {
private:
    std::vector<TableComponent*> tables; ///< Vector to store pointers to table components.
    int tableCount; ///< The number of tables on the floor.
    const long unsigned int MAX_TABLES = 10; ///< Maximum number of tables allowed on the floor.
    bool isFull; ///< Flag indicating whether the floor is fully occupied or not.
    int vacantTables; ///< Number of vacant tables on the floor.
    std::vector<PrototypeWaiter*> waiters; ///< Vector to store pointers to waiters.
    Kitchen* kitchen; ///< Pointer to the Kitchen object associated with the floor.

public:
    /**
    * @brief Constructor for the Floor class.
    * @param numWaiters The number of waiters available on the floor.
    * @param kitchen Pointer to the Kitchen object associated with the floor.
    * Initializes a new instance of Floor with the given number of waiters and kitchen.
    */
    Floor(int numWaiters, Kitchen* kitchen);

    /**
    * @brief Destructor for the Floor class.
    * Cleans up resources and performs necessary cleanup operations.
    */
    ~Floor();

    /**
    * @brief Gets the table component based on the table ID.
    * @param tableID The unique identifier for the table.
    * @return Pointer to the TableComponent object corresponding to the given table ID.
    */
    TableComponent* getTable(int tableID);

    /**
    * @brief Adds a table to the floor.
    * @param table Pointer to the TableComponent object to be added.
    */
    void addTable(TableComponent* table);

    /**
    * @brief Removes a table from the floor.
    * @param table Pointer to the TableComponent object to be removed.
    */
    void removeTable(TableComponent* table);

    /**
    * @brief Splits a table based on the group size.
    * @param id The unique identifier for the table to be split.
    */
    void splitTables(int id);

    /**
    * @brief Merges tables based on the group size.
    * @param groupSize The size of the group for which tables need to be merged.
    * @return Pointer to the merged TableComponent object.
    */
    TableComponent* mergeTables(int groupSize);

    /**
    * @brief Prints the status of the tables on the floor.
    */
    void printTables();

    /**
    * @brief Gets the number of vacant tables on the floor.
    * @return The number of vacant tables on the floor.
    */
    int getVacantCapacity();

    /**
    * @brief Checks if the floor is fully occupied.
    * @return True if the floor is fully occupied, false otherwise.
    */
    bool getIsFull();

    /**
    * @brief Sets the occupancy status of the floor.
    * @param isFull Flag indicating whether the floor is fully occupied or not.
    */
    void setIsFull(bool isFull);

    /**
    * @brief Gets the first vacant table on the floor.
    * @return Pointer to the first vacant TableComponent object.
    */
    TableComponent* getFirstVacantTable();

    /**
    * @brief Attaches a random waiter to the customer group.
    * @param customers Pointer to the CustomerComponent object representing the customers.
    */
    void attachRandomWaiter(CustomerComponent* customers);

    /**
    * @brief Vacates a table based on the table ID.
    * @param tableID The unique identifier for the table to be vacated.
    */
    void vacateTable(int tableID);

    /**
    * @brief Gets the maximum number of tables allowed on the floor.
    * @return The maximum number of tables allowed on the floor.
    */
    int const getMAX_TABLES();

    /**
    * @brief Gets a random occupied table from the floor.
    * @return Pointer to the random occupied TableComponent object.
    */
    TableComponent* getRandomOccupiedTable();

    /**
    * @brief Gets the number of vacant tables on the floor.
    * @return The number of vacant tables on the floor.
    */
    int getNumVacantTables();

    /**
    * @brief Gets the number of occupied tables on the floor.
    * @return The number of occupied tables on the floor.
    */
    int getNumOccupiedTables();

    /**
    * @brief Gets the total number of tables on the floor.
    * @return The total number of tables on the floor.
    */
    int getNumTables();
};
