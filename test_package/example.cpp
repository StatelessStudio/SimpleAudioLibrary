#include <SimpleAudioLibrary/CoreSystem.h>
#include <SimpleAudioLibrary/CorruptedFileException.h>
#include <SimpleAudioLibrary/InvalidPathException.h>
#include <SimpleAudioLibrary/NoContextException.h>
#include <SimpleAudioLibrary/NoDeviceException.h>

#include <iostream>

int main()
{
    try {
        // before you can use this library, you have to initialize it
        SimpleAudioLib::CoreSystem& system = SimpleAudioLib::CoreSystem::getInstance();

        system.initWithDefaultDevice();
        system.setListenerPosition(0, 0, 0);
        system.setListenerVelocity(0, 0, 0);

        // load audio file in wave format
        SimpleAudioLib::AudioEntity* sound = system.createAudioEntityFromFile("../../../../resources/wow.wav");

        std::cout << "Success!" << std::endl;
        std::cout << "q to quit" << std::endl;

        sound->setPitch(0.5);

        char input = ' ';
        float x, y, z;

        while (input != 'q') {

            std::cout << "x: " << std::flush;
            std::cin >> x;
            std::cout << "y: " << std::flush;
            std::cin >> y;
            std::cout << "z: " << std::flush;
            std::cin >> z;
            sound->setPitch(1);
            sound->setPosition(x, y, z);
            
            // play sound
            sound->play();

            std::cout << "q? " << std::flush;
            std::cin >> input;
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

    return 0;
}
