New Site With Pelican Static Site Generator
###########################################
:date: 2017-02-06 20:57
:author: moop
:category: Site
:tags: Site, Pelican
:slug: new-site
:status: published

You may noticee that this site now looks completely different.

I decided that I was bored of paying for an AWS instance to host WordPress,
and restarting PHP when it crashed, and so on. I also got tired of the massive
stall when my tiny AWS instance struggled to create a new post.

I've been thinking about writing my own static site generator for a while, but I
didn't want to commit the time to it when there are more interesting projects and
it's something that's been done before.

After a bit of research I decided I'd try out Pelican. I'm a fan of Python anyway
so I'm right at home editing the config files and I know what I'm doing if I need
to make any tweaks. I've played with reStructuredText when writing documentation
at work so I know the appropriate syntax for writing content too.

Even better it supports importing from WordPress. I did have to make a few tweaks
to remove some markup that didn't convert correctly. Fortunately that was a one off
job and it became trivial with the aid of some simple vim macros. 

There are probably a few more issues I need to sort out but I'm happy enough with
the current state of the site that I've switched it over to the Pelican version.

There's no commenting supported yet. I might bring over the archived comments at
some point by appending them to the appropriate posts. If I decide to enable
comments again I'll probably try out Disqus unless I find a better alternative.

I'm currently hosting this on GitHub pages. We'll see how that pans out, but I
like git and it's free, so seems like a winner so far!

I realise that I've namechecked a bunch of marmite software that will make some
developers howl with joy and others with rage. Maybe it's for the best that there
is no comment system yet!
