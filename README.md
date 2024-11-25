# Pi Shell
A shell program for PiOS
## TODO

- [X] Functional keyboard input
- [ ] Backspace support
- [ ] Parse multiple args
- [ ] commands.c
- [ ] interact with file system
- [ ] etc.

## Issues

- FATFS not implemented (yet) :(
- No multi-arg support
- Can't backspace/delete text

## Running Pi Shell

To launch the operating system emulator, input the following commands:
```bash
make 
make run
```

Pi Shell is intended to launch after the OS boots, and the shell prompt should load:
```
shell>
```

## Current Features

- Limited support for no-arg commands

## Planned Features

- File Traversal/Manipulation
	- `mkdir`, `cd`, `touch`, `ls`, `cp`, `mv`, `rm`
- Shell history
	- Read previous inputs using the up and down arrow keys
- Tab Autocompletion
	- When tab is pressed, the shell will attempt to autocomplete the current argument
- Redirection/Piping
	- `>`, `<`, `>>`, `|`, `||`, etc.
- Wildcard Selector `*`
- Aliases 