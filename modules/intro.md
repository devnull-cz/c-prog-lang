# Introduction

- All information on https://devnull-cz.github.io/c-prog-lang/
	- see the References section for recommended materials
- Make sure you DO SUBSCRIBE TO THE MAILING LIST (see the seminar http page
  above).
- Getting credits - see the seminar web page above.
- What is C.
- Popularity of C:
  [TIOBE\_index on wikipedia](https://en.wikipedia.org/wiki/TIOBE_index), direct
  link to the current [TIOBE\_index](https://www.tiobe.com/tiobe-index/)
- C89, C99, C11 (ie. 2011), C17 (only fixes issues found in C11) standards,
  and current C23 (published at October 31, 2024).  Due to time constraints, we
  will focus on C99.
- Why it's worth learning C?
	- Helps with better understanding of computers
	- Lingua franca of programming
	- Lots of important code in C (Linux and Android kernel, Apple iOS
	  kernel
	  ([Darwin](https://en.wikipedia.org/wiki/Darwin_(operating_system)),
	  also see [PureDarwin](http://www.puredarwin.org/)),
	  major parts of Windows kernel, OpenSSH, OpenSSL,
	  Apache, NGINX, cURL, etc. etc.)
	- Based on the previous, C programmers will be needed virtually for ever
	- Fast, very portable
		- However, now at the expense of having very complex compilers
		  (see e.g. https://queue.acm.org/detail.cfm?id=3212479)
	- Battle proven
	- Great cost/benefit ratio wrt spent time learning the language
	- Still cool and fun
- Objectives of the seminar
	1. You should be able to write and understand non-trivial C code (we
	   focus on C99).
	2. You should be able to recognise whether C is appropriate for solving
	   a specific problem.
	3. You should understand why it may be so easy to get burned when
	   working in C.
		- [A Case Study of Toyota Unintended Acceleration and Software
		  Safety](https://users.ece.cmu.edu/~koopman/pubs/koopman14_toyota_ua_slides.pdf)
- We are here to help you understand concepts, see the big picture, and learn
  new stuff.  SO, IF YOU HAVE A QUESTION, ASK.
	- Ideally use the mailing list so that it's beneficial for others, too.
- Please do read the C style document and DO USE the C style.  The link is on
  the seminar page, or you can get it here:
  https://devnull-cz.github.io/unix-linux-prog-in-c/cstyle.html
- Source code files are in
  https://github.com/devnull-cz/c-prog-lang/tree/master/src
- Clone the github repo using:

```
git clone https://github.com/devnull-cz/c-prog-lang.git
```
