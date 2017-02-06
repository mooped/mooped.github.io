Retrochallenge 2016/10 - Building retro computers with modern tools
###################################################################
:date: 2016-10-23 20:26
:author: moop
:category: Retrochallenge
:tags: RC2014, Retrochallenge
:slug: retrochallenge-201610-building-retro-computers-with-modern-tools
:status: published

I've been struggling for free time this month for poking around with
breadboards and other fun things. To work around this, and still
(hopefully) get my RetroChallenge entry done, I decided to use a
simulator so I could work on it with my laptop whenever and wherever
there was time.

|LogiSim Edge Detector|

For an earlier RC2014 project I used
`LogiSim <http://www.cburch.com/logisim/>`__ which is simple and easy to
use, but I quickly hit some limitations. The built in sequential
building blocks (shift registers, latches, etc) appear to support only a
limited set of variants. There is no option for asynchronous resets, or
transparent latches on the shift registers. It includes combinatorial
building blocks (logic gates, etc) also, but these do not appear to work
correctly for building sequential circuits, as feedback is not always
handled correctly. Because of this I was not able to simulate the exact
characteristics for most of the 74 series ICs I was using.

To solve this problem I switched to using `Altera
Quartus <https://www.altera.com/>`__ to build a model of the circuit and
ModelSim Altera Edition to simulate it. I mainly chose this because I've
used it previously for FPGA projects, and because if some functionality
is missing I can implement it in Verilog.

|Autoshift Circuit|

When redesigning the autoshifter circuit (to shift out 8 bits of data
after each IO write) I built it as a Block Diagram/Schematic File (.bdf)
in Quartus. This allows the design to be entered as a schematic with
various logic symbols supported by default. Additional components can be
created with a hardware definition language such as Verilog, or by using
Quartus' "MegaWizard Plug In Manager" to configure and insert a variant
of an IP core. I set my project up for the Cyclone II FPGA as I have
used it for previous projects. To simulate the 74HCT165 shift register I
configured a variant of the LPM\_SHIFTREG IP core with 8 bits of data,
parallel inputs and serial inputs, serial output, and a clock enable
pin.

Unfortunately this still does not quite match the 74HCT165 exactly as it
has D flip flops rather than transparent latches. I could build my own
shift register in Verilog, but to save time I opted to stick with the
LPM\_SHIFTREG version and ensure that the timings seen in simulation
were such that the transparent latches wouldn't cause a problem.

|Simulation|

In order to test the design I set Quartus up to launch ModelSim and run
Gate Level Simulation after compilation. ModelSim can be driven manually
through the GUI, but this is fairly fiddly and repetitive. Fortunately
it supports scripting via 'do files' which contain lists of commands for
ModelSim to interpret.

I set up four do files:

-  init.do - Reset, add graphs for appropriate signals, set default
   values for inputs
-  shift8.do - Drive the data bus to the appropriate values to set
   SHIFT8 and deassert /BITBANG, then assert and deassert /CONFIGWR
-  write.do - Simulate a write to the device by driving the data bus and
   /DATAWR signals, zoom graph to fit
-  sdtest.do - Run the previous three do files in sequence, zoom graph
   to fit

This allowed a fairly quick turnaround by hitting compile in Quartus,
selecting the project once ModelSim launches, then typing 'do sdtest.do'
to run the simulation.

For a different project I could have sped things up by keeping
everything inside ModelSim, but this would have required me to design
the circuit in a hardware definition language. Since my final target is
a circuit built from discrete components and not an FPGA bitstream I
decided to take advantage of the Block Diagram/Schematic feature in
Quartus. This way everything could be easily translated back to a
physical circuit once it was verified as working.

Now I have the autoshift circuit working, theoretically, I just need to
find some time to build and test the physical version!

.. |LogiSim Edge Detector| image:: http://www.moop.org.uk/wp-content/uploads/2016/10/logisim.png
   :class: size-full wp-image-975
   :width: 804px
   :height: 460px
   :target: http://www.moop.org.uk/index.php/2016/10/23/retrochallenge-201610-building-retro-computers-with-modern-tools/logisim/
   :alt: LogiSim Edge Detector
.. |Autoshift Circuit| image:: http://www.moop.org.uk/wp-content/uploads/2016/10/board2.png
   :class: size-full wp-image-974
   :width: 1438px
   :height: 898px
   :target: http://www.moop.org.uk/index.php/2016/10/23/retrochallenge-201610-building-retro-computers-with-modern-tools/board2/
   :alt: Autoshift Circuit
.. |Simulation| image:: http://www.moop.org.uk/wp-content/uploads/2016/10/simulation2.png
   :class: size-full wp-image-976
   :width: 1438px
   :height: 898px
   :target: http://www.moop.org.uk/index.php/2016/10/23/retrochallenge-201610-building-retro-computers-with-modern-tools/simulation2/
   :alt: Simulation
