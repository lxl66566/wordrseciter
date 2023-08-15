set_project("wordsreciter")
set_version("2.0.0")
set_languages("cxx20")
set_encodings("utf-8")
set_toolchains("msvc")
set_optimize("fastest")
add_rules("mode.debug", "mode.release", "mode.minsizerel")
target("main")
    add_rules("qt.widgetapp")
    add_files("src/*.cpp")
    add_files("src/*.h")
    add_files("src/*.ui")
    add_files("static/static.qrc")
    add_files("lib/dark/darkstyle.qrc")

target("test")
    set_default(false)
    add_files("test/*.cpp")