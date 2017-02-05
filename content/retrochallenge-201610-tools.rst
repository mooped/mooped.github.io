Retrochallenge 2016/10 - Tools
##############################
:date: 2016-11-01 20:00
:author: moop
:category: RC2014, Retrochallenge
:slug: retrochallenge-201610-tools
:status: published

During `Retro Challenge <http://retrochallenge.net/>`__ I needed a way
to run machine code on my rc2014, as BASIC was incapable of the
performance needed to initialise the SD card in bitbang mode.

I didn't (and still don't) have an EEPROM burner when I first got my
rc2014, and although the version of BASIC in the stock rc2014 ROM does
support the USR() function it appears to jump to a hardcoded address
within the ROM so this didn't help me much.

I ended up finding the assembly language source of the BASIC interpreter
(or one very similar) and noticed that the address the USR() function
jumps to is not looked up directly from the ROM, but copied to a block
of information kept in RAM. Once I knew the address of that block I was
able to modify it so USR(0) would jump to an arbitrary address.

.. raw:: html

   <p>
   <script src="https://gist.github.com/mooped/2965d60b2d19a12425ddbc265453a48b.js"></script>
   </p>

With this method I was able to poke in arbitrary code and execute it,
but this was far from an ideal workflow.

To improve this I wrote some Python scripts which would output the BASIC
code to load a binary image into the RC2014's memory at a given address
or run code from a given address. Once appropriate delays were added to
avoid overflowing the (1 byte) input buffer on the RC2014's serial port
I was able to combine these scripts with
`z80asm <http://www.nongnu.org/z80asm/>`__ and a makefile to make a nice
toolchain for rapidly deploying and testing programs to the RC2014.

.. raw:: html

   <p>
   <script src="https://gist.github.com/mooped/535401475bb524e03f12773798c578db.js"></script>
   </p>

By writing the program such that the RC2014 jumps back to the reset
vector at address 0x0000 programs can be developed without the need to
constantly reset the RC2014 (unless something goes wrong in the
program).

I set up my Makefile with additional commands to output hex dumps of the
program, annotated assembly, or to run a program that is already
resident in memory.

.. raw:: html

   <p>
   <script src="https://gist.github.com/mooped/496e506143abd79d0c97941d3800e8e9.js"></script>
   </p>

The only issue I've encountered with this system so far is that it is
quite slow to load large programs. For my Retro Challenge project the
load time was so long that I had to wait for it to finish before
reissuing the run command. The automatically sent run program was lost
because the loader was still running.

This could be improved by writing a faster loader in assembly which
could be bootstrapped with a very small BASIC program. If I had an
EEPROM burner a replacement boot ROM could be made which would boot
straight into the fast version of the monitor program.

The scripts and Makefile I used are on my GitHub under the `RC2014
Tools <https://github.com/mooped/rc2014_tools>`__ project. They will
work on a Linux system or similar, or on Windows with some
modifications.
