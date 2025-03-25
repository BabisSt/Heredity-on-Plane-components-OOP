# Heredity on Plane Components OOP

## Exercise 3: Object-Oriented Programming
Student ID: 1115201600278  
Stevis Charalampos-Antonius

### Files Included:
- `classes.h` // Header files
- `classes.cpp` // Implementation files  
Compilation via `g++ -c classes.cpp`

### Classes in the Files:
- `Object`
- `String`
- `Plane`
- `Plane Compartment`
- `Passenger Compartment`
- `Private Compartment`
- `Equipment Compartment`
- `Cargo Bay`
- `Employee`
- `Security Employee`
- `Maintenance Employee`
- `Cleaning Employee`

### Inheritance Structure:
Object (parent, all others are its children)  
    Plane (parent of all the below)  
        PlaneCompartment  
            PassengerCompartment - PrivateCompartment  
                    EquipmentCompartment - CargoBay  

Employee  
    SecurityEmployee - MaintenanceEmployee - CleaningEmployee



### Class Descriptions:

#### `Object` Class
- **Private:** `id`
- **Constructor:** Default constructor
- **Constructor with `id` argument**
- **Copy Constructor**
- **Virtual Destructor**
- **Virtual `is_equal`** (compares two objects and prints if they are the same or not)
- **Virtual `is_identical`** (compares one object with the `id` and prints the appropriate message)
- **Pure Virtual `toString`** (takes a `char*` and an `int` as arguments)
- **`get_id`** (returns the `id`)

#### `String` Class
- **Private:** `char* str / int length`
- **Constructor with `str` argument**
- **Copy Constructor** (with `String` argument)
- **Virtual Destructor**
- **`clear`** (deletes a `char*` based on the argument)
- **`print_str`** (prints a `char*` argument)
- **`get_length`** (returns the size of the string using `strlen`)
- **`concat`** (concatenates three `char*`, with two to concatenate and one for the result using `strcpy` and `strcat`)
- **`at`** (returns the `char` at a specific index in a `char*`)
- **`updateAt`** (updates the `char*` at a specific index with a new `char`)
- **`toString`** (prints the `char*` and its length)

#### `Plane` Class
- **Private:** `char* description`, `char* title`, `int capacity`, `CargoBay*`, `EquipmentCompartment*`, `PassengerCompartment*`
- **Constructor**
- **Constructor with arguments** (including spaces for the plane)
- **Copy Constructor**
- **Virtual Destructor**
- **`set_capacity_of_plane`** (sets capacity and creates random passenger compartments based on the capacity)
- **`set_description`** (sets a `char*` description)
- **`set_title`** (sets a `char*` title)
- **`get_description`**
- **`get_title`**
- **`get_capacity_of_plane`**

#### `PlaneCompartment` Class
- **Constructor**
- **Virtual Destructor**
- **Pure Virtual `process`** (with three arguments, one for each type of employee)
- **Pure Virtual `ready_check`** (takes three `int` arguments)

#### `PassengerCompartment`, `PrivateCompartment`, `EquipmentCompartment`, and `CargoBay` Classes
- **Constructor** (in `PassengerCompartment`, there is an option to create an internal passenger compartment randomly; in `CargoBay`, there is an `EquipmentCompartment`)
- **Virtual Destructor**
- **Virtual `ready_check`** (takes two or three `int` arguments, checks if all results from `process` are valid and prints if the compartment is ready or not)
- **Virtual `process`** (takes two or three arguments, with the respective employee passed in, uses `rand()` to determine if the employee has completed the task, calls the `report` method of the employee)

#### `Employee` Class
- **Private:** `char* name`
- **Constructor**
- **Constructor with `char*` argument**
- **Virtual Destructor**
- **Virtual `report`** (takes an `int` argument)
- **Virtual `workOn`** (not implemented)
- **`set_name`** (sets the `name` for the employee)
- **`get_name`** (returns the `name`)

#### `SecurityEmployee`, `MaintenanceEmployee`, and `CleaningEmployee` Classes
- **Constructor** (with `char*` argument)
- **Virtual Destructor**
- **Virtual `report`** (takes an `int` argument, prints if the compartment is fine when the argument is 1, otherwise prints a negative message)
- **Virtual `workOn`** (not implemented)

### Missing Implementations:
- There is no `main` function as it was not implemented.
- The `clone_encrypt_and_print` function is not included.
- The `workOn` function for the `Employee` class is not implemented.
