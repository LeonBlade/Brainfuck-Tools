[Brainfuck Tools] - Just a few tools for Brainfuck!
===================================================

To install, just use make:
--------------------------

	$ make

bfprint creates bf code that prints out what message you want:
--------------------------------------------------------------

	$ bfprint "Your message here!"

bfinterp will interpret your bf code (not just for printing messages):
----------------------------------------------------------------------

	$ bfinterp "++++++++++[>++++++>+++++++++>+++>+++++++++>++++++++++++<<<<<-]>+++++>+++++++>++>+>+++<<<<++++++++++++++++++++++++.>++++++++++++++.++++++.---.>.<-----.--------.++++++++++++++..------------------.++++++.--.>.<+++.---.+++++++++++++.-------------.
"

Yo dog, I heard you like pipes:
-------------------------------

	$ bfprint "testing" | bfinterp | bfprint | bfinterp | bfprint | bfinterp | bfprint | bfinterp | bfprint | bfinterp

If you really like this you can install it, defaults to /usr/bin change that if you want:
-----------------------------------------------------------------------------------------
	
	$ sudo make install

Thanks for checking it out
LeonBlade