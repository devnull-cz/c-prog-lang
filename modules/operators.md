# Basic operators

- An equality operator is `==` since a single `=` is for an assignment.

```C
int i = 13;
if (i == 13) {
	// will do something here
}
```

- Logical AND and OR:

```C
if (i == 13 && j < 10) {
	// ...

if (i == 1 || k > 100) {
	// ...
```

- You do not need extra ()'s as `||` and `&&` have lower priority than `==` and
  `<`, `>`, `<=`, `>=`, and `!=`.  We will learn more about operator priority in
  later lectures.

- Non-equality is `!=`

```C
if (i != 13) {
	// ...
}
```
