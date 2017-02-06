Arcade Control Panels
#####################
:date: 2014-02-17 23:20
:author: moop
:category: Things
:tags: Arcade Controllers, Things
:slug: arcade-control-panels
:status: published

Charlie's SuperGun had me inspired to build my own at some point, but I
thought I'd start at the other end and build some appropriate
controllers first. Partly as a birthday present to myself I decided to
make a pair of arcade control panels.

After a long time reading
`SlagCoin <http://slagcoin.com/joystick.html>`__, I settled upon a
fairly simple box design with a joystick and 6 buttons on the front face
and a pair of buttons on the left and right. I eventually settled on a
black and white theme, with a black Perspex face plate and white
buttons.

|Finished Controller|

To get started, I ordered two sets of joystick + 8 arcade buttons from
`UltraCabs <http://www.ultracabs.co.uk/>`__. I also bought a pack of 100
4.8mm female spade connectors, 20m of stranded wire and two A4 sheets of
black Perspex from eBay.

|Initial parts|

Once this arrived I was slightly overwhelmed, but also motivated by the
need to get it all off of my desk so I could reclaim some space.

To decide on the final layout, I printed out various button layouts and
experimented to see what felt best, how much space was required for
wrist rests and how much separation was needed between the joysticks and
buttons. I settled on A4 size for the main panel as this provided plenty
of wrist support and neatly avoided the need to trim the Perspex sheets
I had.

With the panel layout decided, I wanted to get an idea of how the
controllers should fit together and ensure everything would fit. To
achieve this I measured and drew the joysticks and buttons in
`Draftsight <http://www.3ds.com/products-services/draftsight/overview/>`__
before designing the rest of the structure around them. From the initial
3-view I had drawn, I extracted the various panels and printed these for
reference during the build.

You can download the drawing from here, but bear in mind other brands of
buttons and joysticks will vary in size: `Arcade Controller
Layout <http://www.moop.org.uk/index.php/2014/02/17/arcade-control-panels/arcade-controller/>`__

|Controller Layout and Structure|

For the cosmetic front panels I used the
`Nottinghack <http://www.nottinghack.org.uk/>`__ laser cutter to cut
holes for the buttons, directly exported from my plan. Later on, the
front panels also provided a template for drilling the structural front
panel accurately.

For the box I wanted to hide any visible screws, so I built an inner
frame that supported most of the structure from some wood reclaimed from
an old sofa. Each pair of sides was match cut by taping two pieces
together and cutting them to length on the chop saw. They were screwed
together and countersunk using framing clamps to keep everything square,
ensuring that everything lay flat on the table after each corner was
joined.

With the inner frame built, I made a nice looking outer frame from some
planed timber which happened to come in the required size (70mm wide,
18mm deep in my case). I match cut the parts for this similarly to the
inner frame, then screwed this onto the outer frame through pilot holes
drilled in the inner. I wanted the Perspex front panel to sit slightly
proud of the top of the outer frame. To ensure that everything aligned
nicely, I used the real Perspex front panel and some material slightly
thinner than the structural front panel to pack the inner frame to the
correct height. With the outer frame sitting on the table surface. Once
a pair of sides was attached, the packing material was removed so the
real outer frame could set the correct alignment for the other two
sides. Once the outer frame was attached, I drilled a hole in the back
of the the outer frame about 1cm from the bottom for the USB cables to
exit, then used a saw to extend this hole into a slot.

Unfortunately, I messed up the placement of the holes for the side
buttons while making the outer panels, so drilling the holes in the
inner frame would have required drilling through some screws. I decided
to leave them out for now and revisit later, I'm planning to make
additional changes to the controllers in the future.

|Attaching the outer frame|

With the sides of the box built, I cut the structural front panel from
some chipboard plinth material I had lying around from a DIY project.
This was made in two parts in my case though this isn't strictly
necessary. Once cut to shape this material was fitted into the frame and
drilled and counter sunk so that the Perspex front panel could sit on
top. With the Perspex front panel in place, I drew around the holes,
marking the location of the buttons and joystick. I then took the
joystick mounting plate, aligned it with the joystick hole on this panel
and traced the outline.

