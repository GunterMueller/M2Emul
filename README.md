# Modula-2 M-Code Interpreter and Virtual Machine
## Overview
This will become an interpreter and virtual machine for Lilith Modula-2 M-Code object files.

Work in progress.

## Current Development Status
* M-Code Loader fully functional (can load and stage modules and their dependencies).
* Runtime debugging is functional:
  * Single-step execution
  * Set breakpoint / execute to breakpoint
  * Register and stack display
  * Procedure call chain display
  * Inspection of data words (variables)
* Provides a minimal set of "standard" Modula-2 runtime libraries to run a simple command interpreter and the ETHZ single pass compiler developed by Niklaus Wirth. 
* Interpreter can already execute the ETHZ Modula-2 single pass compiler.
* Some M-Codes are still disabled for debugging however (due to ongoing tests).

## Key Features Compared To The Lilith Machine
### Functionality in General
* Supports the original M-Code instruction set implemented in the Lilith.
* Binary compatible with the Lilith's object code format and able to execute code generated by the ETHZ Modula-2 single pass and multipass compilers.
* Built-in runtime monitor and debugger.
### Specific Changes And Improvements
* Loads object files from underlying host filesystem (e.g. UNIX) and therefore does not rely on the original Honeywell D140 disk system. This is accomplished by a custom implementation of module "FileSystem" which performs low-level I/O via calls to the "supervisor" M-Code opcode.
* Provides its own dynamic loader for staging of object files and does not rely on the Medos-2 operating system loader in module "Program".
* Provides its own heap memory allocation functions, which again are tied in to the standard module "Storage" via supervisor calls.
* On the Lilith, all modules share the same 65K (16-bit) address space. **m2emul** provides more memory to programs while still maintaining the original 16-bit instruction set by assigning each module its own code space (max. 65KB per module).
### Current Limitations
* No coroutines, interrupts, priorities and multitasking yet.
### Planned Features
* Framebuffer compatible with original code for graphical output (currently, the emulator only runs in terminal-based text mode).

## Build Process
### Prerequisites
* UNIX (Linux) system with **ncurses** support
### Compiling And Installation
1. Download the .tar.gz packages from the "[Releases](https://github.com/ghoss/m2emul/releases)" page.
2. Extract and build:
    ```
    $ tar xzf m2emul-x.y.tar.gz
    $ cd m2emul-x.y
    $ ./configure
    $ make && make install
    ```

## Usage
### Basic Syntax
```
USAGE: mule [-hV] [object_file]

-t      Enable trace mode (runtime debugging)
-h      Show this help information
-V      Show version information

-v      Verbose mode

object_file is the filename of a Lilith M-Code (OBJ) file.
```
### Practical use
* Download all runtime files in the GitHub directory `disk` to a directory of your choice (e.g. `my_directory`).
* Start the MULE command interpreter (shell) with `mule my_directory/Comint`.
* You can now compile any Modula-2 files in `my_directory` with Niklaus Wirth's Modula-2 single pass compiler by typing the command `compile` at the command prompt. Enter the source file name at the compiler's `in>` prompt (note: filenames are case-sensitive).
* Exit the Modula-2 compiler by pressing the ESC (Escape) key at the `in>` prompt.
* For example, compile the included "Hello World" program (`Hello.MOD`) and run it by typing `Hello` at the command interpreter prompt.
* More commands and shell features to follow…
### "Comint" Shell Commands
* `Comint` is a basic command interpreter. You can launch it directly by entering `mule my_directory/Comint`.
* Type the name of any existing Modula-2 object file to execute it (the .OBJ suffix may be omitted).
* `compile` executes Niklaus Wirth's Modula-2 single pass compiler.
* `exit` terminates the shell and returns to the host operating system.
## References and Credits
* Jos Dreesen's "Emulith" Lilith emulator at ftp.dreesen.ch
* The original Lilith disk images at ftp.dreesen.ch
* Sources of the ETHZ single pass compiler, [discovered by Jos Dreesen](https://groups.google.com/g/comp.lang.modula2/c/MOrSzVeRBXA)
* [Various PDF scans](https://github.com/ghoss/m2emul/tree/master/doc) of old ETHZ manuals and dissertations relating to Modula-2 and the Lilith architecture
* A.F. Borchert's [early M-Code interpreter for UNIX Edition VII](https://github.com/afborchert/lilith-emulator) 
* The description of the [Soviet "Kronos" machine](http://www.kronos.ru/documentation), a 32-bit Lilith variant with almost identical M-code semantics
## Other Links
You might be interested in my other UNIX-based, Lilith-related projects, which I built to help develop this interpreter:

* ["m2decode"](https://github.com/ghoss/m2decode), a Lilith M-code object file disassembler 
* ["m2disk"](https://github.com/ghoss/m2disk), a tool to import/export individual files from/to the Lilith disk images provided by Jos Dreesen in his repository at ftp.dreesen.ch
* ["obdisk"](https://github.com/ghoss/m2disk), a tool to export files from Ceres disk images