# Transcend
Jason Rohrer's Transcend, for modern linux systems.

[Original release](https://transcend.sourceforge.net/)

# Motivation
The codebase is now almost 20 years old, and it depended on an old version of portaudio, so, if you try to compile it
on modern (linux) systems, you'll probably hit a wall.

Me, being inexperienced in C++ game development, made the bare minimum to get it to compile: this repo includes a slightly
newer version (v19) of portaudio, dating from 2007. It has the modern interfaces portaudio provides, so it suffices. Ideally,
we should link against the operating system's version of portaudio though.
I then made some changes to SoundPlayer.cpp, which is the only file in the source that depends on portaudio directly.
These are minimum and it just updates the code into using the new structures and definitions portaudio v19 provides.

Some other modifications include the portaudio section of runToBuild script and the game's own makefile, linking it to 
ALSA and jack, so make sure you have the corresponding libraries in your system, in arch:

```
sudo pacman -S jack2 lib32-jack2
# If you use pipewire:
sudo pacman -S pipewire-jack lib32-pipewire-jack
```

# How to compile
Run:

``./runToBuild``

# TODO

Currently audio doesn't work, to the detriment of my effort.
