Lightwave RF Mood Controller Hack
#################################
:date: 2013-08-25 21:46
:author: charlie
:category: Things
:tags: Charlie
:slug: lightwaverfmoodcontrollerhack
:status: published

It's me, Charlie again, continuing with my scheme to take over Moop's
blog with nothing but home automation articles.

Readers of this blog will know that I've been playing around with
LightwaveRF's home automation stuff a lot recently. Mainly setting up
voice control systems for it. One thing that irked me though was that to
control the devices across the network requires a £65 ($100) box called
the WiFi link
(http://www.lightwaverf.co.uk/LighwaveRF-Connect-Home-Automation-Smartphone-Wifi-Link-White.html).
This seemed a bit much to me but I shelled out the money as there didn't
seem to be any option. However, when someone at work started asking
about it, it got me thinking if there could be a cheaper way. Maybe it'd
be possible to hack the much cheaper mood controller
(http://www.lightwaverf.co.uk/LightwaveRF-Connect-Home-Automation-Hand-Held-Remote-Control-Black.html)
to be controlled from a Raspberry Pi (or any cheap microcontroller)
directly.

So, I started by cracking open the controller I got free in a 3 bulb
bundle. At first there didn't seem to be any screws at all. Peeling back
the label revealed one though. Even with the screw removed however, it
remained stubbornly in one piece. So, I got my spludger out and worked
it into the gap of the case. Working my way around I found tabs that
needed releasing.

Once inside, I got my first surprise. There's more buttons on the
circuit board then there are on the front of the device. I didn't try
these buttons but I am curious to know what they are there for.

|Six Buttons|

Next nice surprise was that the switch electronics were very simple for
the buttons I wanted to hack (the on/off and device select slider). All
three controls clearly weren't multiplexed as they all shared the
battery's ground. This made the hack a heck of a lot easier. Next up was
checking with a multimeter that the other terminals of the buttons were
pulled high. Checking the on and off buttons showed 3V, which is close
enough to drive from the Pi's 3.3V logic. The slider however, showed no
voltage. Checking on the oscilloscope revealed that the slider switch
was only powered for a split second when either the on or off button was
pressed, presumably to save power. The first three pads do this but the
fourth is never powered. I assume this pad isn't actually used as if the
switch isn't in the first three positions, then it logically must be on
the fourth pad.

With everything working as expected I soldered on my connections and
connected these to a header.

|Controller With Header|

The program to actually interface with the device was very easy. I
originally planned to use the tri state logic function to simulate the
button being open. This didn't seem to work however so in the end I just
used a logic high output. This is a bit wrong as the Pi outputs 3.3V
logic which is higher than the potential of the controller but doesn't
seem to cause problems. To simulate the button being pressed, a logic
low output is generated from the Pi. For the slider, I just need to pull
one of the three lines low or keep them all high to select device 4.

|Controller Connected to Pi|

Naturally I made a video to go along with this hack...

http://youtu.be/qLB7Lr4YQ\_4

As always the source for the Pi program can be downloaded
at \ `Lightwave Hack
Source <http://www.moop.org.uk/wp-content/uploads/2013/08/remote.c>`__.

.. |Six Buttons| image:: http://www.moop.org.uk/wp-content/uploads/2013/08/6Buttons.jpg
   :class: aligncenter size-full wp-image-363
   :width: 960px
   :height: 1280px
   :target: http://www.moop.org.uk/wp-content/uploads/2013/08/6Buttons.jpg
   :alt: Six Buttons
.. |Controller With Header| image:: http://www.moop.org.uk/wp-content/uploads/2013/08/AllDone.jpg
   :class: aligncenter size-full wp-image-364
   :width: 960px
   :height: 1280px
   :target: http://www.moop.org.uk/wp-content/uploads/2013/08/AllDone.jpg
   :alt: Controller With Header
.. |Controller Connected to Pi| image:: http://www.moop.org.uk/wp-content/uploads/2013/08/Connected.jpg
   :class: aligncenter size-full wp-image-365
   :width: 960px
   :height: 1280px
   :target: http://www.moop.org.uk/wp-content/uploads/2013/08/Connected.jpg
   :alt: Controller Connected to Pi
