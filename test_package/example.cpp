#include <SimpleAudioLibrary/Listener.h>
#include <SimpleAudioLibrary/CorruptedFileException.h>
#include <SimpleAudioLibrary/InvalidPathException.h>
#include <SimpleAudioLibrary/NoContextException.h>
#include <SimpleAudioLibrary/NoDeviceException.h>
#include <SimpleAudioLibrary/AudioEntity.h>
#include <SimpleAudioLibrary/Sound.h>

#include <iostream>

int main()
{
    try {
        // before you can use this library, you have to initialize it
        SimpleAudioLib::Listener& listener = SimpleAudioLib::Listener::getInstance();

        listener.initWithDefaultDevice();
        listener.setPosition(0, 0, 0);
        listener.setVelocity(0, 0, 0);

        // load audio file in wave format
        SimpleAudioLib::Sound wow;
        wow.loadWaveFile("../../../../resources/wow.wav");

        // Create entity
        SimpleAudioLib::AudioEntity ent;

        std::cout << "Success!" << std::endl;
        std::cout << "q to quit" << std::endl;

        ent.setPitch(0.5);

        char input = ' ';
        float x, y, z;

        while (input != 'q') {

            std::cout << "x: " << std::flush;
            std::cin >> x;
            std::cout << "y: " << std::flush;
            std::cin >> y;
            std::cout << "z: " << std::flush;
            std::cin >> z;
            ent.setPitch(1);
            ent.setPosition(x, y, z);

            // play sound
            ent.play(wow.getBuffer());

            std::cout << "q? " << std::flush;
            std::cin >> input;
        }

        SimpleAudioLib::Listener::release();

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
