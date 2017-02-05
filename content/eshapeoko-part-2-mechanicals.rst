eShapeOko Part 2 - Mechanicals
##############################
:date: 2013-10-22 21:01
:author: moop
:category: ShapeOko, Things
:slug: eshapeoko-part-2-mechanicals
:status: published

Building the mechanical parts of the eShapeOko was fairly
straightforward, but there are some problems and modifications I made
that are worth writing about.

|eShapeOko parts|

The first task of the assembly was to tap the MakerSlide sections to add
a screw thread. This was my first try at tapping anything, but it was
less trouble than expected, except for a few trips into town to get a
tap and die set and some tapping lubricant.

Once the MakerSlide was tapped, everything else pretty much just bolted
together, though it's worth taking the time to think about alignment and
get the spacers right early on. Sorting it out later may require taking
most of the machine apart again just to gain access. Once built, minor
adjustments to the alignment of the rails are less of a problem. The
process is to loosen the rails to be aligned, slide the axis that runs
on those rails to one extreme, tighten the bolts at that end, then
repeat for the other end of the axis.

|eShapeOko assembled|

Another thing to note is that it's worth buying and installing limit
switches early, even if you won't wire them up immediately. There's not
a lot of space behind their mounting points, so it can be difficult or
impossible to get bolts in or to screw on a nut from behind.

|Limit Switch|

When buying the kit I went for the dual X axis and dual Y stepper
options; I'd definitely recommend these. The dual X axis adds a second
section of MakerSlide to the stepper which provides extra rigidity and
prevents the Z axis from twisting about the X axis. The dual Y stepper
upgrade provides the necessary parts for mounting a second stepper motor
to drive the Y axis. I initially bought this but didn't add the second
stepper. I quickly noticed that the undriven side of the Y axis was
lagging behind quite dramatically. Adding the second stepper fixed this.

With 4 stepper motors to drive there were initially a lot of wires
floating around and waiting to get snagged in a nearby moving part. To
help with this I ordered some 15ft of paracord from eBay for a few quid.
By removing the inner of the paracord and melting the ends of the outer
layer to prevent fraying, you can make a nice sheath to reduce the
number of cables and make them more manageable.

[gallery ids="426,458"]

Threading the wires through the paracord was fiddly. The best method I
found was to use pieces of the inner to pull the wires through. First
thread one piece of the inner back through the outer, tie one end around
the first wire, then tie a second piece of inner to the wire in the same
place. Fold the wire back on itself to prevent the knots from slipping
off, and pull it through. This gives you one wire and one piece of inner
threaded through the outer. Untie the inner from the wire and tie the
other end to a new wire, then tie another piece of inner to the wire and
repeat the process. Do this for all the wires, being careful to not let
them slip out and to not lose the end inside the outer. You will
probably find that the outer will stretch and shrink in diameter, which
can fixed by holding the loose end of the wire and pulling the end of
the outer away from it, then manipulating the outer to transfer and
balance out the tension. This process is also handy for getting the
outer to sit neatly against the stepper motor at the end of the process.

[gallery ids="435,441,445,451,450,452"]

This process requires a lot of patience but produced nice results.
Curiously I found that although the second and third wires were quite
hard to pull through the fourth tended to be easier. This was probably
down to the reduced friction of dragging the wire against more wires and
less paracord outer, but it's a good reason not to give up if the third
wire seems hard to get through.

|MDF base and spoil board|

Initially I had the machine mounted on some old laminate floor boards,
which weren't very stiff. This gave bad results for milling wood and
terrible results for milling PCBs. Moving to a sturdy chunk of 3/8" MDF
resolved this nicely. I have a sacrificial piece of thinner MDF on top
of this as a spoil board to preserve the base itself and to provide more
mounting options for materials.

|Z axis leadscrew|

The only real problem I've had with the machine so far is with the Z
axis. Unlike the other two axes the motion is transferred to the axis
via a leadscrew. The leadscrew passes through a flanged bearing
sandwiched between two aluminium plates. The motor is coupled to the
leadscrew with a RepRap style (I believe) flexible coupler.
Unfortunately the set screw that tightens the coupler to the threaded
rod can easily push the rod off centre, causing the shaft to wobble
unless some packing or tape is wrapped around the threaded rod.
Additionally, the rod is held in place vertically by a nut on either
side of the bearing. Depending on the precision with which the nuts were
made this also can result in the axis wobbling if the nuts are tightened
and the axis floating vertically if the nuts come lose.

[gallery ids="472,473"]

The combination of two sources of wobble in the axis and nuts that can
come loose easily makes setting up the Z axis very fiddly and quite time
consuming. This is currently the main obstacle I've found that is making
PCB milling difficult. I've been able to tune out the wobble relatively
effectively, though I worry that it may have damaged the plastic runners
for the Z axis. I still need to fix the issue with the nuts coming
loose. The options for this that I've come up with so far involve either
threadlock or buying a second pair of nuts (it's an Acme thread so
common or garden nuts won't do it) but I've yet to commit to or try one
of these options.

.. |eShapeOko parts| image:: http://www.moop.org.uk/wp-content/uploads/2013/08/2013-04-24-17.30.15.jpg
   :class: alignnone size-full wp-image-398
   :width: 1024px
   :height: 613px
   :target: http://www.moop.org.uk/index.php/2013/08/27/eshapeoko-part-1/2013-04-24-17-30-15/
.. |eShapeOko assembled| image:: http://www.moop.org.uk/wp-content/uploads/2013/08/2013-04-25-22.12.30.jpg
   :class: alignnone size-full wp-image-427
   :width: 1024px
   :height: 613px
   :target: http://www.moop.org.uk/index.php/2013/08/27/eshapeoko-part-1/2013-04-25-22-12-30/
.. |Limit Switch| image:: http://www.moop.org.uk/wp-content/uploads/2013/10/2013-10-22-20.58.20.jpg
   :class: alignnone size-full wp-image-469
   :width: 1024px
   :height: 613px
   :target: http://www.moop.org.uk/index.php/2013/10/22/eshapeoko-part-2-mechanicals/2013-10-22-20-58-20/
.. |MDF base and spoil board| image:: http://www.moop.org.uk/wp-content/uploads/2013/10/2013-10-22-21.38.39.jpg
   :class: alignnone size-full wp-image-471
   :width: 1024px
   :height: 613px
   :target: http://www.moop.org.uk/index.php/2013/10/22/eshapeoko-part-2-mechanicals/2013-10-22-21-38-39/
.. |Z axis leadscrew| image:: http://www.moop.org.uk/wp-content/uploads/2013/08/2013-04-24-20.43.30.jpg
   :class: alignnone size-full wp-image-416
   :width: 1024px
   :height: 613px
   :target: http://www.moop.org.uk/index.php/2013/08/27/eshapeoko-part-1/2013-04-24-20-43-30/
