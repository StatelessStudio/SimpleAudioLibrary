# Simple Audio Library

This is a simple audio library using OpenAL. It was made with the thought in mind to have a pretty simple tool for playing sound/music in a game or another multimedia application.

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

```cpp
#include <Listener.h>
#include <CorruptedFileException.h>
#include <InvalidPathException.h>
#include <NoContextException.h>
#include <NoDeviceException.h>

#include <iostream>

int main()
{
    try {
        // before you can use this library, you have to initialize it
        SimpleAudio::Listener& system = SimpleAudio::Listener::getInstance();

        system.initWithDefaultDevice();

        // load audio file in wave format
        SimpleAudio::Source* sound = system.createSourceFromFile("../resources/test.wav");

        std::cout << "Success!" << std::endl;
        std::cout << "q to quit" << std::endl;

        sound->setPitch(0.5);

        float input = 0.5;
        while (input != 'q') {
            std::cin >> input;

            sound->setPitch(input);
            
            // play sound
            sound->play();
        }

        // clean up
        delete sound;
        sound = NULL;

        SimpleAudio::Listener::release();

    }
    catch (SimpleAudio::InvalidPathException ex) {
        std::cout << "[ERROR] (Invalid Path) " << ex.what() << std::endl;
    }
    catch (SimpleAudio::CorruptedFileException ex) {
        std::cout << "[ERROR] (Corrupted File) " << ex.what() << std::endl;
    }
    catch (SimpleAudio::NoContextException ex) {
        std::cout << "[ERROR] (No Context) " << ex.what() << std::endl;
    }
    catch (SimpleAudio::NoDeviceException ex) {
        std::cout << "[ERROR] (No Device) " << ex.what() << std::endl;
    }
    catch (std::exception ex) {
        std::cout << "[ERROR] " << ex.what() << std::endl;
    }
}
```

## Documentation

Build the docs:

```bash
doxygen
```

You'll see the docs folder, find `index.html`
