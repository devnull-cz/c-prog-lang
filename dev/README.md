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

TBD
