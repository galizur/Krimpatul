#!sh
vendor/premake/premake5 export-compile-commands
cp compile_commands/debug.json compile_commands.json
vendor/premake/premake5 gmake2
