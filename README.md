# Portfolio TUI

A full-screen terminal application built with C++ and FTXUI.

## 🚀 Quick Run (Simplest Way)

No C++ compiler or CMake required! If you have **Node.js** installed, you can run this immediately:

```bash
npx @subhrajyoti5/portfolio
```

Or install it globally to use the `subhra` command:

```bash
npm install -g @subhrajyoti5/portfolio
subhra
```

---

## 🛠️ Building from Source (Developers)

If you want to build the project yourself, follow these steps.

### Prerequisites
- **C++ Compiler**: Supports C++17 (MSVC, GCC, or Clang).
- **CMake**: Version 3.14 or higher.
- **Internet Access**: Required to download dependencies (FTXUI).

### Build Steps

1. **Clone the repository:**
   ```bash
   git clone https://github.com/subhrajyoti5/portfolio-tui.git
   cd portfolio-tui
   ```

2. **Configure with CMake:**
   ```bash
   cmake -B build -S .
   ```

3. **Build the project:**
   ```bash
   cmake --build build
   ```

4. **Run the executable:**
   - **Windows:**
	 ```bash
	 .\build\Debug\subhra.exe
	 ```
   - **Linux/macOS:**
	 ```bash
	 ./build/subhra
	 ```

## Project Structure
- `main.cpp`: Main application logic.
- `CMakeLists.txt`: Build configuration.
- `npm-package/`: Wrapper for distributing via npm with pre-compiled binaries.

## License
Personal
