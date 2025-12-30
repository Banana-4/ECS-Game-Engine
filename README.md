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

In a ECS pattern the whole game is just a state machine where each execution is a transition defined by the order of execution of systems.


