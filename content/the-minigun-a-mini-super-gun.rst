The Minigun (A mini Super Gun)
##############################
:date: 2013-11-24 14:54
:author: charlie
:category: Things
:tags: Charlie
:slug: the-minigun-a-mini-super-gun
:status: published

*Guest post by Charlie again as he continues his quest to take over
Moop's blog with his super long posts:*

TL;DR?
------

Then here's a video instead...

http://youtu.be/AGSSvxihYZs

Preamble
--------

Recently I got into arcade boards. They can be found *reasonably*
cheaply on eBay and as most use the standard JAMMA connection, setting
these up so you can play them on a TV at home is pretty straight
forward. Especially in Europe where SCART is still widely used and thus
almost all TVs have an RGB input.

I built a very traditional supergun (device that allows you to play
JAMMA boards on a TV) last year. It was time consuming but it wasn't
particularly hard. It used a PC ATX power supply to supply the voltages
needed (-5V, +5V and 12V), audio/video output was via SCART and Neo Geo
AES pin compatible D-SUB 15 plugs for the controller inputs. Here's a
couple of pictures of my first effort...

|IMG-0782| |IMG-0787|

Once I started getting more boards, I found that some bootlegs drew a
heck of a lot of current. So much so that the voltage drop over the half
a meter or so of wiring between the PC supply and the board was causing
the boards not to power up (due to the voltage drop across the wire). I
initially tried solving them by using some wider gauge wire in parallel
to feed the board. This worked but for some bootlegs I owned even this
wasn't good enough. I was reading as close to 5V as I could get at the
connector but measuring the voltage on distant parts of the board, the
voltage had dropped to sub 5V. I needed something better.

I could have got a JAMMA power supply off eBay with a variable voltage
output. This was initially tempting but I just couldn't bring myself to
use one for safety reasons. On all the ones I saw the mains power was
just wired into screw terminals. This is fine as it'd be inside my super
gun's case. The thing that worried me was that the outputs were right
next to the mains screw terminal. The boards aren't in a cabinet like a
traditional arcade, they just lay on top. If the mains lead became loose
there is a possibility of the board becoming live. This may sound
surprising coming from the person that made his own bluetooth controlled
mains plug, it wasn't a risk I wanted to live with.

So, I went looking for a variable DC/DC convertor that could transform a
lot of current without needing any active cooling. After some searching
I came up with
http://docs-europe.electrocomponents.com/webdocs/0eec/0900766b80eec532.pdf.
With this I could power the 5V line from the 12V output of the ATX power
supply and add a pot to adjust between around 5-6V so even my very power
hungry boards would be happy.

With this done I felt I had a reasonable design. Then with Christmas
coming around I decided I could make another one for a friend as a
present. Building the first one, I wasn't really thinking about the time
it took as I built it and tweaked it over a couple of weeks. Even
knowing exactly how to build it now, it still took at least 10 hours to
actual do it. I made a few improvements along the way but it was a
tedious build due to the huge number of wires involved (>100
connections) and all the modifications needed to the case. Also, even
with a lot of salvaged parts (the ATX power supply, the SCART plug etc)
it also ended up being quite expensive at about £50. A lot of this was
due to the case which was quite hard to find as it needed to be tall
enough to fit an ATX power supply.

With that out of the way I vowed never to make another supergun
again..... but of course I did. I just kept thinking I must be able to
make a better one. After trying the toner transfer method for the first
time, it got me thinking that I could do away with almost all the wires
by just making a supergun PCB.

The design
----------

Starting the design of a supergun PCB, I really wanted to make it as
compact as I possibly could while still making it easy and cheap to
assemble. One of the ways to do this was to leave out anything
superfluous. The JAMMA standard has various service switches but not all
need hooking up. COIN1/COIN2 are the coin inputs for adding credits.
These are useful to have on the controller so I wired these to the AES
controller's select button as this would otherwise not be used by JAMMA
boards. SERVICE on every board I own also just gives credits so I left
this out. TILT (for detecting people shaking the machine) is rarely
hooked up on superguns and I suspect does nothing interesting on 99% of
boards. This only leaves TEST which is useful so this got it's own
microswitch on the board.

Power was pretty easy. One reason to use an ATX power supply is that it
supplies the -5V that the JAMMA specification requires. However, looking
at my collection of arcade boards, one 1 (out of around 10) uses the -5V
line at all. They were normally just used for older types of audio
amplifiers (my one board which does use it works without it but just
without sound). I felt fairly comfortable with just leaving the -5V line
out all together. This decision along with using the same DC-DC
convertor from my original design means the supply only has to be 12V.
Many laptop power supplies are 12V, compact, cheap and can supply plenty
of current.

The rest of the design mapped quite nicely to the PCB concept. PCB
mounted DSUB and SCART connectors are common. How to connect the JAMMA
edge connector was slightly more difficult. However, I noted that two
standard 1.6mm PCBs stacked on top of each other was almost exactly the
tag separation on the rear of the JAMMA connector. I could make a small
board that sat on top that could then run the signals for the top back
of the connector down onto the bottom board. Both boards I designed to
be single sided (for ease of creating at home) although because they sit
on top of each other it does effectively make it partially double sided.

