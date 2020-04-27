# How to install Swiftshader

You can get a recent version of swiftshader from:

https://github.com/google/gfbuild-swiftshader/releases

To install it:

```
mkdir swiftshader
cd swiftshader
wget https://github.com/google/gfbuild-swiftshader/releases/download/github%2Fgoogle%2Fgfbuild-swiftshader%2F60aa34a990fa77553e2d9a69d34f0b3601ced66a/gfbuild-swiftshader-60aa34a990fa77553e2d9a69d34f0b3601ced66a-Linux_x64_Release.zip
unzip *.zip

export VK_ICD_FILENAMES="$(pwd)/lib/vk_swiftshader_icd.json"
```

To check that it is used:

```
export VK_LOADER_DEBUG=all

timeout -k 1 2 $VULKAN_SDK/bin/vkcube
```

And look for references about libvk_swiftshader.so

