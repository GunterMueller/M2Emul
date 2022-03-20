# Modula-2 M-Code Interpreter and Virtual Machine
## Overview
This will become an interpreter and virtual machine for Lilith Modula-2 M-Code object files.

Work in progress. Not in a usable state yet.

## Key Features Compared To The Lilith Machine
### Functionality in General
* Supports the original M-Code instruction set implemented in the Lilith.
* Binary compatible with the Lilith's object code format and able to execute code generated by the ETHZ Modula-2 single pass and multipass compilers.
* Built-in runtime monitor and debugger.
### Specific Changes And Improvements
* Loads object files from underlying host filesystem (e.g. UNIX) and therefore does not rely on Medos-2 filesystem and disk structure.
* Provides its own dynamic loader for staging of object files and does not rely on the Medos-2 operating system loader.
* On the Lilith, all modules share the same 65K (16-bit) address space. ```m2emul``` provides much more memory to programs while still maintaining the original 16-bit instruction set by assigning each module its own code space (max. 65K per module) and its own data space (an additional max. 65K words). Of course, only as much memory as actually needed is allocated for loaded modules.
* The stack and the heap also are assigned their own memory spaces, again max. 65K words for each. These sizes are configurable at launch time.
### Planned Features
* Framebuffer compatible with original code for graphical output (currently, the emulator only runs in terminal-based text mode).
* Optional support for disk image files in Medos-2 format (such as those provided for Jos Dreesen's *Emulith* emulator).