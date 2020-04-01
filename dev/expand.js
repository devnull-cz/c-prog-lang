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

var BASE_SRC_LINK = "https://github.com/devnull-cz/c-prog-lang/blob/master/src/";
var BASE_MODULE_LINK = "https://github.com/devnull-cz/c-prog-lang/blob/master/modules/";

markdownInclude.registerPlugin({
	pattern: /^#source .+/gm,
	replace: function (tag) {
		var res = tag.split("#source ");
		var file = res[1];
		return ':eyes: [' + file + "](" + BASE_SRC_LINK + file + ")";
	}
});

markdownInclude.registerPlugin({
	pattern: /^#module .+/gm,
	replace: function (tag) {
		var val = tag.replace("#module ", "");
		var idx = val.indexOf(" ");
		var file = val.substring(0, idx);
		var linkname = val.substring(idx + 1);
		return '[' + linkname + "](" + BASE_MODULE_LINK + file + ")";
	}
});

markdownInclude.compileFiles(markdownJson).then(function () {
	console.info(markdownInclude.options.build + ' have been built successfully');
});
