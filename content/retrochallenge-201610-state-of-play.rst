Retrochallenge 2016/10 - State of Play
######################################
:date: 2016-10-31 17:11
:author: moop
:category: RC2014, Retrochallenge
:slug: retrochallenge-201610-state-of-play
:status: published

As it stands my RetroChallenge entry is close to working, but not quite
there.

The fast mode appears to work and I was able to decode the SPI packets
sent to the SD card with
`OpenLogicSniffer's <http://dangerousprototypes.com/blog/open-logic-sniffer/>`__
SPI analyser module.

[caption id="attachment\_996" align="alignnone" width="1024"]\ |Decoded
Messages| Decoded Messages[/caption]

The picture above shows the signals and the decoded data for the SD card
CMD0 (Software Reset) message which is the first step in initialising
the card. The message is the 6 byte string 0x40 0x00 0x00 0x00 0x00 0x95
where 0x40 is the command (bit 6 is always set), the four 0x00s are the
empty parameter section, and 0x95 is the checksum for this command. More
information on the SD card SPI protocol is available on `this
page <http://elm-chan.org/docs/mmc/mmc_e.html>`__, which I've been
referring to regularly for this project.

The eagle eyed will notice that this capture shows an 8mHz clock and
therefore the device is running in fast mode. For the SD to initialise
correctly it needs to be initially clocked slowly (100-400kHz).

Unfortunately, the slow mode, which I was expecting to be the easy bit
is currently not working due to a hack I used to get fast mode working.

[caption id="attachment\_1005" align="alignnone" width="1488"]\ |Current
Schematic| Current Schematic[/caption]

The current schematic, seen above, shows that the 'Shift /Load' input of
the output data shift register (U3 pin 1) is driven by the SHIFTING net.
This gave the correct timings to load the register when data was
written, as the register's input latch would be transparent while
SHIFTING was low. SHIFTING goes high while the autoshift register (U7)
is outputting a 1, so the last value seen by U3 is latched in just
before the train of clock pulses is generated.

This breaks slow mode because SHIFTING is always low when /BITBANG is
asserted, so the output from U3 is always a copy of whatever is on bit 7
of the data bus.

This should be fixable if I can find a better way to load this register
before time runs out.

.. |Decoded Messages| image:: http://www.moop.org.uk/wp-content/uploads/2016/10/IMG_20161030_211120.jpg.sm_.jpg
   :class: size-full wp-image-996
   :width: 1024px
   :height: 766px
   :target: http://www.moop.org.uk/index.php/2016/10/30/retrochallenge-201610-breadboard-fun/img_20161030_211120-jpg-sm/
.. |Current Schematic| image:: http://www.moop.org.uk/wp-content/uploads/2016/10/z80_sd_interface_20161031am.png
   :class: size-full wp-image-1005
   :width: 1488px
   :height: 1052px
   :target: http://www.moop.org.uk/index.php/2016/10/31/retrochallenge-201610-state-of-play/z80_sd_interface_20161031am/
