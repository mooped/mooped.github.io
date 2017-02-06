eShapeOko Part 3 - Tidying up
#############################
:date: 2014-09-13 22:53
:author: moop
:category: ShapeOko, Things
:slug: eshapeoko-part-3-tidying-up
:status: published

Having had the ShapeOko for over a year now I've used it for quite a few
projects, but nowhere near as many as I intended. Part of the reason for
this is that the controller for the machine was still rather jury rigged
so setting it up was a hassle. To solve this problem I've been working
on integrating together a permanent version of the controller.

|Finished Product|

I started by designing a pair of custom PCBs with a bus to connect them
together while allowing for expansion. The first board is essentially an
Arduino with custom pin out. The second board mounts the stepper
controllers. At some point I may add a breakout board for limit switches
and a board to interface with a pendant for manually controlling the
machine.

|Arduino and Stepper Boards|

Having built the boards, they all work fine, but there are things I'd do
differently if I made another. First off I'd probably stick with a
standard Arduino pinout, both for reusability and because the 24 pin DIL
socket I used turned out to be expensive. Additionally, the layout for
the (single sided) boards would have been much simpler without the DIL
socket to consider.

|Arduino board underside with horrible routing for the DIL connector|
=====================================================================

With the boards made I decided on using an FTDI module I had lying
around for USB to serial conversion, replacing the Minimus that I was
using previously. I designed a very simple breakout for this module to
expose the Power, Reset, Ground and Serial Tx/Rx signals in a way that
matches the Arduino's FTDI header. The main benefit of the breakout
board, however, was that I could give it appropriate dimensions for
mounting in a case.

With all of the boards made and (a few months later, once a burst of
motivation turned up) assembled, I needed to build a case to keep the
parts together. I decided to laser cut the case from perspex in order to
get it made quickly—and because I thought a clear perspex case would
look cool.

Due to my earlier experiences with fried Stepper Controllers I decided
to use locking connectors to prevent accidental disconnection while the
machine was powered up. After some searching I found that 4 pin gx16
aviation connectors seemed to do what I want. I ended up ordering some
from China through Amazon as it was the cheapest source, though thanks
to the seller incorrectly filling in the customs form I paid more than
expected for them. Regardless, they work nicely and look good. I also
used one of these connectors for power, with two pins acting as 12v and
ground and spare pins for signalling. Should I choose to power the
machine from a PC power supply at a later date, one of these lines will
be used for the PSU's power on line.

|Locking Connectors|

With the connectors and some switches chosen and measured, I began work
on designing the case. I settled on a fairly simple tabbed box design.
The box is split into two sections to match the two widths of board:
narrow USB to serial breakout and wide Arduino and Stepper Controller
boards. The sides of the box have slots into which various mounting
plates can be bolted. The boards locate into slots in the mounting
plates, allowing for quite flexible arrangement of the boards.

|Case Parts|

|Runners for board mounting|

With the case parts cut, I found it fairly fiddly to assemble, but once
together it was quite sturdy. Some of the wires to the connectors had to
be soldered with parts of the case in place. This makes maintenance
slightly trickier, but will reduce the chance of intermittent
connections to the steppers which could exist if I'd used a second set
of connectors on the board.

|Assembling the controller inside the case|

The layout of the connectors and switches was mostly determined by the
shape of the case and the space taken up by the boards. I ended up with
the stepper connectors on the top of the case in the same section as the
USB to serial adapter. The connectors are quite deep, so they required a
lot of space behind their mounting plate.

|Stepper connectors|

On one end of the case there is a cutout for the USB to serial board and
a reset switch for the Arduino in the form of a big red button. It's not
exactly an emergency stop button but should have a similar effect.

|USB connector and reset switch|

On the other end is an extra gx16 connector for power and a switch that
will act as a power switch if a PC PSU is used. The switch is designed
to connect or disconnect the ATX PS\_ON line instead of being directly
in line with the 12 volt input, which would require a sturdier switch.
There is space for mounting a much smaller alternative switch, but I
went with a large toggle in the end.

