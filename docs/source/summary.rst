Summary
=======


+-------------+-------------+--------------------------------------------------------------------------------------------------------------+
| Category    | Example     | Description                                                                                                  |
+=============+=============+==============================================================================================================+
| Creational  | ABFPS       | A creational pattern creates objects.                                                                        |
+-------------+-------------+--------------------------------------------------------------------------------------------------------------+
| Structural  | ABCDFFP     | A structural pattern organizes classes and objects to form larger structures that provide new functionality. |
+-------------+-------------+--------------------------------------------------------------------------------------------------------------+
| Behavioral  | CCIIMMOSSTV | A behavioral pattern describes collaboration between objects.                                                |
+-------------+-------------+--------------------------------------------------------------------------------------------------------------+
| Concurrency |             | A concurrency pattern supports concurrent processing.                                                        |
+-------------+-------------+--------------------------------------------------------------------------------------------------------------+

Creational
----------

+------------------+-------------+--------------------------------------------------------+
| Pattern          | Participant | Description                                            |
+==================+=============+========================================================+
| Abstract Factory | AACCC       | Mastering Object Creation Elegantly                    |
+------------------+-------------+--------------------------------------------------------+
| Builder          | BCDP        | Crafting Custom Objects with Clarity                   |
+------------------+-------------+--------------------------------------------------------+
| Factory Method   | CCCP        | Enhancing Flexibility with Polymorphic Manufacturing   |
+------------------+-------------+--------------------------------------------------------+
| Prototype        | CCP         | Mastering Object Cloning for Efficient Instantiation   |
+------------------+-------------+--------------------------------------------------------+
| Singleton        | S           | Implementing Global Access Points in Java Applications |
+------------------+-------------+--------------------------------------------------------+

Explicit Client: Abstract Factory, Prototype

Structural
----------

+------------------+-------------+-----------------------------------------------------------+
| Pattern          | Participant | Description                                               |
+==================+=============+===========================================================+
| Adapter          | AACT        | Seamless Integration of Incompatible Systems              |
+------------------+-------------+-----------------------------------------------------------+
| Bridge           | ACIR        | Decouple Abstraction from Implementation                  |
+------------------+-------------+-----------------------------------------------------------+
| Composite        | CCCL        | Building Flexible Tree Structures                         |
+------------------+-------------+-----------------------------------------------------------+
| Decorator        | CCCD        | Extending Classes Dynamically                             |
+------------------+-------------+-----------------------------------------------------------+
| Facade           | FS          | Simplifying Complex System Interfaces                     |
+------------------+-------------+-----------------------------------------------------------+
| Flyweight        | CCFFU       | Maximizing Memory Efficiency with Shared Object Instances |
+------------------+-------------+-----------------------------------------------------------+
| Proxy            | PRS         | Enhancing Security and Control with Smart Proxies         |
+------------------+-------------+-----------------------------------------------------------+

| Explicit Client: Adapter, Composite, Flyweight
| Implicit Client: Bridge, Proxy

Behavioral
----------

+-------------------------+-------------+-----------------------------------------------------------------+
| Pattern                 | Participant | Description                                                     |
+=========================+=============+=================================================================+
| Chain of Responsibility | CCH         | Building Robust Request Handling Mechanisms                     |
+-------------------------+-------------+-----------------------------------------------------------------+
| Command                 | CCCIR       | Empowering Flexible Command Execution                           |
+-------------------------+-------------+-----------------------------------------------------------------+
| Interpreter             | ACCNT       | Building Custom Parsers for Applications                        |
+-------------------------+-------------+-----------------------------------------------------------------+
| Iterator                | ACCI        | Mastering Sequential Element Access                             |
+-------------------------+-------------+-----------------------------------------------------------------+
| Mediator                | CCM         | Simplifying Object Communications in Complex Systems            |
+-------------------------+-------------+-----------------------------------------------------------------+
| Memento                 | CMO         | Preserving Object State for Undo Operations                     |
+-------------------------+-------------+-----------------------------------------------------------------+
| Observer                | CCOS        | Mastering Reactive Interfaces in Applications                   |
+-------------------------+-------------+-----------------------------------------------------------------+
| State                   | CCS         | Enhancing Behavior Dynamics with State Encapsulation            |
+-------------------------+-------------+-----------------------------------------------------------------+
| Strategy                | CCS         | Streamlining Object Behaviors with Interchangeable Algorithms   |
+-------------------------+-------------+-----------------------------------------------------------------+
| Template Method         | AC          | Streamlining Complex Algorithms with Predefined Scaffolds       |
+-------------------------+-------------+-----------------------------------------------------------------+
| Visitor                 | CCEOV       | Implementing Robust Operations Across Diverse Object Structures |
+-------------------------+-------------+-----------------------------------------------------------------+

| Explicit Client: Chain of Responsibility, Command, Interpreter
| Implicit Client: Iterator, Visitor