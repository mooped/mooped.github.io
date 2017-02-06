Siri, control my lights
#######################
:date: 2013-08-15 20:08
:author: charlie
:category: Things
:tags: Charlie
:slug: siri-control-my-lights
:status: published

Once again, it's not moop but Charlie, so we're talking home automation
instead of planes.

My last video on home automation turned out to be surprisingly popular!
So, to celebrate I've done a quick follow up on the same idea. One thing
people commented on was that I should have used SiriProxy. I had
considered this when writing Jeeves
(http://www.youtube.com/watch?v=gZkwvSX0\_Os). I felt it wasn't quite as
cool as having a device that listens all the time though. However,
SiriProxy doesn't seem to require a huge amount of processor time so can
run happily next to Jeeves even on a Raspberry Pi, so I thought I'd give
it a go.

http://youtu.be/Z7gtugR2umI

Setting up was amazingly easy. I basically followed the instructions
verbatim from the main SiriProxy page
(https://github.com/plamoni/SiriProxy). There's a lot of complicated
guides for old versions of SiriProxy but the latest version is quite
simple to setup, so just follow the instructions from the main page.

The only thing I did differently to the instructions was that I had to
copy my .siriproxy directory from my user directory to /root/.siriproxy.
This is probably because when I generated the certificates, I wasn't
root. You should be able to run SiriProxy as an unprivileged user but I
didn't get that to work. It's only on the Pi so, I don't have any
reservations about running SiriProxy as root anyway, so I just went with
it.

Once the Pi was set up and running, all that was left was to set up my
phone. This required e-mailing the generated certificate and changing
the WiFi settings so that the DNS server pointed at the Pi.

With that working, next was the fun part of actually making a plugin for
SiriProxy so it would do my bidding. There's already a LightwaveRF
plugin but what's the fun of being like everyone else! Naturally I wrote
my own. It's might be worse that the existing plugin, I didn't check
before writing my own version.

The first hurdle to overcome was that the plugins need writing in Ruby.
I'd never even seen Ruby code until I wrote the plugin so I probably
didn't do things in the most efficient way but it was easy to get
something working.

The main bulk of the plugin consists of these clauses...

::

    listen_for /some regex/ do |variables,to,store,matches|
      say "Hey I recognised that"
      request_completed
    end

Adding the lightwaveRF UDP protocol was easy from Ruby. First a socket
is created and the host/port set up with...

::

    s = UDPSocket.new
    port = 9760
    host = "192.168.0.10"

To turn on a device can then be done with only one line...

::

    s.send("000,!R1D1F1|Siri|On", 0, host, port)

Each room contains a list of sockets that it has. When saying "There is
a desklamp in the left socket", it first matches via a regular
expression and extracts the two important bits, "desklamp" and "left
socket". Next it verifies that "left socket" is a socket it knows about.
If it is, then it inserts a new entry into the "items" hash map linking
"desklamp" to the left socket.

When you say "Turn on desklamp", the word "desklamp" is looked up in the
items hash map. If it finds a match then it sends the required command
to the socket it was registered with. If it doesn't find anything in the
map then it will check for a socket called "desklamp". Being a lazy
programmer, the lights use this trick as they are implemented as just
another socket. I could say "There is a banana in the lights" and I
would be able to turn on my lights by saying "Switch on banana". That
sort of bug, I don't mind letting slip through though as it's a remote
possibility anyone would try.

I think that pretty much covers it. I hope someone finds it fun and has
a go at implementing their own system.

If you want to look at my code, you can get it by clicking
this \ `siriproxy-lightwave <http://www.moop.org.uk/wp-content/uploads/2013/08/siriproxy-lightwave.zip>`__.
