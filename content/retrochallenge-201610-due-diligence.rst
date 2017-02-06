Retrochallenge 2016/10 - Due diligence
######################################
:date: 2016-10-30 22:45
:author: moop
:category: RC2014, Retrochallenge
:slug: retrochallenge-201610-due-diligence
:status: published

To avoid the work done designing my SD interface being wasted I decided
to verify the concept before going any further.

I used my `Bus
Pirate <http://dangerousprototypes.com/docs/Bus_Pirate>`__ to verify
that the SD card I have would respond to the commands I expected using
the protocol I expected.

The Bus Pirate supports many bus protocols including the SPI bus that
the SD card supports in the mode I'm using.

I don't have an SD card breakout board so I ended up buying a micro SD
card with a standard SD adapter and soldering some right angle pin
headers to the pads. This gave me an SD adapter that would plug into a
breadboard.

[caption id="attachment\_987" align="alignnone"
width="1024"]\ |Makeshift SD Adapter| Makeshift SD Adapter[/caption]

I initially used the Bus Pirate's probe cable as a quick way to connect
to this adapter, but this got frustrating as the mini grabbers had a
habit of letting go at inconvenient times. To get around this I made a
quick adapter on some stripboard.

[caption id="attachment\_988" align="alignnone" width="1024"]\ |Bus
Pirate SD Adapter| Bus Pirate SD Adapter[/caption]

This little adapter also makes it easy to remove the SD adapter from the
Bus Pirate without having to look up the pinout again. It should come in
handy on future SD card related projects and maybe for writing raw data
to the SD card.

Unfortunately I don't have any logs of the session, but with this
adapter and the Bus Pirate I was able to initialise the SD card and read
blocks of data. This gave me confidence that my project would work and
would be worthwhile.

.. |Makeshift SD Adapter| image:: http://www.moop.org.uk/wp-content/uploads/2016/10/SD1.jpg
   :class: size-full wp-image-987
   :width: 1024px
   :height: 766px
   :target: http://www.moop.org.uk/index.php/2016/10/30/retrochallenge-201610-due-diligence/sd1/
.. |Bus Pirate SD Adapter| image:: http://www.moop.org.uk/wp-content/uploads/2016/10/SD2.jpg
   :class: size-full wp-image-988
   :width: 1024px
   :height: 766px
   :target: http://www.moop.org.uk/index.php/2016/10/30/retrochallenge-201610-due-diligence/sd2/