Each end of the case has a grille and mounting holes for a 45mm fan
should extra cooling be required.

|Power switch and connector|

In order to keep the cables for the steppers tidy, I slipped on two
pieces of heat shrink over the paracord sheaths I added. These keep the
ends of the paracord neat at each end of the cable and provide a bit
more bulk so the strain relief in the connectors has something to grip.

|Finished Product|

.. |Finished Product| image:: http://www.moop.org.uk/wp-content/uploads/2014/09/20140913_201752.jpg
   :class: alignnone size-full wp-image-752
   :width: 935px
   :height: 526px
   :target: http://www.moop.org.uk/index.php/2014/09/13/eshapeoko-part-3-tidying-up/20140913_201752/
.. |Arduino and Stepper Boards| image:: http://www.moop.org.uk/wp-content/uploads/2014/09/20140715_202957.jpg
   :class: alignnone size-full wp-image-737
   :width: 935px
   :height: 526px
   :target: http://www.moop.org.uk/index.php/2014/09/13/eshapeoko-part-3-tidying-up/20140715_202957/
.. |Arduino board underside with horrible routing for the DIL connector| image:: http://www.moop.org.uk/wp-content/uploads/2014/09/20140608_194934.jpg
   :class: alignnone size-full wp-image-741
   :width: 935px
   :height: 526px
   :target: http://www.moop.org.uk/index.php/2014/09/13/eshapeoko-part-3-tidying-up/20140608_194934/
.. |Locking Connectors| image:: http://www.moop.org.uk/wp-content/uploads/2014/09/20140913_201732.jpg
   :class: alignnone size-full wp-image-755
   :width: 935px
   :height: 526px
   :target: http://www.moop.org.uk/index.php/2014/09/13/eshapeoko-part-3-tidying-up/20140913_201732/
.. |Case Parts| image:: http://www.moop.org.uk/wp-content/uploads/2014/09/20140619_204746.jpg
   :class: alignnone size-full wp-image-738
   :width: 935px
   :height: 526px
   :target: http://www.moop.org.uk/index.php/2014/09/13/eshapeoko-part-3-tidying-up/20140619_204746/
.. |Runners for board mounting| image:: http://www.moop.org.uk/wp-content/uploads/2014/09/20140619_215111.jpg
   :class: alignnone size-full wp-image-735
   :width: 935px
   :height: 526px
   :target: http://www.moop.org.uk/index.php/2014/09/13/eshapeoko-part-3-tidying-up/20140619_215111/
.. |Assembling the controller inside the case| image:: http://www.moop.org.uk/wp-content/uploads/2014/09/20140715_224126.jpg
   :class: alignnone size-full wp-image-742
   :width: 935px
   :height: 526px
   :target: http://www.moop.org.uk/index.php/2014/09/13/eshapeoko-part-3-tidying-up/20140715_224126/
.. |Stepper connectors| image:: http://www.moop.org.uk/wp-content/uploads/2014/09/20140913_201703.jpg
   :class: alignnone size-full wp-image-754
   :width: 935px
   :height: 526px
   :target: http://www.moop.org.uk/index.php/2014/09/13/eshapeoko-part-3-tidying-up/20140913_201703/
.. |USB connector and reset switch| image:: http://www.moop.org.uk/wp-content/uploads/2014/09/20140913_201740.jpg
   :class: alignnone size-full wp-image-756
   :width: 935px
   :height: 526px
   :target: http://www.moop.org.uk/index.php/2014/09/13/eshapeoko-part-3-tidying-up/20140913_201740/
.. |Power switch and connector| image:: http://www.moop.org.uk/wp-content/uploads/2014/09/20140913_201732.jpg
   :class: alignnone size-full wp-image-755
   :width: 935px
   :height: 526px
   :target: http://www.moop.org.uk/index.php/2014/09/13/eshapeoko-part-3-tidying-up/20140913_201732/
