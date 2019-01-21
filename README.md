# ScreamEngine

[![Build Status](https://travis-ci.com/ajm113/screamEngine.svg?branch=master)](https://travis-ci.com/ajm113/screamEngine)

*Simple 2D Unix game engine based from [olcPixelGameEngine](https://github.com/OneLoneCoder/olcPixelGameEngine).*

## What's different vs olcPixelEngine?

- Clean/organized codebase.
- MIT License (olcPixelEngine uses some sort of sudo GNU license?)
- Makefile for gcc and or Mingw (if building for Windows).
  Ability to extend to other GUI frameworks with ease.
- Unit testing.
- Pure C++. No mixing of C stdlib headers and functions if possiable.
- Use as a library or **fork it**!
- Up to date code standereds.
- Mod support.
- 100% Unix support.
- Maybe more...?

## Install

First, make sure you have gcc installed. After installing clone the repo, and `$ cd screamEngine` and type `make build`.

Once the project is built. You should get a bin folder with the executable. Now run `./build/scream` to start the engine.

## Roadmap

- Get working OpenGL context window working.
- Create renderer.
- Image/Sprite loading.
- Basic physics engine.
- Perhaps Lua support?

## Credits

- Andrew McRobb (ajm113)
