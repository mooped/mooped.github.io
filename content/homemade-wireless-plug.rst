Homemade Wireless Plug
######################
:date: 2013-05-27 15:02
:author: charlie
:category: Things
:tags: Things
:tags: AVR, Bluetooth, DigiSpark, Electronics, Home automation, Wireless
:slug: homemade-wireless-plug
:status: published

Hello readers! First off, if you were expecting one of Moop's awesome
posts then prepare for disappointment as today you have me, Charlie,
posting instead as a special guest contributor.

The design
----------

So, I wanted to automate my home. Nothing too exciting, just turn off an
on lights and plug sockets using my phone.

So, the design main goals were...

-  Functional : It's got to work
-  Cheap : I aimed for a final price of under £10 per socket
-  Small : It had to fit within a standard wall socket/switch cavity

Reason for wanting it to fit within a standard wall cavity was mainly to
make the installation both easy and invisible. The reason for wanting
them to be cheap is because I'm weirdly cheap when it comes to building
stuff. Maybe it's a hang up from doing similar projects as a student
when I really had to to get the part spend down as low as possible. In
any case I like the challenge of trying to design stuff on a shoe
string.

Being a programmer I went straight to wanting a microcontroller of some
kind. I had three ATtiny based DigiSpark boards from when I backed the
project on Kickstarter
(http://www.kickstarter.com/projects/digistump/digispark-the-tiny-arduino-enabled-usb-dev-board).
This has almost blown my budget straight away but was rather convenient.
It was around $8 from what I remember.

Next up, the communication. The most straight forward method seemed to
be Bluetooth. It doesn't have much of a range but enough for our
purposes. Originally I thought I could connect to the sockets directly
from my iPhone however when I went to implement it, it became clear that
Apple only support the new Bluetooth 4 Low Energy profile, which no
cheap Bluetooth modules do at the moment. So instead, the idea became to
run a web server on something like a Raspberry Pi that would have a
Bluetooth module to talk to the sockets. This had the advantage of
allowing things like trivially turning every socket into a timer socket
with a nice web interface.

The Bluetooth module I went with was an HC-05. These are easy to find on
eBay and with shipping cost just $5. A datasheet is here
http://www.mcu-turkey.com/wp-content/uploads/2013/01/HC-Serial-Bluetooth-Products-201104.pdf.

We now need something to switch the mains current with. A relay seems
the obvious solution for this. So back to eBay. I ended up with a relay
that could be switched with 10mA current at 5V and could take 250V AC up
to 10 amps. More than enough for almost any single appliance. I was
mainly thinking about lighting so 2.5kW was more than enough. Cost
including shipping: $1.50

Finally, we needed a transformer of some kind. I originally thought of
building some sort of rectifier and voltage regulator to get the
required power as the amperage I needed was so low. However, even at the
small currents the amount of wasted energy would still be quite large,
which would cause heat dispersion problems, so I went for a transformer
instead. The ones I got were sold as LED drivers for things like
Christmas lights. For our purposes it was very cheap and very small.
This was around $3.

So all in, around $17.50 or £11.50, so a bit over the initial budget of
£10 per socket. If we had an in system programmer we could use a plain
ATtiny which would have only been around 60p ($1) instead of the $8
DigiSpark. Also ordering in bulk would have reduced the cost of the
other components as the prices all included shipping.

The circuit was so simple that a schematic probably isn't needed. The
transformer was wired into the mains power coming into the socket and
the 5V side powered the microcontroller, Bluetooth module and relay
module. The live wire of the mains went through the high voltage part of
the relay to the socket. The control of the relay went to an IO pin on
the DigiSpark. Three more IO pins were used by the Bluetooth module (RX,
TX and KEY).

The Bluetooth module was 3.3V chip but the ATtiny is 5V. I didn't
initially realise this until half way through building. I thought the
ATtiny was 3.3V too. This was mainly due to measuring the voltage at Vin
on the DigiSpark and seeing around 3.3V. This was the pin I powered the
Bluetooth module from. However, this was actually caused by a voltage
drop across a diode just there to protect the voltage regulator from
being connected up in reverse (D'oh!). To prevent over driving the input
pins of the Bluetooth module I also added diodes to the RX and KEY lines
as a quick fix.

I connected the relay to default to on so if it was to break the
light/socket would still be functional. The original idea was to wire up
the transformer to the socket's switch as well, although this turned out
to be difficult in practice. The reasoning behind this was that by
turning the switch off it would not only stop the internals drawing
power but if anything went wrong, there was a way to reset the
microcontroller and if the system fell into disuse all the switch would
still operate normally.

I also wired up the Bluetooth status LED as it was trivial to do and
quite helpful during testing. In practice this wasn't a good idea as the
flashing could be seen outside the socket.

The build
---------

First thing was to turn the surface mount Bluetooth module into
something a bit easier to work with. I'd never worked with surface mount
parts before, so I decided to turn it in to a through hole part by
attaching it to a bit of PCB. The spacing was quite small so couldn't
use stripboard or the like. In another first, I thought I'd try printing
my own circuit board. First, I cut a small piece of copper board. Then
holding the Bluetooth module on with a bit of tape, I then drew draw up
to the contacts that I wanted with an etch resist pen. Extending these I
created pads for where I would eventually drill through to connect the
wires. Then it was simply a matter of etching. This did take a long time
(it was very cold that day and I was just doing it in a tray) but
eventually patience paid off and I had my PCB. I then drilled the holes
and finally soldered on the part which was straight forward.

|Bluetooth Module|

At this point, I realised I'd completely destroyed my trousers! Pro tip:
Don't wear your best trousers when working with acid.

With the most difficult part over, it was then just a case of soldering
the parts together according to the design.

|Wireless plug on bench|

The software
------------

So, on to the software. The ATtiny just needs to setup the Bluetooth
module then wait to receive commands for switching the relay.

The Bluetooth module uses the RS232 interface. I originally thought I
would have to do something complex to allow full duplex sending and
receiving but in practice a very simple send, then wait for response
worked perfectly well.

Format was 1 start bit, followed by 8 bits ASCII followed by a stop bit.
Sending was as simple as...

::

     // start bit
     digitalWrite(TX, LOW);
     delayMicroseconds(BAUD_RATE);
     //character
     digitalWrite(TX, (c&1)?HIGH:LOW);
     delayMicroseconds(BAUD_RATE);
     ...
     digitalWrite(TX, (c&128)?HIGH:LOW);
     delayMicroseconds(BAUD_RATE);
     //stop bit
     digitalWrite(TX, HIGH);
     delayMicroseconds(BAUD_RATE);

After sending a command string, it would then wait for a response using
almost the complete reverse.

::

     // wait for start of start bit
     while (digitalRead(RX));
     // delay to get the middle of first bit of character
     delayMicroseconds(BAUD_RATE+BAUD_RATE/2);
     // character
     c|=(digitalRead(RX)==HIGH)?1:0;
     delayMicroseconds(BAUD_RATE);
     ...
     c|=(digitalRead(RX)==HIGH)?128:0;
     delayMicroseconds(BAUD_RATE);
     // could check for stop bit here as verification

The receiving would just loop until a newline character was read. This
was assumed to be the end of the response.

Before we could start sending commands, we set up all the IO lines, then
pulsed the KEY line low to get the Bluetooth module to start up in 9600
baud AT command mode. We could then start sending the AT commands to
setup the module. In a real world case this would set up passcodes etc
(so your neighbours couldn't control your lights). But for now we just
gave it a name and made sure we got OK back.

::

    SPARK: AT+NAME=PLUG\r\n
    BLUETOOTH: OK\r\n

From this point the KEY line was returned to low to switch the module to
communication mode. Once done it just waited to receive a character like
we did before. A '0' would turn the relay off or a '1' would turn the
relay on.

Next up was to code the web server. This needed to interface with a web
page and send the 0 or 1 to the Bluetooth module.

Being trendy, I thought a Websocket's interface would be the way to go.
Instead of doing the sensible thing and downloading a library, I decided
to do everything myself. This turned out not to be a great idea. Firstly
the websockets protocol seems needlessly complex. First, a key is sent
which you have to transform and send back. This transformation isn't the
easiest when you're trying to write everything yourself in C. First the
key gets a magic string appended, then a SHA1 hash of this is generated
and finally that hash is encoded in base64 ready to be returned. Even
when the connection is established you then need to XOR everything you
send. Not super complicated but lots of code to write. Weirdly although
this worked perfectly with Chrome, both Safari and Firefox didn't accept
my Websocket connection response. Moral of this lesson, don't pointless
write functionality you could just download a library to do.

Although I planned eventually to run the server on a Raspberry Pi or
similar, I started off programming on my laptop which meant I wrote the
Bluetooth communication code using OSX's IOBluetooth interface. This
allowed automatically pairing with the plug and the sending of the
control signals. Not having done much OSX programming before, I spent a
good hour or two pulling my hair out until I realised I didn't get
callbacks unless I called CFRunLoopRun(). Once I realised this,
everything went a lot smoother. Below is a cut down version of my
pairing code (ie. no error checking etc).

::

     inquiry=[IOBluetoothDeviceInquiry inquiryWithDelegate:self];
     [inquiry setSearchCriteria:0 majorDeviceClass:kBluetoothDeviceClassMajorUnclassified minorDeviceClass:kBluetoothDeviceClassMinorComputerUnclassified];
     if ([inquiry start]==kIOReturnSuccess)
     {
       CFRunLoopRun();
       NSArray *devices = [inquiry foundDevices];
       for (IOBluetoothDevice *device in devices)
       {
         if (![device isPaired])
         {
           IOBluetoothDevicePair *pair=[IOBluetoothDevicePair pairWithDevice:device];
           [pair setDelegate:self];
           if ([pair start]==kIOReturnSuccess)
           {
             CFRunLoopRun();
           }
         }
         if ([device openConnection]==kIOReturnSuccess)
         {
           IOBluetoothRFCOMMChannel *rfChannel;
           if ([device openRFCOMMChannelSync:&rfChannel withChannelID:1 delegate:self]==kIOReturnSuccess)
           {
             // Now you can communicate on rfChannel
             // ie. [rfChannel writeSync:(void*)str length:strlen(str)];
           }
         }
       }
     }

The object needs to implement callbacks but mostly these just consist of
calling CFRunLoopStop(CFRunLoopGetCurrent()) when the complete callbacks
is received. The only one I really had to implement was the PIN code
exchange.

The wrap up
-----------

Next up was just to cram everything into the socket...

|Wireless plug socket|

And try it out...

http://www.youtube.com/watch?v=GBEqYxaKBfM

So, I didn't actually meet my price goal or get it to fit snugly inside
a standard socket. But it isn't too far off. I have a smaller (and
cheaper!) transformer but haven't tried it yet. Also, there's lots of
space to save by integrating parts like the ATtiny, Bluetooth module and
relay driver into one PCB.

The relay might need some work too as it wasn't too impressive. After
some time (a few minutes) it tends to return to it's default state
(power on) even though it's input pin is still high. I mainly blame this
on the power supply not being able to maintain a high enough voltage but
that's just a hunch.

In practice I never put these in any sockets in the house. This was
mainly due to safety (ie. fire) and legal issues (probably is illegal to
replace sockets with own uncertified modifications). I am still
interested in home automation but will probably play it safe and stick
to the commercially available products.

.. |Bluetooth Module| image:: http://www.moop.org.uk/wp-content/uploads/2013/05/module.jpg
   :class: aligncenter size-full wp-image-250
   :width: 480px
   :height: 640px
   :target: http://www.moop.org.uk/index.php/2013/05/27/homemade-wireless-plug/module/
.. |Wireless plug on bench| image:: http://www.moop.org.uk/wp-content/uploads/2013/05/together.jpg
   :class: aligncenter size-full wp-image-251
   :width: 640px
   :height: 480px
   :target: http://www.moop.org.uk/index.php/2013/05/27/homemade-wireless-plug/together/
.. |Wireless plug socket| image:: http://www.moop.org.uk/wp-content/uploads/2013/05/cram.jpg
   :class: aligncenter size-full wp-image-252
   :width: 640px
   :height: 480px
   :target: http://www.moop.org.uk/index.php/2013/05/27/homemade-wireless-plug/cram/
