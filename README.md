# ECS Game Engine

## Goal

This project has two goals. 

The first is to explore CS concepts:
  1. ECS design pattern - use of the design pattern as a tool for analyzing, understanding complex systems, as a framework for thinking.
  2. Data Driven Design - designing programs around data, storing data for efficient use by the CPU.
  3. Exploring the C programming language.

The second goal is to create a game using my own ECS Engine.


## ECS

Entity-Component-System is a approach in design, that breaks a complex system for managing data sets into its essential parts: identity, data and behaviour.
Its main concerns is how to store and use data efficiently by the CPU, reducing cache misses and avoiding slow main memory reads. 

  - Entity is a unique identifier that represents a group of components that form a single data record. It has no behaviour or data other then the one used for identification.

  - Component is a single data row. It contains no logic, only state.

  - A System defines behavior. It operates on sets of components, transforming their data according to rules for that component type. Systems are the logic of the program.

### How does the ECS pattern help with structuring, reasoning and understanding of a game engine:

All the benefits that the ECS pattern gives are a consequence of the separation that it provides, this allows working independently on:
1. Reasoning about the structure and informations that define a specific data entry, object.
2. Representing a single information in memory, code.
3. Developing, testing and reasoning about systems in isolation.
4. Creating a complex system from simple, composable parts.
5. Allows reusing of solution for different data entries.

ECS reduces coupling, improves clarity, allows reusing of concepts and makes large systems easier to reason about and extend.

### ECS design pattern applied as a tool to analyze games data:

The basic game data units are game objects.
Game objects are a collection of states and behaviours.
The state of the game object are its properties, the data that defines what a game object can do.
Behaviours are the logical rules that define how the states are to be used and manipulated, the definitions of actions that the properties can perform.

#### Using the ECS pattern to analyze a game object:

Game object can be broken down into:
  1. Entity, identification for ownership of data.
  2. Components, extracted data that define a single property of the game object. 
  3. Systems, extracted behaviour of a property, example moving it is a behaviour that is defined by a position and velocity properties.

A game object can be decomposed cleanly and precisely into a Entity (identifier), individual components (single properties), systems(game rules, game object behaviours).


The extraction of a system from a single game object, lets the system be used for all game object that have the components on which the system operates. 

Within a ECS pattern, game objects are no longer a black box monolith, encapsulated structure with complex inheritance. They are now a simple group of components, data, identified by a Entity on which systems operate.

A game object can be modeled like a database record.
The whole game can be viewed like a interactive database system that processes data in real time to create a experience for the users.


## Modules:


### Memory:

This module is a subsystem that is responsible for allocating and freeing memory, organizing data into memory layout that is cache-friendly and provides fast access to data.
It uses a Structs of Arrays as the primary data storing unit.
Each SoA is stores a single type of components with the ownership data.
The component data is stored into packed arrays and the ownership data is stored into a sparse array, where each index position represents the ID and the value at each index is the index of the component that belongs to that ID.

The memory system has a clean and simple interface for each SoA:
  1. init - initilaze the SoA to store a fixed size of components of a type.
  2. push - adds a component for a entity to the end of SoA, only if the SoA storage is not full.
  3. remove - removes a component that belongs to a entity, uses swap with the last element removal.
  4. free - frees the allocated storage for a SoA.
  5. print - debug printing of all the components of the SoA.


### Entity:
Header defining the structure and the informations that are used to identifie and group components into a Entity.

### Components:
Header file where components are defined, it provides a template for instanciating diffrent component objects.

### Systems:
Logical subsystem responsiable for logical data manipulation.


### Input:
Susbsystem that manages interactions with the users of the systems by providing a interface for accepting input devices data and processing them into a commands.

### Render:
Data visualziation subsystem. Responsiable for displaying drawable entities visualy on the screen.



## File Organization:
```
ecs-engine/
│
├── include/                 # Public headers
│   ├── ecs.h                # Main ECS interface
│   ├── entity.h             # Entity management
│   ├── component.h          # Component definitions
│   ├── system.h             # System interface
│   ├── memory.h             # Memory management (dynamic arrays, allocators)
│   ├── input.h              # User input handlers
|   └── render.h             # Displays data on the screen
|
├── src/                     # Source files
│   ├── ecs.c                # ECS engine core
│   ├── entity.c             # Entity implementation
│   ├── component.c          # Component storage/management
│   ├── system.c             # System execution logic
│   ├── memory.c             # Dynamic array / memory subsystem
│   ├── input.c              # Converts user input into commands, that call systems on specific entities
|   └── render.c             # Draws the entites on the screen
|
├── examples/                # Example usage of your ECS
│   └── main.c               # Sample game loop or test
│
├── tests/                   # Unit tests
│   ├── test_entities.c
│   ├── test_components.c
│   ├── test_systems.c
|   ├── test_input.c
|   ├── test_render.c
│   └── test_memory.c
│
├── CMakeLists.txt           # Build system file (if using CMake)
├── Makefile                 # Optional Makefile for building
└── README.md                # Project overview
```

## Moduls Interactions:

## ECS:

The ECS modul interacts directly with the systems modul, inderectly it interacts through the systems modul with a;; the other moduls.

## Systems:

This modul interacts with the ECS modul through function return values, signals that help the ECS decide what system to call next, should it stop...
Systems modul interacts with the memory subsystem through the memorys interface, the main reason for interacting with memory is to get data and send data to be stored.

## Memory:

This modul interacts only with the system modul by providing data to it or receving data from the systems to store.

## Input:

This modul interacts only with the ECS modul by returning commands that represent a sequence of systems calls.

## Render:

Render is a isolated systems modul that is responsiable for drawing the entities on the screen so its main interaction is with the memory same like the systems modul.

## How the data is structured:

### Entity:
A simple struct that has two data members a id that represents a index that is used to accses its components in the array.
A integer mask whose set bits represent the components that the entity has.

### Components:
Structs that have a smeantic a name and hold the data that define a property. Example positon component:
Name: Position
Data:
int x - x coordinate
int y -  y coordiante

### Systems:

Functions that return a optional value that represents a signal for the ECS modul, take no arguments or take a entity argument. The component set with which they operate is hard coded inside them (for now).

### Input:

Functions that take input device data and convert the input into a command.

### Render:

Function that takes no arguments, goes through all entities drawing the entities that have draw component.

## List of Systems:

1. move_system(Entity e) - a system that moves a entity in 2d grid and checks for collisons uses a Entitys velocity component to update the state of the Entitys position component.
2. attack_system(Entity source, Entity target) - a system that mainpulates the target entitys health component with the data from the source entitys attack component.

