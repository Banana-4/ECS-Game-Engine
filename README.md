# ECS Game Engine

## Goals
  0. Make a data processing engine for use in my personal projects.
  1. ECS design pattern - use of the design pattern as a tool for analyzing, understanding complex systems, as a framework for thinking.
  2. Data Driven Design - designing programs around data, storing data for efficient processing.
  3. Exploring the C programming language.
  
## ECS

Entity-Component-System is a approach in design, that breaks a complex system for managing data sets into its essential parts: identity, data and behaviour.
Its main concerns is how to store data for efficient processing by the CPU. To reduce cache misses, and to avoid reading data from main memory that will not be process, keeping the cache filled with data without holes. 


  - Entity is a unique identifier that represents a group of components that form a single data record. It has no behaviour or data other then the one used for identification.

  - Component is a single data cell of a column. It contains no logic, only state.

  - A System defines behavior. It operates on sets of components, transforming their data according to rules for that component type. Systems are the logic of the program.

  
### How does the ECS pattern help with structuring, reasoning and understanding of a game engine:
The ECS is responsible for game data processing. It isolates the data processing of a game engine into a separated system. 

All the benefits that the ECS pattern gives are a consequence of the separation that it provides.
The seperation breaks the complex hard to define responsibility of Data Processing into clean, precise and distinct smaller responsibilities:
1. Reasoning about the structure and informations that define a specific data entry, object.
2. Representation of data in memory and code.
3. Developing, testing and reasoning about systems in isolation.
4. Creating a complex system from simple, composable parts.
5. Allows uniform data processing, one type of data is processed in the same way.

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


## Uses:

THe main purpose of the ECS engine is to provide Entity storage in memory that is organized for processing in groups. To achive this the engine needs to provide the user with the ability to create and delete Entities, iterate over all entities, give acsess to systems that allowe the user to transform the data.
The system lets the use decide how much memory he wants to use for the data.
A Entity without any meaningless data is useless for a system whose purpose is to process data. That leads that the invariant of the system is that all Entities will have data associated with them.
The user is expected to provide on Entity creation the types of components that the entity has.

## Data:
ECS deals with Entities, that is table data:
| IDs | COMPONENT | COMPONENT | COMPONENT |
| KEY | DATA      | DATA      | DATA      |
| KEY | DATA      | -         | DATA      |

The key represents the owner of the data, ID of the Entity.
A component store is a whole column of data.
In a ECS Engine the data is bulk processed, to reduce the amount of main memory reads and copys to the CPU cache.
In ECS the table is broken down into individual columns with ownership.
The individual columns are represented in memory as Structs of Arrays called stores.


## Modules:

### ECS:

This module handles the cordination of other modules. 
It is responsible for:
1. Entity management.
2. Initialization of the ECS data engine.
3. Stoping of the ECS data engine.
4. For providing access to the engine for other functions, other game systems.

#### Entity managment:
This submodule is a set of functions and one entities store.
It is responsible for:
1. Creation and removal of entities.
2. Addition and removal of components to a entity, with respect to the invariant that each entity has only one component of each type.

### Memory:

This module is a subsystem that is responsible for allocating and freeing memory, organizing data using cache-friendly memory layout and providing fast access to it.
It uses Structs of Arrays as the primary data storing unit.
Each SoA stores a single type of components with the ownership data.
The component data is stored into packed arrays and the ownership data is stored into a sparse array, where each index position represents the ID and the value at each index is the index of the component that belongs to that ID.

The memory system has a clean and simple interface for each SoA:
  1. init - initilaze the SoA to store a fixed size of components of a type.
  2. push - adds a component for a entity to the end of SoA, only if the SoA storage is not full.
  3. remove - removes a component that belongs to a entity, uses swap with the last element removal.
  4. free - frees the allocated storage for a SoA.
  5. print - debug printing of all the components of the SoA.


### Entity:

Subsystem for creating IDs, entities.
The subsystems core responsibility is to ensure the creation of unique whole number IDs in inclusive range 0 to MAX_ENTITIES.
Removed IDs are recycled by pusing them onto a stack.

### Components:
The components module is a sub system designed to manage components. 
It is responsible for:
1. Initilization of all the stores.
2. Providing accesess to each store.
3. Allowing data to be stored in a store.
4. Removal of stores. 


### Systems:
This system is responsible for data transformation. Its job is to use the data that is stored in the components stores.

## File Organization:
```
ecs-engine/
│
├── include/                 # Public headers
│   ├── ecs.h                # Main ECS interface
│   ├── entity.h             # Entity creation
│   ├── component.h          # Component managment
│   ├── system.h             # System interface
│   └── memory.h             # Memory management (dynamic arrays, allocators)
|
├── src/                     # Source files
│   ├── ecs.c                # ECS engine core
│   ├── entity.c             # Entity implementation
│   ├── component.c          # Component storage/management
│   ├── system.c             # System execution logic
│   └── memory.c             # Dynamic array / memory subsystem
|
├── examples/                # Example usage of your ECS
│   └── main.c               # Sample game loop or test
│
├── tests/                   # Unit tests
│   ├── test_entities.c
│   ├── test_components.c
│   ├── test_systems.c
|   ├── test_ecs.c
│   └── test_memory.c
│
├── CMakeLists.txt           # Build system file (if using CMake)
├── Makefile                 # Optional Makefile for building
└── README.md                # Project overview
```
