eShapeOko Part 1
################
:date: 2013-08-27 18:28
:author: moop
:category: Things
:tags: ShapeOko, Things
:slug: eshapeoko-part-1
:status: published

I was partway through writing a draft for a post about PCB milling when
I realised I hadn't yet written anything about the machine I've been
using, so I think it's about time for a post about the
`eShapeOko <http://www.makerslideeurope.com/eshapeoko-kits.html>`__ CNC
machine I built.

I ordered the mechanical kit only, so no motors or electronics were
included. To kill time while the much awaited parcel made its way to me,
I ordered a pair of `EasyDriver <http://schmalzhaus.com/EasyDriver/>`__
stepper controllers and some stepper motors to experiment with. The
EasyDriver boards aren't particularly cheap but very easy to use, just
supply power, ground, connections to the motor and signals for Step and
Direction.

I soldered some pin headers onto the boards to break out all of the pins
I needed. With them plugged into a breadboard I could easily experiment
with driving them via a Minimus USB microcontroller board. Thanks to the
simplicity of the stepper controllers I had it driving the motors nicely
within an hour, though unfortunately I shortly after discovered several
ways to fry the Allegro A3967 chip that the EasyDriver is based on.

|EasyDriver stepper boards|

The first mistake was forgetting to power off the boards while
unplugging a motor. The controller keeps the coils in the stepper motor
energised continuously in order to hold the motor steady. Suddenly
removing the load tends to fry the controller. When I make a permanent
controller board for the machine, I plan to use locking connectors to
avoid absent mindedly unplugging the motors in this way.

The second mistake was playing around with circuit on the breadboard
while it was powered up. I accidentally connected the Step input to my
12v supply instead of the regulated 5v output that the EasyDriver
provides.

Either way, I now had two unusable EasyDriver boards. Fortunately the
A3967 chips are available for about 1/4 of the price of the EasyDriver
board, so I was able to order some replacements. Despite being surface
mount chips they were relatively easy to replace, with a fine tipped
soldering iron. The hardest part being removing the old chips as the
solder wicks under the pins. Some brute force was required, but not too
much as it is easy to peel up the tracks.

With the stepper controllers proven to work (once refurbished) I ordered
an additional board to control the third axis.

The next step was to get something in place to act as a controller. I
briefly considered writing my own but decided it would add a lot of work
and even more unknowns. After looking around online I decided on
`GRBL <https://github.com/grbl/grbl>`__. GRBL is a CNC controller
firmware designed to run on an Arduino, and thanks to a conveniently
timed workshop at Nottingham Hackspace I had an Arduino board I'd built
lying around. GRBL takes instructions in G-Code — which is a fairly
standard language for controlling CNC machines — and outputs step and
direction pulses.

GRBL is designed to read G-Code through the Arduino's serial port, so a
USB to serial converter was required (and was also required to program
the Arduino). Fortunately, the trusty Minimus board came to the rescue,
along with some
`instructions <http://rlab.org.uk/wiki/Projects/Minimus#USB_To_Serial_Project>`__
provided by Reading Hackspace. With a Minimus acting as a USB to serial
adapter, I had the electronics side of the machine in place (albeit
cobbled together).

|Cobbled together CNC controller|

I'll cover the mechanical side of it in another post.

.. |EasyDriver stepper boards| image:: http://www.moop.org.uk/wp-content/uploads/2013/08/2013-03-01-06.31.13.jpg
   :class: size-full wp-image-380
   :width: 1024px
   :height: 613px
   :target: http://www.moop.org.uk/index.php/2013/08/27/eshapeoko-part-1/2013-03-01-06-31-13/
   :alt: EasyDriver stepper boards
.. |Cobbled together CNC controller| image:: http://www.moop.org.uk/wp-content/uploads/2013/08/2013-04-06-13.00.37.jpg
   :class: size-full wp-image-390
   :width: 1024px
   :height: 613px
   :target: http://www.moop.org.uk/index.php/2013/08/27/eshapeoko-part-1/2013-04-06-13-00-37/
   :alt: Cobbled together CNC controller
