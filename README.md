# Shitfest Chat

A server <-> client chat service.

## Building

```bash
git clone --depth 1 https://github.com/RamblingMadMan/shitfest.git
cd shitfest
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build . -j$(nproc)
```

## Running

From the build directory run the given commands:

### Client

```bash
./client/sf-gui
```

### Server

```bash
./server/sf-srv
```
