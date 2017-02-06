RetroChallenge 2016/10 - One bodge to fix them all
##################################################
:date: 2016-11-02 21:35
:author: moop
:category: RC2014, Retrochallenge
:slug: retrochallenge-201610-one-bodge-to-fix-them-all
:status: published

It's two days past the deadline, but I found an extra moment to work on
my SD card interface today and I have it working!

I switched the clock output to the SD card from SH\_CLK to /SH\_CLK to
move the rising edge of the clock to a point where the output from the
shift register is stable, and now it works nicely.

[caption id="attachment\_1031" align="alignnone" width="1024"]\ |It's
always a one character Fix!| It's always a one character Fix![/caption]

This eliminated the critical timing that the Bus Pirate was have gotten
away with but my circuit did not.

[caption id="attachment\_1027" align="alignnone" width="1024"]\ |0x40|
0x40[/caption]

[caption id="attachment\_1028" align="alignnone" width="1024"]\ |0x95
and a response| 0x95 and a response (0x01)[/caption]

[caption id="attachment\_1029" align="alignnone" width="1024"]\ |SPI
Decoder| SPI Decoder[/caption]

Once I had this working I checked that the 74HCT595 was clocking the
data coming back from the SD correctly. Since my test program soft
resets the rc2014 when it finishes I was able to check this from BASIC.

[caption id="attachment\_1030" align="alignnone" width="1024"]\ |Reading
back the response| Reading back the response[/caption]

Now that this is working I need to write a (less messy) program to fully
initialise the SD card and switch to fast mode. Once that is done I will
verify the schematic by rebuilding the circuit on stripboard from the
schematic, before designing a proper PCB for the circuit including a
proper SD card socket.

There are also a couple of potential minor hardware improvements to
investigate:

-  As noted in my last post that it's likely that I can get rid of the
   second 74HCT374 and switch to just using the simple edge trigger
   circuit.
-  Fast mode should be pretty optimal when used with the Z80 OTIR
   instruction to write many bytes of data from memory straight to an IO
   port, however for reading data from the card I currently need to
   alternate writing 0xff and then read the result back with with an IN
   instruction. I can use the INI instruction to automatically keep
   track of where the read bytes should go in memory but I can't use the
   INIR instruction which would be faster. Some extra logic to
   (optionally) trigger a write after a read would allow me to use INIR
   to read blocks of data with the implicit write priming the input
   shift register with the next byte after each read.

Finally, here's the final schematic:

[caption id="attachment\_1032" align="alignnone" width="1488"]\ |Final
Schematic| Final Schematic[/caption]

Even though I didn't quite get it done within the deadline I can call
this RetroChallenge a success (it was definitely good motivation).

For bonus points I managed to use exactly all the gates in the 7400 quad
NAND and 7404 hex inverter that make up my glue logic.

Now it's probably time to start reading the CP/M BIOS Alteration Guide!

.. |It's always a one character Fix!| image:: http://www.moop.org.uk/wp-content/uploads/2016/11/IMG_20161102_210914.jpg.sm_.jpg
   :class: size-full wp-image-1031
   :width: 1024px
   :height: 766px
   :target: http://www.moop.org.uk/index.php/2016/11/02/retrochallenge-201610-one-bodge-to-fix-them-all/img_20161102_210914-jpg-sm/
.. |0x40| image:: http://www.moop.org.uk/wp-content/uploads/2016/11/IMG_20161102_200157.jpg.sm_.jpg
   :class: size-full wp-image-1027
   :width: 1024px
   :height: 766px
   :target: http://www.moop.org.uk/index.php/2016/11/02/retrochallenge-201610-one-bodge-to-fix-them-all/img_20161102_200157-jpg-sm/
.. |0x95 and a response| image:: http://www.moop.org.uk/wp-content/uploads/2016/11/IMG_20161102_200226.jpg.sm_.jpg
   :class: size-full wp-image-1028
   :width: 1024px
   :height: 766px
   :target: http://www.moop.org.uk/index.php/2016/11/02/retrochallenge-201610-one-bodge-to-fix-them-all/img_20161102_200226-jpg-sm/
.. |SPI Decoder| image:: http://www.moop.org.uk/wp-content/uploads/2016/11/IMG_20161102_200335.jpg.sm_.jpg
   :class: size-full wp-image-1029
   :width: 1024px
   :height: 766px
   :target: http://www.moop.org.uk/index.php/2016/11/02/retrochallenge-201610-one-bodge-to-fix-them-all/img_20161102_200335-jpg-sm/
.. |Reading back the response| image:: http://www.moop.org.uk/wp-content/uploads/2016/11/IMG_20161102_200739.jpg.sm_.jpg
   :class: size-full wp-image-1030
   :width: 1024px
   :height: 766px
   :target: http://www.moop.org.uk/index.php/2016/11/02/retrochallenge-201610-one-bodge-to-fix-them-all/img_20161102_200739-jpg-sm/
.. |Final Schematic| image:: http://www.moop.org.uk/wp-content/uploads/2016/11/z80_sd_interface.sch_.png
   :class: size-full wp-image-1032
   :width: 1488px
   :height: 1052px
   :target: http://www.moop.org.uk/index.php/2016/11/02/retrochallenge-201610-one-bodge-to-fix-them-all/z80_sd_interface-sch-2/
