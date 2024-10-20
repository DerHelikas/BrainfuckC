cmake_minimum_required(VERSION 3.28)

project(BrainFuck)



file(GLOB BrainfFuckModules "BrainFuckC_files/*.c" "BrainFuckC_files/*.h")

add_executable(BrainFuckIntr Main.c ${BrainfFuckModules})