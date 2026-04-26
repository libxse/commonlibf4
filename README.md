# CommonLibF4

### Requirements
* [XMake](https://xmake.io) [3.0.0+]
* C++23 Compiler (MSVC or Clang-CL)

## Getting Started
```bat
git clone --recurse-submodules https://github.com/libxse/commonlibf4
cd commonlibf4
```

### Build
To build the project, run the following command:
```bat
xmake build
```

> ***Note:*** *This will generate a `build/windows/` directory in the **project's root directory** with the build output.*

### Project Generation (Optional)
If you use Visual Studio, run the following command:
```bat
xmake project -k vsxmake
```

> ***Note:*** *This will generate a `vsxmakeXXXX/` directory in the **project's root directory** using the latest version of Visual Studio installed on the system.*

**Alternatively**, if you do not use Visual Studio, you can generate a `compile_commands.json` file for use with a laguage server like clangd in any code editor that supports it, like vscode:
```bat
xmake project -k compile_commands
```

> ***Note:*** *You must have a language server extension installed to make use of this file. I recommend `clangd`. Do not have more than one installed at a time as they will conflict with each other. I also recommend installing the `xmake` extension if available to make building the project easier.*

## Notes

CommonLibF4 is intended to replace F4SE as a static dependency. However, the runtime component of F4SE is still required.
