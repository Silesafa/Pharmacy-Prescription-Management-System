# 💊 Pharmacy & Prescription Management System (C++)

A C++ console application for managing pharmacy product catalogs, associative keyword validation for medical instructions, and prescription processing with flat-file persistence.

Developed for the **Introduction to Programming (Course Code 00831)** course at Universidad Estatal a Distancia (UNED) — I Trimester.

---

## 🛠️ Technologies & Tools

- **Language:** C++ (C++11 Standard)
- **IDE:** Code::Blocks
- **Persistence:** C++ File Streams (`<fstream>`)
- **Data Files:** `MEDICAMENTOS.TXT`, `CLAVES.TXT`, `RECETA.TXT`

---

## 🚀 Key Features

The system features an interactive console menu with the following options:

1. **Add Products:** Register pharmacy medications with a unique numeric ID, unique name, and available stock. Persisted in `MEDICAMENTOS.TXT`.
2. **Add Product Associations:** Associate specific keywords with product IDs for prescription validation (e.g., `ACETAMINOFEN` ➔ `TABLETA`). Persisted in `CLAVES.TXT`.
3. **Register Prescription:** Issue prescriptions with a unique ID (starting from 1000), patient name, medication ID, quantity, and usage instructions.
   - **Automated Validation:** Verifies that the designated keyword exists within the typed instruction string before saving.
   - **Inventory Control:** Automatically deducts requested quantities from active medication stock upon successful validation.
4. **Product Catalog Report:** Displays a formatted overview of all registered medications and their quantities.
5. **Prescription Report & Printing:** Generates a formatted layout of processed prescriptions.

---

## ⚙️ Getting Started

1. Clone the repository:
   ```bash
   git clone [https://github.com/Silesafa/Pharmacy-Prescription-Management-System.git](https://github.com/Silesafa/Pharmacy-Prescription-Management-System.git)
