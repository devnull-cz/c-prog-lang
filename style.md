# Source code links

use the `#source` tag e.g. like this:

```
#source foo.c
```

and it will be expanded into proper link.

There must be at most one directive on each line. The line can start with
anything however after `#source` is encountered there can be only the file
name.

# Module links

To link to files under the `modules` directory use the `#module` tag like so:

```
#module file.md foo bar
```

that will get turned into link to `modules/file.md` with the description
`foo bar`.

The tag has to be on separate line.

# Markdown styles

  - see source code: :eyes:
  - watch-out: :heavy\_exclamation\_mark:
  - pro-tip: :bulb:
  - task: :wrench:
  - see example: :flashlight:
  - solution: :key:

section links: [Basics](01.md#basics)

ASCII art (indent 4 spaces):

    +---+
    |   |
    +---+
