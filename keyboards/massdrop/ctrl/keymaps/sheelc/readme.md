To build and flash keyboard:

From qmk_firmware directory:

```
qmk compile -kb massdrop/ctrl -km sheelc && \
cp massdrop_ctrl_sheelc.bin ../mdloader/build/massdrop_ctrl_sheelc.bin && \
cd ../mdloader && \
./build/mdloader --first --download build/massdrop_ctrl_sheelc.bin --restart && \
cd ../qmk_firmware
```

Then put keyboard into reboot mode (fn + b, hold for a few seconds then release).
