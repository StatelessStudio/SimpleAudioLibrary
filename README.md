Simple Audio Library v0.1.0
============================

This is a simple audio library using OpenAL. It was made with the thought in mind to have a pretty simple tool
for playing sound/music in a game or another kind of application.

<span style="font-weight: bold; text-decoration: underline;">WARNING:</span> This is a pretty early version, keep in mind, that method/classes can be removed/renamed/changed at any time.

## License

Simple Audio Library is released under the [MIT license](http://opensource.org/licenses/MIT).

## Platform

For now, it is only build for Mac OS X. But Windows and Linux will be also supported as soon as possible.

## How to build

**Mac OS X**

- Open your console and go to <span style="text-decoration: underline;">"[directory of your copy]/Code/"</span>.
- Enter: make

Now it'll compile the library on your machine and after it's finished it copies all header files into:
<span style="text-decoration: underline;">"[directory of your copy]/Header/"</span> and the bineary to
<span style="text-decoration: underline;">"[directory of your copy]/Lib/"</span>.

So, to use this library in your application, all you have to do is to set the header path to:
<span style="text-decoration: underline;">"[directory of your copy]/Header/"</span> and the library path to:
<span style="text-decoration: underline;">"[directory of your copy]/Lib/"</span> and here we goes. You are ready to work with this libary.

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