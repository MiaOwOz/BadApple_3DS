# Bad Apple!! on Nintendo 3DS

This project is a simple implementation of the popular music video "Bad Apple" on the 3DS.
It is implemented by drawing ASCII characters on the screen.

## Installation

Grab the latest `.3dsx` release from the `Releases` section and put it into the `/3ds/` folder on your 3DS' SD Card.
Then, run the app through the Homebrew Launcher.

## Building

The project does not have any additional dependencies besides the `devkitPro` toolchain with the `3ds-dev` package.
Clone the project, `cd` into its directory and run the `make` command.

The `convert_frames.py` script is used to create the required header `frames.h`. If you want to create your own header using the script, you'll need to provide a video file the script can use. The filename is currently hardcoded, so you need to change the name in the script.

## Contributing

Feel free to open an Issue or Pull Request.
I currently do not intend to add any more features, but if you want to add something, go ahead!

## Credits

[devkitPro](https://devkitpro.org/) for providing the necessary tools<br>
[u/KittyKingCrafting](https://www.reddit.com/user/KittyKingCrafting/) on Reddit for providing the [VS Code configuration](https://www.reddit.com/r/homebrew/comments/1n6jdpt/comment/ndc19ki/) for getting IntelliSense to work

## License

MIT License

Copyright (c) [2025] [Miaowz]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.