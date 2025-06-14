# Issue 48: Describe the terms and fundamentals associated with object oriented programming using Python

## Class
Defines an object's interface and implementation. Specifies the object's internal representation and defines the operations the object can perform.
Templates for an object. Classes generically describe the characteristics of an object (non-specific) by defining what the object can / cannot do, 
how they behave, etc. 

## Object
A run-time entity that packages both data and the procedures that operate on that data. Instances of a class. The object is a unique existence of a
class.    

## Difference between an object when discussing a class
Classes are a broad-stroke characterization (eg. a book genre - Shakespearean plays) and an object is a specific instance of that class 
(eg. a specific book of that genre - Romeo and Juliet).

## Advantages to OO Programming
Allows developers to compartmentalize more complex concepts into programming. Instead of only being able to hold singular pieces of data into a
variable, developers can now encapsulate more complex attributes like a chess piece through multi-faceted structures or classes.

## Inheritance
A relationship that defines one entity in terms of another. In OO, there are several different kinds of relevent inheritances. 

- Class Inheritance (from a derived Class / subclass)
- Interface Inheritance
- Implementation Inheritance

Inheritance is the concept that establishes the class hierarchy to which related classes branch off of each other. 

## "Super" Keyword
Refers to the higher echelon class to which subclasses are based.

## Initialization function of a constructor
The initialization function of a constructor in Python is the `__init__` method. 
This method is automatically called when a new instance of a class is created. And this method primarily intializes attributes of a
newly created class in the format below.

```
class ClassName:
    def __init__(self, attr1, attr2):
        self.attr1 = attr1
        self.attr2 = attr1

obj1 = ClassName(attr1_value, attr2_value)
```

### Attributes of a class
Attributes are variables that contain an object's state information or data. Attributes are characteristics that provide details
about a specific instance of a class. Attributes come in two primary varieties:
- Instance Attribute (An attribute specific to an instance of a Class)
- Class Attribute (An attribute specific to all members of a Class)

### "Self" Keyword
In instantiating classes, the default first parameter is always `self`. This keyword represents any instance of the created
class, allowing the initialization of the object's attributes. Because of the generic keyword, ensuing objects created from 
the class can have their attributes access using their own name in conjunction with the dot operator. For instance, 
in the above example, the attributes `attr1` and `attr2` can be accessed for `obj1` via `obj1.attr1` and `obj1.attr2` because of the 
"self" keyword in the class definition.  

## Getter and Setter Functions
Functions used to access and modify attributes of a class. Get and Set are principles of OOP's encapsulation principle.
### Getters
Retrieves the value of a private or protected attribute. Allows controlled access to the attribute. Allows for validation, formatting, or transformation on access
The getter method essentially allows for read-only access to an attribute within a class

```
class ClassName:
    def __init__(self, attr1, attr2):
        self.__attr1 = attr1    # Initialize a private attribute
        self.attr2 = attr1

    def get_attr1(self):
        return self.__attr1

obj1 = ClassName(attr1_value, attr2_value)
print(obj1.get_attr1())         # Retrieves the private attribute
```

### Setters
Modifies the value of a private or protected attribute. Controls how attributes are updated via validation or sanitation. By defining a setter method within a
class, the developer can dictate how an attribute within a class can be set or changed/updated. 

```
class ClassName:
    def __init__(self, attr1, attr2):
        self.__attr1 = attr1    # Initialize a private attribute
        self.attr2 = attr1

    def set_attr1(self, attr1):
        if len(attr1) > 0:
            self.__attr1 = attr1
        else:
            print("Invalid attribute value")

obj1 = ClassName(attr1_value, attr2_value)  # Define original attribute values for the object
obj1.set_attr1(attr1_value2)                # Update attribute 1 on the condition defined within the class' setter function for attr1
```

## Factory Design Pattern
A creational pattern that defines an interface for creating an object, but lets subclasses decide which class to instantiate. 
This method essentially lets a class defer instantiation to its subclasses; It is easier for the developer to make code for a series of 
products that they may not be completely certain. The responsibility of creating a concrete product is solely given to a single interface 
called a "factory". The shared attributes of a concrete product are abstracted into a method that makes it easier for the developer to 
modify the concrete products without significantly impacting the overall structure of the existing code.    

## Singleton Design Pattern
A creational pattern that ensures a class only has one instance, and provide a global point of access to it. The structure of this pattern
allows for frequent re-use of the data within due to its singular instance - preferrably one object at a time. This characteristic ensures 
consistent data retrieval and faster access. As such, this design pattern relies more on getter methods and limits, if not prohibits, setter
methods.  

## Adapter Design Pattern
A structural pattern that converts the interface of a class into another interface clients expect. Adapter lets classes work together 
that couldn't otherwise because of incompatible interfaces. For example, if an existing UI uses XML data and want to transform the data 
to be compatible with JSON classes without compromising the existing UI. In order to rectify theis interface change, a method must be 
developed to allow for different interfaces to be readable by the existing interface. 

## Bridge Design Pattern
A structural pattern that decouples an abstraction from its implementation so that the two can vary independently. Instead of creating brand new
classes based on an overly complex hierarchy, new classes are formed from existing objects. The design principle shifts from a focus on inheritance
to composition. Specifically, a new class is created using an object as an attribute. This flexibility allows for a large class to split into separate,
independent hierarchies so that the developer does not have to overcomplicate and repeat code just to create a similar subclass.  

## Works Cited

Gamma E, Helm R, Johnson R, Vlissides J. Design Patterns: Elements of Reusable Object-Oriented Software. Addison-Wesley; 1995.