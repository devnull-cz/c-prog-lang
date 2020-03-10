## Conway 1D

write a 1-D implementation of [Conway's game of life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)
  - use [rule 30](http://mathworld.wolfram.com/Rule30.html) to determine the next
  - use two arrays (one 2-D and one 1-D) to represent the rules and its
    resulting values
    - there are 8 rules, each has 3 values to compare against and one result
  - we now have the arsenal to write 2-D variant however to display 2-D
    world some way to refresh the terminal would be needed so we will stick
    with 1-D.
    - use `\r` to reset the line between iterations
    - sleep for 1 second between iterations (`unistd.h` is needed for that)
  - each life "tick" will print the line representing the world
  - use functions to refactor the code
  - once having a working solution, try to rewrite it to be more efficient
    or elegant (or both)
