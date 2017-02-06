Tricopter
#########
:date: 2014-12-28 16:12
:author: moop
:category: Things
:tags: Maiden Flights, Things, TriCopter
:slug: tricopter
:status: published

|Finished Tricopter|

I've been neglecting this blog recently due to various distractions but
have several projects I want to write up. Around April I found myself
with the urge to build a multicopter. In the end I settled on a
tricopter design as it's a little unusual and because the wider angle
between the arms allows plenty of clearance to mount a camera without
getting the propellors in frame.

|Bare frame|

To keep costs down and because I enjoy designing things I ended up
drawing and laser cutting my own plywood frame. This was loosely based
on the folding arms of `David Windestål's
design <http://rcexplorer.se/projects/2013/01/the-tricopter-v2-6hv-delux/>`__,
with a lot of modifications to fit the size and shape I wanted and to
fit the parts I had chosen.

The arms of my tricopter are cut from 3/8" birch engine bearer stock, as
sold in most model shops. I bought 3 12" lengths which I cut off centre
to make a set of 7" arms and a set of 5" arms. In the end I was happy
with the 7" arms so I've not yet tested the 5" version.

|Folded|

The frame is designed to have two 3mm ply lower plates that the arms are
sandwiched between, held together with 2mm machine screws. The screws
are tightened so that the arms are held in place by friction when
unfolded, but they can still be folded relatively easily without any
adjustments or tools.

Following David's pattern, the landing struts and motor plates are
attached with cable ties. These hold everything firmly in place but will
hopefully give or break before the frame components if too large an
impact is applied.

Above the two structural plates of the frame there is a third plate with
a large number of cutouts. This sits above the frame on laser cut
plywood standoffs and serves to protect the electronics that sit on top
of the frame. The `KK
2.1 <http://www.hobbyking.com/hobbyking/store/__54299__Hobbyking_KK2_1_5_Multi_rotor_LCD_Flight_Control_Board_With_6050MPU_And_Atmel_644PA.html>`__
flight controller I'm using has a build in LCD display and buttons for
configuration in the field. All of the buttons and the display are
accessible through a cutout in the top plate. Additionally the plate
helps with cable management, wiring being attached to the frame with
cable ties and velcro straps to keep it neat.

|Swivel Mount|

Because I went for a tricopter design I required a swivel mount for the
rear motor. This consists of a modified motor mount plate with two tabs
on the bottom through which an M3 bolt is threaded. A pair of bearing
carriers are formed from two layers of ply parts that slot over the rear
arm with appropriately sized holes to trap a pair of bearings through
which the bolt runs. The rear landing strut was cut with an appropriate
cutout for the metal gear servo that moves the rear motor mount. This
turned out to be a weak point and is so far the only part I have broken.
A new design has been drawn up but has yet to be tried as the
replacement rear leg is still going strong after many more landings
(with slightly more care).

|Rear ESC modifications|

Electronically the tricopter is fairly simple, though there is a small
hack to power the rear servo. Each speed controller includes a voltage
regulator which normally powers the other equipment that needs 5 volts.
Since there are multiple ESCs in a multicopter, only one of these is
required. People cut the 5v wire to prevent the regulators from fighting
(probably only necessary with switching regulators). The KK 2.1 board
simplifies this as the first ESC connector powers the board and radio
reciever while the 5v pin from the other 7 are isolated so no wires need
to be cut. This does mean, however, that no power is provided to the
servo. To work around this I modified the rear ESC by desoldering the 5v
wire and removing it from the connector. I then soldered a 3 pin header
to the voltage regulator output to make the 5v and ground lines of an
additional connector. The 5v wire from the original connector was
attached to the third pin of this and at the other end plugged into the
signal pin from the servo output on the KK 2.1 board. This provides a
connector on the rear ESC into which the servo could be plugged,
providing power and the appropriate signal to drive the servo (see
diagram).

|Tricopter Wiring Diagram|

|Top View|

Very few changes were required to make the tricopter fly nicely, with
the exception of increasing the proportional gain for roll and pitch
without which the controls felt quite sluggish.

I have some video from an early test flight shot using a cheap 808
keychain camera. I've since bought a Mobius and added an appropriate
mount but haven't had chance to get any footage with the new camera due
to weather. The downside of building the tricopter from wood is I don't
want to get it wet!

|Mobius Cam|

| **Components:**
| **Reciever:** Hitec Optima 7
| **Flight Controller:** KK 2.1
| **ESCs:** Turnigy Plush 10A
| **Motors:** Turnigy Multistar 1704-1900kV
| **Rear Servo:** Turnigy TSS 10-MG
| **Battery:** Turnigy 1000Mah 3S 20C LiPo

I've made the drawings from which the tricopter was built are available
to
`download <http://www.moop.org.uk/index.php/2014/12/28/tricopter/moop-triciopter/>`__
and I'd enjoy hearing about it if anyone uses them in a project.

.. |Finished Tricopter| image:: http://www.moop.org.uk/wp-content/uploads/2014/12/20140914_124309.jpg
   :class: alignnone size-full wp-image-782
   :width: 938px
   :height: 528px
   :target: http://www.moop.org.uk/index.php/2014/12/28/tricopter/20140914_124309/
   :alt: Finished Tricopter
.. |Bare frame| image:: http://www.moop.org.uk/wp-content/uploads/2014/12/20140626_212027.jpg
   :class: alignnone size-full wp-image-769
   :width: 938px
   :height: 528px
   :target: http://www.moop.org.uk/index.php/2014/12/28/tricopter/20140626_212027/
   :alt: Bare frame
.. |Folded| image:: http://www.moop.org.uk/wp-content/uploads/2014/12/20140914_124330.jpg
   :class: alignnone size-full wp-image-783
   :width: 413px
   :height: 734px
   :target: http://www.moop.org.uk/index.php/2014/12/28/tricopter/20140914_124330/
   :alt: Folded
.. |Swivel Mount| image:: http://www.moop.org.uk/wp-content/uploads/2014/12/20140626_222614.jpg
   :class: alignnone size-full wp-image-771
   :width: 413px
   :height: 734px
   :target: http://www.moop.org.uk/index.php/2014/12/28/tricopter/20140626_222614/
   :alt: Swivel Mount
.. |Rear ESC modifications| image:: http://www.moop.org.uk/wp-content/uploads/2014/12/20140703_214613.jpg
   :class: alignnone size-full wp-image-776
   :width: 938px
   :height: 528px
   :target: http://www.moop.org.uk/index.php/2014/12/28/tricopter/20140703_214613/
   :alt: Rear ESC modifications
.. |Tricopter Wiring Diagram| image:: http://www.moop.org.uk/wp-content/uploads/2014/12/tricopter-wiring.png
   :class: alignnone size-full wp-image-795
   :width: 1368px
   :height: 692px
   :target: http://www.moop.org.uk/index.php/2014/12/28/tricopter/tricopter-wiring/
   :alt: Tricopter Wiring Diagram
.. |Top View| image:: http://www.moop.org.uk/wp-content/uploads/2014/12/20140703_214719.jpg
   :class: alignnone size-full wp-image-778
   :width: 938px
   :height: 528px
   :target: http://www.moop.org.uk/index.php/2014/12/28/tricopter/20140703_214719/
   :alt: Top View
.. |Mobius Cam| image:: http://www.moop.org.uk/wp-content/uploads/2014/12/20141016_221414.jpg
   :class: alignnone size-full wp-image-786
   :width: 938px
   :height: 528px
   :target: http://www.moop.org.uk/index.php/2014/12/28/tricopter/20141016_221414/
   :alt: Mobius Cam
