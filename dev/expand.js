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

var BASE_LINK = "https://github.com/devnull-cz/c-prog-lang/blob/master/"
var SRC_LINK = BASE_LINK + "src/";
var MODULE_LINK = BASE_LINK + "modules/";

markdownInclude.registerPlugin({
	pattern: /#source .+/gm,
	replace: function (tag) {
		var res = tag.split("#source ");
		var file = res[1];
		return res[0] + ':eyes: [' + file + "](" + SRC_LINK + file + ")";
	}
});

markdownInclude.registerPlugin({
	pattern: /^#module .+/gm,
	replace: function (tag) {
		var val = tag.replace("#module ", "");
		var idx = val.indexOf(" ");
		var file = val.substring(0, idx);
		var linkname = val.substring(idx + 1);
		return '[' + linkname + "](" + MODULE_LINK + file + ")";
	}
});

markdownInclude.compileFiles(markdownJson).then(function () {
	console.info(markdownInclude.options.build + ' have been built successfully');
});
