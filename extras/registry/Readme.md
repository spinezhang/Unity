# 📚 Unity Test Framework with Dynamic Registration

This extensions — designed for **automatic test group registration** without changing the main entry point. It is useful for the big project with multiple test groups running on single process, particulally for the software running on embedded device.

---

## ✨ Features

- **Dynamic Test Registration**:  
  New test groups/modules can be added without modifying `main()` or a central list.
- **Simple Expansion**:  
  To add a new module, only update the new module’s test file itself.
- **Automatic Test Execution**:  
  `runAllTests()` automatically runs all registered groups.

---

## 🏗️ Project Structure

```plaintext
src/
├── unity_registry.h      # Unity registry header file.
├── unity_registry.c      # Implementation of Unity registry
├── unity_main_with_registry.c  # main()
test/
├── unity_registry_Test1.c # TestGroup1 example
├── unity_registry_Test2.c # TestGroup2 example
```

---
## 🛠️ How to Add a New Test Module
1. Create a new test file (e.g., test_xyz_unity.c).
2. Write your test group and tests normally.
3. Add registration code:
```c
#include "test_registry.h"

TEST_GROUP(Xyz);

// your TEST_SETUP, TEST_TEAR_DOWN, TEST cases here

REGISTER_TEST_GROUP(Xyz); // <-- This registers the group automatically
```
✅ That's it! No need to touch unity_test.c or other files.

 ## 🛠️ Requirements
GCC, this extension only works with gcc for the __attribute__((constructor)).