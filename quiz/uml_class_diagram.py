import random

def run_quiz():
    # Data extracted from your summary
    patterns = [
        # Creational
        "Abstract Factory",
        "Builder",
        "Factory Method",
        "Prototype",
        "Singleton",
        
        # Structural
        "Adapter",
        # "Bridge",
        "Composite",
        "Decorator",
        # "Facade",
        # "Flyweight",
        # "Proxy",
        
        # Behavioral
        "Chain of Responsibility",
        "Command",
        # "Interpreter",
        # "Iterator",
        # "Mediator",
        # "Memento",
        # "Observer",
        # "State",
        "Strategy",
        # "Template Method",
        # "Visitor"
    ]

    random.shuffle(patterns)


    print("=== Design Pattern UML Class Diagram Quiz ===")
    print("Type 'q' to quit at any time.\n")

    for name in patterns:
        print(f"draw UML for {name} pattern")
        print("-" * 30)

        if input().strip().upper() == 'Q':
            print("\nQuiz terminated.")
            break
        

    print("Quiz Finished!")

if __name__ == "__main__":
    run_quiz()