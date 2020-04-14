# Development

Notes about how automation works.

## Auto generate

The content under the `modules` directory is expanded into set of Markdown files in the `notes` branch and set of HTML pages in the `gh-pages` branch.

### Markdown expansion

The markdown files use `#include` directives expanded by the https://github.com/sethen/markdown-include

Github actions run the `dev/expand.sh` script that expands all files under the `input` directory.

#### Expansion by hand

To test expansion of Markdown includes by hand, install pre-requisites first, e.g. on
MacOS:
```
brew install node
npm install markdown-include
```

and then run e.g.:
```
./dev/expand.js input/2020/09.json
```

### HTML expansion

HTML files are constructed from the Markdown files using https://github.com/joeyespo/grip

## Code compile

For quick sanity check the source code files under the `src` directory are compiled. Files listed in `src/blacklist.txt` are avoided since they contain errors on purpose.

This is done using the `dev/compile_src.sh` script.
