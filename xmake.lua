-- set minimum xmake version
set_xmakever("3.0.0")

-- set project constants
set_project("commonlibf4")
set_languages("c++23")
set_warnings("allextra")
set_encodings("utf-8")

-- add common rules
add_rules("mode.debug", "mode.releasedbg")

-- include subprojects
includes("lib/commonlib-shared")

-- define targets
target("commonlibf4", function()
    -- set target kind
    set_kind("static")

    -- set build by default
    set_default(os.scriptdir() == os.projectdir())

    -- add dependencies
    add_deps("commonlib-shared", { public = true })

    -- add source files
    add_files("src/**.cpp")

    -- add header files
    add_includedirs("include", { public = true })
    add_headerfiles(
        "include/(F4SE/**.h)",
        "include/(RE/**.h)",
        "include/(Scaleform/**.h)"
    )

    -- add extra files
    add_extrafiles("res/commonlibf4.natvis")

    -- set precompiled header
    set_pcxxheader("include/F4SE/Impl/PCH.h")
end)

rule("commonlibf4.plugin", function()
    add_deps("commonlib.plugin")

    on_load(function(target)
        target:data_set("commonlib.plugin.config", target:extraconf("rules", "commonlibf4.plugin"))
        target:data_set("commonlib.plugin.package", { prefixdir = "Data" })
    end)

    on_config(function(target)
        target:add("deps", "commonlibf4")

        target:add("configfiles", path.join(os.scriptdir(), "res/commonlibf4-plugin.cpp.in"))
        target:add("files", path.join(target:configdir(), "commonlibf4-plugin.cpp"))

        if os.getenv("XSE_FO4_MODS_PATH") then
            target:set("installdir", path.join(os.getenv("XSE_FO4_MODS_PATH"), target:name()))
        elseif os.getenv("XSE_FO4_GAME_PATH") then
            target:set("installdir", path.join(os.getenv("XSE_FO4_GAME_PATH"), "Data"))
        end

        target:add("installfiles", target:targetfile(), { prefixdir = "F4SE/Plugins" })
        target:add("installfiles", target:symbolfile(), { prefixdir = "F4SE/Plugins" })
    end)
end)

rule("commonlibf4.archive", function()
    add_deps("commonlib.archive")

    on_load(function(target)
        target:data_set("commonlib.archive.config", target:extraconf("rules", "commonlibf4.archive"))
        target:data_set("commonlib.archive.format", "-fo4" )
        target:data_set("commonlib.archive.extension", ".ba2")
        target:data_set("commonlib.archive.suffix", " - Main")
    end)
end)

rule("commonlibf4.ddsarchive", function()
    add_deps("commonlib.archive")

    on_load(function(target)
        target:data_set("commonlib.archive.config", target:extraconf("rules", "commonlibf4.archive"))
        target:data_set("commonlib.archive.format", "-fo4dds" )
        target:data_set("commonlib.archive.extension", ".ba2")
        target:data_set("commonlib.archive.suffix", " - Textures")
    end)
end)

rule("commonlibf4.papyrus", function()
    add_deps("commonlib.papyrus")

    on_load(function(target)
        target:data_set("commonlib.papyrus.config", target:extraconf("rules", "commonlibf4.papyrus"))
        target:data_set("commonlib.papyrus.game", "fallout4" )
        target:data_set("commonlib.papyrus.gamevar", "XSE_FO4_GAME_PATH")
        target:data_set("commonlib.papyrus.defaults", {
            "Data/Scripts/Source/User",
            "Data/Scripts/Source/CreationClub",
            "Data/Scripts/Source/DLC06",
            "Data/Scripts/Source/DLC05",
            "Data/Scripts/Source/DLC04",
            "Data/Scripts/Source/DLC03",
            "Data/Scripts/Source/DLC02",
            "Data/Scripts/Source/DLC01",
            "Data/Scripts/Source/Base" } )
        target:data_set("commonlib.papyrus.flags", "Institute_Papyrus_Flags.flg")
    end)
end)
