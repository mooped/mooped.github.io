Retrochallenge 2016/10 - Previous version and problems
######################################################
:date: 2016-10-15 13:51
:author: moop
:category: Retrochallenge
:tags: RC2014, Retrochallenge
:slug: retrochallenge-201610-previous-version-and-problems
:status: published

In my previous post I promised to show the previous implementation of my
Z80 SD interface, and to run through the problems which I intend to fix
this month.

|Original Z80 SD Interface Schematic|

The 74138 (U1) in the top left of the schematic is used to detect and
decode IO reads and writes from the Z80. Three bits of the address bus
(A7, A1, A0) are decoded along with the /RD line, M1 line and /IORQ
line. With this configuration the device responds to any IO address
between 0x80 and 0xff. Some more gates will be used to further decode
the address later. The lower two bits (ie. the address modulo 4) select
a register within the device. Address 0 selects the DATA shift register
(U4) for reads or writes while address 1 selects the CONFIG register
(U3) for writes only.

One NAND gate from the 7400 (U2A) quad NAND is used to invert the
CONFIGWR signal, as the 74138 outputs are active low while the latch
input on the 74374 is active high.

In the middle row of the schematic are the 74374 register (U3) that
holds configuration information and the 74299 shift register (U4) that
is used to transfer data to the SD card. To the right of these is a
74165 (U7) shift register that implements the automatic shifting
mechanism for high speed mode along with some more NAND logic (U2B, U2C,
U2D) to generate the appropriate signals depending on the operating
mode.

The automatic shifting behaviour is implemented by latching the state of
the SHIFT8 bit of the config register into all 8 bits of U7's input
register when /DATAWR is asserted (ie. the data register is written to).
This fills the register with 1s. The serial in (Ds) pin of the register
is connected to ground so with each clock pulse the train of 1s is
shifted and the gap is filled with a 0. The serial output of the
register (SHIFTING) is NANDed with the clock by U2B. The output from U2B
is either a train of 8 inverted clock pulses or a constant logic 1
level, depending on the state of SHIFT8 at the time the DATA register
was written to. NAND gate U2C will either invert this train of clock
pulses if /BITBANG is high, or reflect the inverted state of the
/BITBANG config bit if U2A is outputting a constant logic 1 at the time.
Put together this allows either the SHIFT8 config bit or the /BITBANG
config bit to control the clock depending on the desired operating mode
(relying on the driver to avoid trying to do both simultaneously).

The final NAND gate of the 7400 (U2D) is used to invert the /DATAWR
signal to drive U4's S1 input to select the Parallel Load operation when
/DATAWR is asserted or to Shift Left otherwise. S0 of U4 is tied to
ground as the Shift Right and Hold operations are never used.

Finally, a 74107 dual JK flip flop was used to divide the RC2014's clock
signal (CLK) by four to produce (Q\_CLK). This was initially intended to
solve a timing issue, but has caused more trouble than it was worth.

The timing diagram below shows the behaviour of the device when the
SHIFT8 bit is set and a write is issued to the DATA address.

|Original SD Interface Timings|

A couple of issues are noticeable:

-  SH\_CLK is producing one partial pulse, followed by a gap, followed
   by 7 real clock pulses.
-  /DATAWR (and therefore SH\_LOAD) is asserted for several clock
   pulses.
-  CLK (actually Q\_CLK) behaves strangely.

Most of these issues were introduced by attempts to work around other
problems.

Before the clock divider was introduced U7 was emitting a train of 11
clock pulses rather than the expected 8. This is because the 74165 has a
transparent latch rather than an edge triggered latch. The Z80 asserts
/IORQ for many clock cycles so the train of 1s from SHIFT8 was being
reloaded, wiping out the 0 introduced through the Ds input, until /IORQ
was deasserted. Introducing and resetting the clock divider was an
attempt to prevent the shift registers from being clocked during this
period by holding it in the reset state when /DATAWR is asserted.

Unfortunately because the Z80 instructions take a variable number of
clock cycles to complete and aren't necessarily a multiple of 4 cycles
the state of the divided clock when /DATAWR is asserted is not
predictable. This is likely the cause of the glitchy short pulse seen on
CLK as /DATAWR is asserted.

Without this unexpected pulse U4 would not be loaded, as 74299's the
Parallel Load operation is synchronous with the clock, and shares a
clock with the Shift operation. Extra logic would be required to create
a seperate clock that is a superset of the shift clock.

Given these problems I'm going back to the drawing board slightly. I may
try adding the extra logic to clock only the 74299 but if that fails I'm
replacing the 74299 with a pair of shift registers - a 74165 for data
moving from the Z80 to the SD card and a 74595 for data moving from the
SD card to the Z80. This is probably wise anyway as the 74299 is a rare
part which is many times the cost of a 74165 or 74595 and supplies are
less plentiful.

I'll also be removing the 74107 clock divider circuit and replacing it
with a simple edge trigger circuit to limit the /DATAWR pulse to a
single clock.

Hopefully I will have a write up of this new version soon.

.. |Original Z80 SD Interface Schematic| image:: http://www.moop.org.uk/wp-content/uploads/2016/10/Z80-SD-Interface-74HC299-Schematic_2048.png
   :class: size-full wp-image-966
   :width: 2048px
   :height: 1448px
   :target: http://www.moop.org.uk/index.php/2016/10/15/retrochallenge-201610-previous-version-and-problems/z80-sd-interface-74hc299-schematic_2048/
   :alt: Original Z80 SD Interface Schematic
.. |Original SD Interface Timings| image:: http://www.moop.org.uk/wp-content/uploads/2016/10/Z80-SD-Interface-74HC299.png
   :class: size-full wp-image-965
   :width: 1652px
   :height: 936px
   :target: http://www.moop.org.uk/index.php/2016/10/15/retrochallenge-201610-previous-version-and-problems/z80-sd-interface-74hc299/
   :alt: Original SD Interface Timings
