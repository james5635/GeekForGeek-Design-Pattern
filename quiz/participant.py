import random

def run_quiz():
    # Data extracted from your summary
    patterns = {
        # Creational
        "Abstract Factory": "AACCC",
        "Builder": "BCDP",
        "Factory Method": "CCCP",
        "Prototype": "CCP",
        "Singleton": "S",
        
        # Structural
        "Adapter": "AACT",
        "Bridge": "ACIR",
        "Composite": "CCCL",
        "Decorator": "CCCD",
        "Facade": "FS",
        "Flyweight": "CCFFU",
        "Proxy": "PRS",
        
        # Behavioral
        "Chain of Responsibility": "CCH",
        "Command": "CCCIR",
        "Interpreter": "ACCNT",
        "Iterator": "ACCI",
        "Mediator": "CCM",
        "Memento": "CMO",
        "Observer": "CCOS",
        "State": "CCS",
        "Strategy": "CCS",
        "Template Method": "AC",
        "Visitor": "CCEOV"
    }

    pattern_list = list(patterns.items())
    random.shuffle(pattern_list)

    score = 0
    total = len(pattern_list)

    print("=== Design Pattern Participants Quiz ===")
    print("Type the initials for the participants of the given pattern.")
    print("Type 'q' to quit at any time.\n")

    for i, (name, participants) in enumerate(pattern_list):
        user_input = input(f"[{i+1}/{total}] What are the participants for '{name}'? ").strip().upper()

        if user_input == 'Q':
            print("\nQuiz terminated.")
            break
        
        if user_input == participants:
            print("✅ Correct!")
            score += 1
        else:
            print(f"❌ Incorrect. The correct answer is: {participants}")
        
        print("-" * 30)

    print(f"\nQuiz Finished!")
    print(f"Your final score: {score}/{i if user_input == 'Q' else total}")

if __name__ == "__main__":
    run_quiz()