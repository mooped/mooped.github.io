CNC cut control horns
#####################
:date: 2015-05-04 19:35
:author: moop
:category: Things
:tags: ShapeOko, Speed Twin, Things
:slug: cnc-cut-control-horns
:status: published

I was at a loose end during today's bank holiday so I decided to do a
mini-project (with bonus recycling features) and make a set of control
horns for my radio controlled SpeedTwin ST-2.

|Control horns in DraftSight|

After deciding on a sensible size for the control horns I drew them up
in DraftSight. These ended up being 25mm tall and 12.5mm wide at the
base. I designed them on a sprue so that when I come to etch the
remaining copper off they don't get lost in the etching tank. The horns
are shaped so that the holes for the linkage can lie on the hinge line
with plenty of material around them for strength.

The DraftSight file for the parts can be found on GitHub in my `rc-parts
repository <https://github.com/mooped/rc-parts/blob/master/CNC%20Control%20Horns.dwg>`__,
which also contains drawings of various bits of radio control hardware
that I've designed parts around. Please feel free to use any of it or to
contribute drawings of parts.

|The victim|

The PCB material I used comes from a nice FR4 board onto which was
otherwise unusable due to a design mistake. The board was intended to be
used as a 2 player version of Charlie's 'Minigun' miniature SuperGun
project. Unfortunately after etching I noticed I had messed up the
pinout of the JAMMA connector when transcribing the design from Eagle to
KiCad. Rather than throwing it away this project is allowing me to reuse
the material for something useful. My 2 player 'MiniGun' will eventually
get finished and written up too.

|SpeedTwin|

As a quick aside, the SpeedTwin has made some progress since I last
posted about it. The fuselage is nearly finished, except for sanding the
canopy to shape and some more work on shaping the nose cone. The wing is
also coming along, with the top half of the engine nacelles planked and
mostly sanded to shape. The remaining work on the wing is to install the
tips and build the bottom half of the nacelles, which will be removable
for access to the landing gear.

Once the control horn design was ready I used CamBam to convert it to
G-Code. Unfortunately some manual editing was required on the output to
get Grbl to accept it happily. The main problem was a G17 code, intended
to signal that arcs should occur on the XY plane, which caused Grbl to
error after any subsequent G3 (arc) code. This setting was default
anyway so the line was removed with no adverse effects. I also tend to
remove comments from any code that is passed to Grbl - the parser can
choke on lines over 50 characters so comments at the end of lines are
best removed. If I find an open source CAM program that will provide
Grbl compatible G-Code out of the box I will probably switch to it, I
just need to put in the time to find one. :)

|Cutting the parts|

This is the first time using my eShapeOko since I rebuilt the controller
so I had to spend some time setting up again. Once I'd calculated the
appropriate steps/mm settings for each axis everything went fairly
smoothly and after a few 'air cut' test runs I cut the parts. Since this
part is all made in one cut I simplified things slightly by removing all
of the Z axis movement from the program. I manually plunged the bit into
the work from GrblController and then set the program going.

I decided not to drill the holes on the CNC to save setup time and
because I don't have a suitable drill bit that fits my eShapeOko's
rotary tool. They will be quick and easy to drill accurately on the
drill press at `NottingHack <http://www.nottinghack.org.uk/>`__ at a
later date.

|Mostly finished parts|

All that remains is to etch the remaining copper off (and sadly lose the
current futuristic look), drill the holes and cut off the sprue.

.. |Control horns in DraftSight| image:: http://www.moop.org.uk/wp-content/uploads/2015/05/drawing.png
   :class: alignnone size-full wp-image-829
   :width: 1024px
   :height: 576px
   :target: http://www.moop.org.uk/index.php/2015/05/04/cnc-cut-control-horns/drawing/
   :alt: Control horns in DraftSight
.. |The victim| image:: http://www.moop.org.uk/wp-content/uploads/2015/05/20150504_132026.jpg
   :class: alignnone size-full wp-image-823
   :width: 1024px
   :height: 576px
   :target: http://www.moop.org.uk/index.php/2015/05/04/cnc-cut-control-horns/20150504_132026/
   :alt: The victim
.. |SpeedTwin| image:: http://www.moop.org.uk/wp-content/uploads/2015/05/20150504_193645.jpg
   :class: alignnone size-full wp-image-828
   :width: 1024px
   :height: 576px
   :target: http://www.moop.org.uk/index.php/2015/05/04/cnc-cut-control-horns/20150504_193645/
   :alt: SpeedTwin
.. |Cutting the parts| image:: http://www.moop.org.uk/wp-content/uploads/2015/05/20150504_191802.jpg
   :class: alignnone size-full wp-image-825
   :width: 1024px
   :height: 576px
   :target: http://www.moop.org.uk/index.php/2015/05/04/cnc-cut-control-horns/20150504_191802/
   :alt: Cutting the parts
.. |Mostly finished parts| image:: http://www.moop.org.uk/wp-content/uploads/2015/05/20150504_193504.jpg
   :class: alignnone size-full wp-image-827
   :width: 1024px
   :height: 576px
   :target: http://www.moop.org.uk/index.php/2015/05/04/cnc-cut-control-horns/20150504_193504/
   :alt: Mostly finished parts
