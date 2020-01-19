[![Github Actions status](https://github.com/devnull-cz/c-prog-lang/workflows/Refresh%20notes/badge.svg)](https://github.com/devnull-cz/c-prog-lang)

# c-prog-lang
Programming in C

See [lecture-notes](/lecture-notes) for notes from individual classes.

See [style.md](/style.md) on the style used.

## Modifying lecture notes

In the directory `input`, you define each lecture via including individual
modules from the `modules` directory.  For example, `input/2020/01.md` looks
like this:

```
#include "modules/intro.md"
#include "modules/hello-world.md"
#include "modules/basics.md"
#include "modules/moving-star.md"
```

When you push a new changeset to the repo, the github backend will automatically
process the input files and generates ready to use notes in Markdown in the
`lecture-notes` directory.  In the `doc` directory, you will find HTML version
of the notes.

The idea is to write small but self-contained modules so that for each year,
based on how it goes, we can easily create notes just by including modules as
needed.

You should never put notes into the input files.