|Front panel marked out|

For the button holes I found the centres using a paper template printed
from my CAD drawing, then drilled them out with a 1 inch spade bit. For
the buttons I used, the hole in the perspex needed to be larger than the
hole in the front panel as there is a 3mm deep step below the bevel.
Mounting the joystick was more complicated, as it needs to sit as close
to the Perspex front panel as possible. To achieve this I used my
eShapeOko CNC machine with a 3mm end mill. I had a `simple python
script <http://www.moop.org.uk/index.php/2014/02/17/arcade-control-panels/leveller/>`__
that I'd previously written to level the bed on the machine, which I
used to generate g-code for the rectangular pockets required.

[gallery ids="652,656,657,658,662,665"]

After routing the pockets and cutting out a square hole for the joystick
body with a coping saw I noticed that the body was slightly too shallow,
so fitting the joystick would put a lot of pressure on the contacts of
its microswitches. To work around this I made some additional pockets on
the back side as a relief for these contacts to sit in.

With all the mounting holes cut out I removed the structural front panel
and spray painted it black, to blend it in with the Perspex faceplate
and to hide all the marks from cutting it to shape.

[gallery ids="645,667"]

To protect the wood of the outer frame, which will be handled often, I
painted on two coats of Eze-Cote water based polyurethane resin, sanding
in between with 400 grit sandpaper. This is really intended for applying
fibreglass to model aircraft, but worked well to give a nice smooth feel
to the controllers while retaining the natural look and light colour of
the wood.

|Finishing the wood|

The final structural component of the controllers was the bottom panel,
for which I used a simple A4 sheet of 3mm MDF. This was drilled and
countersunk in the four corners and then screwed to the bottom of the
inner frame.

Initially I decided I wanted these controllers to be able to emulate a
USB keyboard so they could be used on nearly any PC game. Later on I
plan to make the encoder swappable so the controllers can be used with a
SuperGun or various retro consoles by swapping out an encoder cartridge.

For the USB version I used a Minimus AVR dev board from the Nottinghack
vending machine, running a modifed version of the `LUFA keyboard
demo <https://github.com/abcminiuser/lufa/tree/master/Demos/Device/ClassDriver/Keyboard>`__.
I decided since I would be changing the encoder later that I would avoid
soldering directly to the Minimus board, so I added pin headers to it. I
based the wiring loom for the controller on a piece of stripboard, using
a widened 40 pin DIL socket to mount the Minimus. In the case of my
controller, all of the ground connections are wired to the ground pin on
the Minimus, and the other pole on each microswitch is connected to a
pin on either port B or port D of the Minimus.

[gallery ids="620,622,625,674"]

To cut down on the number of wires leaving the board I daisy chained the
ground connections for the joystick (4 terminals) and the face buttons
(6 terminals). The buttons for the currently unused side buttons (which
have their own grounds) are tied back out of the way and covered in
insulating tape (not shown above).

You can find my changes to the LUFA Keyboard demo on `my GitHub
account <https://github.com/mooped/lufa/commit/765cf6a21b5a47a56b46480600cfdcdfb3b76eb2>`__,
but your mileage may vary and I will probably be making further
refinements later. Using this code the input pins, mappings and intended
uses are as follows:

`` PB0 - Z - Coin PB1 - X - Start PB2 - W - Up PB3 - S - Down PB4 - A - Left PB5 - D - Right PB6 - F - Button 1 PB7 - G - Button 2 PD0 - H - Button 3 PD1 - V - Button 4 PD2 - B - Button 5 PD3 - N - Button 6``

This layout maps the joystick to appropriate keys for playing
`Nidhogg <http://nidhogggame.com/>`__. Most games will provide some form
of input remapping, which is easier than reprogramming the controllers
each time. For games where this is not possible, I use
`AutoHotKey <http://www.autohotkey.com/>`__ which can remap keys on the
fly. More interestingly, it can change the mappings depending on which
window is active. For example, to feed my
`SuperCrateBox <http://www.supercratebox.com/>`__ addiction, I use the
following script:

