## Dynamic tracing

- dtrace / SystemTap
- should have minimal overhead, mostly can be run on production systems
- provides syscall/library tracing as well as variety of other insights into
  the system (neworking abstractions, CPU performance counters/cache analysis,
  ...)
- allows to ask (before unheard of) questions that could not be answered before
  - e.g. what process is stressing particular disk with I/O, what are the most
    contributing processes that send TCP traffic to port X and what are their
    most frequently executed stack traces, ...
