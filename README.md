# simple webasm template for raylib
You need to have emsdk installed.
On arch you can just install it like this:
```sh
yay -S emsdk
```

When you first download this template, run:
```sh
emcmake cmake . --fresh
```

Also compile raylib:
```sh
cd extern/raylib

mkdir build
cd build
emcmake cmake .. -DPLATFORM=Web
make -j$(nproc)
```

When you are ready to build the project, just run:
```sh
make
```
