# Pi Shell
A shell program for PiOS
## TODO

- [ ] Functional keyboard input
- [ ] Parse multiple args
- [ ] Write commands
- [ ] Forks
- [ ] etc.

## Issues

- 

## Running Pi Shell

To launch the operating system emulator, input the following commands:
```bash
make clean
make all
make run
```

Pi Shell is intended to launch after the OS boots, and the shell prompt should load:
```
shell>
```

## Current Features

- A headache

## Planned Features

- File Traversal/Manipulation
	- `mkdir`, `cd`, `touch`, `ls`, `cp`, `mv`, `rm`
- Shell history
	- Read previous inputs using the up and down arrow keys
- Tab Autocompletion
	- When tab is pressed, the shell will attempt to autocomplete the current argument
- Redirection/Piping
	- `>`, `<`, `>>`, 