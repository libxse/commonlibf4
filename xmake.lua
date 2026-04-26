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

-- override runtime count
add_defines("COMMONLIB_RUNTIMECOUNT=3")

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

        local plugin_file = path.join(os.scriptdir(), "res/commonlibf4-plugin.cpp.in")
        local custom_plugin_file = target:extraconf("rules", "commonlibf4.plugin", "plugin_template")

        if custom_plugin_file then
            plugin_file = custom_plugin_file
        end

        target:add("configfiles", plugin_file)
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
