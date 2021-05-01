workspace "Lebakas"
    architecture 'x64'

    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Lebakas"
    location "Lebakas"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "vendor/SFML/include"
    }

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0"

        defines
        {
            "LEBAKAS_BUILD_DLL",
            "LEBAKAS_PLATFORM_WINDOWS"
        }

        libdirs
        {
            "vendor/SFML/lib"
        }
    
        links
        {
            "opengl32.lib",
            "freetype.lib",
            "winmm.lib",
            "gdi32.lib",
            "openal32.lib",
            "flac.lib",
            "vorbisenc.lib",
            "vorbisfile.lib",
            "vorbis.lib",
            "ogg.lib",
            "ws2_32.lib"
        }

    filter "system:linux"
        cppdialect "C++17"
        staticruntime "On"

        defines
        {
            "LEBAKAS_PLATFORM_UNIX"
        }

        buildoptions 
        {
            "-fPIC"
        }

    filter "configurations:Debug"
        defines "LEBAKAS_DEBUG"
        symbols "On"

        links
        {
            "sfml-audio-d.lib",
            "sfml-graphics-d.lib",
            "sfml-network-d.lib",
            "sfml-system-d.lib",
            "sfml-window-d.lib"
        }

    filter "configurations:Release"
        defines "LEBAKAS_RELEASE"
        optimize "On"

        links
        {
            "sfml-audio.lib",
            "sfml-graphics.lib",
            "sfml-network.lib",
            "sfml-system.lib",
            "sfml-window.lib"
        }

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Lebakas/vendor/spdlog/include",
        "Lebakas/src",
        "vendor/SFML/include"
    }

    links
    {
        "Lebakas"
    }

    postbuildcommands
    {
        ("{COPY} ../vendor/SFML/bin/ ../bin/" .. outputdir .. "/Sandbox")
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0"

        defines
        {
            "LEBAKAS_PLATFORM_WINDOWS"
        }

        libdirs
        {
            "vendor/SFML/lib"
        }

    filter "system:linux"
        cppdialect "C++17"
        staticruntime "On"

        defines
        {
            "LEBAKAS_PLATFORM_UNIX"
        }

    filter "configurations:Debug"
        defines "LEBAKAS_DEBUG"
        symbols "On"

        links
        {
            "sfml-audio-d.lib",
            "sfml-graphics-d.lib",
            "sfml-network-d.lib",
            "sfml-system-d.lib",
            "sfml-window-d.lib"
        }

    filter "configurations:Release"
        defines "LEBAKAS_RELEASE"
        optimize "On"

        links
        {
            "sfml-audio.lib",
            "sfml-graphics.lib",
            "sfml-network.lib",
            "sfml-system.lib",
            "sfml-window.lib"
        }
