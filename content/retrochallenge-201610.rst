Retrochallenge 2016/10
######################
:date: 2016-10-05 20:04
:author: moop
:category: RC2014, Retrochallenge
:slug: retrochallenge-201610
:status: published

I decided to join in with
` <http://www.wickensonline.co.uk/retrochallenge-2012sc/>`__\ Retrochallenge
2016/10 this October. I'm also hoping this will provide some incentive
to write more posts and updates about other projects once I'm back into
the swing of things!

[caption id="attachment\_952" align="alignnone" width="1024"]\ |RC2014
Z80 computer| RC2014 Z80 computer[/caption]

My goal for this Retrochallenge is to finish an SD card interface I
started designing for Spencer Owen's ` <http://rc2014.co.uk/>`__\ RC2014
Z80 based computer (which was spawned by a previous Retrochallenge,
hence the name). This should work with most Z80 computers that don't do
anything crazy to the I/O interface, so I may also get it working on a
ZX Spectrum if there is time.

I'm intending to build my SD interface from 74 series and similar
discrete logic ICs. This is partly for fun and partly because the
microcontroller in the SD card is likely already more powerful than the
RC2014. Adding another microcontroller into the mix to interface with
the one in the SD card is just a step too far.

I'll be using the SPI-like mode of the SD card protocol, not least
because information on the faster SD mode is not publicly available. The
SPI-like interface should allow me to use shift registers for
communication with the SD card.

I was initially planning to use a 74ALS299 universal shift register to
reduce chip count. Unfortunately, in addition to being somewhat hard to
get, the interface on this chip is troublesome as the shift, shift
direction, and output enable are all synchronous and controlled via two
pins that set the operation. The extra glue logic needed to deal with
this completely nullifies the benefit of using a single universal shift
register. Because of this I'm planning to redesign around a pair of
shift registers: a 75HCT595 serial-in-parallel-out register and a
75HTC165 parallel-in-serial-out register.

The SD card requires a slow clock pulse for initialisation (around
100khz), but once initialised supports faster clock speeds. The design
is complicated by the need to run at both speeds, but I have a scheme to
cope with this.

My intended interface uses a pair of registers mapped to the Z80's I/O
space.

.. raw:: html

   <ul>
   <li>

**DATA**

.. raw:: html

   </li>

-  Writes to this address latch the byte from the Z80 data bus into the
   74HTC165 which is used to send data to the SD card.
-  Reads from this address enable the outputs on the 74HTC595 shift
   register which receives data from the SD card.

.. raw:: html

   <li>

**CONFIG**

.. raw:: html

   </li>
   <ul>
   <li>

Writes to this address update a 74HTC374 register holding a
configuration byte. The following bits are currently used:

.. raw:: html

   </li>

-  **autoshift** - Automatically shift 8 bits from the shift registers
   to the SD card and back after a write to the **DATA** address. This
   is used for the SD card's "normal" high speed mode and should allow
   fast enough I/O that the Z80 becomes the bottleneck.
-  **clock** - OR'd with the automatic clock signal to the shift
   registers and SD card, allowing communication at a speed controlled
   directly by the Z80 to provide a 'bitbang' mode. This mode is not
   efficient, but allows the slower speed required for the SD card
   initialisation process without much extra logic.

.. raw:: html

   </ul>
   </ul>

[caption id="attachment\_953" align="alignnone" width="1024"]\ |Original
version on breadboard| Original version on breadboard[/caption]

An initial version similar to this design has been built on a breadboard
using a 74ALS299. In addition to the issues with the synchronous control
signals needed to load this shift register, there were also
compatibility issues with the timing of the Z80's I/O control signals.
This requires additional glue logic and a redesign of automatic shifting
logic that enables the high speed mode to work.

Before I take the previous version apart to rebuild, I'll take some
logic analyser captures indicating the timing issues, and write up (and
remind myself of) the problems.

.. |RC2014 Z80 computer| image:: http://www.moop.org.uk/wp-content/uploads/2016/10/rc2104.jpg
   :class: size-full wp-image-952
   :width: 1024px
   :height: 576px
   :target: http://www.moop.org.uk/?attachment_id=952
.. |Original version on breadboard| image:: http://www.moop.org.uk/wp-content/uploads/2016/10/original_breadboard.jpg
   :class: size-full wp-image-953
   :width: 1024px
   :height: 576px
   :target: http://www.moop.org.uk/?attachment_id=953
