Simple Audio Library v0.1.0
============================

This is a simple audio library using OpenAL. It was made with the thought in mind to have a pretty simple tool
for playing sound/music in a game or another kind of application.

WARNING: This is a pretty early version, keep in mind, that method/classes can be removed/renamed/changed at any time.

## License

Simple Audio Library is released under the [MIT license](http://opensource.org/licenses/MIT).

## Platform

For now, it is only build for Mac OS X. But Windows and Linux will be also supported as soon as possible.

## How to build

**Mac OS X**

- Open your console and go to "[directory of your copy]/Code/".
- Enter: make

Now it'll compile the library on your machine and after it's finished it copies all header files into:
"[directory of your copy]/Header/" and the bineary to
"[directory of your copy]/Lib/".

So, to use this library in your application, all you have to do is to set the header path to:
"[directory of your copy]/Header/" and the library path to:
"[directory of your copy]/Lib/" and here we goes. You are ready to work with this libary.

## Code Example

This is the simplest version to work with this library:
```c++
// include needed header files
#include <SimpleAudioLib/CoreSystem.h>

// before you can use this library, you have to initialize it
SimpleAudioLib::CoreSystem& system = SimpleAudioLib::CoreSystem::getInstance();

system.initWithDefaultDevice();

// load audio file in wave format
SimpleAudioLib::AudioEntity* sound = system.createAudioEntityFromFile("YourAudioFile.wav");

// play sound
sound.play();

// clean up
delete sound;
sound = NULL;

SimpleAudioLib::CoreSystem::release();
```