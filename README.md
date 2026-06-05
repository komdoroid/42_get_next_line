*This project has been created as part of the 42 curriculum by kkomurat*

# get_next_line

> Reading a line from a file descriptor — one call at a time.

---

## Description

`get_next_line` is a C function that reads and returns one line at a time from a given file descriptor. Calling it repeatedly allows you to iterate through an entire file line by line, without loading everything into memory at once.

The project introduces one of C's most important concepts: **static variables** — variables that retain their value between function calls. This is used to maintain a persistent "stash" of unprocessed bytes across calls, so that data read beyond a newline isn't lost.

### Key behaviors

- Returns the next line from `fd`, including the trailing `\n` (except at end-of-file if the file doesn't end with one)
- Returns `NULL` when there is nothing left to read, or on error
- Works with both regular files and standard input (`stdin`)
- Buffer size is configurable at compile time via `-D BUFFER_SIZE=n`
- Undefined behavior if the file is modified between calls before EOF is reached

---

## Instructions

### Compilation

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

The `BUFFER_SIZE` macro defines how many bytes `read()` fetches per call. You can change this value to test different behaviors. If omitted, a default value defined in the header is used.

### Usage

**main func**
```c
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		fd2;
	char	*line;
	char	*line2;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("cant open\n");
		return (1);
	}
	fd2 = open("test2.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("cant open\n");
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line != NULL)
			printf("%s", line);
		line2 = get_next_line(fd2);
		if (line2 != NULL)
			printf("%s", line2);
		if (line == NULL && line2 == NULL)
			break;
	}
	free(line);
	free(line2);
	close(fd);
	close(fd2);
	return (0);
}
```

**test.txt**
```txt
Hello, 
42 
Tokyo .
```

**test2.txt**
```txt
Mr and Mrs Dursley, of number four, Privet Drive, were proud to say that they were perfectly normal, thank you very much.
The Cupboard under the Stairs
4 Privet Drive
Little Whinging
Surrey
```

### Files

| File | Description |
|------|-------------|
| `get_next_line.h` | Header — prototypes and includes |
| `get_next_line.c` | Core logic of `get_next_line()` |
| `get_next_line_utils.c` | Helper functions (string ops, etc.) |

Bonus files follow the same structure with a `_bonus` suffix.

---

## Algorithm

### Overview

Each call to `get_next_line()` must return exactly one line, even though `read()` operates on fixed-size chunks (the buffer). The core challenge is bridging these two different granularities.

The solution uses a **static stash variable** — a string that persists across calls and accumulates buffered data until a full line is available.

### Three-phase loop

```
┌─────────────────────────────────────┐
│  1. READ                            │
│     read() → append chunk to stash  │
│     repeat until '\n' found or EOF  │
├─────────────────────────────────────┤
│  2. EXTRACT                         │
│     isolate everything up to '\n'   │
│     → this is the line to return    │
├─────────────────────────────────────┤
│  3. UPDATE STASH                    │
│     keep everything after '\n'      │
│     → used as input for next call   │
└─────────────────────────────────────┘
```

### Why a static variable?

`read()` does not remember its position across calls — each call advances the file offset at the OS level, but the bytes already fetched into the buffer are only available in that function scope. Without a static stash, any bytes read beyond a newline would be silently discarded.

By declaring `static char *stash`, the leftover data survives between calls:

```
Call 1: read returns "Hello\nWorld"
        → return "Hello\n"
        → stash = "World"

Call 2: stash already has "World"
        → read more if no '\n' yet
        → return "World\n" (or "World" at EOF)
        → stash = ""
```

### Bonus: multiple file descriptors

The bonus implementation uses `static char *stash[OPEN_MAX]` — an array indexed by `fd`. This allows the function to track independent stashes for multiple open file descriptors simultaneously, without any cross-contamination between them.

### Design rationale

This approach was chosen because it:
- Reads the minimum amount necessary per call (stops as soon as a `\n` is found)
- Avoids loading the entire file into memory
- Correctly handles any `BUFFER_SIZE` value, including 1 and very large values
- Cleanly separates reading, extraction, and state management

---

## Resources

### Documentation

- [`read(2)` — Linux man page](https://man7.org/linux/man-pages/man2/read.2.html)
- [`open(2)` — Linux man page](https://man7.org/linux/man-pages/man2/open.2.html)
- [C static variables — cppreference.com](https://en.cppreference.com/w/c/language/storage_duration)

### Articles & tutorials

- [Understanding file descriptors in Unix](https://bottomupcs.com/file_descriptors.xhtml)

### AI usage

AI was used for:
- Debugging issues
- Reviewing code structure
- Help with creating README

AI (Claude) was used as a **learning aid** during this project — specifically to clarify concepts around static variable initialization, C memory semantics (zero-initialization of static locals vs. indeterminate state of automatic locals), and to sanity-check reasoning about the stash accumulation pattern. No code was generated or copied by AI.
