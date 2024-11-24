# Online Banking System in C

The **Online Banking System** is a command-line application designed to simulate the core functionalities of a banking system. This project is built in C, demonstrating efficient handling of user accounts, transactions, and account management in a secure and interactive manner. The system supports multiple banking operations like deposits, withdrawals, balance checks, and account creation, all while ensuring robust error handling and data integrity.

---

## **Features**

- **User Account Management:** Create, update, and delete user accounts with secure storage.
- **Transaction Operations:** Perform deposits, withdrawals, and check account balances.
- **Admin Functionality:** View all user accounts and their transaction histories.
- **Data Persistence:** Use file handling in C for storing and retrieving account details.
- **Secure Operations:** Implements basic input validation and error handling for secure transactions.
- **Interactive CLI:** Provides a user-friendly command-line interface.

---

## **Technologies Used**

### **Programming Language**

- **C:** The application is written entirely in C, leveraging its performance and close-to-hardware capabilities.

### **Core Features & Libraries**

- **File Handling:** Utilized to store account data persistently using text files.
- **Standard C Libraries:**
  - `<stdio.h>` and `<stdlib.h>` for input/output operations and memory management.
  - `<string.h>` for managing account names and strings efficiently.

### **Utilities**

- **Modular Design:** Functions for modular operations such as account creation, deposit, and withdrawal.
- **Error Handling:** Ensures graceful handling of invalid inputs and system errors.

---

## **Installation Guide**

To set up and run the **Online Banking System**, follow these steps:

1. Clone the repository:

   ```bash
   git clone https://github.com/Muhdal-Amin/online-banking-system.git
   cd online-banking-system
   ```

2. Compile the source code:

   ```bash
   gcc -o banking_system banking_system.c
   ```

3. Run the application:
   ```bash
   ./banking_system
   ```

---

## **Challenges Encountered**

1. **Data Persistence:**

   - Ensuring data remains intact across program restarts was challenging due to file handling intricacies.
   - **Solution:** Implemented structured text-based storage with clear separators for account records.

2. **Security and Validation:**

   - Preventing invalid inputs like negative amounts or non-existent account access was critical.
   - **Solution:** Added thorough input validation and error messages for each operation.

3. **Concurrency Simulation:**
   - Handling multiple users in a single-threaded application posed limitations.
   - **Solution:** Designed a sequential operation flow to simulate concurrent access without race conditions.

---

## **Lessons Learned**

1. **Importance of Data Structures:** Leveraged arrays and file structures for efficient storage and retrieval.
2. **Robust Input Handling:** Learned to validate user inputs thoroughly to prevent system crashes.
3. **Modular Programming:** Modular design in C greatly simplifies code maintenance and debugging.
4. **File Handling Mastery:** Gained practical experience with persistent data storage techniques in C.

---

## **Future Plans**

1. **Add Multi-threading:** Incorporate threads to handle multiple user sessions simultaneously.
2. **Encryption for Security:** Encrypt sensitive account data stored in files.
3. **GUI Integration:** Expand to a graphical interface for better usability.
4. **Database Integration:** Replace text-based storage with a relational database for scalability.

---

## **Contribution Guidelines**

We welcome contributions to improve the **Online Banking System**! Please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature.
3. Commit your changes with clear messages.
4. Create a pull request to the main repository.

---

## **Acknowledgments**

- **C Programming Community:** For resources and guidance on modular programming and file handling.
- **ADV Learning:** For inspiration and guidance on creating C projects.

---
