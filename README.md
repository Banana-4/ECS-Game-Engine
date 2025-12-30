# ECS Game Engine

## Goal

This project explores the use of design patterns as tools for reasoning about structuring and understanding complex systems. The goal is to use architectural patterns to clarify how data and behaviour interact within a system.


## ECS

Entity-Component-System is a design aproach that breaks a complex data set managing system into its essential parts: identity, data and behaviour.

 - Entity is a unique identifier that represents a group of components that form a single data set. It has no behaviour or data other then the one used for identifcation.

- Component is a single data entry from a data set. It contains no logic, only state.

- A System  defines behavior. It operates on a set of components, transforming their data by specific rules. Systems  hold the logic of the program.

### How does the ECS pattern achive strcutring, reasoning and understanding:

The separation that it provides allows working independetly on:
1. Reasoning about the structure and informations that define a specific data entry, object.
2. Representing a single information in memory, code.
3. Developing, testing and reasoning about a single bahevior in isolation.
4. Creating a complex system from simple, composable parts.
5. Allows reusing of solution for diffrent data entries.

ECS reduces coupling, improves clarity, allows reusing of concepts and makes large systems easier to reason about and extend.

### ECS design pattern in use as a tool to reason about a game:
A game in the simplest form is made from a set of game objects.
Game object is the basic data unit of a game. A collection of states and operations.
The states are the data properties that define a object.
The operations represent a set of behaviours that the game objects are capable of. Each operation manipulates a set of states, alone or by calling other operations.

#### Loking at a game through the ECS pattern:

1. Game object - represents a identifier for a set of states and behaviours. It is a Entity.
2. State - data that defines a single property of the object, a component.
3. Operation - systems that operate on sets of data.

The ECS cleanly and precisly saparates the game object into Entity, Components and Systems.
The consequance of this saperation is that operations are not any longer tied to a game object.
States are now just parts that can be exchanged and viewed in isolation from logic that should operate on them.
The game object is a identifiable set of data, database entry. It has no behaviour of its own, it is just a collection of editable data.

In a ECS pattern the whole game is just a state machine where each execution is a transition defined by the decisons what systems to call and when.

## Moduls:

### ECS:
The core of the game responsiable for tiening toghter all the subsystems into a game loop.

### Memory:
The memory subsystem is responsable for storing components and entities in memory and for providing efficent accses for systems to data.

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

