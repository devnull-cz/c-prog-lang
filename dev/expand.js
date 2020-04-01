#!/usr/bin/env node

/* eslint-env node */
'use strict';

var myArgs = process.argv.slice(2);
if (myArgs.length != 1) {
	console.info("requires one argument");
	process.exit(1);
}

var markdownJson = myArgs[0]
console.info("processing " + markdownJson);
var markdownInclude = require('markdown-include');

markdownInclude.compileFiles(markdownJson).then(function () {
	console.info(markdownInclude.options.build + ' have been built successfully');
});
