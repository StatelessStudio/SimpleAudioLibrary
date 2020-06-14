from conans import ConanFile, CMake


class SimpleAudioLibraryConan(ConanFile):
    name = "simple-audio-library"
    version = "1.0.0"
    license = "MIT"
    author = "Stateless Studio, Drew Immerman, Andy Smile"
    url = "https://github.com/StatelessStudio/SimpleAudioLibrary"
    description = "Simple OpenAL Wrapper"
    topics = ("audio", "3d", "openal")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = {"shared": False}
    generators = "cmake"
    exports_sources = "src/*"

    requires = [
        ("openal/1.19.1")
    ]

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder="src")
        cmake.build()

    def package(self):
        self.copy("*.h", dst="include/SimpleAudio", src="src")
        self.copy("*.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.dylib*", dst="lib", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["SimpleAudioLibrary"]
