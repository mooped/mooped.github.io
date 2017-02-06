Retrochallenge 2016/10 - Deadline
#################################
:date: 2016-10-31 23:08
:author: moop
:category: Retrochallenge
:tags: RC2014, Retrochallenge
:slug: retrochallenge-201610-deadline
:status: published

I'm at my deadline for RetroChallenge 2016/10 and unfortunately I'm
tantalisingly close to having something that works, but not quite there.

I have the bitbang/slow mode working and generating pulses that match
the output I get from my Bus Pirate when using it to talk to the SD
card. However, the Bus Pirate gets a response and my circuit does not.

I blamed my level shifter for a while. As an experiment I tried writing
to the card from the Bus Pirate and reading the response through the
level shifter works fine, so that can't be the problem.

|Final State Of Play|

Bitbang mode was fixed by adding an additional edge trigger circuit.
Instead of a synchronous edge trigger I used the simple trick of feeding
a signal and an inverted copy of the signal into an AND gate. When the
signal goes high the inverted version remains high for the propogation
delay of the NOT gate used to invert it, so the output from the AND gate
is temporarily high. Since I had a free NAND gate and second free NOT I
used these to build an AND. I ended up picking the existing EDGE signal
(ie. the synchronous edge trigger) as the input to the new edge trigger.
This provided a signal that could be used to make the output flip flop's
latch transparent for only a brief period.

I could probably at this point do away with the synchronous edge trigger
and save a mostly unused 74HCT374, but there was no time to test this
today. I will test this when I get chance.

With the bitbang mode working I was able to attempt to initialise the SD
card at the low clock rate it requires. After some fiddling I discovered
that my output pulse train was off by one relative to the clock pulse.
In an effort to get things to work I bodged the values I was writing to
make the output signal match what I see when using the Bus Pirate. This
included adding a new bit to the CONFIG register to drive the serial
input on the output shift register. This ensured the Data Out line
(MOSI) to the SD card was pulled high, in order to match exactly the Bus
Pirate's behaviour.

|CMD0 on Bus Pirate|

It was difficult to get a screenshot that captured the whole pulse
train, but the above shot shows the Bus Pirate sending CMD0 (0x40, 0x00,
0x00, 0x00, 0x00, 0x95) and receiving 0xFF (no response) followed by
0x01 (OK). The shot below shows the commands sent to the Bus Pirate and
the response.

|Bus Pirate Commands|

The next shot shows my circuit sending the same output, but recieving no
response.

In both cases a large number of clock pulses were sent with the SD
card's chip select deasserted, as is apparently required to initialise
the card.

|CMD0 From My Circuit|

My suspicion is that either my timing is too fast - I'm currently
running at 330kHz while the Bus Pirate is running at 33kHz - or the
rising edge of my clock is very subtly off with respect to the data.

There are still hardware bugs (the off by one issue, mainly), but the
final schematic and final netlist are included below for posterity.

|Final Schematic|

|Final Netlist|

I plan to continue working on this project after RetroChallenge and will
and post further updates as I figure it out.

I also plan to write a post about the toolchain I have setup for running
assembly programs quickly and painlessly on the RC2014. Hopefully I'll
be able to post that tomorrow.

.. |Final State Of Play| image:: http://www.moop.org.uk/wp-content/uploads/2016/10/IMG_20161031_222456.jpg.sm_.jpg
   :class: size-full wp-image-1012
   :width: 1024px
   :height: 766px
   :target: http://www.moop.org.uk/index.php/2016/10/31/retrochallenge-201610-deadline/img_20161031_222456-jpg-sm/
   :alt: Final State Of Play
.. |CMD0 on Bus Pirate| image:: http://www.moop.org.uk/wp-content/uploads/2016/10/IMG_20161031_220127.jpg.sm_.jpg
   :class: size-full wp-image-1010
   :width: 1024px
   :height: 766px
   :target: http://www.moop.org.uk/index.php/2016/10/31/retrochallenge-201610-deadline/img_20161031_220127-jpg-sm/
   :alt: CMD0 on Bus Pirate
.. |Bus Pirate Commands| image:: http://www.moop.org.uk/wp-content/uploads/2016/10/IMG_20161031_215925.jpg.sm_.jpg
   :class: size-full wp-image-1009
   :width: 1024px
   :height: 766px
   :target: http://www.moop.org.uk/index.php/2016/10/31/retrochallenge-201610-deadline/img_20161031_215925-jpg-sm/
   :alt: Bus Pirate Commands
.. |CMD0 From My Circuit| image:: http://www.moop.org.uk/wp-content/uploads/2016/10/IMG_20161031_221128.jpg.sm_.jpg
   :class: size-full wp-image-1011
   :width: 1024px
   :height: 766px
   :target: http://www.moop.org.uk/index.php/2016/10/31/retrochallenge-201610-deadline/img_20161031_221128-jpg-sm/
   :alt: CMD0 From My Circuit
.. |Final Schematic| image:: http://www.moop.org.uk/wp-content/uploads/2016/10/z80_sd_interface.sch_.png
   :class: size-full wp-image-1014
   :width: 1488px
   :height: 1052px
   :target: http://www.moop.org.uk/index.php/2016/10/31/retrochallenge-201610-deadline/z80_sd_interface-sch/
   :alt: Final Schematic
.. |Final Netlist| image:: http://www.moop.org.uk/wp-content/uploads/2016/10/IMG_20161031_223638.jpg.sm_.jpg
   :class: size-full wp-image-1013
   :width: 1024px
   :height: 766px
   :target: http://www.moop.org.uk/index.php/2016/10/31/retrochallenge-201610-deadline/img_20161031_223638-jpg-sm/
   :alt: Final Netlist
