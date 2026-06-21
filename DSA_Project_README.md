# Amusement Park Queue System
A console-based amusement park ride management system built in C++ as a 3rd semester Data Structures & Algorithms project at Bahria University.

> **Group project** — developed collaboratively by Mohid Ali, Shafay, and Wahab.

---

## What It Does
Simulates customer queuing for amusement park rides using a **Priority Queue** built from scratch with a linked list. Customers are served based on their ticket type — VIP first, then FastPass, then Regular.

**Four rides supported:**
- Ferris Wheel
- Merry-Go-Round
- Roller Coaster
- Drop Tower

**Operations available:**
- Add a customer to a ride's queue (with ticket type and ride selection)
- Run a step-by-step console animation of any ride
- Search for a customer by ID across all queues
- Delete a customer by ID from any queue
- Display all current queues

---

## DSA Concepts Used
- **Linked List** — The Priority Queue is implemented manually using a singly linked list (no STL queue used)
- **Priority Queue** — Customers are inserted in priority order (VIP > FastPass > Regular) at enqueue time
- **Enums** — Used to represent ticket types with integer priority values
- **Dynamic Memory Allocation** — Nodes are created with `new` and deleted with `delete`
- **Linear Search** — Used to find and remove customers by ID across the queue

---

## Tech Used
- **Language:** C++
- **Concepts:** Linked Lists, Priority Queues, Enums, Dynamic Memory, OOP

---

## How to Run

**Requirements:** A C++ compiler (g++ recommended)

```bash
# Clone the repo
git clone https://github.com/YOUR_USERNAME/amusement-park-queue-system.git
cd amusement-park-queue-system

# Compile
g++ main.cpp -o park

# Run
./park          # Linux/Mac
park.exe        # Windows
```

---

## Ticket Priority
| Ticket Type | Priority Value |
|-------------|---------------|
| VIP         | 3 (highest)   |
| FastPass    | 2             |
| Regular     | 1 (lowest)    |

Customers with higher priority are always served before lower-priority ones, regardless of arrival order.

---

## Project Structure
```
amusement-park-queue-system/
│
├── main.cpp      # All source code
└── README.md
```

---

## Context
Built as a 3rd semester project for the Data Structures & Algorithms course (BSCS) at Bahria University, Lahore. The core focus was implementing a priority queue from scratch using a linked list — without relying on STL containers — and applying it to a real-world scheduling scenario.
