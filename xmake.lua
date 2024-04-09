set_project("wordsreciter")
set_version("2.0.1")
set_languages("cxx20")
set_encodings("utf-8")
if is_plat("windows") then
    set_toolchains("msvc")
else
    set_toolchains("clang")
end
set_optimize("fastest")
add_rules("mode.debug", "mode.release", "mode.minsizerel")
target("wordsreciter")
    add_rules("qt.widgetapp")
    add_files("src/*.cpp")
    add_files("src/*.h")
    add_files("src/*.ui")
    add_files("static/static.qrc")
    add_files("static/icon.rc")
    add_files("lib/dark/darkstyle.qrc")
    -- add_packages("cmake::lib/QHotkey")

    add_files("lib/QHotkey/QHotkey/*.h")
    add_files("lib/QHotkey/QHotkey/qhotkey.cpp")
    if is_plat("macosx") then
        add_files("lib/QHotkey/QHotkey/qhotkey_mac.cpp")
    elseif is_plat("windows") then
        add_files("lib/QHotkey/QHotkey/qhotkey_win.cpp")
    elseif is_plat("linux") then
        add_files("lib/QHotkey/QHotkey/qhotkey_x11.cpp")
    end

target("test")
    set_default(false)
    add_files("test/*.cpp")