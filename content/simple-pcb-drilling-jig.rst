Simple PCB drilling jig
#######################
:date: 2014-06-12 21:16
:author: moop
:category: Things
:tags: PCB Drilling Jig, Things
:slug: simple-pcb-drilling-jig
:status: published

|Drilling jig in action|

Recently I've been making a lot of printed circuit boards. One of the
common problems I run into is aligning holes correctly when hand
drilling. This is especially troublesome on boards with large arrays of
pins, such as my hexapod controller (I promise I'll write that up
soon!). A misaligned hole will prevent IC sockets from fitting correctly
or cause pin headers to sit at crazy angles. This is really obvious on
the first version of my hexapod controller board as shown below.

|Wonky pin headers|

In order to work around this for the second version of the hexapod board
I used my CNC machine to drill the holes. This is great for relatively
large jobs, but the setup time makes it less attractive for small one
off boards.

Since I was scheduled to have an induction on `Nottingham
Hackspace's <http://nottinghack.org.uk/>`__ new laser cutter and given
the option of cutting my own project during the induction, I came up
with a simple mechanical solution to drilling holes at the 0.1 inch
spacing required for most IC sockets and pin headers.

|Simple PCB Drilling Jig|

The concept is very simple: a zigzag line is cut through a piece of
plywood with a "wavelength" of 0.1 inches. One side of the cut is
clamped to the work surface of a pillar dril,l and the board to be
drilled is taped to the other side. The serrated edges can be moved
around, and when pushed back together they naturally align to multiples
of 0.1 inch. I went with a sawtooth style wave in the end so pressure
can be applied in towards the flat edge of the sawtooth without the
piece slipping.

|Drilling jig in action|

The photo above shows masking tape, but double sided tape would have
worked better if I'd had any with me when taking the photos.

In order to make grid style layouts I added a second layer of serrations
at 90 degrees to the first. I've not had chance to test this as the work
area of the pillar drill I've been using does not have space. The
intended usage is that both of the outer stages would be clamped in
place and the inner piece manipulated by hand to drill columns of holes.
Once a column is complete the middle stage would be un-clamped, adjusted
then re-clamped. This is repeated for as many columns as necessary.

I've used the jig with a single stage on a few boards now, and it works
well so long as the initial hole is well aligned. An easy way to ensure
this is to align the drill bit with the smallest hole in the row and
then clamp the jig in place.

To ensure that the board is aligned correctly in the jig, I usually find
the longest run of holes on the board and put a ruler against the edge.
Drawing a pencil line along the ruler provides alignment marks on the
board that can be matched up with the etched lines on the jig.

In the current version, the inner section of the jig is a sacrificial
piece which will eventually become full of holes. I toyed with the idea
of making the inner section in an L shape into which the board would
fit, but this would rely on the edges of the board being cut exactly
parallel with the grid so it's less useful in practice. Hopefully the
sacrificial part of the jig will last long enough, and it's cheap enough
to just make another when it wears out.

|FTDI breakout breakout|

Earlier today I used the jig to make a very simple breakout board to
match the pinout from an FTDI board to an Arduino style six pin header.
The 6 pin header and 32 pin (minus 4 due to the weird layout on the FTDI
board) IC socket I used fitted perfectly first time.

|Perfect fit|

I've made the CAD drawing for the jig available to download. Hopefully
it will be useful to someone.

`DrillingGuide.zip <http://www.moop.org.uk/index.php/2014/06/12/simple-pcb-drilling-jig/drillingguide/>`__

.. |Drilling jig in action| image:: http://www.moop.org.uk/wp-content/uploads/2014/06/20140612_165348.jpg
   :class: alignnone size-full wp-image-709
   :width: 935px
   :height: 526px
   :target: http://www.moop.org.uk/index.php/2014/06/12/simple-pcb-drilling-jig/20140612_165348/
   :alt: Drilling jig in action
.. |Wonky pin headers| image:: http://www.moop.org.uk/wp-content/uploads/2014/06/2013-10-26-22.31.25.jpg
   :class: alignnone size-full wp-image-708
   :width: 935px
   :height: 560px
   :target: http://www.moop.org.uk/index.php/2014/06/12/simple-pcb-drilling-jig/2013-10-26-22-31-25/
   :alt: Wonky pin headers
.. |Simple PCB Drilling Jig| image:: http://www.moop.org.uk/wp-content/uploads/2014/06/20140612_214508.jpg
   :class: alignnone size-full wp-image-714
   :width: 935px
   :height: 526px
   :target: http://www.moop.org.uk/index.php/2014/06/12/simple-pcb-drilling-jig/20140612_214508/
   :alt: Simple PCB Drilling Jig
.. |FTDI breakout breakout| image:: http://www.moop.org.uk/wp-content/uploads/2014/06/20140612_171146.jpg
   :class: alignnone size-full wp-image-710
   :width: 935px
   :height: 526px
   :target: http://www.moop.org.uk/index.php/2014/06/12/simple-pcb-drilling-jig/20140612_171146/
   :alt: FTDI breakout breakout
.. |Perfect fit| image:: http://www.moop.org.uk/wp-content/uploads/2014/06/20140612_171159.jpg
   :class: alignnone size-full wp-image-711
   :width: 935px
   :height: 526px
   :target: http://www.moop.org.uk/index.php/2014/06/12/simple-pcb-drilling-jig/20140612_171159/
   :alt: Perfect fit
