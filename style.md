# Source code links

use the `#source` tag e.g. like this:

```
#source foo.c
```

and it will be expanded into proper link.

There must be only one directive on each line.

# Module links

To link to files under the `modules` directory use the `#module` tag like so:

```
#module file.md foo bar
```

that will get turned into link to `modules/file.md` with the description
`foo bar`.

Like with `#source` the tag has to be on separate line.

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
