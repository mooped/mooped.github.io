STOMP STOMP STOMP STOMP
#######################
:date: 2013-12-12 21:21
:author: moop
:category: Things
:tags: Hexapod, Things
:slug: stomp-stomp-stomp-stomp
:status: published

I've been a bit quiet on here for a while, and slacking on the PCB
milling experiments I've been meaning to do, though I have made some
progress on that front.

Anyway, here's what I got sidetracked by building:

This is a small budget hexapod, using 18 of the cheapest servos I could
find (£2.50 each). It uses a custom board with a power supply and 3
shift registers to control the servos. This in turn is controlled
through an SPI bus to a Minimus USB AVR board, pretending to be a USB to
serial device. The data sent over the serial line is interpreted as
servo IDs followed by the desired position of the servo.

|Mark 2 servo controller board|

The control software I wrote for the hexapod can run on any Linux
computer with a USB port. For dev I use a netbook but it also runs
nicely on a Raspberry Pi.

The original plan was to use the Raspberry Pi's SPI port to control
the servo board directly, unfortunately due to Linux's scheduling not
being particularly real time even in real time mode there was a lot of
timing jitter leading to real life servo jitter. Switching to the
Minimus meant having a very dedicated if much slower CPU generating
the pulses resulting in much smoother control of the servos.

|Hexapod|

I'll hopefully post a full making of post on the hexapod soon, but for
now I just wanted to post a video of some stomping!

.. |Mark 2 servo controller board| image:: http://www.moop.org.uk/wp-content/uploads/2013/12/2013-12-11-21.54.59.jpg
   :class: size-full wp-image-506
   :width: 2592px
   :height: 1552px
   :target: http://www.moop.org.uk/index.php/2013/12/12/stomp-stomp-stomp-stomp/2013-12-11-21-54-59/
   :alt: Mark 2 servo controller board
.. |Hexapod| image:: http://www.moop.org.uk/wp-content/uploads/2013/12/2013-10-23-19.15.36.jpg
   :class: size-full wp-image-507
   :width: 2592px
   :height: 1552px
   :target: http://www.moop.org.uk/index.php/2013/12/12/stomp-stomp-stomp-stomp/2013-10-23-19-15-36/
   :alt: Hexapod
