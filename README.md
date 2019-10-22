# Fdf
![screenshot](https://github.com/alyapin/Fdf/blob/master/screens/screenshot.jpg)

Fdf is project A simple 3D height-map renderer. You can rotate models, color is defined by relative height in the map.

## Features
* Simple file format definition (array of space-separated integers)
* 3D rotatioт via keyboards
* Camera controls (zoom, translate)
* Pretty color gradients!
* Line clipping

## Compiling and running
Run `make`. An executable will compile. Currently only tested on OS X.

Run it with `./fdf [map]`. A bunch of sample maps are provided in the `test_maps`
directory. The one in the screenshot above is `test_maps/42.fdf`.

## License
This project is licensed under the GNU General Public License 3.

