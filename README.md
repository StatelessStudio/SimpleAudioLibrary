# Simple Audio Library

This is a simple audio library using OpenAL. It was built as a simple tool for playing sound/music in a game or another multimedia application.

## Installation

### Conan (Recommended)

Add the remote:

`conan remote add https://bintray.com/statelessstudio/simple-audio-library`

Create your conanfile:

`conanfile.txt`
```
[requires]
simple-audio-library/1.0.0@demo/testing

[options]

[generators]
cmake
```

Create your CMake file:

`CMakeLists.txt`
```
cmake_minimum_required (VERSION 3.8)
project(SalTest)

include(dependencies/conanbuildinfo.cmake)
conan_basic_setup()

# Add source to this project's executable.
file(GLOB source_files
    "*.h"
    "*.cpp"
)

add_executable(SalTest ${source_files})
target_link_libraries(SalTest ${CONAN_LIBS})
```

And install!

`mkdir dependencies && cd dependencies`

`conan install ..`

## Usage

[See the example](https://github.com/StatelessStudio/SimpleAudioLibrary/test_package/example.cpp)

### Create a listener (observer)

Create a listener to "hear" the sound, and to register a device to hear with.

**NOTE - As of v1.0.0, you can create multiple listeners, but only if you know what you're doing! Most applications will only need a single listener!**

```cpp
SimpleAudio::Listener listener;
listener.initWithDefaultDevice();
listener.setPosition(0, 0, 0);
listener.setVelocity(0, 0, 0);
```

### Load a sound file

Load a wave file into a `Sound`:

```cpp
SimpleAudio::Sound ouch;
ouch.loadWaveFile("../resources/ouch.wav");
```

### Create a source to play the sound

In addition to loading a sound, you'll also need somewhere to play it:

```cpp
SimpleAudio::Source player;
player.setPosition(1, 0, 0);
```

### Play the sound!

```cpp
player.play(ouch.getBuffer());
```

## Documentation

Build the docs:

```bash
doxygen
```

You'll see the docs folder appear, find and open `index.html`.
