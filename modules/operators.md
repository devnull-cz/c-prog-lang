# Operators

- equality is `==` since a single `=` is an assignment operator
```
	int i = 13;
	if (i == 13) {
		// will do something here
	}
```
- logical AND and OR
```
	if (i == 13 && j < 10) {
		...

	if (i == 1 || k > 100) {
		...
```
	  - you do not need extra ()'s as `||` and `&&` have lower priority
	    than `==` and `<`, `>`, `<=`, `>=`, and `!=`.  We will learn more
	    about operator priority in later lectures.

- non-equality is !=
```
	if (i != 13) {
		...
	}
```