`` ; ArcadeStick -> SuperCrateBox #IfWinActive ahk_class TRunnerForm w::Up s::Down a::Left d::Right f::x g::z h::p v::z b::x n::Esc #IfWinActive``

Finally, the finished product, fully assembled:

|Finished|

The Perspex panel is held down by the bevels on the buttons, so no
additional work was required to fix it.

I still have a few things I need to tackle, but I'm enjoying the
controllers as they are currently, and they work nicely on the games
I've tried so far.

My future goals for the controllers are:

-  Input debouncing - hard to tell if this is needed but there is the
   occasional glitch
-  Side buttons
-  Use side buttons to switch between player 1/2 key mappings or as
   coin/start buttons on a Jamma arcade board
-  Swappable encoder cartridges
-  Make use of the illuminated buttons

The Draftsight drawing of the controller is available to download via
the following link: `Arcade Controller
Drawings <http://www.moop.org.uk/wp-content/uploads/2014/02/controller.zip>`__
This contains 2D projections of the wooden and perspex parts needed to
build the controller.

.. |Finished Controller| image:: http://www.moop.org.uk/wp-content/uploads/2014/02/2014-02-17-19.25.35.jpg
   :class: alignnone size-full wp-image-685
   :width: 1024px
   :height: 613px
   :target: http://www.moop.org.uk/index.php/2014/02/17/arcade-control-panels/2014-02-17-19-25-35/
   :alt: Finished Controller
.. |Initial parts| image:: http://www.moop.org.uk/wp-content/uploads/2014/02/2014-01-23-19.16.01.jpg
   :class: alignnone size-full wp-image-615
   :width: 1024px
   :height: 613px
   :target: http://www.moop.org.uk/index.php/2014/02/17/arcade-control-panels/2014-01-23-19-16-01/
   :alt: Initial parts
.. |Controller Layout and Structure| image:: http://www.moop.org.uk/wp-content/uploads/2014/02/3-view.png
   :class: alignnone size-full wp-image-686
   :width: 1012px
   :height: 778px
   :target: http://www.moop.org.uk/index.php/2014/02/17/arcade-control-panels/3-view/
   :alt: Controller Layout and Structure
.. |Attaching the outer frame| image:: http://www.moop.org.uk/wp-content/uploads/2014/02/2014-02-06-19.31.01.jpg
   :class: alignnone size-full wp-image-688
   :width: 1024px
   :height: 613px
   :target: http://www.moop.org.uk/index.php/2014/02/17/arcade-control-panels/2014-02-06-19-31-01/
   :alt: Attaching the outer frame
.. |Front panel marked out| image:: http://www.moop.org.uk/wp-content/uploads/2014/02/2014-02-07-20.22.53.jpg
   :class: alignnone size-full wp-image-689
   :width: 1024px
   :height: 613px
   :target: http://www.moop.org.uk/index.php/2014/02/17/arcade-control-panels/2014-02-07-20-22-53/
   :alt: Front panel marked out
.. |Finishing the wood| image:: http://www.moop.org.uk/wp-content/uploads/2014/02/2014-02-16-00.06.32.jpg
   :class: alignnone size-full wp-image-680
   :width: 1024px
   :height: 613px
   :target: http://www.moop.org.uk/index.php/2014/02/17/arcade-control-panels/2014-02-16-00-06-32/
   :alt: Finishing the wood
.. |Finished| image:: http://www.moop.org.uk/wp-content/uploads/2014/02/2014-02-17-19.25.18.jpg
   :class: alignnone size-full wp-image-683
   :width: 1024px
   :height: 613px
   :target: http://www.moop.org.uk/index.php/2014/02/17/arcade-control-panels/2014-02-17-19-25-18/
   :alt: Finished