The design was quick to knock up in Eagle (maybe too quick as we'll see
later) but when I came to lay it out I hit my first snag. The free
version of Eagle is restricted by the size of the board it will let you
lay out. The longest dimension is 10cm. This wasn't long enough to
connect to every pin of the JAMMA connector. In fact, it was 3 pins
short. Luckily of these three, one is unconnected and the last two are
ground which exists on the other side of the connector anyway. It would
have been nice to connect these additional grounds but I didn't see much
harm in leaving them floating (assuming the grounds are connected on the
arcade board itself). So I designed the board to the Eagle limitations
and just added terminals at that end of the board if in the future I
wanted to wire the extra grounds in with some short jumper wires.

Laying out the board itself was straight forward but time consuming as I
wanted to keep the layout single sided (with no jumpers) as it needed to
be simple to etch at home using hobbyist processes like the toner
transfer method. As such I needed to keep the traces fat too. This led
to another compromise. Because the traces had to be fat and single sided
fitting two controller ports was just too difficult. It's something I'd
like to fix in a future design if I was just going to get it
professionally manufactured via PCBcart or similar.

Building
--------

Construction wasn't particularly interesting and was quite straight
forward. It was only my second attempt at the toner transfer method but
the traces were fat enough that I could fix most problems by hand with
just an etch resist pen. It wasn't perfect but I was fairly pleased with
the end result.

|IMG-1818|

Soldering the various connectors was quick and painless. The only
difficult bit was lining up the top and bottom boards to make the double
sided portion. Although because the via pads were quite big the
positioning wasn't that critical and any slight alignment problems could
be fixed by just adjusting some of the drilling locations.

Once the components were all added, it was ready to test!

|IMG-1819|

Testing
-------

Once everything was assembled I grabbed my male to male SCART cable and
immediately realised I had made a mistake. I knew I'd made a mistake as
I'd made the exact same one with my friend's supergun. Male to male
SCART cables don't map all the pins through one to one. Most do but some
are crossed over, so for example the audio output pins on one side go to
the audio input pins on the other. And the same for the video signal.
D'oh! So, out came the scalpel the offending traces were cut and
replaced by bodge wires.

Tried again and this time the game sprang to life, everything was great
and then I noticed the colours were off. A quick check on the Neo Geo
test menu showed red and blue were reversed! Two mistakes on the same
board was quite embarrassing. I know exactly how it happened though as
when I tried to fix it, I made the exact same mistake. I initially wired
up the RGB pins on the SCART from memory and then checked them before
doing the board layout. I saw the mistake at this stage and thought I
had corrected it. Everything was connected via named labels in the
schematic so I just renamed the label on the pin (say from RED to BLUE).
Eagle asked "Do you want to connect RED to BLUE?". Thinking this would
then cause all the pins to connect I said no but assumed the rename had
worked. Nope, I'd just done nothing. A second, "D'oh!".

So back out came the soldering iron and another set of bodge wires
causing the final board to be a messier than I would have liked but
everything I have thrown at it has worked so I'm quite pleased with the
results. Everything works as well as my big traditional super gun but
now it's in a very tiny portable package.

|IMG-1821|

Make your own
-------------

I made this as my contribution to the super gun / JAMMA comunity so I've
fixed up my board layout (the swapped channel problem etc) and I'm
offering it as a download here: \ `Minigun -
Final <http://www.moop.org.uk/wp-content/uploads/2013/11/Minigun-Final.zip>`__
(EAGLE file format). I hope people will build there own, make
improvements and share these improved versions with the community.

Nb: The current design has the SCART socket mounts overlapping as the
connector I used had a different mounting to the stock one in EAGLE.
Also the single top layer trace is the 5V line to the controller port. I
don't use this in my home-brew controllers so I left it unconnected but
if you did want to use AES controllers you may have to solder a jumper
wire between these points.

.. |IMG-0782| image:: http://www.moop.org.uk/wp-content/uploads/2013/11/IMG_0782.jpg
   :class: aligncenter size-full wp-image-487
   :width: 816px
   :height: 612px
   :target: http://www.moop.org.uk/wp-content/uploads/2013/11/IMG_0782.jpg
.. |IMG-0787| image:: http://www.moop.org.uk/wp-content/uploads/2013/11/IMG_0787.jpg
   :class: aligncenter size-full wp-image-483
   :width: 816px
   :height: 612px
   :target: http://www.moop.org.uk/wp-content/uploads/2013/11/IMG_0787.jpg
.. |IMG-1818| image:: http://www.moop.org.uk/wp-content/uploads/2013/11/IMG_18181.jpg
   :class: aligncenter size-full wp-image-484
   :width: 816px
   :height: 612px
   :target: http://www.moop.org.uk/wp-content/uploads/2013/11/IMG_18181.jpg
.. |IMG-1819| image:: http://www.moop.org.uk/wp-content/uploads/2013/11/IMG_1819.jpg
   :class: aligncenter size-full wp-image-485
   :width: 816px
   :height: 612px
   :target: http://www.moop.org.uk/wp-content/uploads/2013/11/IMG_1819.jpg
.. |IMG-1821| image:: http://www.moop.org.uk/wp-content/uploads/2013/11/IMG_1821.jpg
   :class: aligncenter size-full wp-image-486
   :width: 816px
   :height: 612px
   :target: http://www.moop.org.uk/wp-content/uploads/2013/11/IMG_1821.jpg
