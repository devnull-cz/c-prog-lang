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

var BASE_LINK = "https://github.com/devnull-cz/c-prog-lang/blob/master/src/";

markdownInclude.registerPlugin({
	pattern: /^#source .+/gm,
	replace: function (tag) {
		var res = tag.split("#source ");
		var file = res[1];
		return ':eyes: [' + file + "](" + BASE_LINK + file + ")";
	}
});

markdownInclude.compileFiles(markdownJson).then(function () {
	console.info(markdownInclude.options.build + ' have been built successfully');
});
