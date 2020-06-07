#Simple Audio Library

This is a simple audio library using OpenAL. It was made with the thought in mind to have a pretty simple tool
for playing sound/music in a game or another multimedia application.

WARNING: This is a pretty early version, keep in mind, that method/classes can be removed/renamed/changed at any time.

## License

Simple Audio Library is released under the [MIT license](http://opensource.org/licenses/MIT).

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
#include <CoreSystem.h>
#include <CorruptedFileException.h>
#include <InvalidPathException.h>
#include <NoContextException.h>
#include <NoDeviceException.h>

#include <iostream>

int main()
{
    try {
        // before you can use this library, you have to initialize it
        SimpleAudioLib::CoreSystem& system = SimpleAudioLib::CoreSystem::getInstance();

        system.initWithDefaultDevice();

        // load audio file in wave format
        SimpleAudioLib::AudioEntity* sound = system.createAudioEntityFromFile("../resources/test.wav");

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

        SimpleAudioLib::CoreSystem::release();

    }
    catch (SimpleAudioLib::InvalidPathException ex) {
        std::cout << "[ERROR] (Invalid Path) " << ex.what() << std::endl;
    }
    catch (SimpleAudioLib::CorruptedFileException ex) {
        std::cout << "[ERROR] (Corrupted File) " << ex.what() << std::endl;
    }
    catch (SimpleAudioLib::NoContextException ex) {
        std::cout << "[ERROR] (No Context) " << ex.what() << std::endl;
    }
    catch (SimpleAudioLib::NoDeviceException ex) {
        std::cout << "[ERROR] (No Device) " << ex.what() << std::endl;
    }
    catch (std::exception ex) {
        std::cout << "[ERROR] " << ex.what() << std::endl;
    }
}
```
