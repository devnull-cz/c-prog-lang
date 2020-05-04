[![Github Actions status](https://github.com/devnull-cz/c-prog-lang/workflows/Refresh%20notes/badge.svg)](https://github.com/devnull-cz/c-prog-lang/actions?query=workflow%3A%22Refresh+notes%22)
[![Github Actions status](https://github.com/devnull-cz/c-prog-lang/workflows/Compile%20source%20code/badge.svg)](https://github.com/devnull-cz/c-prog-lang/actions?query=workflow%3A%22Compile+source+code%22)

# Programming in C

This repository hosts the materials for teaching the [Programming in C class](http://mff.devnull.cz/c-prog-lang/) at [MFF-UK](http://www.mff.cuni.cz) 

See [lecture-notes](https://github.com/devnull-cz/c-prog-lang/tree/notes) for notes from individual classes in Markdown format and https://devnull-cz.github.io/c-prog-lang/ for HTML format.

## Modifying lecture notes

See [style.md](/style.md) on the style used.

In the directory `input`, you define each lecture via including individual
modules from the `modules` directory.  For example, `input/2020/01.md` looks
like this:

```
#include "modules/intro.md"
#include "modules/hello-world.md"
#include "modules/basics.md"
#include "modules/moving-star.md"
```

Each of the modules is supposed to be self contained - i.e. no recursive
includes.

When you push a new changeset to the repo, the github backend will automatically
process the input files and generates ready to use notes in Markdown in the
`notes` branch.  In the `gh-pages` branch, you will find HTML version
of the notes.

The idea is to write small but self-contained modules so that for each year,
based on how it goes, we can easily create notes just by including modules as
needed.

You should never put notes into the input files unless really specific to a
class, otherwise use modules and include those.
